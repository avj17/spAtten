# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Make include file with class lists
#
# This file lists generated Verilated files, for including in higher level makefiles.
# See VSpAttenSim.mk for the caller.

### Switches...
# C11 constructs required?  0/1 (always on now)
VM_C11 = 1
# Timing enabled?  0/1
VM_TIMING = 0
# Coverage output mode?  0/1 (from --coverage)
VM_COVERAGE = 0
# Parallel builds?  0/1 (from --output-split)
VM_PARALLEL_BUILDS = 1
# Tracing output mode?  0/1 (from --trace/--trace-fst)
VM_TRACE = 1
# Tracing output mode in VCD format?  0/1 (from --trace)
VM_TRACE_VCD = 0
# Tracing output mode in FST format?  0/1 (from --trace-fst)
VM_TRACE_FST = 1

### Object file lists...
# Generated module classes, fast-path, compile with highest optimization
VM_CLASSES_FAST += \
	VSpAttenSim \
	VSpAttenSim___024root__DepSet_h9bdc4250__0 \
	VSpAttenSim___024root__DepSet_h926fac72__0 \
	VSpAttenSim_SpAttenSim__DepSet_haec3a11f__0 \
	VSpAttenSim_SpAttenSim__DepSet_haec3a11f__1 \
	VSpAttenSim_SpAtten__DepSet_haf38bf87__0 \
	VSpAttenSim_SpAtten__DepSet_h0494d37f__0 \
	VSpAttenSim_SpAtten__DepSet_h0494d37f__1 \
	VSpAttenSim_SpAtten__DepSet_h0494d37f__2 \
	VSpAttenSim_SpAttenController__DepSet_hc195f2ae__0 \
	VSpAttenSim_SpAttenController__DepSet_hc195f2ae__1 \
	VSpAttenSim_SpAttenController__DepSet_hc195f2ae__2 \
	VSpAttenSim_SpAttenController__DepSet_h8605712c__0 \
	VSpAttenSim_SpAttenController__DepSet_h8605712c__1 \
	VSpAttenSim_SpAttenController__DepSet_h8605712c__2 \
	VSpAttenSim_SpAttenController__DepSet_h8605712c__3 \
	VSpAttenSim_SpAttenController__DepSet_h8605712c__4 \
	VSpAttenSim_SpAttenController__DepSet_h8605712c__5 \
	VSpAttenSim_SpAttenController__DepSet_h8605712c__6 \
	VSpAttenSim_SpAttenController__DepSet_h8605712c__7 \
	VSpAttenSim_Buffer_2__DepSet_hdefcd4a6__0 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__0 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__1 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__2 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__3 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__4 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__5 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__6 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__7 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__8 \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__9 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__0 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__1 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__2 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__3 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__4 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__5 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__6 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__7 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__8 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__9 \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__10 \
	VSpAttenSim_MatrixFetcher__DepSet_h4fb3c806__0 \
	VSpAttenSim_MatrixFetcher__DepSet_h4fb3c806__1 \
	VSpAttenSim_MatrixFetcher__DepSet_h4fb3c806__2 \
	VSpAttenSim_MatrixFetcher__DepSet_h4fb3c806__3 \
	VSpAttenSim_MatrixFetcher__DepSet_hfd3e86de__0 \
	VSpAttenSim_MatrixFetcher__DepSet_hfd3e86de__1 \
	VSpAttenSim_MultiBankRAM_24__DepSet_heaf3a71a__0 \
	VSpAttenSim_MultiBankRAM_24__DepSet_h9306a60e__0 \
	VSpAttenSim_MultiBankRAM_23__DepSet_h214d3e2a__0 \
	VSpAttenSim_MultiBankRAM_23__DepSet_h80232d44__0 \
	VSpAttenSim_MultiBankRAM_22__DepSet_h44448ff1__0 \
	VSpAttenSim_MultiBankRAM_22__DepSet_h482d3097__0 \
	VSpAttenSim_MultiBankRAM_22__DepSet_h97a7f462__0 \
	VSpAttenSim_MultiBankRAM_21__DepSet_h5c0edf08__0 \
	VSpAttenSim_MultiBankRAM_21__DepSet_h3f87d89f__0 \
	VSpAttenSim_MultiBankRAM_20__DepSet_h64502e74__0 \
	VSpAttenSim_MultiBankRAM_20__DepSet_h79271079__0 \
	VSpAttenSim_MultiBankRAM_19__DepSet_hdeadfe60__0 \
	VSpAttenSim_MultiBankRAM_19__DepSet_h96d87a03__0 \
	VSpAttenSim_MultiBankRAM_18__DepSet_hae29bdc4__0 \
	VSpAttenSim_MultiBankRAM_18__DepSet_h3a9b01df__0 \
	VSpAttenSim_MultiBankRAM_17__DepSet_ha608c180__0 \
	VSpAttenSim_MultiBankRAM_17__DepSet_h851374f7__0 \
	VSpAttenSim_MultiBankRAM_16__DepSet_h2d63ab2f__0 \
	VSpAttenSim_MultiBankRAM_16__DepSet_hd6172594__0 \
	VSpAttenSim_MultiBankRAM_15__DepSet_hb94c1aad__0 \
	VSpAttenSim_MultiBankRAM_15__DepSet_h0a9f3aec__0 \
	VSpAttenSim_MultiBankRAM_14__DepSet_hd5905e07__0 \
	VSpAttenSim_MultiBankRAM_14__DepSet_h98b54f85__0 \
	VSpAttenSim_MultiBankRAM_13__DepSet_h608cab56__0 \
	VSpAttenSim_MultiBankRAM_13__DepSet_hb5d143c2__0 \
	VSpAttenSim_StageLoadData__DepSet_h2b23af87__0 \
	VSpAttenSim_StageLoadData__DepSet_hae40877f__0 \
	VSpAttenSim_StageLoadData__DepSet_hae40877f__1 \
	VSpAttenSim_StageLoadData__DepSet_hae40877f__2 \
	VSpAttenSim_StageLoadData__DepSet_hae40877f__3 \
	VSpAttenSim_StageLoadData__DepSet_hae40877f__4 \
	VSpAttenSim_StreamRAM_28__DepSet_hd9ae0a29__0 \
	VSpAttenSim_StreamRAM_28__DepSet_h8a326208__0 \
	VSpAttenSim_StreamRAM_30__DepSet_h5e9bbc82__0 \
	VSpAttenSim_StreamRAM_30__DepSet_h2edfd675__0 \
	VSpAttenSim_StreamRAM_32__DepSet_h9d19345a__0 \
	VSpAttenSim_StreamRAM_32__DepSet_h82588ab7__0 \
	VSpAttenSim_StreamRAM_34__DepSet_h48b347cb__0 \
	VSpAttenSim_StreamRAM_34__DepSet_hb81e67c2__0 \
	VSpAttenSim_StreamRAM_36__DepSet_ha86222d2__0 \
	VSpAttenSim_StreamRAM_36__DepSet_h5c2dba59__0 \
	VSpAttenSim_StreamRAM_38__DepSet_h73f2e7c7__0 \
	VSpAttenSim_StreamRAM_38__DepSet_hb897e0cf__0 \
	VSpAttenSim_StreamRAM_40__DepSet_h64e43266__0 \
	VSpAttenSim_StreamRAM_40__DepSet_h67103316__0 \
	VSpAttenSim_StreamRAM_42__DepSet_he8329070__0 \
	VSpAttenSim_StreamRAM_42__DepSet_h106d8b03__0 \
	VSpAttenSim_StreamRAM_44__DepSet_h9218a96e__0 \
	VSpAttenSim_StreamRAM_44__DepSet_hce46485c__0 \
	VSpAttenSim_StreamRAM_46__DepSet_h9d25ae6b__0 \
	VSpAttenSim_StreamRAM_46__DepSet_hbf46cfda__0 \
	VSpAttenSim_StreamRAM_48__DepSet_h0d42a1f9__0 \
	VSpAttenSim_StreamRAM_48__DepSet_h08e523ec__0 \
	VSpAttenSim_StreamRAM_50__DepSet_hee535c21__0 \
	VSpAttenSim_StreamRAM_50__DepSet_h6c4966be__0 \

# Generated module classes, non-fast-path, compile with low/medium optimization
VM_CLASSES_SLOW += \
	VSpAttenSim__ConstPool_0 \
	VSpAttenSim___024root__Slow \
	VSpAttenSim___024root__DepSet_h9bdc4250__0__Slow \
	VSpAttenSim___024root__DepSet_h926fac72__0__Slow \
	VSpAttenSim_SpAttenSim__Slow \
	VSpAttenSim_SpAttenSim__DepSet_h2b25b93a__0__Slow \
	VSpAttenSim_SpAttenSim__DepSet_haec3a11f__0__Slow \
	VSpAttenSim_SpAtten__Slow \
	VSpAttenSim_SpAtten__DepSet_haf38bf87__0__Slow \
	VSpAttenSim_SpAtten__DepSet_haf38bf87__1__Slow \
	VSpAttenSim_SpAtten__DepSet_h0494d37f__0__Slow \
	VSpAttenSim_SpAtten__DepSet_h0494d37f__1__Slow \
	VSpAttenSim_SpAtten__DepSet_h0494d37f__2__Slow \
	VSpAttenSim_SpAtten__DepSet_h0494d37f__3__Slow \
	VSpAttenSim_SpAttenController__Slow \
	VSpAttenSim_SpAttenController__DepSet_hc195f2ae__0__Slow \
	VSpAttenSim_SpAttenController__DepSet_hc195f2ae__1__Slow \
	VSpAttenSim_SpAttenController__DepSet_hc195f2ae__2__Slow \
	VSpAttenSim_SpAttenController__DepSet_hc195f2ae__3__Slow \
	VSpAttenSim_SpAttenController__DepSet_h8605712c__0__Slow \
	VSpAttenSim_Buffer_2__Slow \
	VSpAttenSim_Buffer_2__DepSet_hdefcd4a6__0__Slow \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__0__Slow \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__1__Slow \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__2__Slow \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__3__Slow \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__4__Slow \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__5__Slow \
	VSpAttenSim_Buffer_2__DepSet_h765e6ea6__6__Slow \
	VSpAttenSim_Buffer_1__Slow \
	VSpAttenSim_Buffer_1__DepSet_hba4229df__0__Slow \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__0__Slow \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__1__Slow \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__2__Slow \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__3__Slow \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__4__Slow \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__5__Slow \
	VSpAttenSim_Buffer_1__DepSet_hca8b7451__6__Slow \
	VSpAttenSim_MatrixFetcher__Slow \
	VSpAttenSim_MatrixFetcher__DepSet_h4fb3c806__0__Slow \
	VSpAttenSim_MatrixFetcher__DepSet_h4fb3c806__1__Slow \
	VSpAttenSim_MatrixFetcher__DepSet_hfd3e86de__0__Slow \
	VSpAttenSim_MatrixFetcher__DepSet_hfd3e86de__1__Slow \
	VSpAttenSim_MultiBankRAM_24__Slow \
	VSpAttenSim_MultiBankRAM_24__DepSet_h60a7257b__0__Slow \
	VSpAttenSim_MultiBankRAM_24__DepSet_heaf3a71a__0__Slow \
	VSpAttenSim_MultiBankRAM_24__DepSet_h9306a60e__0__Slow \
	VSpAttenSim_MultiBankRAM_23__Slow \
	VSpAttenSim_MultiBankRAM_23__DepSet_h80baf319__0__Slow \
	VSpAttenSim_MultiBankRAM_23__DepSet_h214d3e2a__0__Slow \
	VSpAttenSim_MultiBankRAM_23__DepSet_h80232d44__0__Slow \
	VSpAttenSim_MultiBankRAM_22__Slow \
	VSpAttenSim_MultiBankRAM_22__DepSet_h44448ff1__0__Slow \
	VSpAttenSim_MultiBankRAM_22__DepSet_h482d3097__0__Slow \
	VSpAttenSim_MultiBankRAM_22__DepSet_h97a7f462__0__Slow \
	VSpAttenSim_MultiBankRAM_21__Slow \
	VSpAttenSim_MultiBankRAM_21__DepSet_hfb514fa0__0__Slow \
	VSpAttenSim_MultiBankRAM_21__DepSet_h5c0edf08__0__Slow \
	VSpAttenSim_MultiBankRAM_21__DepSet_h3f87d89f__0__Slow \
	VSpAttenSim_MultiBankRAM_20__Slow \
	VSpAttenSim_MultiBankRAM_20__DepSet_heea8dce8__0__Slow \
	VSpAttenSim_MultiBankRAM_20__DepSet_h64502e74__0__Slow \
	VSpAttenSim_MultiBankRAM_20__DepSet_h79271079__0__Slow \
	VSpAttenSim_MultiBankRAM_19__Slow \
	VSpAttenSim_MultiBankRAM_19__DepSet_hb5135fca__0__Slow \
	VSpAttenSim_MultiBankRAM_19__DepSet_hdeadfe60__0__Slow \
	VSpAttenSim_MultiBankRAM_19__DepSet_h96d87a03__0__Slow \
	VSpAttenSim_MultiBankRAM_18__Slow \
	VSpAttenSim_MultiBankRAM_18__DepSet_heb91e03a__0__Slow \
	VSpAttenSim_MultiBankRAM_18__DepSet_hae29bdc4__0__Slow \
	VSpAttenSim_MultiBankRAM_18__DepSet_h3a9b01df__0__Slow \
	VSpAttenSim_MultiBankRAM_17__Slow \
	VSpAttenSim_MultiBankRAM_17__DepSet_h7ca3638d__0__Slow \
	VSpAttenSim_MultiBankRAM_17__DepSet_ha608c180__0__Slow \
	VSpAttenSim_MultiBankRAM_17__DepSet_h851374f7__0__Slow \
	VSpAttenSim_MultiBankRAM_16__Slow \
	VSpAttenSim_MultiBankRAM_16__DepSet_hf8fbfe03__0__Slow \
	VSpAttenSim_MultiBankRAM_16__DepSet_h2d63ab2f__0__Slow \
	VSpAttenSim_MultiBankRAM_16__DepSet_hd6172594__0__Slow \
	VSpAttenSim_MultiBankRAM_15__Slow \
	VSpAttenSim_MultiBankRAM_15__DepSet_h82d791ae__0__Slow \
	VSpAttenSim_MultiBankRAM_15__DepSet_hb94c1aad__0__Slow \
	VSpAttenSim_MultiBankRAM_15__DepSet_h0a9f3aec__0__Slow \
	VSpAttenSim_MultiBankRAM_14__Slow \
	VSpAttenSim_MultiBankRAM_14__DepSet_h2bdb2518__0__Slow \
	VSpAttenSim_MultiBankRAM_14__DepSet_hd5905e07__0__Slow \
	VSpAttenSim_MultiBankRAM_14__DepSet_h98b54f85__0__Slow \
	VSpAttenSim_MultiBankRAM_13__Slow \
	VSpAttenSim_MultiBankRAM_13__DepSet_h40ccf071__0__Slow \
	VSpAttenSim_MultiBankRAM_13__DepSet_h608cab56__0__Slow \
	VSpAttenSim_MultiBankRAM_13__DepSet_hb5d143c2__0__Slow \
	VSpAttenSim_StageLoadData__Slow \
	VSpAttenSim_StageLoadData__DepSet_h2b23af87__0__Slow \
	VSpAttenSim_StageLoadData__DepSet_h2b23af87__1__Slow \
	VSpAttenSim_StageLoadData__DepSet_hae40877f__0__Slow \
	VSpAttenSim_StreamRAM_28__Slow \
	VSpAttenSim_StreamRAM_28__DepSet_hd9ae0a29__0__Slow \
	VSpAttenSim_StreamRAM_28__DepSet_h8a326208__0__Slow \
	VSpAttenSim_StreamRAM_30__Slow \
	VSpAttenSim_StreamRAM_30__DepSet_h5e9bbc82__0__Slow \
	VSpAttenSim_StreamRAM_30__DepSet_h2edfd675__0__Slow \
	VSpAttenSim_StreamRAM_32__Slow \
	VSpAttenSim_StreamRAM_32__DepSet_h9d19345a__0__Slow \
	VSpAttenSim_StreamRAM_32__DepSet_h82588ab7__0__Slow \
	VSpAttenSim_StreamRAM_34__Slow \
	VSpAttenSim_StreamRAM_34__DepSet_h48b347cb__0__Slow \
	VSpAttenSim_StreamRAM_34__DepSet_hb81e67c2__0__Slow \
	VSpAttenSim_StreamRAM_36__Slow \
	VSpAttenSim_StreamRAM_36__DepSet_ha86222d2__0__Slow \
	VSpAttenSim_StreamRAM_36__DepSet_h5c2dba59__0__Slow \
	VSpAttenSim_StreamRAM_38__Slow \
	VSpAttenSim_StreamRAM_38__DepSet_h73f2e7c7__0__Slow \
	VSpAttenSim_StreamRAM_38__DepSet_hb897e0cf__0__Slow \
	VSpAttenSim_StreamRAM_40__Slow \
	VSpAttenSim_StreamRAM_40__DepSet_h64e43266__0__Slow \
	VSpAttenSim_StreamRAM_40__DepSet_h67103316__0__Slow \
	VSpAttenSim_StreamRAM_42__Slow \
	VSpAttenSim_StreamRAM_42__DepSet_he8329070__0__Slow \
	VSpAttenSim_StreamRAM_42__DepSet_h106d8b03__0__Slow \
	VSpAttenSim_StreamRAM_44__Slow \
	VSpAttenSim_StreamRAM_44__DepSet_h9218a96e__0__Slow \
	VSpAttenSim_StreamRAM_44__DepSet_hce46485c__0__Slow \
	VSpAttenSim_StreamRAM_46__Slow \
	VSpAttenSim_StreamRAM_46__DepSet_h9d25ae6b__0__Slow \
	VSpAttenSim_StreamRAM_46__DepSet_hbf46cfda__0__Slow \
	VSpAttenSim_StreamRAM_48__Slow \
	VSpAttenSim_StreamRAM_48__DepSet_h0d42a1f9__0__Slow \
	VSpAttenSim_StreamRAM_48__DepSet_h08e523ec__0__Slow \
	VSpAttenSim_StreamRAM_50__Slow \
	VSpAttenSim_StreamRAM_50__DepSet_hee535c21__0__Slow \
	VSpAttenSim_StreamRAM_50__DepSet_h6c4966be__0__Slow \

# Generated support classes, fast-path, compile with highest optimization
VM_SUPPORT_FAST += \
	VSpAttenSim__Dpi \
	VSpAttenSim__Trace__0 \
	VSpAttenSim__Trace__1 \
	VSpAttenSim__Trace__2 \
	VSpAttenSim__Trace__3 \
	VSpAttenSim__Trace__4 \
	VSpAttenSim__Trace__5 \
	VSpAttenSim__Trace__6 \
	VSpAttenSim__Trace__7 \
	VSpAttenSim__Trace__8 \
	VSpAttenSim__Trace__9 \
	VSpAttenSim__Trace__10 \
	VSpAttenSim__Trace__11 \
	VSpAttenSim__Trace__12 \
	VSpAttenSim__Trace__13 \
	VSpAttenSim__Trace__14 \

# Generated support classes, non-fast-path, compile with low/medium optimization
VM_SUPPORT_SLOW += \
	VSpAttenSim__Syms \
	VSpAttenSim__Trace__0__Slow \
	VSpAttenSim__TraceDecls__0__Slow \
	VSpAttenSim__Trace__1__Slow \
	VSpAttenSim__Trace__2__Slow \
	VSpAttenSim__Trace__3__Slow \
	VSpAttenSim__Trace__4__Slow \
	VSpAttenSim__Trace__5__Slow \
	VSpAttenSim__Trace__6__Slow \
	VSpAttenSim__Trace__7__Slow \
	VSpAttenSim__Trace__8__Slow \
	VSpAttenSim__Trace__9__Slow \
	VSpAttenSim__Trace__10__Slow \
	VSpAttenSim__Trace__11__Slow \
	VSpAttenSim__Trace__12__Slow \
	VSpAttenSim__Trace__13__Slow \
	VSpAttenSim__Trace__14__Slow \
	VSpAttenSim__Trace__15__Slow \
	VSpAttenSim__Trace__16__Slow \
	VSpAttenSim__Trace__17__Slow \
	VSpAttenSim__Trace__18__Slow \
	VSpAttenSim__Trace__19__Slow \
	VSpAttenSim__Trace__20__Slow \
	VSpAttenSim__Trace__21__Slow \
	VSpAttenSim__Trace__22__Slow \
	VSpAttenSim__Trace__23__Slow \
	VSpAttenSim__Trace__24__Slow \
	VSpAttenSim__Trace__25__Slow \
	VSpAttenSim__Trace__26__Slow \
	VSpAttenSim__Trace__27__Slow \
	VSpAttenSim__Trace__28__Slow \
	VSpAttenSim__Trace__29__Slow \
	VSpAttenSim__Trace__30__Slow \

# Global classes, need linked once per executable, fast-path, compile with highest optimization
VM_GLOBAL_FAST += \
	verilated \
	verilated_dpi \
	verilated_fst_c \
	verilated_threads \

# Global classes, need linked once per executable, non-fast-path, compile with low/medium optimization
VM_GLOBAL_SLOW += \


# Verilated -*- Makefile -*-
