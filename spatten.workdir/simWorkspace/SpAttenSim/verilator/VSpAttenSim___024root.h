// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VSpAttenSim.h for the primary calling header

#ifndef VERILATED_VSPATTENSIM___024ROOT_H_
#define VERILATED_VSPATTENSIM___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"
class VSpAttenSim_SpAttenSim;


class VSpAttenSim__Syms;

class alignas(VL_CACHE_LINE_BYTES) VSpAttenSim___024root final : public VerilatedModule {
  public:
    // CELLS
    VSpAttenSim_SpAttenSim* SpAttenSim;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(reset,0,0);
        VL_IN8(io_req_valid,0,0);
        VL_IN8(io_req_payload_fragment_metadata_profile_key_bit_count,3,0);
        VL_IN8(io_req_payload_fragment_metadata_profile_val_bit_count,3,0);
        VL_IN16(io_req_payload_fragment_query_5,11,0);
        VL_IN16(io_req_payload_fragment_query_6,11,0);
        VL_IN16(io_req_payload_fragment_query_7,11,0);
        VL_IN16(io_req_payload_fragment_query_24,11,0);
        VL_IN16(io_req_payload_fragment_query_2,11,0);
        VL_IN16(io_req_payload_fragment_query_10,11,0);
        VL_IN16(io_req_payload_fragment_query_25,11,0);
        VL_IN16(io_req_payload_fragment_query_59,11,0);
        VL_IN(io_req_payload_fragment_metadata_key_requant_base_addr,31,0);
        VL_IN(io_req_payload_fragment_metadata_val_base_addr,31,0);
        VL_OUT16(io_resp_payload_results_2,11,0);
        VL_OUT16(io_resp_payload_results_4,11,0);
        VL_OUT16(io_resp_payload_results_7,11,0);
        VL_OUT16(io_resp_payload_results_8,11,0);
        VL_OUT16(io_resp_payload_results_12,11,0);
        VL_OUT16(io_resp_payload_results_15,11,0);
        VL_OUT16(io_resp_payload_results_20,11,0);
        VL_OUT16(io_resp_payload_results_23,11,0);
        VL_OUT16(io_resp_payload_results_24,11,0);
        VL_OUT16(io_resp_payload_results_28,11,0);
        VL_OUT16(io_resp_payload_results_60,11,0);
        VL_OUT16(io_resp_payload_results_63,11,0);
        VL_OUT16(io_resp_payload_results_1,11,0);
        VL_OUT16(io_resp_payload_results_11,11,0);
        VL_OUT16(io_resp_payload_results_14,11,0);
        VL_OUT16(io_resp_payload_results_17,11,0);
        VL_OUT16(io_resp_payload_results_19,11,0);
        VL_OUT16(io_resp_payload_results_26,11,0);
        VL_OUT16(io_resp_payload_results_27,11,0);
        VL_OUT16(io_resp_payload_results_30,11,0);
        VL_OUT16(io_resp_payload_results_33,11,0);
        VL_OUT16(io_resp_payload_results_36,11,0);
        VL_OUT16(io_resp_payload_results_40,11,0);
        VL_OUT16(io_resp_payload_results_44,11,0);
        VL_OUT16(io_resp_payload_results_46,11,0);
        VL_OUT16(io_resp_payload_results_50,11,0);
        VL_OUT16(io_resp_payload_results_52,11,0);
        VL_OUT16(io_resp_payload_results_59,11,0);
        VL_OUT16(io_resp_payload_results_3,11,0);
        VL_OUT16(io_resp_payload_results_5,11,0);
        VL_OUT16(io_resp_payload_results_6,11,0);
        VL_OUT16(io_resp_payload_results_9,11,0);
        VL_OUT16(io_resp_payload_results_10,11,0);
        VL_OUT16(io_resp_payload_results_13,11,0);
        VL_OUT16(io_resp_payload_results_18,11,0);
        VL_OUT16(io_resp_payload_results_21,11,0);
        VL_OUT16(io_resp_payload_results_22,11,0);
        VL_OUT16(io_resp_payload_results_25,11,0);
        VL_OUT16(io_resp_payload_results_29,11,0);
        VL_OUT16(io_resp_payload_results_34,11,0);
        VL_OUT16(io_resp_payload_results_38,11,0);
        VL_OUT16(io_resp_payload_results_42,11,0);
        VL_OUT16(io_resp_payload_results_58,11,0);
        VL_OUT16(io_resp_payload_results_61,11,0);
        VL_OUT16(io_resp_payload_results_0,11,0);
        VL_OUT16(io_resp_payload_results_16,11,0);
        VL_OUT16(io_resp_payload_results_31,11,0);
        VL_OUT16(io_resp_payload_results_54,11,0);
        VL_OUT16(io_resp_payload_results_35,11,0);
        VL_OUT16(io_resp_payload_results_37,11,0);
    };
    struct {
        VL_OUT16(io_resp_payload_results_39,11,0);
        VL_OUT16(io_resp_payload_results_41,11,0);
        VL_OUT16(io_resp_payload_results_43,11,0);
        VL_OUT16(io_resp_payload_results_45,11,0);
        VL_OUT16(io_resp_payload_results_49,11,0);
        VL_OUT16(io_resp_payload_results_51,11,0);
        VL_OUT16(io_resp_payload_results_53,11,0);
        VL_OUT16(io_resp_payload_results_55,11,0);
        VL_OUT16(io_resp_payload_results_56,11,0);
        VL_OUT16(io_resp_payload_results_32,11,0);
        VL_OUT16(io_resp_payload_results_47,11,0);
        VL_OUT16(io_resp_payload_results_48,11,0);
        VL_OUT16(io_resp_payload_results_57,11,0);
        VL_OUT16(io_resp_payload_results_62,11,0);
        VL_OUT8(io_resp_valid,0,0);
        VL_OUT8(io_resp_payload_metadata_profile_key_bit_count,3,0);
        VL_OUT8(io_resp_payload_metadata_profile_key_fused_mat,1,0);
        VL_OUT8(io_resp_payload_metadata_profile_val_bit_count,3,0);
        VL_OUT8(io_resp_payload_metadata_profile_val_fused_mat,1,0);
        VL_OUT8(io_resp_payload_metadata_allow_requantize,0,0);
        VL_OUT16(io_resp_payload_metadata_thres_requantize,11,0);
        VL_OUT(io_resp_payload_metadata_key_base_addr,31,0);
        VL_OUT(io_resp_payload_metadata_universal_id,31,0);
        VL_IN8(io_req_payload_fragment_metadata_profile_val_fused_mat,1,0);
        VL_IN8(io_req_payload_fragment_metadata_val_fetch_num,7,0);
        VL_IN8(io_req_payload_fragment_metadata_topk_enable,0,0);
        VL_IN8(io_req_payload_fragment_metadata_topk_num,7,0);
        VL_IN16(io_req_payload_fragment_query_0,11,0);
        VL_IN16(io_req_payload_fragment_query_1,11,0);
        VL_IN16(io_req_payload_fragment_query_3,11,0);
        VL_IN16(io_req_payload_fragment_query_4,11,0);
        VL_IN16(io_req_payload_fragment_query_8,11,0);
        VL_IN16(io_req_payload_fragment_query_9,11,0);
        VL_IN16(io_req_payload_fragment_query_11,11,0);
        VL_IN16(io_req_payload_fragment_query_12,11,0);
        VL_IN16(io_req_payload_fragment_query_13,11,0);
        VL_IN16(io_req_payload_fragment_query_14,11,0);
        VL_IN16(io_req_payload_fragment_query_15,11,0);
        VL_IN16(io_req_payload_fragment_query_16,11,0);
        VL_IN16(io_req_payload_fragment_query_26,11,0);
        VL_IN16(io_req_payload_fragment_query_27,11,0);
        VL_IN16(io_req_payload_fragment_query_28,11,0);
        VL_IN16(io_req_payload_fragment_query_29,11,0);
        VL_IN16(io_req_payload_fragment_query_30,11,0);
        VL_IN16(io_req_payload_fragment_query_31,11,0);
        VL_IN16(io_req_payload_fragment_query_32,11,0);
        VL_IN16(io_req_payload_fragment_query_33,11,0);
        VL_IN16(io_req_payload_fragment_query_34,11,0);
        VL_IN16(io_req_payload_fragment_query_35,11,0);
        VL_IN16(io_req_payload_fragment_query_36,11,0);
        VL_IN16(io_req_payload_fragment_query_37,11,0);
        VL_IN16(io_req_payload_fragment_query_38,11,0);
        VL_IN16(io_req_payload_fragment_query_39,11,0);
        VL_IN16(io_req_payload_fragment_query_40,11,0);
        VL_IN16(io_req_payload_fragment_query_41,11,0);
        VL_IN16(io_req_payload_fragment_query_55,11,0);
        VL_IN16(io_req_payload_fragment_query_56,11,0);
        VL_IN16(io_req_payload_fragment_query_57,11,0);
        VL_IN16(io_req_payload_fragment_query_58,11,0);
        VL_IN16(io_req_payload_fragment_query_60,11,0);
        VL_IN16(io_req_payload_fragment_query_61,11,0);
        VL_IN16(io_req_payload_fragment_query_62,11,0);
        VL_IN16(io_req_payload_fragment_query_63,11,0);
        VL_IN(io_req_payload_fragment_metadata_key_base_addr,31,0);
    };
    struct {
        VL_IN8(io_req_payload_fragment_metadata_key_fetch_num,7,0);
        VL_IN8(io_req_payload_fragment_metadata_profile_key_fused_mat,1,0);
        VL_IN16(io_req_payload_fragment_query_23,11,0);
        VL_IN16(io_req_payload_fragment_query_42,11,0);
        VL_IN16(io_req_payload_fragment_query_43,11,0);
        VL_IN16(io_req_payload_fragment_query_44,11,0);
        VL_IN16(io_req_payload_fragment_query_45,11,0);
        VL_IN16(io_req_payload_fragment_query_54,11,0);
        VL_IN8(io_req_payload_fragment_metadata_allow_requantize,0,0);
        VL_IN16(io_req_payload_fragment_query_17,11,0);
        VL_IN16(io_req_payload_fragment_query_18,11,0);
        VL_IN16(io_req_payload_fragment_query_19,11,0);
        VL_IN16(io_req_payload_fragment_query_20,11,0);
        VL_IN16(io_req_payload_fragment_query_21,11,0);
        VL_IN16(io_req_payload_fragment_query_22,11,0);
        VL_IN16(io_req_payload_fragment_query_46,11,0);
        VL_IN16(io_req_payload_fragment_query_47,11,0);
        VL_IN16(io_req_payload_fragment_query_48,11,0);
        VL_IN16(io_req_payload_fragment_query_49,11,0);
        VL_IN16(io_req_payload_fragment_query_50,11,0);
        VL_IN16(io_req_payload_fragment_query_51,11,0);
        VL_IN16(io_req_payload_fragment_query_52,11,0);
        VL_IN16(io_req_payload_fragment_query_53,11,0);
        VL_IN16(io_req_payload_fragment_metadata_thres_requantize,11,0);
        VL_IN(io_req_payload_fragment_metadata_universal_id,31,0);
        VL_IN(io_req_payload_fragment_metadata_topk_latency,31,0);
        VL_IN8(io_req_payload_fragment_metadata_size_d,6,0);
        VL_IN8(io_req_payload_last,0,0);
        VL_OUT8(io_req_ready,0,0);
        VL_OUT8(io_resp_payload_metadata_key_fetch_num,7,0);
        VL_OUT8(io_resp_payload_metadata_val_fetch_num,7,0);
        VL_OUT8(io_resp_payload_metadata_topk_enable,0,0);
        VL_OUT8(io_resp_payload_metadata_topk_num,7,0);
        VL_OUT8(io_resp_payload_metadata_size_d,6,0);
        VL_OUT(io_resp_payload_metadata_key_requant_base_addr,31,0);
        VL_OUT(io_resp_payload_metadata_val_base_addr,31,0);
        VL_OUT(io_resp_payload_metadata_topk_latency,31,0);
        VL_IN8(io_resp_ready,0,0);
        VL_IN8(clk,0,0);
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __VactDidInit;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<CData/*0:0*/, 71> __Vm_traceActivity;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;
    VlMTaskVertex __Vm_mtaskstate_24;
    VlMTaskVertex __Vm_mtaskstate_67;
    VlMTaskVertex __Vm_mtaskstate_46;
    VlMTaskVertex __Vm_mtaskstate_40;
    VlMTaskVertex __Vm_mtaskstate_63;
    VlMTaskVertex __Vm_mtaskstate_73;
    VlMTaskVertex __Vm_mtaskstate_59;
    VlMTaskVertex __Vm_mtaskstate_23;
    VlMTaskVertex __Vm_mtaskstate_35;
    VlMTaskVertex __Vm_mtaskstate_7;
    VlMTaskVertex __Vm_mtaskstate_4;
    VlMTaskVertex __Vm_mtaskstate_43;
    VlMTaskVertex __Vm_mtaskstate_61;
    VlMTaskVertex __Vm_mtaskstate_65;
    VlMTaskVertex __Vm_mtaskstate_37;
    VlMTaskVertex __Vm_mtaskstate_42;
    VlMTaskVertex __Vm_mtaskstate_72;
    VlMTaskVertex __Vm_mtaskstate_68;
    VlMTaskVertex __Vm_mtaskstate_57;
    VlMTaskVertex __Vm_mtaskstate_29;
    VlMTaskVertex __Vm_mtaskstate_71;
    VlMTaskVertex __Vm_mtaskstate_41;
    VlMTaskVertex __Vm_mtaskstate_36;
    VlMTaskVertex __Vm_mtaskstate_53;
    VlMTaskVertex __Vm_mtaskstate_38;
    VlMTaskVertex __Vm_mtaskstate_19;
    VlMTaskVertex __Vm_mtaskstate_22;
    VlMTaskVertex __Vm_mtaskstate_3;
    VlMTaskVertex __Vm_mtaskstate_28;
    VlMTaskVertex __Vm_mtaskstate_39;
    VlMTaskVertex __Vm_mtaskstate_21;
    VlMTaskVertex __Vm_mtaskstate_44;
    VlMTaskVertex __Vm_mtaskstate_60;
    VlMTaskVertex __Vm_mtaskstate_69;
    VlMTaskVertex __Vm_mtaskstate_62;
    VlMTaskVertex __Vm_mtaskstate_18;
    VlMTaskVertex __Vm_mtaskstate_20;
    VlMTaskVertex __Vm_mtaskstate_64;
    VlMTaskVertex __Vm_mtaskstate_70;
    VlMTaskVertex __Vm_mtaskstate_54;
    VlMTaskVertex __Vm_mtaskstate_45;
    VlMTaskVertex __Vm_mtaskstate_final__nba;

    // INTERNAL VARIABLES
    VSpAttenSim__Syms* const vlSymsp;

    // CONSTRUCTORS
    VSpAttenSim___024root(VSpAttenSim__Syms* symsp, const char* v__name);
    ~VSpAttenSim___024root();
    VL_UNCOPYABLE(VSpAttenSim___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
