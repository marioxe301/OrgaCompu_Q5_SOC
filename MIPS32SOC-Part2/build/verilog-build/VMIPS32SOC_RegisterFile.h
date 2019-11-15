// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMIPS32SOC.h for the primary calling header

#ifndef _VMIPS32SOC_RegisterFile_H_
#define _VMIPS32SOC_RegisterFile_H_

#include "verilated.h"
#include "VMIPS32SOC__Dpi.h"

class VMIPS32SOC__Syms;

//----------

VL_MODULE(VMIPS32SOC_RegisterFile) {
  public:
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(__PVT__clk,0,0);
    VL_IN8(__PVT__ra1,4,0);
    VL_IN8(__PVT__ra2,4,0);
    VL_IN8(__PVT__wa,4,0);
    VL_IN8(__PVT__we,0,0);
    VL_IN(__PVT__wd,31,0);
    VL_OUT(__PVT__rd1,31,0);
    VL_OUT(__PVT__rd2,31,0);
    
    // LOCAL SIGNALS
    // Begin mtask footprint  all: 
    VL_SIG(memory[32],31,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    VMIPS32SOC__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMIPS32SOC_RegisterFile);  ///< Copying not allowed
  public:
    VMIPS32SOC_RegisterFile(const char* name="TOP");
    ~VMIPS32SOC_RegisterFile();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(VMIPS32SOC__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _initial__TOP__MIPS32SOC__regFile__1(VMIPS32SOC__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__MIPS32SOC__regFile__2(VMIPS32SOC__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
