// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMIPS32SOC.h for the primary calling header

#ifndef _VMIPS32SOC_MIPS32SOC_H_
#define _VMIPS32SOC_MIPS32SOC_H_

#include "verilated.h"
#include "VMIPS32SOC__Dpi.h"

class VMIPS32SOC__Syms;
class VMIPS32SOC_InstMemory;
class VMIPS32SOC_DataMemory;
class VMIPS32SOC_RegisterFile;

//----------

VL_MODULE(VMIPS32SOC_MIPS32SOC) {
  public:
    // CELLS
    VMIPS32SOC_InstMemory*	instMem;
    VMIPS32SOC_DataMemory*	dataMem;
    VMIPS32SOC_RegisterFile*	regFile;
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    
    // LOCAL SIGNALS
    // Begin mtask footprint  all: 
    VL_SIG8(rd,4,0);
    VL_SIG8(rt,4,0);
    VL_SIG8(rs,4,0);
    VL_SIG8(__PVT__aluSrc,0,0);
    VL_SIG8(__PVT__rfWriteEnable,0,0);
    VL_SIG8(__PVT__rfWriteAddrSel,0,0);
    VL_SIG8(__PVT__rfWriteDataSel,1,0);
    VL_SIG8(__PVT__memWrite,0,0);
    VL_SIG8(__PVT__memRead,0,0);
    VL_SIG8(__PVT__aluFunc,2,0);
    VL_SIG8(isJmp,0,0);
    VL_SIG8(isBeq,0,0);
    VL_SIG8(isBne,0,0);
    VL_SIG8(isZero,0,0);
    VL_SIG8(invalidOpcode,0,0);
    VL_SIG8(__PVT__rfLuiSelector,0,0);
    VL_SIG16(__PVT__memAddr,10,0);
    VL_SIG(inst,31,0);
    VL_SIG(__PVT__nextPC,31,0);
    VL_SIG(PC,31,0);
    VL_SIG(rfData1,31,0);
    VL_SIG(rfData2,31,0);
    VL_SIG(__PVT__imm32,31,0);
    VL_SIG(__PVT__aluOperand2,31,0);
    VL_SIG(__PVT__aluResult,31,0);
    VL_SIG(__PVT__branchTargetAddr,31,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    VMIPS32SOC__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMIPS32SOC_MIPS32SOC);  ///< Copying not allowed
  public:
    VMIPS32SOC_MIPS32SOC(const char* name="TOP");
    ~VMIPS32SOC_MIPS32SOC();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(VMIPS32SOC__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__MIPS32SOC__1(VMIPS32SOC__Syms* __restrict vlSymsp);
    static void _sequent__TOP__MIPS32SOC__2(VMIPS32SOC__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
