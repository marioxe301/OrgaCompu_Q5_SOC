// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _VMIPS32SOC__Syms_H_
#define _VMIPS32SOC__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VMIPS32SOC.h"
#include "VMIPS32SOC_MIPS32SOC.h"
#include "VMIPS32SOC_DataMemory.h"
#include "VMIPS32SOC_InstMemory.h"
#include "VMIPS32SOC_RegisterFile.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS
class VMIPS32SOC__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VMIPS32SOC*                    TOPp;
    VMIPS32SOC_MIPS32SOC           TOP__MIPS32SOC;
    VMIPS32SOC_DataMemory          TOP__MIPS32SOC__dataMem;
    VMIPS32SOC_InstMemory          TOP__MIPS32SOC__instMem;
    VMIPS32SOC_RegisterFile        TOP__MIPS32SOC__regFile;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_MIPS32SOC;
    VerilatedScope __Vscope_MIPS32SOC__dataMem;
    VerilatedScope __Vscope_MIPS32SOC__instMem;
    VerilatedScope __Vscope_MIPS32SOC__regFile;
    
    // CREATORS
    VMIPS32SOC__Syms(VMIPS32SOC* topp, const char* namep);
    ~VMIPS32SOC__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
