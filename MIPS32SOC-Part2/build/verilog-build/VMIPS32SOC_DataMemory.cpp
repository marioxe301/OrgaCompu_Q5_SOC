// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC_DataMemory.h"
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMIPS32SOC_DataMemory) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VMIPS32SOC_DataMemory::__Vconfigure(VMIPS32SOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMIPS32SOC_DataMemory::~VMIPS32SOC_DataMemory() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VMIPS32SOC_DataMemory::_sequent__TOP__MIPS32SOC__dataMem__1(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_DataMemory::_sequent__TOP__MIPS32SOC__dataMem__1\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC__dataMem.__Vdlyvset__memory__v0 = 0U;
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/DataMemory.v:13
    if (vlSymsp->TOP__MIPS32SOC.__PVT__memWrite) {
	vlSymsp->TOP__MIPS32SOC__dataMem.__Vdlyvval__memory__v0 
	    = vlSymsp->TOP__MIPS32SOC.rfData2;
	vlSymsp->TOP__MIPS32SOC__dataMem.__Vdlyvset__memory__v0 = 1U;
	vlSymsp->TOP__MIPS32SOC__dataMem.__Vdlyvdim0__memory__v0 
	    = vlSymsp->TOP__MIPS32SOC.__PVT__memAddr;
    }
}

VL_INLINE_OPT void VMIPS32SOC_DataMemory::_sequent__TOP__MIPS32SOC__dataMem__2(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_DataMemory::_sequent__TOP__MIPS32SOC__dataMem__2\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYSPOST at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/DataMemory.v:15
    if (vlSymsp->TOP__MIPS32SOC__dataMem.__Vdlyvset__memory__v0) {
	vlSymsp->TOP__MIPS32SOC__dataMem.memory[vlSymsp->TOP__MIPS32SOC__dataMem.__Vdlyvdim0__memory__v0] 
	    = vlSymsp->TOP__MIPS32SOC__dataMem.__Vdlyvval__memory__v0;
    }
}

void VMIPS32SOC_DataMemory::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_DataMemory::_ctor_var_reset\n"); );
    // Body
    __PVT__addr = VL_RAND_RESET_I(11);
    __PVT__writeData = VL_RAND_RESET_I(32);
    __PVT__memWrite = VL_RAND_RESET_I(1);
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__memRead = VL_RAND_RESET_I(1);
    __PVT__readData = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<2048; ++__Vi0) {
	    memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
    readData__out = VL_RAND_RESET_I(32);
    readData__en = VL_RAND_RESET_I(32);
    __Vdlyvdim0__memory__v0 = VL_RAND_RESET_I(11);
    __Vdlyvval__memory__v0 = VL_RAND_RESET_I(32);
    __Vdlyvset__memory__v0 = VL_RAND_RESET_I(1);
}
