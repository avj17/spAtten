
#include <stdint.h>
#include <string>
#include <memory>
#include <jni.h>
#include <iostream>

#include "VSpAttenSim.h"
#ifdef TRACE
#include "verilated_fst_c.h"
#endif
#include "VSpAttenSim__Syms.h"

using namespace std;

class ISignalAccess{
public:
  virtual ~ISignalAccess() {}

  virtual void getAU8(JNIEnv *env, jbyteArray value) {}
  virtual void getAU8_mem(JNIEnv *env, jbyteArray value, size_t index) {}
  virtual void setAU8(JNIEnv *env, jbyteArray value, int length) {}
  virtual void setAU8_mem(JNIEnv *env, jbyteArray value, int length, size_t index) {}

  virtual uint64_t getU64() = 0;
  virtual uint64_t getU64_mem(size_t index) = 0;
  virtual void setU64(uint64_t value) = 0;
  virtual void setU64_mem(uint64_t value, size_t index) = 0;
};

class  CDataSignalAccess : public ISignalAccess{
public:
    CData *raw;
    CDataSignalAccess(CData *raw) : raw(raw){}
    CDataSignalAccess(CData &raw) : raw(addressof(raw)){}
    uint64_t getU64() {return *raw;}
    uint64_t getU64_mem(size_t index) {return raw[index];}
    void setU64(uint64_t value)  {*raw = value; }
    void setU64_mem(uint64_t value, size_t index){raw[index] = value; }
};


class  SDataSignalAccess : public ISignalAccess{
public:
    SData *raw;
    SDataSignalAccess(SData *raw) : raw(raw){}
    SDataSignalAccess(SData &raw) : raw(addressof(raw)){}
    uint64_t getU64() {return *raw;}
    uint64_t getU64_mem(size_t index) {return raw[index];}
    void setU64(uint64_t value)  {*raw = value; }
    void setU64_mem(uint64_t value, size_t index){raw[index] = value; }
};


class  IDataSignalAccess : public ISignalAccess{
public:
    IData *raw;
    IDataSignalAccess(IData *raw) : raw(raw){}
    IDataSignalAccess(IData &raw) : raw(addressof(raw)){}
    uint64_t getU64() {return *raw;}
    uint64_t getU64_mem(size_t index) {return raw[index];}
    void setU64(uint64_t value)  {*raw = value; }
    void setU64_mem(uint64_t value, size_t index){raw[index] = value; }
};


class  QDataSignalAccess : public ISignalAccess{
public:
    QData *raw;
    QDataSignalAccess(QData *raw) : raw(raw){}
    QDataSignalAccess(QData &raw) : raw(addressof(raw)){}
    uint64_t getU64() {return *raw;}
    uint64_t getU64_mem(size_t index) {return raw[index];}
    void setU64(uint64_t value)  {*raw = value; }
    void setU64_mem(uint64_t value, size_t index){raw[index] = value; }
};

class  WDataSignalAccess : public ISignalAccess{
public:
    WData *raw;
    uint32_t width;
    uint32_t wordsCount;
    bool sint;

    WDataSignalAccess(WData *raw, uint32_t width, bool sint) : 
      raw(raw), width(width), wordsCount((width+31)/32), sint(sint) {}

    uint64_t getU64_mem(size_t index) {
      WData *mem_el = &(raw[index*wordsCount]);
      return mem_el[0] + (((uint64_t)mem_el[1]) << 32);
    }

    uint64_t getU64() { return getU64_mem(0); }

    void setU64_mem(uint64_t value, size_t index)  {
      WData *mem_el = &(raw[index*wordsCount]);
      mem_el[0] = value;
      mem_el[1] = value >> 32;
      uint32_t padding = ((value & 0x8000000000000000l) && sint) ? 0xFFFFFFFF : 0;
      for(uint32_t idx = 2;idx < wordsCount;idx++){
        mem_el[idx] = padding;
      }

      if(width%32 != 0) mem_el[wordsCount-1] &= (1l << width%32)-1;
    }

    void setU64(uint64_t value)  {
      setU64_mem(value, 0);
    }
    
    void getAU8_mem(JNIEnv *env, jbyteArray value, size_t index) {
      WData *mem_el = &(raw[index*wordsCount]);
      uint32_t byteCount = wordsCount*4;
      uint32_t shift = 32-(width % 32);
      uint32_t backup = mem_el[wordsCount-1];
      uint8_t values[byteCount + !sint];
      if(sint && shift != 32) mem_el[wordsCount-1] = (((int32_t)backup) << shift) >> shift;
      for(uint32_t idx = 0;idx < byteCount;idx++){
        values[idx + !sint] = ((uint8_t*)mem_el)[byteCount-idx-1];
      }
      (env)->SetByteArrayRegion ( value, 0, byteCount + !sint, reinterpret_cast<jbyte*>(values));
      mem_el[wordsCount-1] = backup;
    }
  
    void getAU8(JNIEnv *env, jbyteArray value) {
      getAU8_mem(env, value, 0);
    }

    void setAU8_mem(JNIEnv *env, jbyteArray jvalue, int length, size_t index) {
      WData *mem_el = &(raw[index*wordsCount]);
      jbyte value[length];
      (env)->GetByteArrayRegion( jvalue, 0, length, value);
      uint32_t padding = (value[0] & 0x80 && sint) != 0 ? 0xFFFFFFFF : 0;
      for(uint32_t idx = 0;idx < wordsCount;idx++){
        mem_el[idx] = padding;
      }
      uint32_t capedLength = length > 4*wordsCount ? 4*wordsCount : length;
      for(uint32_t idx = 0;idx < capedLength;idx++){
        ((uint8_t*)mem_el)[idx] = value[length-idx-1];
      }
      if(width%32 != 0) mem_el[wordsCount-1] &= (1l << width%32)-1;
    }

    void setAU8(JNIEnv *env, jbyteArray jvalue, int length) {
      setAU8_mem(env, jvalue, length, 0);
    }
};

class Wrapper_1;
thread_local Wrapper_1 *simHandle1;

#include <chrono>
using namespace std::chrono;

class Wrapper_1{
public:
    uint64_t time;
    high_resolution_clock::time_point lastFlushAt;
    uint32_t timeCheck;
    bool waveEnabled;
    VSpAttenSim top;
    ISignalAccess *signalAccess[295];
    #ifdef TRACE
	  VerilatedFstC tfp;
	  #endif
    string name;
    int32_t time_precision;

    Wrapper_1(const char * name){
      simHandle1 = this;
      time = 0;
      timeCheck = 0;
      lastFlushAt = high_resolution_clock::now();
      waveEnabled = true;
      signalAccess[0] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_0_count_read_value );
      signalAccess[1] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_0_count_write_value );
      signalAccess[2] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_1_count_read_value );
      signalAccess[3] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_1_count_write_value );
      signalAccess[4] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_2_count_read_value );
      signalAccess[5] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_2_count_write_value );
      signalAccess[6] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_3_count_read_value );
      signalAccess[7] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_3_count_write_value );
      signalAccess[8] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_4_count_read_value );
      signalAccess[9] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_4_count_write_value );
      signalAccess[10] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_5_count_read_value );
      signalAccess[11] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_5_count_write_value );
      signalAccess[12] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_6_count_read_value );
      signalAccess[13] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_6_count_write_value );
      signalAccess[14] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_7_count_read_value );
      signalAccess[15] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_7_count_write_value );
      signalAccess[16] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_8_count_read_value );
      signalAccess[17] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_8_count_write_value );
      signalAccess[18] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_9_count_read_value );
      signalAccess[19] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_9_count_write_value );
      signalAccess[20] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_10_count_read_value );
      signalAccess[21] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_10_count_write_value );
      signalAccess[22] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_11_count_read_value );
      signalAccess[23] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_11_count_write_value );
      signalAccess[24] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_12_count_read_value );
      signalAccess[25] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_12_count_write_value );
      signalAccess[26] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_13_count_read_value );
      signalAccess[27] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_13_count_write_value );
      signalAccess[28] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_14_count_read_value );
      signalAccess[29] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_14_count_write_value );
      signalAccess[30] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_15_count_read_value );
      signalAccess[31] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->mat_fetcher_inst->stageLoadData_1->subareaRespFifoCounters_15_count_write_value );
      signalAccess[32] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_0->ram_insts_0->areaCounter_count_read_value );
      signalAccess[33] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_0->ram_insts_0->areaCounter_count_write_value );
      signalAccess[34] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_0->ram_insts_1->areaCounter_count_read_value );
      signalAccess[35] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_0->ram_insts_1->areaCounter_count_write_value );
      signalAccess[36] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_1->ram_insts_0->areaCounter_count_read_value );
      signalAccess[37] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_1->ram_insts_0->areaCounter_count_write_value );
      signalAccess[38] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_1->ram_insts_1->areaCounter_count_read_value );
      signalAccess[39] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_1->ram_insts_1->areaCounter_count_write_value );
      signalAccess[40] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_2->ram_insts_0->areaCounter_count_read_value );
      signalAccess[41] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_2->ram_insts_0->areaCounter_count_write_value );
      signalAccess[42] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_2->ram_insts_1->areaCounter_count_read_value );
      signalAccess[43] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_2->ram_insts_1->areaCounter_count_write_value );
      signalAccess[44] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_3->ram_insts_0->areaCounter_count_read_value );
      signalAccess[45] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_3->ram_insts_0->areaCounter_count_write_value );
      signalAccess[46] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_3->ram_insts_1->areaCounter_count_read_value );
      signalAccess[47] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_3->ram_insts_1->areaCounter_count_write_value );
      signalAccess[48] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_4->ram_insts_0->areaCounter_count_read_value );
      signalAccess[49] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_4->ram_insts_0->areaCounter_count_write_value );
      signalAccess[50] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_4->ram_insts_1->areaCounter_count_read_value );
      signalAccess[51] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_4->ram_insts_1->areaCounter_count_write_value );
      signalAccess[52] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_5->ram_insts_0->areaCounter_count_read_value );
      signalAccess[53] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_5->ram_insts_0->areaCounter_count_write_value );
      signalAccess[54] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_5->ram_insts_1->areaCounter_count_read_value );
      signalAccess[55] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_5->ram_insts_1->areaCounter_count_write_value );
      signalAccess[56] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_6->ram_insts_0->areaCounter_count_read_value );
      signalAccess[57] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_6->ram_insts_0->areaCounter_count_write_value );
      signalAccess[58] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_6->ram_insts_1->areaCounter_count_read_value );
      signalAccess[59] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_6->ram_insts_1->areaCounter_count_write_value );
      signalAccess[60] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_7->ram_insts_0->areaCounter_count_read_value );
      signalAccess[61] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_7->ram_insts_0->areaCounter_count_write_value );
      signalAccess[62] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_7->ram_insts_1->areaCounter_count_read_value );
      signalAccess[63] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_7->ram_insts_1->areaCounter_count_write_value );
      signalAccess[64] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_8->ram_insts_0->areaCounter_count_read_value );
      signalAccess[65] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_8->ram_insts_0->areaCounter_count_write_value );
      signalAccess[66] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_8->ram_insts_1->areaCounter_count_read_value );
      signalAccess[67] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_8->ram_insts_1->areaCounter_count_write_value );
      signalAccess[68] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_9->ram_insts_0->areaCounter_count_read_value );
      signalAccess[69] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_9->ram_insts_0->areaCounter_count_write_value );
      signalAccess[70] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_9->ram_insts_1->areaCounter_count_read_value );
      signalAccess[71] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_9->ram_insts_1->areaCounter_count_write_value );
      signalAccess[72] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_10->ram_insts_0->areaCounter_count_read_value );
      signalAccess[73] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_10->ram_insts_0->areaCounter_count_write_value );
      signalAccess[74] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_10->ram_insts_1->areaCounter_count_read_value );
      signalAccess[75] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_10->ram_insts_1->areaCounter_count_write_value );
      signalAccess[76] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_11->ram_insts_0->areaCounter_count_read_value );
      signalAccess[77] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_11->ram_insts_0->areaCounter_count_write_value );
      signalAccess[78] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_11->ram_insts_1->areaCounter_count_read_value );
      signalAccess[79] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_key->data_ram_insts_11->ram_insts_1->areaCounter_count_write_value );
      signalAccess[80] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_0->ram_insts_0->areaCounter_count_read_value );
      signalAccess[81] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_0->ram_insts_0->areaCounter_count_write_value );
      signalAccess[82] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_0->ram_insts_1->areaCounter_count_read_value );
      signalAccess[83] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_0->ram_insts_1->areaCounter_count_write_value );
      signalAccess[84] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_1->ram_insts_0->areaCounter_count_read_value );
      signalAccess[85] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_1->ram_insts_0->areaCounter_count_write_value );
      signalAccess[86] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_1->ram_insts_1->areaCounter_count_read_value );
      signalAccess[87] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_1->ram_insts_1->areaCounter_count_write_value );
      signalAccess[88] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_2->ram_insts_0->areaCounter_count_read_value );
      signalAccess[89] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_2->ram_insts_0->areaCounter_count_write_value );
      signalAccess[90] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_2->ram_insts_1->areaCounter_count_read_value );
      signalAccess[91] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_2->ram_insts_1->areaCounter_count_write_value );
      signalAccess[92] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_3->ram_insts_0->areaCounter_count_read_value );
      signalAccess[93] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_3->ram_insts_0->areaCounter_count_write_value );
      signalAccess[94] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_3->ram_insts_1->areaCounter_count_read_value );
      signalAccess[95] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_3->ram_insts_1->areaCounter_count_write_value );
      signalAccess[96] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_4->ram_insts_0->areaCounter_count_read_value );
      signalAccess[97] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_4->ram_insts_0->areaCounter_count_write_value );
      signalAccess[98] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_4->ram_insts_1->areaCounter_count_read_value );
      signalAccess[99] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_4->ram_insts_1->areaCounter_count_write_value );
      signalAccess[100] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_5->ram_insts_0->areaCounter_count_read_value );
      signalAccess[101] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_5->ram_insts_0->areaCounter_count_write_value );
      signalAccess[102] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_5->ram_insts_1->areaCounter_count_read_value );
      signalAccess[103] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_5->ram_insts_1->areaCounter_count_write_value );
      signalAccess[104] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_6->ram_insts_0->areaCounter_count_read_value );
      signalAccess[105] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_6->ram_insts_0->areaCounter_count_write_value );
      signalAccess[106] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_6->ram_insts_1->areaCounter_count_read_value );
      signalAccess[107] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_6->ram_insts_1->areaCounter_count_write_value );
      signalAccess[108] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_7->ram_insts_0->areaCounter_count_read_value );
      signalAccess[109] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_7->ram_insts_0->areaCounter_count_write_value );
      signalAccess[110] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_7->ram_insts_1->areaCounter_count_read_value );
      signalAccess[111] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_7->ram_insts_1->areaCounter_count_write_value );
      signalAccess[112] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_8->ram_insts_0->areaCounter_count_read_value );
      signalAccess[113] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_8->ram_insts_0->areaCounter_count_write_value );
      signalAccess[114] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_8->ram_insts_1->areaCounter_count_read_value );
      signalAccess[115] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_8->ram_insts_1->areaCounter_count_write_value );
      signalAccess[116] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_9->ram_insts_0->areaCounter_count_read_value );
      signalAccess[117] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_9->ram_insts_0->areaCounter_count_write_value );
      signalAccess[118] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_9->ram_insts_1->areaCounter_count_read_value );
      signalAccess[119] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_9->ram_insts_1->areaCounter_count_write_value );
      signalAccess[120] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_10->ram_insts_0->areaCounter_count_read_value );
      signalAccess[121] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_10->ram_insts_0->areaCounter_count_write_value );
      signalAccess[122] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_10->ram_insts_1->areaCounter_count_read_value );
      signalAccess[123] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_10->ram_insts_1->areaCounter_count_write_value );
      signalAccess[124] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_11->ram_insts_0->areaCounter_count_read_value );
      signalAccess[125] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_11->ram_insts_0->areaCounter_count_write_value );
      signalAccess[126] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_11->ram_insts_1->areaCounter_count_read_value );
      signalAccess[127] = new IDataSignalAccess( top.SpAttenSim->spatten_inst->controller_inst->buffer_val->data_ram_insts_11->ram_insts_1->areaCounter_count_write_value );
      signalAccess[128] = new CDataSignalAccess( top.io_req_valid );
      signalAccess[129] = new CDataSignalAccess( top.io_req_ready );
      signalAccess[130] = new CDataSignalAccess( top.io_req_payload_last );
      signalAccess[131] = new SDataSignalAccess( top.io_req_payload_fragment_query_0 );
      signalAccess[132] = new SDataSignalAccess( top.io_req_payload_fragment_query_1 );
      signalAccess[133] = new SDataSignalAccess( top.io_req_payload_fragment_query_2 );
      signalAccess[134] = new SDataSignalAccess( top.io_req_payload_fragment_query_3 );
      signalAccess[135] = new SDataSignalAccess( top.io_req_payload_fragment_query_4 );
      signalAccess[136] = new SDataSignalAccess( top.io_req_payload_fragment_query_5 );
      signalAccess[137] = new SDataSignalAccess( top.io_req_payload_fragment_query_6 );
      signalAccess[138] = new SDataSignalAccess( top.io_req_payload_fragment_query_7 );
      signalAccess[139] = new SDataSignalAccess( top.io_req_payload_fragment_query_8 );
      signalAccess[140] = new SDataSignalAccess( top.io_req_payload_fragment_query_9 );
      signalAccess[141] = new SDataSignalAccess( top.io_req_payload_fragment_query_10 );
      signalAccess[142] = new SDataSignalAccess( top.io_req_payload_fragment_query_11 );
      signalAccess[143] = new SDataSignalAccess( top.io_req_payload_fragment_query_12 );
      signalAccess[144] = new SDataSignalAccess( top.io_req_payload_fragment_query_13 );
      signalAccess[145] = new SDataSignalAccess( top.io_req_payload_fragment_query_14 );
      signalAccess[146] = new SDataSignalAccess( top.io_req_payload_fragment_query_15 );
      signalAccess[147] = new SDataSignalAccess( top.io_req_payload_fragment_query_16 );
      signalAccess[148] = new SDataSignalAccess( top.io_req_payload_fragment_query_17 );
      signalAccess[149] = new SDataSignalAccess( top.io_req_payload_fragment_query_18 );
      signalAccess[150] = new SDataSignalAccess( top.io_req_payload_fragment_query_19 );
      signalAccess[151] = new SDataSignalAccess( top.io_req_payload_fragment_query_20 );
      signalAccess[152] = new SDataSignalAccess( top.io_req_payload_fragment_query_21 );
      signalAccess[153] = new SDataSignalAccess( top.io_req_payload_fragment_query_22 );
      signalAccess[154] = new SDataSignalAccess( top.io_req_payload_fragment_query_23 );
      signalAccess[155] = new SDataSignalAccess( top.io_req_payload_fragment_query_24 );
      signalAccess[156] = new SDataSignalAccess( top.io_req_payload_fragment_query_25 );
      signalAccess[157] = new SDataSignalAccess( top.io_req_payload_fragment_query_26 );
      signalAccess[158] = new SDataSignalAccess( top.io_req_payload_fragment_query_27 );
      signalAccess[159] = new SDataSignalAccess( top.io_req_payload_fragment_query_28 );
      signalAccess[160] = new SDataSignalAccess( top.io_req_payload_fragment_query_29 );
      signalAccess[161] = new SDataSignalAccess( top.io_req_payload_fragment_query_30 );
      signalAccess[162] = new SDataSignalAccess( top.io_req_payload_fragment_query_31 );
      signalAccess[163] = new SDataSignalAccess( top.io_req_payload_fragment_query_32 );
      signalAccess[164] = new SDataSignalAccess( top.io_req_payload_fragment_query_33 );
      signalAccess[165] = new SDataSignalAccess( top.io_req_payload_fragment_query_34 );
      signalAccess[166] = new SDataSignalAccess( top.io_req_payload_fragment_query_35 );
      signalAccess[167] = new SDataSignalAccess( top.io_req_payload_fragment_query_36 );
      signalAccess[168] = new SDataSignalAccess( top.io_req_payload_fragment_query_37 );
      signalAccess[169] = new SDataSignalAccess( top.io_req_payload_fragment_query_38 );
      signalAccess[170] = new SDataSignalAccess( top.io_req_payload_fragment_query_39 );
      signalAccess[171] = new SDataSignalAccess( top.io_req_payload_fragment_query_40 );
      signalAccess[172] = new SDataSignalAccess( top.io_req_payload_fragment_query_41 );
      signalAccess[173] = new SDataSignalAccess( top.io_req_payload_fragment_query_42 );
      signalAccess[174] = new SDataSignalAccess( top.io_req_payload_fragment_query_43 );
      signalAccess[175] = new SDataSignalAccess( top.io_req_payload_fragment_query_44 );
      signalAccess[176] = new SDataSignalAccess( top.io_req_payload_fragment_query_45 );
      signalAccess[177] = new SDataSignalAccess( top.io_req_payload_fragment_query_46 );
      signalAccess[178] = new SDataSignalAccess( top.io_req_payload_fragment_query_47 );
      signalAccess[179] = new SDataSignalAccess( top.io_req_payload_fragment_query_48 );
      signalAccess[180] = new SDataSignalAccess( top.io_req_payload_fragment_query_49 );
      signalAccess[181] = new SDataSignalAccess( top.io_req_payload_fragment_query_50 );
      signalAccess[182] = new SDataSignalAccess( top.io_req_payload_fragment_query_51 );
      signalAccess[183] = new SDataSignalAccess( top.io_req_payload_fragment_query_52 );
      signalAccess[184] = new SDataSignalAccess( top.io_req_payload_fragment_query_53 );
      signalAccess[185] = new SDataSignalAccess( top.io_req_payload_fragment_query_54 );
      signalAccess[186] = new SDataSignalAccess( top.io_req_payload_fragment_query_55 );
      signalAccess[187] = new SDataSignalAccess( top.io_req_payload_fragment_query_56 );
      signalAccess[188] = new SDataSignalAccess( top.io_req_payload_fragment_query_57 );
      signalAccess[189] = new SDataSignalAccess( top.io_req_payload_fragment_query_58 );
      signalAccess[190] = new SDataSignalAccess( top.io_req_payload_fragment_query_59 );
      signalAccess[191] = new SDataSignalAccess( top.io_req_payload_fragment_query_60 );
      signalAccess[192] = new SDataSignalAccess( top.io_req_payload_fragment_query_61 );
      signalAccess[193] = new SDataSignalAccess( top.io_req_payload_fragment_query_62 );
      signalAccess[194] = new SDataSignalAccess( top.io_req_payload_fragment_query_63 );
      signalAccess[195] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_profile_key_bit_count );
      signalAccess[196] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_profile_key_fused_mat );
      signalAccess[197] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_profile_val_bit_count );
      signalAccess[198] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_profile_val_fused_mat );
      signalAccess[199] = new IDataSignalAccess( top.io_req_payload_fragment_metadata_key_base_addr );
      signalAccess[200] = new IDataSignalAccess( top.io_req_payload_fragment_metadata_key_requant_base_addr );
      signalAccess[201] = new IDataSignalAccess( top.io_req_payload_fragment_metadata_val_base_addr );
      signalAccess[202] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_key_fetch_num );
      signalAccess[203] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_val_fetch_num );
      signalAccess[204] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_topk_enable );
      signalAccess[205] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_topk_num );
      signalAccess[206] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_size_d );
      signalAccess[207] = new CDataSignalAccess( top.io_req_payload_fragment_metadata_allow_requantize );
      signalAccess[208] = new SDataSignalAccess( top.io_req_payload_fragment_metadata_thres_requantize );
      signalAccess[209] = new IDataSignalAccess( top.io_req_payload_fragment_metadata_universal_id );
      signalAccess[210] = new IDataSignalAccess( top.io_req_payload_fragment_metadata_topk_latency );
      signalAccess[211] = new CDataSignalAccess( top.io_resp_valid );
      signalAccess[212] = new CDataSignalAccess( top.io_resp_ready );
      signalAccess[213] = new SDataSignalAccess( top.io_resp_payload_results_0 );
      signalAccess[214] = new SDataSignalAccess( top.io_resp_payload_results_1 );
      signalAccess[215] = new SDataSignalAccess( top.io_resp_payload_results_2 );
      signalAccess[216] = new SDataSignalAccess( top.io_resp_payload_results_3 );
      signalAccess[217] = new SDataSignalAccess( top.io_resp_payload_results_4 );
      signalAccess[218] = new SDataSignalAccess( top.io_resp_payload_results_5 );
      signalAccess[219] = new SDataSignalAccess( top.io_resp_payload_results_6 );
      signalAccess[220] = new SDataSignalAccess( top.io_resp_payload_results_7 );
      signalAccess[221] = new SDataSignalAccess( top.io_resp_payload_results_8 );
      signalAccess[222] = new SDataSignalAccess( top.io_resp_payload_results_9 );
      signalAccess[223] = new SDataSignalAccess( top.io_resp_payload_results_10 );
      signalAccess[224] = new SDataSignalAccess( top.io_resp_payload_results_11 );
      signalAccess[225] = new SDataSignalAccess( top.io_resp_payload_results_12 );
      signalAccess[226] = new SDataSignalAccess( top.io_resp_payload_results_13 );
      signalAccess[227] = new SDataSignalAccess( top.io_resp_payload_results_14 );
      signalAccess[228] = new SDataSignalAccess( top.io_resp_payload_results_15 );
      signalAccess[229] = new SDataSignalAccess( top.io_resp_payload_results_16 );
      signalAccess[230] = new SDataSignalAccess( top.io_resp_payload_results_17 );
      signalAccess[231] = new SDataSignalAccess( top.io_resp_payload_results_18 );
      signalAccess[232] = new SDataSignalAccess( top.io_resp_payload_results_19 );
      signalAccess[233] = new SDataSignalAccess( top.io_resp_payload_results_20 );
      signalAccess[234] = new SDataSignalAccess( top.io_resp_payload_results_21 );
      signalAccess[235] = new SDataSignalAccess( top.io_resp_payload_results_22 );
      signalAccess[236] = new SDataSignalAccess( top.io_resp_payload_results_23 );
      signalAccess[237] = new SDataSignalAccess( top.io_resp_payload_results_24 );
      signalAccess[238] = new SDataSignalAccess( top.io_resp_payload_results_25 );
      signalAccess[239] = new SDataSignalAccess( top.io_resp_payload_results_26 );
      signalAccess[240] = new SDataSignalAccess( top.io_resp_payload_results_27 );
      signalAccess[241] = new SDataSignalAccess( top.io_resp_payload_results_28 );
      signalAccess[242] = new SDataSignalAccess( top.io_resp_payload_results_29 );
      signalAccess[243] = new SDataSignalAccess( top.io_resp_payload_results_30 );
      signalAccess[244] = new SDataSignalAccess( top.io_resp_payload_results_31 );
      signalAccess[245] = new SDataSignalAccess( top.io_resp_payload_results_32 );
      signalAccess[246] = new SDataSignalAccess( top.io_resp_payload_results_33 );
      signalAccess[247] = new SDataSignalAccess( top.io_resp_payload_results_34 );
      signalAccess[248] = new SDataSignalAccess( top.io_resp_payload_results_35 );
      signalAccess[249] = new SDataSignalAccess( top.io_resp_payload_results_36 );
      signalAccess[250] = new SDataSignalAccess( top.io_resp_payload_results_37 );
      signalAccess[251] = new SDataSignalAccess( top.io_resp_payload_results_38 );
      signalAccess[252] = new SDataSignalAccess( top.io_resp_payload_results_39 );
      signalAccess[253] = new SDataSignalAccess( top.io_resp_payload_results_40 );
      signalAccess[254] = new SDataSignalAccess( top.io_resp_payload_results_41 );
      signalAccess[255] = new SDataSignalAccess( top.io_resp_payload_results_42 );
      signalAccess[256] = new SDataSignalAccess( top.io_resp_payload_results_43 );
      signalAccess[257] = new SDataSignalAccess( top.io_resp_payload_results_44 );
      signalAccess[258] = new SDataSignalAccess( top.io_resp_payload_results_45 );
      signalAccess[259] = new SDataSignalAccess( top.io_resp_payload_results_46 );
      signalAccess[260] = new SDataSignalAccess( top.io_resp_payload_results_47 );
      signalAccess[261] = new SDataSignalAccess( top.io_resp_payload_results_48 );
      signalAccess[262] = new SDataSignalAccess( top.io_resp_payload_results_49 );
      signalAccess[263] = new SDataSignalAccess( top.io_resp_payload_results_50 );
      signalAccess[264] = new SDataSignalAccess( top.io_resp_payload_results_51 );
      signalAccess[265] = new SDataSignalAccess( top.io_resp_payload_results_52 );
      signalAccess[266] = new SDataSignalAccess( top.io_resp_payload_results_53 );
      signalAccess[267] = new SDataSignalAccess( top.io_resp_payload_results_54 );
      signalAccess[268] = new SDataSignalAccess( top.io_resp_payload_results_55 );
      signalAccess[269] = new SDataSignalAccess( top.io_resp_payload_results_56 );
      signalAccess[270] = new SDataSignalAccess( top.io_resp_payload_results_57 );
      signalAccess[271] = new SDataSignalAccess( top.io_resp_payload_results_58 );
      signalAccess[272] = new SDataSignalAccess( top.io_resp_payload_results_59 );
      signalAccess[273] = new SDataSignalAccess( top.io_resp_payload_results_60 );
      signalAccess[274] = new SDataSignalAccess( top.io_resp_payload_results_61 );
      signalAccess[275] = new SDataSignalAccess( top.io_resp_payload_results_62 );
      signalAccess[276] = new SDataSignalAccess( top.io_resp_payload_results_63 );
      signalAccess[277] = new CDataSignalAccess( top.io_resp_payload_metadata_profile_key_bit_count );
      signalAccess[278] = new CDataSignalAccess( top.io_resp_payload_metadata_profile_key_fused_mat );
      signalAccess[279] = new CDataSignalAccess( top.io_resp_payload_metadata_profile_val_bit_count );
      signalAccess[280] = new CDataSignalAccess( top.io_resp_payload_metadata_profile_val_fused_mat );
      signalAccess[281] = new IDataSignalAccess( top.io_resp_payload_metadata_key_base_addr );
      signalAccess[282] = new IDataSignalAccess( top.io_resp_payload_metadata_key_requant_base_addr );
      signalAccess[283] = new IDataSignalAccess( top.io_resp_payload_metadata_val_base_addr );
      signalAccess[284] = new CDataSignalAccess( top.io_resp_payload_metadata_key_fetch_num );
      signalAccess[285] = new CDataSignalAccess( top.io_resp_payload_metadata_val_fetch_num );
      signalAccess[286] = new CDataSignalAccess( top.io_resp_payload_metadata_topk_enable );
      signalAccess[287] = new CDataSignalAccess( top.io_resp_payload_metadata_topk_num );
      signalAccess[288] = new CDataSignalAccess( top.io_resp_payload_metadata_size_d );
      signalAccess[289] = new CDataSignalAccess( top.io_resp_payload_metadata_allow_requantize );
      signalAccess[290] = new SDataSignalAccess( top.io_resp_payload_metadata_thres_requantize );
      signalAccess[291] = new IDataSignalAccess( top.io_resp_payload_metadata_universal_id );
      signalAccess[292] = new IDataSignalAccess( top.io_resp_payload_metadata_topk_latency );
      signalAccess[293] = new CDataSignalAccess( top.clk );
      signalAccess[294] = new CDataSignalAccess( top.reset );

      #ifdef TRACE
      Verilated::traceEverOn(true);
      top.trace(&tfp, 99);
      tfp.open((std::string("/home/arun-venkat/summer_project/spatten/spatten.workdir/./simWorkspace/SpAttenSim/") + name + ".fst").c_str());
      #endif
      this->name = name;
      this->time_precision = Verilated::timeprecision();
    }

    virtual ~Wrapper_1(){
      for(int idx = 0;idx < 295;idx++){
          delete signalAccess[idx];
      }

      #ifdef TRACE
      if(waveEnabled) tfp.dump((vluint64_t)time);
      tfp.close();
      #endif
      #ifdef COVERAGE
      VerilatedCov::write((("/home/arun-venkat/summer_project/spatten/spatten.workdir/./simWorkspace/SpAttenSim/") + name + ".dat").c_str());
      #endif

      Verilated::runFlushCallbacks();
      Verilated::runExitCallbacks();
    }

};

double sc_time_stamp () {
  return simHandle1->time;
}


void vl_finish(const char* filename, int linenum, const char* hier) VL_MT_UNSAFE {
    if (false && hier) {}
    VL_PRINTF(  // Not VL_PRINTF_MT, already on main thread
        "- %s:%d: Verilog $finish\n", filename, linenum);
   /*if (Verilated::threadContextp()->gotFinish()) {
        VL_PRINTF(  // Not VL_PRINTF_MT, already on main thread
            "- %s:%d: Second verilog $finish, exiting\n", filename, linenum);
        Verilated::runFlushCallbacks();
        Verilated::runExitCallbacks();
        std::exit(0);
    }*/
    Verilated::threadContextp()->gotFinish(true);
}

#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <stdint.h>

#define API __attribute__((visibility("default")))


JNIEXPORT Wrapper_1 * API JNICALL Java_wrapper_1verilator_VerilatorNative_newHandle_11
  (JNIEnv * env, jobject obj, jstring name, jint seedValue){
    #if defined(_WIN32) && !defined(__CYGWIN__)
    srand(seedValue);
    #else
    srand48(seedValue);
    #endif
    Verilated::randReset(2);
    const char* ch = env->GetStringUTFChars(name, 0);
    Wrapper_1 *handle = new Wrapper_1(ch);
    env->ReleaseStringUTFChars(name, ch);
    return handle;
}

JNIEXPORT jboolean API JNICALL Java_wrapper_1verilator_VerilatorNative_eval_11
  (JNIEnv *, jobject, Wrapper_1 *handle){
   handle->top.eval();
   return Verilated::gotFinish();
}

JNIEXPORT jint API JNICALL Java_wrapper_1verilator_VerilatorNative_getTimePrecision_11
  (JNIEnv *, jobject, Wrapper_1 *handle){
  return handle->time_precision;
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_sleep_11
  (JNIEnv *, jobject, Wrapper_1 *handle, uint64_t cycles){
  #ifdef TRACE
  if(handle->waveEnabled) {
    handle->tfp.dump((vluint64_t)handle->time);
  }
  handle->timeCheck++;
  if(handle->timeCheck > 10000){
    handle->timeCheck = 0;
    high_resolution_clock::time_point timeNow = high_resolution_clock::now();
    duration<double, std::milli> time_span = timeNow - handle->lastFlushAt;
    if(time_span.count() > 1e3){
      handle->lastFlushAt = timeNow;
      handle->tfp.flush();
    }
  }
  #endif
  handle->time += cycles;
}

JNIEXPORT jlong API JNICALL Java_wrapper_1verilator_VerilatorNative_getU64_11
  (JNIEnv *, jobject, Wrapper_1 *handle, int id){
  return handle->signalAccess[id]->getU64();
}

JNIEXPORT jlong API JNICALL Java_wrapper_1verilator_VerilatorNative_getU64mem_11
  (JNIEnv *, jobject, Wrapper_1 *handle, int id, uint64_t index){
  return handle->signalAccess[id]->getU64_mem(index);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_setU64_11
  (JNIEnv *, jobject, Wrapper_1 *handle, int id, uint64_t value){
  handle->signalAccess[id]->setU64(value);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_setU64mem_11
  (JNIEnv *, jobject, Wrapper_1 *handle, int id, uint64_t value, uint64_t index){
  handle->signalAccess[id]->setU64_mem(value, index);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_deleteHandle_11
  (JNIEnv *, jobject, Wrapper_1 * handle){
  delete handle;
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_getAU8_11
  (JNIEnv * env, jobject obj, Wrapper_1 * handle, jint id, jbyteArray value){
  handle->signalAccess[id]->getAU8(env, value);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_getAU8mem_11
  (JNIEnv * env, jobject obj, Wrapper_1 * handle, jint id, jbyteArray value, uint64_t index){
  handle->signalAccess[id]->getAU8_mem(env, value, index);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_setAU8_11
  (JNIEnv * env, jobject obj, Wrapper_1 * handle, jint id, jbyteArray value, jint length){
  handle->signalAccess[id]->setAU8(env, value, length);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_setAU8mem_11
  (JNIEnv * env, jobject obj, Wrapper_1 * handle, jint id, jbyteArray value, jint length, uint64_t index){
  handle->signalAccess[id]->setAU8_mem(env, value, length, index);
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_enableWave_11
  (JNIEnv *, jobject, Wrapper_1 * handle){
  handle->waveEnabled = true;
}

JNIEXPORT void API JNICALL Java_wrapper_1verilator_VerilatorNative_disableWave_11
  (JNIEnv *, jobject, Wrapper_1 * handle){
  handle->waveEnabled = false;
}

#ifdef __cplusplus
}
#endif
     