// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSpAttenSim.h for the primary calling header

#ifndef VERILATED_VSPATTENSIM_STREAMRAM_38_H_
#define VERILATED_VSPATTENSIM_STREAMRAM_38_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"


class VSpAttenSim__Syms;

class alignas(VL_CACHE_LINE_BYTES) VSpAttenSim_StreamRAM_38 final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __PVT__areaWrite_input_ready;
    CData/*0:0*/ __PVT__areaWrite_input_rValid;
    CData/*0:0*/ __PVT__areaWrite_input_rData_context_src_port;
    CData/*0:0*/ __PVT__areaWrite_input_valid;
    VL_OUT8(__PVT__io_write_req_ready,0,0);
    CData/*0:0*/ __PVT__areaCounter_count_read_willIncrement;
    CData/*0:0*/ __PVT__areaWrite_write_enable;
    CData/*4:0*/ __PVT__areaInit_init_addr;
    CData/*0:0*/ __PVT__when_MultiBankRAM_l70;
    CData/*4:0*/ __PVT__areaWrite_input_payload_addr;
    CData/*4:0*/ __PVT__areaWrite_input_rData_addr;
    CData/*4:0*/ __Vdly__areaInit_init_addr;
    VlWide<4>/*127:0*/ __PVT__areaWrite_input_payload_data;
    VlWide<4>/*127:0*/ __PVT__areaWrite_input_rData_data;
    CData/*4:0*/ __Vdlyvdim0__ram__v0;
    CData/*0:0*/ __Vdlyvset__ram__v0;
    VlWide<4>/*127:0*/ __Vdlyvval__ram__v0;
    CData/*0:0*/ __PVT__areaInit_inited;
    IData/*31:0*/ __PVT__areaCounter_count_read_valueNext;
    IData/*31:0*/ areaCounter_count_read_value;
    IData/*31:0*/ __PVT__areaCounter_count_write_valueNext;
    IData/*31:0*/ areaCounter_count_write_value;
    CData/*0:0*/ __PVT__areaCounter_count_write_willIncrement;
    VL_OUT8(__PVT__io_read_req_ready,0,0);
    CData/*0:0*/ __PVT__areaRead_input_rValid;
    CData/*4:0*/ __PVT__areaRead_input_rData_addr;
    CData/*0:0*/ __PVT__areaWrite_input_rData_mask;
    CData/*0:0*/ __PVT___zz_io_read_resp_valid_1;
    CData/*0:0*/ __PVT__areaRead_input_ready;
    CData/*0:0*/ __PVT___zz_areaRead_input_m2sPipe_ready;
    CData/*0:0*/ __PVT__areaRead_input_valid;
    VlWide<4>/*127:0*/ __PVT___zz_io_read_resp_payload_data;
    VlUnpacked<VlWide<4>/*127:0*/, 32> __PVT__ram;
    VlWide<4>/*127:0*/ __PVT___zz_ram_port1;
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__io_write_req_valid,0,0);
    VL_IN8(__PVT__io_write_req_payload_addr,4,0);
    VL_IN8(__PVT__io_write_req_payload_mask,0,0);
    VL_IN8(__PVT__io_write_req_payload_context_src_port,0,0);
    VL_OUT8(__PVT__io_write_resp_valid,0,0);
    VL_IN8(__PVT__io_write_resp_ready,0,0);
    VL_OUT8(__PVT__io_write_resp_payload_context_src_port,0,0);
    VL_IN8(__PVT__io_read_req_valid,0,0);
    VL_IN8(__PVT__io_read_req_payload_addr,4,0);
    VL_OUT8(__PVT__io_read_resp_valid,0,0);
    VL_IN8(__PVT__io_read_resp_ready,0,0);
    VL_IN8(__PVT__reset,0,0);
    VL_INW(__PVT__io_write_req_payload_data,127,0,4);
    VL_OUTW(__PVT__io_read_resp_payload_data,127,0,4);

    // INTERNAL VARIABLES
    VSpAttenSim__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSpAttenSim_StreamRAM_38(VSpAttenSim__Syms* symsp, const char* v__name);
    ~VSpAttenSim_StreamRAM_38();
    VL_UNCOPYABLE(VSpAttenSim_StreamRAM_38);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
