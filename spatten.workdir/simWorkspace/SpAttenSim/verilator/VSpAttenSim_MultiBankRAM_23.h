// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSpAttenSim.h for the primary calling header

#ifndef VERILATED_VSPATTENSIM_MULTIBANKRAM_23_H_
#define VERILATED_VSPATTENSIM_MULTIBANKRAM_23_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"
class VSpAttenSim_StreamRAM_30;


class VSpAttenSim__Syms;

class alignas(VL_CACHE_LINE_BYTES) VSpAttenSim_MultiBankRAM_23 final : public VerilatedModule {
  public:
    // CELLS
    VSpAttenSim_StreamRAM_30* ram_insts_0;
    VSpAttenSim_StreamRAM_30* ram_insts_1;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ __PVT__streamArbiter_159_io_chosen;
        CData/*0:0*/ __PVT__streamArbiter_159__DOT__maskRouted_0;
        CData/*0:0*/ __PVT__streamDemux_161_io_outputs_1_valid;
        CData/*0:0*/ __PVT__streamDemux_162_io_outputs_1_valid;
        CData/*0:0*/ __PVT__streamArbiter_159_io_output_valid;
        CData/*0:0*/ __PVT__data_ram_insts_10_streamArbiter_158_io_output_combStage_ready;
        CData/*0:0*/ __PVT__data_ram_insts_10_streamArbiter_159_io_output_combStage_ready;
        CData/*0:0*/ __PVT__streamArbiter_158_io_chosen;
        CData/*0:0*/ __PVT__streamArbiter_158__DOT__maskRouted_0;
        CData/*0:0*/ __PVT__streamArbiter_158_io_output_valid;
        CData/*0:0*/ __PVT__streamDemux_161_io_outputs_0_valid;
        CData/*0:0*/ __PVT__streamDemux_162_io_outputs_0_valid;
        CData/*0:0*/ __PVT___zz_io_write_req_payload_context_src_port;
        CData/*0:0*/ __PVT___zz_io_write_req_payload_context_src_port_1;
        CData/*0:0*/ __PVT__streamArbiter_158__DOT__locked;
        CData/*0:0*/ __PVT__streamArbiter_158__DOT__maskLocked_0;
        CData/*0:0*/ __PVT__streamArbiter_158__DOT__maskLocked_1;
        CData/*1:0*/ __PVT__streamArbiter_158__DOT___zz_maskProposal_1;
        CData/*0:0*/ __PVT__streamArbiter_159__DOT__locked;
        CData/*0:0*/ __PVT__streamArbiter_159__DOT__maskLocked_0;
        CData/*0:0*/ __PVT__streamArbiter_159__DOT__maskLocked_1;
        CData/*1:0*/ __PVT__streamArbiter_159__DOT___zz_maskProposal_1;
        CData/*0:0*/ __PVT__areaWrite_0_arbiter__DOT__locked;
        CData/*0:0*/ __PVT__areaWrite_0_arbiter__DOT__maskLocked_0;
        CData/*0:0*/ __PVT__areaWrite_0_arbiter__DOT__maskLocked_1;
        CData/*0:0*/ __PVT__areaWrite_1_arbiter__DOT__locked;
        CData/*0:0*/ __PVT__areaWrite_1_arbiter__DOT__maskLocked_0;
        CData/*0:0*/ __PVT__areaWrite_1_arbiter__DOT__maskLocked_1;
        CData/*1:0*/ __PVT__areaWrite_0_arbiter__DOT___zz_maskProposal_0;
        CData/*3:0*/ __PVT__areaWrite_0_arbiter__DOT___zz_maskProposal_0_2;
        CData/*1:0*/ __PVT__areaWrite_0_arbiter__DOT___zz_maskProposal_0_3;
        CData/*1:0*/ __PVT__areaWrite_1_arbiter__DOT___zz_maskProposal_0;
        CData/*3:0*/ __PVT__areaWrite_1_arbiter__DOT___zz_maskProposal_0_2;
        CData/*1:0*/ __PVT__areaWrite_1_arbiter__DOT___zz_maskProposal_0_3;
        CData/*0:0*/ __PVT__areaWrite_0_arbiter_io_chosen;
        CData/*0:0*/ __PVT__areaWrite_1_arbiter_io_chosen;
        CData/*0:0*/ __PVT__streamDemux_158_io_outputs_0_valid;
        CData/*0:0*/ __PVT__streamDemux_158_io_outputs_1_valid;
        CData/*0:0*/ __PVT__streamDemux_159_io_outputs_0_valid;
        CData/*0:0*/ __PVT__streamDemux_159_io_outputs_1_valid;
        CData/*0:0*/ __PVT__areaWrite_0_arbiter__DOT__maskRouted_0;
        CData/*0:0*/ __PVT__areaWrite_1_arbiter__DOT__maskRouted_0;
        CData/*0:0*/ __PVT___zz_io_output_ready;
        CData/*0:0*/ __PVT___zz_io_output_ready_1;
        CData/*0:0*/ __PVT__areaWrite_0_arbiter_io_output_valid;
        CData/*0:0*/ __PVT__areaWrite_1_arbiter_io_output_valid;
        CData/*0:0*/ __PVT__streamDemux_158_io_input_ready;
        CData/*0:0*/ __PVT__streamDemux_159_io_input_ready;
        CData/*0:0*/ __PVT__streamDemux_161_io_input_ready;
        CData/*0:0*/ __PVT__streamDemux_162_io_input_ready;
        CData/*0:0*/ __PVT___zz_io_write_req_payload_mask;
        CData/*0:0*/ __PVT___zz_io_write_req_payload_mask_1;
        CData/*0:0*/ __PVT__streamArbiter_160__DOT__maskLocked_1;
        CData/*1:0*/ __PVT__streamArbiter_160__DOT___zz_maskProposal_1;
        CData/*0:0*/ __PVT__streamArbiter_160_io_chosen;
        CData/*0:0*/ __PVT__streamArbiter_160__DOT__maskRouted_0;
        CData/*0:0*/ __PVT__data_ram_insts_10_streamArbiter_160_io_output_combStage_ready;
        CData/*0:0*/ __PVT__data_ram_insts_10_streamArbiter_160_io_output_combStage_rValid;
        CData/*0:0*/ __PVT___zz_when_Stream_l369_1;
        CData/*0:0*/ __PVT___zz_when_Stream_l369_3;
        CData/*0:0*/ __PVT__data_ram_insts_10_streamArbiter_158_io_output_combStage_rValid;
        CData/*0:0*/ __PVT__data_ram_insts_10_streamArbiter_159_io_output_combStage_rValid;
        VlWide<4>/*127:0*/ __PVT___zz_io_write_req_payload_data;
        VlWide<4>/*127:0*/ __PVT___zz_io_write_req_payload_data_1;
    };
    struct {
        CData/*4:0*/ __PVT___zz_io_write_req_payload_addr;
        CData/*4:0*/ __PVT___zz_io_write_req_payload_addr_1;
        CData/*0:0*/ __PVT__streamDemux_160_io_outputs_0_valid;
        CData/*0:0*/ __PVT__streamDemux_160_io_outputs_1_valid;
        CData/*0:0*/ __PVT__streamDemux_160_io_input_ready;
        CData/*0:0*/ __PVT__streamArbiter_160_io_output_valid;
        CData/*0:0*/ __PVT__streamArbiter_160__DOT__locked;
        CData/*0:0*/ __PVT__streamArbiter_160__DOT__maskLocked_0;
        VlWide<4>/*127:0*/ __PVT__data_ram_insts_10_streamArbiter_160_io_output_combStage_rData_data;
        VL_IN8(__PVT__clk,0,0);
        VL_IN8(__PVT__io_write_req_0_valid,0,0);
        VL_OUT8(__PVT__io_write_req_0_ready,0,0);
        VL_IN8(__PVT__io_write_req_0_payload_addr,5,0);
        VL_IN8(__PVT__io_write_req_0_payload_mask,0,0);
        VL_IN8(__PVT__io_write_req_1_valid,0,0);
        VL_OUT8(__PVT__io_write_req_1_ready,0,0);
        VL_IN8(__PVT__io_write_req_1_payload_addr,5,0);
        VL_IN8(__PVT__io_write_req_1_payload_mask,0,0);
        VL_OUT8(__PVT__io_write_resp_0_valid,0,0);
        VL_IN8(__PVT__io_write_resp_0_ready,0,0);
        VL_OUT8(__PVT__io_write_resp_1_valid,0,0);
        VL_IN8(__PVT__io_write_resp_1_ready,0,0);
        VL_IN8(__PVT__io_read_req_0_valid,0,0);
        VL_OUT8(__PVT__io_read_req_0_ready,0,0);
        VL_IN8(__PVT__io_read_req_0_payload_addr,5,0);
        VL_OUT8(__PVT__io_read_resp_0_valid,0,0);
        VL_IN8(__PVT__io_read_resp_0_ready,0,0);
        VL_IN8(__PVT__reset,0,0);
        VL_INW(__PVT__io_write_req_0_payload_data,127,0,4);
        VL_INW(__PVT__io_write_req_1_payload_data,127,0,4);
        VL_OUTW(__PVT__io_read_resp_0_payload_data,127,0,4);
    };

    // INTERNAL VARIABLES
    VSpAttenSim__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSpAttenSim_MultiBankRAM_23(VSpAttenSim__Syms* symsp, const char* v__name);
    ~VSpAttenSim_MultiBankRAM_23();
    VL_UNCOPYABLE(VSpAttenSim_MultiBankRAM_23);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
