// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC.h"
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMIPS32SOC) {
    VMIPS32SOC__Syms* __restrict vlSymsp = __VlSymsp = new VMIPS32SOC__Syms(this, name());
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(MIPS32SOC, VMIPS32SOC_MIPS32SOC);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VMIPS32SOC::__Vconfigure(VMIPS32SOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMIPS32SOC::~VMIPS32SOC() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void VMIPS32SOC::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VMIPS32SOC::eval\n"); );
    VMIPS32SOC__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void VMIPS32SOC::_eval_initial_loop(VMIPS32SOC__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void VMIPS32SOC::_eval(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMIPS32SOC::_eval\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
	vlSymsp->TOP__MIPS32SOC__dataMem._sequent__TOP__MIPS32SOC__dataMem__1(vlSymsp);
	vlSymsp->TOP__MIPS32SOC._sequent__TOP__MIPS32SOC__1(vlSymsp);
	vlSymsp->TOP__MIPS32SOC__regFile._sequent__TOP__MIPS32SOC__regFile__2(vlSymsp);
	vlSymsp->TOP__MIPS32SOC__dataMem._sequent__TOP__MIPS32SOC__dataMem__2(vlSymsp);
	vlSymsp->TOP__MIPS32SOC._sequent__TOP__MIPS32SOC__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VMIPS32SOC::_eval_initial(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMIPS32SOC::_eval_initial\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC__regFile._initial__TOP__MIPS32SOC__regFile__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void VMIPS32SOC::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMIPS32SOC::final\n"); );
    // Variables
    VMIPS32SOC__Syms* __restrict vlSymsp = this->__VlSymsp;
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VMIPS32SOC::_eval_settle(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMIPS32SOC::_eval_settle\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC._sequent__TOP__MIPS32SOC__2(vlSymsp);
}

VL_INLINE_OPT QData VMIPS32SOC::_change_request(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMIPS32SOC::_change_request\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VMIPS32SOC::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMIPS32SOC::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
	Verilated::overWidthError("rst");}
}
#endif // VL_DEBUG

void VMIPS32SOC::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VMIPS32SOC::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
}
