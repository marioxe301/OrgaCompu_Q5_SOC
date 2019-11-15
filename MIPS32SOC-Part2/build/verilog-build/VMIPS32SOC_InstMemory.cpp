// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC_InstMemory.h"
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMIPS32SOC_InstMemory) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VMIPS32SOC_InstMemory::__Vconfigure(VMIPS32SOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMIPS32SOC_InstMemory::~VMIPS32SOC_InstMemory() {
}

//--------------------
// Internal Methods

void VMIPS32SOC_InstMemory::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_InstMemory::_ctor_var_reset\n"); );
    // Body
    __PVT__addr = VL_RAND_RESET_I(10);
    __PVT__en = VL_RAND_RESET_I(1);
    __PVT__readData = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<1024; ++__Vi0) {
	    memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    readData__out = VL_RAND_RESET_I(32);
    readData__en = VL_RAND_RESET_I(32);
}
