// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC_RegisterFile.h"
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMIPS32SOC_RegisterFile) {
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VMIPS32SOC_RegisterFile::__Vconfigure(VMIPS32SOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMIPS32SOC_RegisterFile::~VMIPS32SOC_RegisterFile() {
}

//--------------------
// Internal Methods

void VMIPS32SOC_RegisterFile::_initial__TOP__MIPS32SOC__regFile__1(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RegisterFile::_initial__TOP__MIPS32SOC__regFile__1\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/RegisterFile.v:28
    vlSymsp->TOP__MIPS32SOC__regFile.memory[0U] = 0U;
}

VL_INLINE_OPT void VMIPS32SOC_RegisterFile::_sequent__TOP__MIPS32SOC__regFile__2(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RegisterFile::_sequent__TOP__MIPS32SOC__regFile__2\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__memory__v0,4,0);
    VL_SIG8(__Vdlyvset__memory__v0,0,0);
    VL_SIG(__Vdlyvval__memory__v0,31,0);
    // Body
    __Vdlyvset__memory__v0 = 0U;
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/RegisterFile.v:22
    if (vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable) {
	__Vdlyvval__memory__v0 = ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__rfLuiSelector)
				   ? (0xffff0000U & 
				      (vlSymsp->TOP__MIPS32SOC.inst 
				       << 0x10U)) : 
				  ((1U & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteDataSel))
				    ? ((((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__memRead)
					  ? vlSymsp->TOP__MIPS32SOC__dataMem.memory
					 [vlSymsp->TOP__MIPS32SOC.__PVT__memAddr]
					  : 0U) & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__memRead)
						    ? 0xffffffffU
						    : 0U)) 
				       & ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__memRead)
					   ? 0xffffffffU
					   : 0U)) : vlSymsp->TOP__MIPS32SOC.__PVT__aluResult));
	__Vdlyvset__memory__v0 = 1U;
	__Vdlyvdim0__memory__v0 = ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteAddrSel)
				    ? (IData)(vlSymsp->TOP__MIPS32SOC.rd)
				    : (IData)(vlSymsp->TOP__MIPS32SOC.rt));
    }
    // ALWAYSPOST at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/RegisterFile.v:25
    if (__Vdlyvset__memory__v0) {
	vlSymsp->TOP__MIPS32SOC__regFile.memory[__Vdlyvdim0__memory__v0] 
	    = __Vdlyvval__memory__v0;
    }
}

void VMIPS32SOC_RegisterFile::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VMIPS32SOC_RegisterFile::_ctor_var_reset\n"); );
    // Body
    __PVT__ra1 = VL_RAND_RESET_I(5);
    __PVT__ra2 = VL_RAND_RESET_I(5);
    __PVT__wa = VL_RAND_RESET_I(5);
    __PVT__wd = VL_RAND_RESET_I(32);
    __PVT__we = VL_RAND_RESET_I(1);
    __PVT__clk = VL_RAND_RESET_I(1);
    __PVT__rd1 = VL_RAND_RESET_I(32);
    __PVT__rd2 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    memory[__Vi0] = VL_RAND_RESET_I(32);
    }}
}
