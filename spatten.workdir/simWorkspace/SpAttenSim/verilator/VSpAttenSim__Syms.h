// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSPATTENSIM__SYMS_H_
#define VERILATED_VSPATTENSIM__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VSpAttenSim.h"

// INCLUDE MODULE CLASSES
#include "VSpAttenSim___024root.h"
#include "VSpAttenSim_SpAttenSim.h"
#include "VSpAttenSim_SpAtten.h"
#include "VSpAttenSim_SpAttenController.h"
#include "VSpAttenSim_Buffer_2.h"
#include "VSpAttenSim_Buffer_1.h"
#include "VSpAttenSim_MatrixFetcher.h"
#include "VSpAttenSim_MultiBankRAM_24.h"
#include "VSpAttenSim_MultiBankRAM_23.h"
#include "VSpAttenSim_MultiBankRAM_22.h"
#include "VSpAttenSim_MultiBankRAM_21.h"
#include "VSpAttenSim_MultiBankRAM_20.h"
#include "VSpAttenSim_MultiBankRAM_19.h"
#include "VSpAttenSim_MultiBankRAM_18.h"
#include "VSpAttenSim_MultiBankRAM_17.h"
#include "VSpAttenSim_MultiBankRAM_16.h"
#include "VSpAttenSim_MultiBankRAM_15.h"
#include "VSpAttenSim_MultiBankRAM_14.h"
#include "VSpAttenSim_MultiBankRAM_13.h"
#include "VSpAttenSim_StageLoadData.h"
#include "VSpAttenSim_StreamRAM_28.h"
#include "VSpAttenSim_StreamRAM_30.h"
#include "VSpAttenSim_StreamRAM_32.h"
#include "VSpAttenSim_StreamRAM_34.h"
#include "VSpAttenSim_StreamRAM_36.h"
#include "VSpAttenSim_StreamRAM_38.h"
#include "VSpAttenSim_StreamRAM_40.h"
#include "VSpAttenSim_StreamRAM_42.h"
#include "VSpAttenSim_StreamRAM_44.h"
#include "VSpAttenSim_StreamRAM_46.h"
#include "VSpAttenSim_StreamRAM_48.h"
#include "VSpAttenSim_StreamRAM_50.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)VSpAttenSim__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VSpAttenSim* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MULTI-THREADING
    VlThreadPool* __Vm_threadPoolp;
    bool __Vm_even_cycle__ico = false;
    bool __Vm_even_cycle__act = false;
    bool __Vm_even_cycle__nba = false;

    // MODULE INSTANCE STATE
    VSpAttenSim___024root          TOP;
    VSpAttenSim_SpAttenSim         TOP__SpAttenSim;
    VSpAttenSim_SpAtten            TOP__SpAttenSim__spatten_inst;
    VSpAttenSim_SpAttenController  TOP__SpAttenSim__spatten_inst__controller_inst;
    VSpAttenSim_Buffer_1           TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key;
    VSpAttenSim_MultiBankRAM_13    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_0;
    VSpAttenSim_StreamRAM_50       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_0__ram_insts_0;
    VSpAttenSim_StreamRAM_50       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_0__ram_insts_1;
    VSpAttenSim_MultiBankRAM_14    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_1;
    VSpAttenSim_StreamRAM_48       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_1__ram_insts_0;
    VSpAttenSim_StreamRAM_48       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_1__ram_insts_1;
    VSpAttenSim_MultiBankRAM_23    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_10;
    VSpAttenSim_StreamRAM_30       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_10__ram_insts_0;
    VSpAttenSim_StreamRAM_30       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_10__ram_insts_1;
    VSpAttenSim_MultiBankRAM_24    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_11;
    VSpAttenSim_StreamRAM_28       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_11__ram_insts_0;
    VSpAttenSim_StreamRAM_28       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_11__ram_insts_1;
    VSpAttenSim_MultiBankRAM_15    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_2;
    VSpAttenSim_StreamRAM_46       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_2__ram_insts_0;
    VSpAttenSim_StreamRAM_46       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_2__ram_insts_1;
    VSpAttenSim_MultiBankRAM_16    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_3;
    VSpAttenSim_StreamRAM_44       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_3__ram_insts_0;
    VSpAttenSim_StreamRAM_44       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_3__ram_insts_1;
    VSpAttenSim_MultiBankRAM_17    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_4;
    VSpAttenSim_StreamRAM_42       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_4__ram_insts_0;
    VSpAttenSim_StreamRAM_42       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_4__ram_insts_1;
    VSpAttenSim_MultiBankRAM_18    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_5;
    VSpAttenSim_StreamRAM_40       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_5__ram_insts_0;
    VSpAttenSim_StreamRAM_40       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_5__ram_insts_1;
    VSpAttenSim_MultiBankRAM_19    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_6;
    VSpAttenSim_StreamRAM_38       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_6__ram_insts_0;
    VSpAttenSim_StreamRAM_38       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_6__ram_insts_1;
    VSpAttenSim_MultiBankRAM_20    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_7;
    VSpAttenSim_StreamRAM_36       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_7__ram_insts_0;
    VSpAttenSim_StreamRAM_36       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_7__ram_insts_1;
    VSpAttenSim_MultiBankRAM_21    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_8;
    VSpAttenSim_StreamRAM_34       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_8__ram_insts_0;
    VSpAttenSim_StreamRAM_34       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_8__ram_insts_1;
    VSpAttenSim_MultiBankRAM_22    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_9;
    VSpAttenSim_StreamRAM_32       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_9__ram_insts_0;
    VSpAttenSim_StreamRAM_32       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_9__ram_insts_1;
    VSpAttenSim_Buffer_2           TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val;
    VSpAttenSim_MultiBankRAM_13    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_0;
    VSpAttenSim_StreamRAM_50       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_0__ram_insts_0;
    VSpAttenSim_StreamRAM_50       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_0__ram_insts_1;
    VSpAttenSim_MultiBankRAM_14    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_1;
    VSpAttenSim_StreamRAM_48       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_1__ram_insts_0;
    VSpAttenSim_StreamRAM_48       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_1__ram_insts_1;
    VSpAttenSim_MultiBankRAM_23    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_10;
    VSpAttenSim_StreamRAM_30       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_10__ram_insts_0;
    VSpAttenSim_StreamRAM_30       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_10__ram_insts_1;
    VSpAttenSim_MultiBankRAM_24    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_11;
    VSpAttenSim_StreamRAM_28       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_11__ram_insts_0;
    VSpAttenSim_StreamRAM_28       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_11__ram_insts_1;
    VSpAttenSim_MultiBankRAM_15    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_2;
    VSpAttenSim_StreamRAM_46       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_2__ram_insts_0;
    VSpAttenSim_StreamRAM_46       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_2__ram_insts_1;
    VSpAttenSim_MultiBankRAM_16    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_3;
    VSpAttenSim_StreamRAM_44       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_3__ram_insts_0;
    VSpAttenSim_StreamRAM_44       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_3__ram_insts_1;
    VSpAttenSim_MultiBankRAM_17    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_4;
    VSpAttenSim_StreamRAM_42       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_4__ram_insts_0;
    VSpAttenSim_StreamRAM_42       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_4__ram_insts_1;
    VSpAttenSim_MultiBankRAM_18    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_5;
    VSpAttenSim_StreamRAM_40       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_5__ram_insts_0;
    VSpAttenSim_StreamRAM_40       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_5__ram_insts_1;
    VSpAttenSim_MultiBankRAM_19    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_6;
    VSpAttenSim_StreamRAM_38       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_6__ram_insts_0;
    VSpAttenSim_StreamRAM_38       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_6__ram_insts_1;
    VSpAttenSim_MultiBankRAM_20    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_7;
    VSpAttenSim_StreamRAM_36       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_7__ram_insts_0;
    VSpAttenSim_StreamRAM_36       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_7__ram_insts_1;
    VSpAttenSim_MultiBankRAM_21    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_8;
    VSpAttenSim_StreamRAM_34       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_8__ram_insts_0;
    VSpAttenSim_StreamRAM_34       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_8__ram_insts_1;
    VSpAttenSim_MultiBankRAM_22    TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_9;
    VSpAttenSim_StreamRAM_32       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_9__ram_insts_0;
    VSpAttenSim_StreamRAM_32       TOP__SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_9__ram_insts_1;
    VSpAttenSim_MatrixFetcher      TOP__SpAttenSim__spatten_inst__controller_inst__mat_fetcher_inst;
    VSpAttenSim_StageLoadData      TOP__SpAttenSim__spatten_inst__controller_inst__mat_fetcher_inst__stageLoadData_1;

    // SCOPE NAMES
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_0__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_0__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_10__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_10__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_11__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_11__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_1__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_1__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_2__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_2__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_3__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_3__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_4__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_4__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_5__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_5__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_6__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_6__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_7__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_7__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_8__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_8__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_9__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_key__data_ram_insts_9__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_0__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_0__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_10__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_10__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_11__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_11__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_1__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_1__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_2__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_2__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_3__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_3__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_4__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_4__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_5__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_5__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_6__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_6__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_7__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_7__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_8__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_8__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_9__ram_insts_0;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__buffer_val__data_ram_insts_9__ram_insts_1;
    VerilatedScope __Vscope_SpAttenSim__spatten_inst__controller_inst__mat_fetcher_inst__stageLoadData_1;

    // CONSTRUCTORS
    VSpAttenSim__Syms(VerilatedContext* contextp, const char* namep, VSpAttenSim* modelp);
    ~VSpAttenSim__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
