// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VMIPS32SOC.h for the primary calling header

#ifndef _VMIPS32SOC_InstMemory_H_
#define _VMIPS32SOC_InstMemory_H_

#include "verilated.h"
#include "VMIPS32SOC__Dpi.h"

class VMIPS32SOC__Syms;

//----------

VL_MODULE(VMIPS32SOC_InstMemory) {
  public:
    
    // PORTS
    // Begin mtask footprint  all: 
    VL_IN8(__PVT__en,0,0);
    VL_IN16(__PVT__addr,9,0);
    VL_IN(__PVT__readData,31,0);
    VL_OUT(readData__out,31,0);
    VL_OUT(readData__en,31,0);
    
    // LOCAL SIGNALS
    // Begin mtask footprint  all: 
    VL_SIG(memory[1024],31,0);
    
    // LOCAL VARIABLES
    
    // INTERNAL VARIABLES
  private:
    VMIPS32SOC__Syms* __VlSymsp;  // Symbol table
  public:
    
    // PARAMETERS
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VMIPS32SOC_InstMemory);  ///< Copying not allowed
  public:
    VMIPS32SOC_InstMemory(const char* name="TOP");
    ~VMIPS32SOC_InstMemory();
    
    // API METHODS
    
    // INTERNAL METHODS
    void __Vconfigure(VMIPS32SOC__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
