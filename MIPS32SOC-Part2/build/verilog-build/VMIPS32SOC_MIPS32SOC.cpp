// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VMIPS32SOC.h for the primary calling header

#include "VMIPS32SOC_MIPS32SOC.h"
#include "VMIPS32SOC__Syms.h"

#include "verilated_dpi.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(VMIPS32SOC_MIPS32SOC) {
    VL_CELL(instMem, VMIPS32SOC_InstMemory);
    VL_CELL(dataMem, VMIPS32SOC_DataMemory);
    VL_CELL(regFile, VMIPS32SOC_RegisterFile);
    // Reset internal values
    // Reset structure values
    _ctor_var_reset();
}

void VMIPS32SOC_MIPS32SOC::__Vconfigure(VMIPS32SOC__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VMIPS32SOC_MIPS32SOC::~VMIPS32SOC_MIPS32SOC() {
}

//--------------------
// Internal Methods

VL_INLINE_OPT void VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__1(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__1\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/MIPS32SOC.v:90
    vlSymsp->TOP__MIPS32SOC.PC = ((IData)(vlTOPp->rst)
				   ? 0x400000U : vlSymsp->TOP__MIPS32SOC.__PVT__nextPC);
}

VL_INLINE_OPT void VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__2(VMIPS32SOC__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_sequent__TOP__MIPS32SOC__2\n"); );
    VMIPS32SOC* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlSymsp->TOP__MIPS32SOC.inst = vlSymsp->TOP__MIPS32SOC__instMem.memory
	[(0x3ffU & (vlSymsp->TOP__MIPS32SOC.PC >> 2U))];
    vlSymsp->TOP__MIPS32SOC.rd = (0x1fU & (vlSymsp->TOP__MIPS32SOC.inst 
					   >> 0xbU));
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable = 0U;
	if ((0x20U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 4U)))) {
		if ((8U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 2U)))) {
			if ((2U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((1U & (~ vlSymsp->TOP__MIPS32SOC.inst))) {
				vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable = 1U;
			    }
			}
		    }
		} else {
		    if ((4U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 1U)))) {
			    vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable = 1U;
			}
		    } else {
			vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable = 1U;
		    }
		}
	    }
	}
    } else {
	vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable = 0U;
	if ((0x80000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			      >> 0x1dU)))) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 0x1cU)))) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable = 1U;
			    }
			}
		    }
		}
	    }
	} else {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((0x20000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable = 1U;
			    }
			} else {
			    vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable = 1U;
			}
		    } else {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 0x1bU)))) {
			    vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteEnable = 1U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteAddrSel = 0U;
	if ((0x20U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 4U)))) {
		if ((8U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 2U)))) {
			if ((2U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((1U & (~ vlSymsp->TOP__MIPS32SOC.inst))) {
				vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteAddrSel = 1U;
			    }
			}
		    }
		} else {
		    if ((4U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 1U)))) {
			    vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteAddrSel = 1U;
			}
		    } else {
			vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteAddrSel = 1U;
		    }
		}
	    }
	}
    } else {
	vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteAddrSel = 0U;
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U != (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.__PVT__rfLuiSelector = 0U;
	if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
		      >> 0x1fU)))) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((0x20000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__rfLuiSelector = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteDataSel = 0U;
    } else {
	vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteDataSel = 0U;
	if ((0x80000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			      >> 0x1dU)))) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 0x1cU)))) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__rfWriteDataSel = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.__PVT__memWrite = 0U;
    } else {
	vlSymsp->TOP__MIPS32SOC.__PVT__memWrite = 0U;
	if ((0x80000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((0x20000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 0x1cU)))) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__memWrite = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.__PVT__memRead = 0U;
    } else {
	vlSymsp->TOP__MIPS32SOC.__PVT__memRead = 0U;
	if ((0x80000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			      >> 0x1dU)))) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 0x1cU)))) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__memRead = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.invalidOpcode = 0U;
	if ((0x20U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((0x10U & vlSymsp->TOP__MIPS32SOC.inst)) {
		vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
	    } else {
		if ((8U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((4U & vlSymsp->TOP__MIPS32SOC.inst)) {
			vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
		    } else {
			if ((2U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((1U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			    }
			} else {
			    vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			}
		    }
		} else {
		    if ((4U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((2U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			}
		    }
		}
	    }
	} else {
	    vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
	}
    } else {
	vlSymsp->TOP__MIPS32SOC.invalidOpcode = 0U;
	if ((0x80000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((0x40000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
	    } else {
		if ((0x20000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
		    } else {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
					  >> 0x1aU)))) {
				vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			    }
			} else {
			    vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			}
		    }
		} else {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
		    } else {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
					  >> 0x1aU)))) {
				vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			    }
			} else {
			    vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			}
		    }
		}
	    }
	} else {
	    if ((0x40000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
	    } else {
		if ((0x20000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
					  >> 0x1aU)))) {
				vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			    }
			}
		    } else {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			}
		    }
		} else {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			}
		    } else {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			    }
			} else {
			    vlSymsp->TOP__MIPS32SOC.invalidOpcode = 1U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.isBne = 0U;
    } else {
	vlSymsp->TOP__MIPS32SOC.isBne = 0U;
	if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
		      >> 0x1fU)))) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			      >> 0x1dU)))) {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 0x1bU)))) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.isBne = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.isJmp = 0U;
    } else {
	vlSymsp->TOP__MIPS32SOC.isJmp = 0U;
	if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
		      >> 0x1fU)))) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			      >> 0x1dU)))) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 0x1cU)))) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
					  >> 0x1aU)))) {
				vlSymsp->TOP__MIPS32SOC.isJmp = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.isBeq = 0U;
    } else {
	vlSymsp->TOP__MIPS32SOC.isBeq = 0U;
	if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
		      >> 0x1fU)))) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			      >> 0x1dU)))) {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 0x1bU)))) {
			    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
					  >> 0x1aU)))) {
				vlSymsp->TOP__MIPS32SOC.isBeq = 1U;
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = 0U;
	if ((0x20U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 4U)))) {
		if ((8U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 2U)))) {
			if ((2U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((1U & (~ vlSymsp->TOP__MIPS32SOC.inst))) {
				vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = 5U;
			    }
			}
		    }
		} else {
		    if ((4U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 1U)))) {
			    vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc 
				= ((1U & vlSymsp->TOP__MIPS32SOC.inst)
				    ? 4U : 3U);
			}
		    } else {
			vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc 
			    = ((2U & vlSymsp->TOP__MIPS32SOC.inst)
			        ? 2U : 1U);
		    }
		}
	    }
	}
    } else {
	vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = 0U;
	if ((0x80000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((0x20000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 0x1cU)))) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = 1U;
			    }
			}
		    }
		} else {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 0x1cU)))) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = 1U;
			    }
			}
		    }
		}
	    }
	} else {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((0x20000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 0x1bU)))) {
			    vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc 
				= ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)
				    ? 4U : 3U);
			}
		    } else {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 0x1bU)))) {
			    vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = 1U;
			}
		    }
		} else {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 0x1bU)))) {
			    vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc = 2U;
			}
		    }
		}
	    }
	}
    }
    vlSymsp->TOP__MIPS32SOC.rs = (0x1fU & (vlSymsp->TOP__MIPS32SOC.inst 
					   >> 0x15U));
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ControlUnit.v:23
    if ((0U == (0x3fU & (vlSymsp->TOP__MIPS32SOC.inst 
			 >> 0x1aU)))) {
	vlSymsp->TOP__MIPS32SOC.__PVT__aluSrc = 0U;
    } else {
	vlSymsp->TOP__MIPS32SOC.__PVT__aluSrc = 0U;
	if ((0x80000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((0x20000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 0x1cU)))) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__aluSrc = 1U;
			    }
			}
		    }
		} else {
		    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				  >> 0x1cU)))) {
			if ((0x8000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			    if ((0x4000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
				vlSymsp->TOP__MIPS32SOC.__PVT__aluSrc = 1U;
			    }
			}
		    }
		}
	    }
	} else {
	    if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
			  >> 0x1eU)))) {
		if ((0x20000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
		    if ((0x10000000U & vlSymsp->TOP__MIPS32SOC.inst)) {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 0x1bU)))) {
			    vlSymsp->TOP__MIPS32SOC.__PVT__aluSrc = 1U;
			}
		    } else {
			if ((1U & (~ (vlSymsp->TOP__MIPS32SOC.inst 
				      >> 0x1bU)))) {
			    vlSymsp->TOP__MIPS32SOC.__PVT__aluSrc = 1U;
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/BitExtender.v:7
    vlSymsp->TOP__MIPS32SOC.__PVT__imm32 = ((0xffff0000U 
					     & (VL_NEGATE_I((IData)(
								    (1U 
								     & (vlSymsp->TOP__MIPS32SOC.inst 
									>> 0xfU)))) 
						<< 0x10U)) 
					    | (0xffffU 
					       & vlSymsp->TOP__MIPS32SOC.inst));
    vlSymsp->TOP__MIPS32SOC.rt = (0x1fU & (vlSymsp->TOP__MIPS32SOC.inst 
					   >> 0x10U));
    vlSymsp->TOP__MIPS32SOC.rfData1 = vlSymsp->TOP__MIPS32SOC__regFile.memory
	[vlSymsp->TOP__MIPS32SOC.rs];
    vlSymsp->TOP__MIPS32SOC.__PVT__branchTargetAddr 
	= ((IData)(4U) + (vlSymsp->TOP__MIPS32SOC.PC 
			  + (0xfffffffcU & (vlSymsp->TOP__MIPS32SOC.__PVT__imm32 
					    << 2U))));
    vlSymsp->TOP__MIPS32SOC.rfData2 = vlSymsp->TOP__MIPS32SOC__regFile.memory
	[vlSymsp->TOP__MIPS32SOC.rt];
    vlSymsp->TOP__MIPS32SOC.__PVT__aluOperand2 = ((IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluSrc)
						   ? vlSymsp->TOP__MIPS32SOC.__PVT__imm32
						   : vlSymsp->TOP__MIPS32SOC.rfData2);
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/ALU.v:13
    vlSymsp->TOP__MIPS32SOC.__PVT__aluResult = ((4U 
						 & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
						 ? 
						((2U 
						  & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
						  ? 0U
						  : 
						 ((1U 
						   & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
						   ? 
						  VL_LTS_III(32,32,32, vlSymsp->TOP__MIPS32SOC.rfData1, vlSymsp->TOP__MIPS32SOC.__PVT__aluOperand2)
						   : 
						  (vlSymsp->TOP__MIPS32SOC.rfData1 
						   | vlSymsp->TOP__MIPS32SOC.__PVT__aluOperand2)))
						 : 
						((2U 
						  & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
						  ? 
						 ((1U 
						   & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
						   ? 
						  (vlSymsp->TOP__MIPS32SOC.rfData1 
						   & vlSymsp->TOP__MIPS32SOC.__PVT__aluOperand2)
						   : 
						  (vlSymsp->TOP__MIPS32SOC.rfData1 
						   - vlSymsp->TOP__MIPS32SOC.__PVT__aluOperand2))
						  : 
						 ((1U 
						   & (IData)(vlSymsp->TOP__MIPS32SOC.__PVT__aluFunc))
						   ? 
						  (vlSymsp->TOP__MIPS32SOC.rfData1 
						   + vlSymsp->TOP__MIPS32SOC.__PVT__aluOperand2)
						   : 0U)));
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/MemoryDecoder.v:15
    if (((0x10010000U <= vlSymsp->TOP__MIPS32SOC.__PVT__aluResult) 
	 & (0x10010fffU >= vlSymsp->TOP__MIPS32SOC.__PVT__aluResult))) {
	vlSymsp->TOP__MIPS32SOC.__PVT__memAddr = (0x7ffU 
						  & (vlSymsp->TOP__MIPS32SOC.__PVT__aluResult 
						     >> 2U));
    } else {
	if (((0x7ffff000U <= vlSymsp->TOP__MIPS32SOC.__PVT__aluResult) 
	     & (0x7fffffffU >= vlSymsp->TOP__MIPS32SOC.__PVT__aluResult))) {
	    vlSymsp->TOP__MIPS32SOC.__PVT__memAddr 
		= (0x7ffU & (vlSymsp->TOP__MIPS32SOC.__PVT__aluResult 
			     >> 2U));
	}
    }
    vlSymsp->TOP__MIPS32SOC.isZero = (0U == vlSymsp->TOP__MIPS32SOC.__PVT__aluResult);
    // ALWAYS at /home/marioxe301/Documents/OrgaComp/ProyectoOrga/ProyectoSOC/MIPS32SOC-Part2/test-cases/../verilog/MIPS32SOC.v:78
    vlSymsp->TOP__MIPS32SOC.__PVT__nextPC = ((IData)(vlSymsp->TOP__MIPS32SOC.isJmp)
					      ? ((0xf0000000U 
						  & ((IData)(4U) 
						     + vlSymsp->TOP__MIPS32SOC.PC)) 
						 | (0xffffffcU 
						    & (vlSymsp->TOP__MIPS32SOC.inst 
						       << 2U)))
					      : (((IData)(vlSymsp->TOP__MIPS32SOC.isBeq) 
						  & (IData)(vlSymsp->TOP__MIPS32SOC.isZero))
						  ? vlSymsp->TOP__MIPS32SOC.__PVT__branchTargetAddr
						  : 
						 (((IData)(vlSymsp->TOP__MIPS32SOC.isBne) 
						   & (~ (IData)(vlSymsp->TOP__MIPS32SOC.isZero)))
						   ? vlSymsp->TOP__MIPS32SOC.__PVT__branchTargetAddr
						   : 
						  ((IData)(4U) 
						   + vlSymsp->TOP__MIPS32SOC.PC))));
}

void VMIPS32SOC_MIPS32SOC::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VMIPS32SOC_MIPS32SOC::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    inst = VL_RAND_RESET_I(32);
    __PVT__nextPC = VL_RAND_RESET_I(32);
    PC = VL_RAND_RESET_I(32);
    rd = VL_RAND_RESET_I(5);
    rt = VL_RAND_RESET_I(5);
    rs = VL_RAND_RESET_I(5);
    __PVT__aluSrc = VL_RAND_RESET_I(1);
    __PVT__rfWriteEnable = VL_RAND_RESET_I(1);
    __PVT__rfWriteAddrSel = VL_RAND_RESET_I(1);
    __PVT__rfWriteDataSel = VL_RAND_RESET_I(2);
    rfData1 = VL_RAND_RESET_I(32);
    rfData2 = VL_RAND_RESET_I(32);
    __PVT__imm32 = VL_RAND_RESET_I(32);
    __PVT__memAddr = VL_RAND_RESET_I(11);
    __PVT__memWrite = VL_RAND_RESET_I(1);
    __PVT__memRead = VL_RAND_RESET_I(1);
    __PVT__aluFunc = VL_RAND_RESET_I(3);
    __PVT__aluOperand2 = VL_RAND_RESET_I(32);
    __PVT__aluResult = VL_RAND_RESET_I(32);
    __PVT__branchTargetAddr = VL_RAND_RESET_I(32);
    isJmp = VL_RAND_RESET_I(1);
    isBeq = VL_RAND_RESET_I(1);
    isBne = VL_RAND_RESET_I(1);
    isZero = VL_RAND_RESET_I(1);
    invalidOpcode = VL_RAND_RESET_I(1);
    __PVT__rfLuiSelector = VL_RAND_RESET_I(1);
}
