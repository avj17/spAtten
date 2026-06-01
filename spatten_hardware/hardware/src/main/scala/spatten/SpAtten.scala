package spatten

import spinal.core._
import spinal.lib._
import spinal.lib.bus.amba4.axi._
import spinal.lib.bus.misc.SizeMapping


case class SpAttenConfig(
    val widthQuantValue: Int = 12 /*32*/,
    val widthFPValue: Int = 32,
    // @deprecated
    // val sizeN: Int = 320,
    val minD: Int = 64,
    val sizeD: Int = 64,
    val numMultipliers: Int = /* 64   */ 512,
    val numBufferLines: Int = /* 2048 */ 256,
    
    val maxBatchSize: Int = 1024,

    val numDRAMChannel: Int = /*2*/ 16,
    val dramBusConfig: Axi4Config,

    val numMatrixFetcherChannel: Int = /*4*/ 32,
    val maxFusedMatrix: Int = 2,

    val useDummyTopK: Boolean = true
) {
    val maxNumKey      = numMultipliers / minD * numBufferLines
    val maxNumVal      = maxNumKey
    val numSoftMaxUnit = numMultipliers / minD

    def genFix()    = SInt(widthQuantValue bits)
    def genFloat()  = Bits(widthFPValue bits)

    def genBufAddr()  = UInt(log2Up(numBufferLines) bits)

    @deprecated
    def genDBufId() = Bits(1 bit)
}

object SpAttenConfigScaledown {
    def apply(config: SpAttenConfig, ratio: Int) = {
        config.copy(
            numMultipliers = config.numBufferLines / ratio,
            numBufferLines = config.numBufferLines * ratio,
            numDRAMChannel = config.numDRAMChannel / ratio,
            numMatrixFetcherChannel = config.numMatrixFetcherChannel / ratio
        )
    }
}

object SpAttenConfigScaledownDRAMOnly {
    def apply(config: SpAttenConfig, ratio: Int) = {
        config.copy(
            numDRAMChannel = config.numDRAMChannel / ratio,
            numMatrixFetcherChannel = (config.numMatrixFetcherChannel / ratio) max (config.numSoftMaxUnit)
        )
    }
}

case class QuantProfile(config: SpAttenConfig) extends Bundle {
    val bit_count = UInt(log2Up(config.widthQuantValue + 1) bits)
    val fused_mat = UInt(log2Up(config.maxFusedMatrix + 1) bits)
}

case class SpAttenRequestMetadata(config: SpAttenConfig) extends Bundle {
    val profile_key           = QuantProfile(config)
    val profile_val           = QuantProfile(config)
    val key_base_addr         = UInt(config.dramBusConfig.addressWidth bits)
    val key_requant_base_addr = UInt(config.dramBusConfig.addressWidth bits)
    val val_base_addr         = UInt(config.dramBusConfig.addressWidth bits)
    val key_fetch_num         = UInt(log2Up(config.maxNumKey + 1) bits)
    val val_fetch_num         = UInt(log2Up(config.maxNumVal + 1) bits)
    val topk_enable           = Bool
    val topk_num              = UInt(log2Up(config.maxNumKey + 1) bits)
    val size_d                = UInt(log2Up(config.sizeD + 1) bits)
    val allow_requantize      = Bool
    val thres_requantize      = config.genFix()

    // for debug
    val universal_id          = UInt(32 bits).dontSimplifyIt()
    val topk_latency          = UInt(32 bits)
}

case class SpAttenRequest(config: SpAttenConfig) extends Bundle {
    val query         = Vec(config.genFix, config.sizeD)
    val metadata      = SpAttenRequestMetadata(config)
}
case class SpAttenResponse(config: SpAttenConfig) extends Bundle {
    val results       = Vec(config.genFix, config.sizeD)
    val metadata      = SpAttenRequestMetadata(config)
}

class Crossbar(numMasters: Int, numSlaves: Int, masterConfig: Axi4Config, slaveConfig: Axi4Config) extends Component {
    val io = new Bundle {
        val masters = Vec(slave(Axi4ReadOnly(masterConfig)), numMasters)
        val slaves  = Vec(master(Axi4ReadOnly(slaveConfig)), numSlaves)
    }

    val balance_slaves  = Vec(Reg(SInt(32 bits)) init(0), numSlaves)
    val balance_masters = Vec(Reg(SInt(32 bits)) init(0), numMasters)

    for (i <- 0 until numSlaves) {
        balance_slaves(i) := (balance_slaves(i) + io.slaves(i).ar.fire.asSInt - io.slaves(i).r.fire.asSInt).resized
    }
    for (i <- 0 until numMasters) {
        balance_masters(i) := (balance_masters(i) + io.masters(i).ar.fire.asSInt - io.masters(i).r.fire.asSInt).resized
    }

    val low_bit = 5

    val m2s_ar = Vec.tabulate(numMasters) { i => 
        StreamDemux(io.masters(i).ar, io.masters(i).ar.addr(log2Up(numSlaves) + low_bit - 1 downto low_bit), numSlaves)
    }
    val s2m_r  = Vec.tabulate(numSlaves) { i => 
        StreamDemux(io.slaves(i).r, io.slaves(i).r.id, numMasters)
    }

    for (i <- 0 until numSlaves) {
        val arbiter = StreamArbiterFactory.transactionLock.lowerFirst.build(Axi4Ar(masterConfig), numMasters)

        for (j <- 0 until numMasters) {
            arbiter.io.inputs(j) << m2s_ar(j)(i)
        }

        io.slaves(i).ar.translateFrom(arbiter.io.output) { (to, from) => 
            to.addr := (from.addr >> (low_bit + log2Up(numSlaves)) << low_bit).resized
            to.id   := arbiter.io.chosen
        }
    }

    for (i <- 0 until numMasters) {
        StreamArbiterFactory.transactionLock.lowerFirst.on(s2m_r.map(_(i))).translateInto(io.masters(i).r) { (to, from) => 
            to.data := from.data
            to.last := from.last
        }
    }
}

class SpAtten(config: SpAttenConfig) extends Component {
    import config._

    implicit val config_impl: SpAttenConfig = config

    val slaveConfig = dramBusConfig.copy(useId=true, idWidth=log2Up(numMatrixFetcherChannel))

    val io = new Bundle {
        val req  = slave Stream(Fragment(SpAttenRequest(config)))
        val resp = master Stream(SpAttenResponse(config))
        val bus  = Vec(master(Axi4ReadOnly(slaveConfig)), numDRAMChannel)
    }


    val controller_inst = new SpAttenController

    controller_inst.io.req  << io.req
    controller_inst.io.resp >> io.resp

    val crossbar = new Crossbar(numMatrixFetcherChannel, numDRAMChannel, dramBusConfig, slaveConfig)

    (crossbar.io.masters, controller_inst.io.bus).zipped.foreach(_ << _)
    (crossbar.io.slaves,  io.bus).zipped.foreach(_ >> _)
}

class SpAttenSim(config: SpAttenConfig) extends Component {

    import config._

    implicit val config_impl: SpAttenConfig = config

    val io = new Bundle {
        val req  = slave Stream(Fragment(SpAttenRequest(config)))
        val resp = master Stream(SpAttenResponse(config))
    }

    val dram = Vec(DRAMSim(DRAMSimConfig(dramBusConfig.addressWidth, dramBusConfig.dataWidth)), numDRAMChannel)

    val spatten_inst = new SpAtten(config)

    spatten_inst.io.req  << io.req
    spatten_inst.io.resp >> io.resp
    (dram, spatten_inst.io.bus).zipped.foreach { _.fromAxi4(_) }

    val dram_insts = Array.tabulate(numDRAMChannel) { i => new DRAMSimDPIDriver(dram(i).config) }
    for (i <- 0 until numDRAMChannel) {
        dram_insts(i).io.dram <> dram(i)
    }
}

object ElaborateA3base {
    def main(args: Array[String]): Unit = {
        val axiConfig = Axi4Config(32, 256, 
                useId     = false,
                useRegion = false,
                useBurst  = false,
                useLock   = false,
                useCache  = false,
                useSize   = false,
                useQos    = false,
                useLen    = false,
                useLast   = true,
                useResp   = false,
                useProt   = false,
                useStrb   = false)

        val numBufferLines  = args(0).toInt
        val bandwidthDownsample = if (args.size >= 2) args(1).toInt else 1

        println(s"numBufferLines=${numBufferLines}")
        println(s"bandwidth downsample=${bandwidthDownsample}")

        val config = SpAttenConfigScaledownDRAMOnly(
            SpAttenConfig(
                dramBusConfig  = axiConfig, 
                numBufferLines = numBufferLines,
                numMultipliers = 128,  // THE FIX: Shrinks the internal datapath to avoid the 8192-bit crash
                useDummyTopK   = false
            ), 
            ratio = bandwidthDownsample
        )

        // THE FIX: Standard config with no fake custom MIT parameters
        SpinalConfig(verbose=true)
            .addStandardMemBlackboxing(blackboxAllWhatsYouCan)
            .generateVerilog { 
                new SpAtten(config)
            }
    }
}