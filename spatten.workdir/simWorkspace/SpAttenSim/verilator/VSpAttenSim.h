// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary model header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef VERILATED_VSPATTENSIM_H_
#define VERILATED_VSPATTENSIM_H_  // guard

#include "verilated.h"
#include "verilated_threads.h"
#include "svdpi.h"

class VSpAttenSim__Syms;
class VSpAttenSim___024root;
class VerilatedFstC;
class VSpAttenSim_SpAttenSim;


// This class is the main interface to the Verilated model
class alignas(VL_CACHE_LINE_BYTES) VSpAttenSim VL_NOT_FINAL : public VerilatedModel {
  private:
    // Symbol table holding complete model state (owned by this class)
    VSpAttenSim__Syms* const vlSymsp;

  public:

    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(&reset,0,0);
    VL_IN8(&io_req_valid,0,0);
    VL_IN8(&io_req_payload_fragment_metadata_profile_key_bit_count,3,0);
    VL_IN8(&io_req_payload_fragment_metadata_profile_val_bit_count,3,0);
    VL_IN16(&io_req_payload_fragment_query_5,11,0);
    VL_IN16(&io_req_payload_fragment_query_6,11,0);
    VL_IN16(&io_req_payload_fragment_query_7,11,0);
    VL_IN16(&io_req_payload_fragment_query_24,11,0);
    VL_IN16(&io_req_payload_fragment_query_2,11,0);
    VL_IN16(&io_req_payload_fragment_query_10,11,0);
    VL_IN16(&io_req_payload_fragment_query_25,11,0);
    VL_IN16(&io_req_payload_fragment_query_59,11,0);
    VL_IN(&io_req_payload_fragment_metadata_key_requant_base_addr,31,0);
    VL_IN(&io_req_payload_fragment_metadata_val_base_addr,31,0);
    VL_OUT16(&io_resp_payload_results_2,11,0);
    VL_OUT16(&io_resp_payload_results_4,11,0);
    VL_OUT16(&io_resp_payload_results_7,11,0);
    VL_OUT16(&io_resp_payload_results_8,11,0);
    VL_OUT16(&io_resp_payload_results_12,11,0);
    VL_OUT16(&io_resp_payload_results_15,11,0);
    VL_OUT16(&io_resp_payload_results_20,11,0);
    VL_OUT16(&io_resp_payload_results_23,11,0);
    VL_OUT16(&io_resp_payload_results_24,11,0);
    VL_OUT16(&io_resp_payload_results_28,11,0);
    VL_OUT16(&io_resp_payload_results_60,11,0);
    VL_OUT16(&io_resp_payload_results_63,11,0);
    VL_OUT16(&io_resp_payload_results_1,11,0);
    VL_OUT16(&io_resp_payload_results_11,11,0);
    VL_OUT16(&io_resp_payload_results_14,11,0);
    VL_OUT16(&io_resp_payload_results_17,11,0);
    VL_OUT16(&io_resp_payload_results_19,11,0);
    VL_OUT16(&io_resp_payload_results_26,11,0);
    VL_OUT16(&io_resp_payload_results_27,11,0);
    VL_OUT16(&io_resp_payload_results_30,11,0);
    VL_OUT16(&io_resp_payload_results_33,11,0);
    VL_OUT16(&io_resp_payload_results_36,11,0);
    VL_OUT16(&io_resp_payload_results_40,11,0);
    VL_OUT16(&io_resp_payload_results_44,11,0);
    VL_OUT16(&io_resp_payload_results_46,11,0);
    VL_OUT16(&io_resp_payload_results_50,11,0);
    VL_OUT16(&io_resp_payload_results_52,11,0);
    VL_OUT16(&io_resp_payload_results_59,11,0);
    VL_OUT16(&io_resp_payload_results_3,11,0);
    VL_OUT16(&io_resp_payload_results_5,11,0);
    VL_OUT16(&io_resp_payload_results_6,11,0);
    VL_OUT16(&io_resp_payload_results_9,11,0);
    VL_OUT16(&io_resp_payload_results_10,11,0);
    VL_OUT16(&io_resp_payload_results_13,11,0);
    VL_OUT16(&io_resp_payload_results_18,11,0);
    VL_OUT16(&io_resp_payload_results_21,11,0);
    VL_OUT16(&io_resp_payload_results_22,11,0);
    VL_OUT16(&io_resp_payload_results_25,11,0);
    VL_OUT16(&io_resp_payload_results_29,11,0);
    VL_OUT16(&io_resp_payload_results_34,11,0);
    VL_OUT16(&io_resp_payload_results_38,11,0);
    VL_OUT16(&io_resp_payload_results_42,11,0);
    VL_OUT16(&io_resp_payload_results_58,11,0);
    VL_OUT16(&io_resp_payload_results_61,11,0);
    VL_OUT16(&io_resp_payload_results_0,11,0);
    VL_OUT16(&io_resp_payload_results_16,11,0);
    VL_OUT16(&io_resp_payload_results_31,11,0);
    VL_OUT16(&io_resp_payload_results_54,11,0);
    VL_OUT16(&io_resp_payload_results_35,11,0);
    VL_OUT16(&io_resp_payload_results_37,11,0);
    VL_OUT16(&io_resp_payload_results_39,11,0);
    VL_OUT16(&io_resp_payload_results_41,11,0);
    VL_OUT16(&io_resp_payload_results_43,11,0);
    VL_OUT16(&io_resp_payload_results_45,11,0);
    VL_OUT16(&io_resp_payload_results_49,11,0);
    VL_OUT16(&io_resp_payload_results_51,11,0);
    VL_OUT16(&io_resp_payload_results_53,11,0);
    VL_OUT16(&io_resp_payload_results_55,11,0);
    VL_OUT16(&io_resp_payload_results_56,11,0);
    VL_OUT16(&io_resp_payload_results_32,11,0);
    VL_OUT16(&io_resp_payload_results_47,11,0);
    VL_OUT16(&io_resp_payload_results_48,11,0);
    VL_OUT16(&io_resp_payload_results_57,11,0);
    VL_OUT16(&io_resp_payload_results_62,11,0);
    VL_OUT8(&io_resp_valid,0,0);
    VL_OUT8(&io_resp_payload_metadata_profile_key_bit_count,3,0);
    VL_OUT8(&io_resp_payload_metadata_profile_key_fused_mat,1,0);
    VL_OUT8(&io_resp_payload_metadata_profile_val_bit_count,3,0);
    VL_OUT8(&io_resp_payload_metadata_profile_val_fused_mat,1,0);
    VL_OUT8(&io_resp_payload_metadata_allow_requantize,0,0);
    VL_OUT16(&io_resp_payload_metadata_thres_requantize,11,0);
    VL_OUT(&io_resp_payload_metadata_key_base_addr,31,0);
    VL_OUT(&io_resp_payload_metadata_universal_id,31,0);
    VL_IN8(&io_req_payload_fragment_metadata_profile_val_fused_mat,1,0);
    VL_IN8(&io_req_payload_fragment_metadata_val_fetch_num,7,0);
    VL_IN8(&io_req_payload_fragment_metadata_topk_enable,0,0);
    VL_IN8(&io_req_payload_fragment_metadata_topk_num,7,0);
    VL_IN16(&io_req_payload_fragment_query_0,11,0);
    VL_IN16(&io_req_payload_fragment_query_1,11,0);
    VL_IN16(&io_req_payload_fragment_query_3,11,0);
    VL_IN16(&io_req_payload_fragment_query_4,11,0);
    VL_IN16(&io_req_payload_fragment_query_8,11,0);
    VL_IN16(&io_req_payload_fragment_query_9,11,0);
    VL_IN16(&io_req_payload_fragment_query_11,11,0);
    VL_IN16(&io_req_payload_fragment_query_12,11,0);
    VL_IN16(&io_req_payload_fragment_query_13,11,0);
    VL_IN16(&io_req_payload_fragment_query_14,11,0);
    VL_IN16(&io_req_payload_fragment_query_15,11,0);
    VL_IN16(&io_req_payload_fragment_query_16,11,0);
    VL_IN16(&io_req_payload_fragment_query_26,11,0);
    VL_IN16(&io_req_payload_fragment_query_27,11,0);
    VL_IN16(&io_req_payload_fragment_query_28,11,0);
    VL_IN16(&io_req_payload_fragment_query_29,11,0);
    VL_IN16(&io_req_payload_fragment_query_30,11,0);
    VL_IN16(&io_req_payload_fragment_query_31,11,0);
    VL_IN16(&io_req_payload_fragment_query_32,11,0);
    VL_IN16(&io_req_payload_fragment_query_33,11,0);
    VL_IN16(&io_req_payload_fragment_query_34,11,0);
    VL_IN16(&io_req_payload_fragment_query_35,11,0);
    VL_IN16(&io_req_payload_fragment_query_36,11,0);
    VL_IN16(&io_req_payload_fragment_query_37,11,0);
    VL_IN16(&io_req_payload_fragment_query_38,11,0);
    VL_IN16(&io_req_payload_fragment_query_39,11,0);
    VL_IN16(&io_req_payload_fragment_query_40,11,0);
    VL_IN16(&io_req_payload_fragment_query_41,11,0);
    VL_IN16(&io_req_payload_fragment_query_55,11,0);
    VL_IN16(&io_req_payload_fragment_query_56,11,0);
    VL_IN16(&io_req_payload_fragment_query_57,11,0);
    VL_IN16(&io_req_payload_fragment_query_58,11,0);
    VL_IN16(&io_req_payload_fragment_query_60,11,0);
    VL_IN16(&io_req_payload_fragment_query_61,11,0);
    VL_IN16(&io_req_payload_fragment_query_62,11,0);
    VL_IN16(&io_req_payload_fragment_query_63,11,0);
    VL_IN(&io_req_payload_fragment_metadata_key_base_addr,31,0);
    VL_IN8(&io_req_payload_fragment_metadata_key_fetch_num,7,0);
    VL_IN8(&io_req_payload_fragment_metadata_profile_key_fused_mat,1,0);
    VL_IN16(&io_req_payload_fragment_query_23,11,0);
    VL_IN16(&io_req_payload_fragment_query_42,11,0);
    VL_IN16(&io_req_payload_fragment_query_43,11,0);
    VL_IN16(&io_req_payload_fragment_query_44,11,0);
    VL_IN16(&io_req_payload_fragment_query_45,11,0);
    VL_IN16(&io_req_payload_fragment_query_54,11,0);
    VL_IN8(&io_req_payload_fragment_metadata_allow_requantize,0,0);
    VL_IN16(&io_req_payload_fragment_query_17,11,0);
    VL_IN16(&io_req_payload_fragment_query_18,11,0);
    VL_IN16(&io_req_payload_fragment_query_19,11,0);
    VL_IN16(&io_req_payload_fragment_query_20,11,0);
    VL_IN16(&io_req_payload_fragment_query_21,11,0);
    VL_IN16(&io_req_payload_fragment_query_22,11,0);
    VL_IN16(&io_req_payload_fragment_query_46,11,0);
    VL_IN16(&io_req_payload_fragment_query_47,11,0);
    VL_IN16(&io_req_payload_fragment_query_48,11,0);
    VL_IN16(&io_req_payload_fragment_query_49,11,0);
    VL_IN16(&io_req_payload_fragment_query_50,11,0);
    VL_IN16(&io_req_payload_fragment_query_51,11,0);
    VL_IN16(&io_req_payload_fragment_query_52,11,0);
    VL_IN16(&io_req_payload_fragment_query_53,11,0);
    VL_IN16(&io_req_payload_fragment_metadata_thres_requantize,11,0);
    VL_IN(&io_req_payload_fragment_metadata_universal_id,31,0);
    VL_IN(&io_req_payload_fragment_metadata_topk_latency,31,0);
    VL_IN8(&io_req_payload_fragment_metadata_size_d,6,0);
    VL_IN8(&io_req_payload_last,0,0);
    VL_OUT8(&io_req_ready,0,0);
    VL_OUT8(&io_resp_payload_metadata_key_fetch_num,7,0);
    VL_OUT8(&io_resp_payload_metadata_val_fetch_num,7,0);
    VL_OUT8(&io_resp_payload_metadata_topk_enable,0,0);
    VL_OUT8(&io_resp_payload_metadata_topk_num,7,0);
    VL_OUT8(&io_resp_payload_metadata_size_d,6,0);
    VL_OUT(&io_resp_payload_metadata_key_requant_base_addr,31,0);
    VL_OUT(&io_resp_payload_metadata_val_base_addr,31,0);
    VL_OUT(&io_resp_payload_metadata_topk_latency,31,0);
    VL_IN8(&io_resp_ready,0,0);
    VL_IN8(&clk,0,0);

    // CELLS
    // Public to allow access to /* verilator public */ items.
    // Otherwise the application code can consider these internals.
    VSpAttenSim_SpAttenSim* const SpAttenSim;

    // Root instance pointer to allow access to model internals,
    // including inlined /* verilator public_flat_* */ items.
    VSpAttenSim___024root* const rootp;

    // CONSTRUCTORS
    /// Construct the model; called by application code
    /// If contextp is null, then the model will use the default global context
    /// If name is "", then makes a wrapper with a
    /// single model invisible with respect to DPI scope names.
    explicit VSpAttenSim(VerilatedContext* contextp, const char* name = "TOP");
    explicit VSpAttenSim(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    virtual ~VSpAttenSim();
  private:
    VL_UNCOPYABLE(VSpAttenSim);  ///< Copying not allowed

  public:
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    /// Are there scheduled events to handle?
    bool eventsPending();
    /// Returns time at next time slot. Aborts if !eventsPending()
    uint64_t nextTimeSlot();
    /// Trace signals in the model; called by application code
    void trace(VerilatedFstC* tfp, int levels, int options = 0);
    /// Retrieve name of this model instance (as passed to constructor).
    const char* name() const;

    // Abstract methods from VerilatedModel
    const char* hierName() const override final;
    const char* modelName() const override final;
    unsigned threads() const override final;
    /// Prepare for cloning the model at the process level (e.g. fork in Linux)
    /// Release necessary resources. Called before cloning.
    void prepareClone() const;
    /// Re-init after cloning the model at the process level (e.g. fork in Linux)
    /// Re-allocate necessary resources. Called after cloning.
    void atClone() const;
    std::unique_ptr<VerilatedTraceConfig> traceConfig() const override final;
};

#endif  // guard
