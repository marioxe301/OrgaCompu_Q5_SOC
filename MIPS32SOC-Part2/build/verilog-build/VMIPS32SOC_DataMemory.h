// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMIPS32SOC.h for the primary calling header

#ifndef _VMIPS32SOC_DataMemory_H_
#define _VMIPS32SOC_DataMemory_H_

#include "verilated.h"
#include "VMIPS32SOC__Dpi.h"

class VMIPS32SOC__Syms;

//----------

VL_MODULE(VMIPS32SOC_DataMemory) {
  public:
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__memWrite,0,0);
    VL_IN8(__PVT__memRead,0,0);
    VL_IN16(__PVT__addr,10,0);
    VL_IN(__PVT__writeData,31,0);
    VL_IN(__PVT__readData,31,0);
    VL_OUT(readData__out,31,0);
    VL_OUT(readData__en,31,0);
    
    // LOCAL SIGNALS
    // Begin mtask footprint  all: 
    VL_SIG(memory[2048],31,0);
    
    // LOCAL VARIABLES
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvset__memory__v0,0,0);
    VL_SIG16(__Vdlyvdim0__memory__v0,10,0);
    VL_SIG(__Vdlyvval__memory__v0,31,0);
    
    // INTERNAL VARIABLES
  private:
    VMIPS32SOC__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMIPS32SOC_DataMemory);  ///< Copying not allowed
  public:
    VMIPS32SOC_DataMemory(const char* name="TOP");
    ~VMIPS32SOC_DataMemory();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(VMIPS32SOC__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _sequent__TOP__MIPS32SOC__dataMem__1(VMIPS32SOC__Syms* __restrict vlSymsp);
    static void _sequent__TOP__MIPS32SOC__dataMem__2(VMIPS32SOC__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
