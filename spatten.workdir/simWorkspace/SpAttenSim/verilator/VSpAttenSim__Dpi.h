// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VSPATTENSIM__DPI_H_
#define VERILATED_VSPATTENSIM__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at /home/arun-venkat/summer_project/spatten/spatten.workdir/dpi/DRAMSimDPIDriver.sv:23:34
    extern int DRAMSimDPIDriverCreate(int dataWidth, int seed, long long* obj);
    // DPI import at /home/arun-venkat/summer_project/spatten/spatten.workdir/dpi/DRAMSimDPIDriver.sv:24:34
    extern void DRAMSimDPIDriverDestroy(long long obj);
    // DPI import at /home/arun-venkat/summer_project/spatten/spatten.workdir/dpi/DRAMSimDPIDriver.sv:26:34
    extern int DRAMSimDPIDriverPopResponse(long long obj, unsigned long long* addr, svBitVecVal* data, svBit* is_write);
    // DPI import at /home/arun-venkat/summer_project/spatten/spatten.workdir/dpi/DRAMSimDPIDriver.sv:25:34
    extern int DRAMSimDPIDriverPushRequest(long long obj, unsigned long long addr, const svBitVecVal* data, svBit is_write);
    // DPI import at /home/arun-venkat/summer_project/spatten/spatten.workdir/dpi/DRAMSimDPIDriver.sv:27:34
    extern int DRAMSimDPIDriverTick(long long obj);

#ifdef __cplusplus
}
#endif

#endif  // guard
