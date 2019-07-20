// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vchartest.h for the primary calling header

#include "Vchartest.h"
#include "Vchartest__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vchartest) {
    Vchartest__Syms* __restrict vlSymsp = __VlSymsp = new Vchartest__Syms(this, name());
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vchartest::__Vconfigure(Vchartest__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vchartest::~Vchartest() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vchartest::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vchartest::eval\n"); );
    Vchartest__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
	vlSymsp->__Vm_activity = true;
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

void Vchartest::_eval_initial_loop(Vchartest__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
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

void Vchartest::_initial__TOP__1(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_initial__TOP__1\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIGW(__Vtemp1,95,0,3);
    // Body
    // INITIAL at ../../VGA_CTL.v:200
    __Vtemp1[0U] = 0x6c697374U;
    __Vtemp1[1U] = 0x5053322eU;
    __Vtemp1[2U] = 0x5647415fU;
    VL_READMEM_W(true,8,4096, 0,3, __Vtemp1, vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__charset_rom__DOT__romdata
		 ,0,~0);
}

VL_INLINE_OPT void Vchartest::_sequent__TOP__2(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_sequent__TOP__2\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdly__o_cpu_ack,0,0);
    // Body
    __Vdly__o_cpu_ack = vlTOPp->o_cpu_ack;
    // ALWAYS at ../../VGA_CTL.v:81
    if (vlTOPp->i_reset) {
	__Vdly__o_cpu_ack = 1U;
    } else {
	if (vlTOPp->o_vga_select) {
	    if (((~ (IData)(vlTOPp->o_cpu_ack)) & (IData)(vlTOPp->o_vga_select))) {
		__Vdly__o_cpu_ack = 1U;
	    }
	} else {
	    __Vdly__o_cpu_ack = 0U;
	}
    }
    // ALWAYS at ../../VGA_CTL.v:81
    if ((1U & (~ (IData)(vlTOPp->i_reset)))) {
	if ((1U & (~ (IData)(vlTOPp->o_vga_select)))) {
	    if (vlTOPp->o_cpu_rw) {
		if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
			      >> 7U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				  >> 6U)))) {
			if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				      >> 5U)))) {
			    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					  >> 4U)))) {
				if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					      >> 3U)))) {
				    if ((4U & (IData)(vlTOPp->o_cpu_a_bus))) {
					if ((1U & (~ 
						   ((IData)(vlTOPp->o_cpu_a_bus) 
						    >> 1U)))) {
					    if ((1U 
						 & (~ (IData)(vlTOPp->o_cpu_a_bus)))) {
						vlTOPp->i_vga_interrupt = 1U;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at ../../VGA_CTL.v:81
    if ((1U & (~ (IData)(vlTOPp->i_reset)))) {
	if ((1U & (~ (IData)(vlTOPp->o_vga_select)))) {
	    if (vlTOPp->o_cpu_rw) {
		vlTOPp->chartest__DOT__vga_interface_0__DOT__out_buff 
		    = ((0x80U & (IData)(vlTOPp->o_cpu_a_bus))
		        ? 0U : ((0x40U & (IData)(vlTOPp->o_cpu_a_bus))
				 ? 0U : ((0x20U & (IData)(vlTOPp->o_cpu_a_bus))
					  ? 0U : ((0x10U 
						   & (IData)(vlTOPp->o_cpu_a_bus))
						   ? 0U
						   : 
						  ((8U 
						    & (IData)(vlTOPp->o_cpu_a_bus))
						    ? 0U
						    : 
						   ((4U 
						     & (IData)(vlTOPp->o_cpu_a_bus))
						     ? 
						    ((2U 
						      & (IData)(vlTOPp->o_cpu_a_bus))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->o_cpu_a_bus))
						       ? 0U
						       : (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_hi))
						      : 
						     ((1U 
						       & (IData)(vlTOPp->o_cpu_a_bus))
						       ? (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_lo)
						       : (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_misc_0)))
						     : 
						    ((2U 
						      & (IData)(vlTOPp->o_cpu_a_bus))
						      ? 
						     ((1U 
						       & (IData)(vlTOPp->o_cpu_a_bus))
						       ? (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y)
						       : (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x))
						      : 
						     ((1U 
						       & (IData)(vlTOPp->o_cpu_a_bus))
						       ? (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config)
						       : (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select)))))))));
	    }
	}
    }
    vlTOPp->o_cpu_ack = __Vdly__o_cpu_ack;
    // ALWAYS at ../../VGA_CTL.v:81
    if (vlTOPp->i_reset) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_misc_0 = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->o_vga_select)))) {
	    if ((1U & (~ (IData)(vlTOPp->o_cpu_rw)))) {
		if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
			      >> 7U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				  >> 6U)))) {
			if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				      >> 5U)))) {
			    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					  >> 4U)))) {
				if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					      >> 3U)))) {
				    if ((4U & (IData)(vlTOPp->o_cpu_a_bus))) {
					if ((1U & (~ 
						   ((IData)(vlTOPp->o_cpu_a_bus) 
						    >> 1U)))) {
					    if ((1U 
						 & (~ (IData)(vlTOPp->o_cpu_a_bus)))) {
						vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_misc_0 
						    = vlTOPp->io_cpu_d_bus;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at ../../VGA_CTL.v:81
    if (vlTOPp->i_reset) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->o_vga_select)))) {
	    if ((1U & (~ (IData)(vlTOPp->o_cpu_rw)))) {
		if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
			      >> 7U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				  >> 6U)))) {
			if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				      >> 5U)))) {
			    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					  >> 4U)))) {
				if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					      >> 3U)))) {
				    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
						  >> 2U)))) {
					if ((2U & (IData)(vlTOPp->o_cpu_a_bus))) {
					    if ((1U 
						 & (IData)(vlTOPp->o_cpu_a_bus))) {
						vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y 
						    = vlTOPp->io_cpu_d_bus;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at ../../VGA_CTL.v:81
    if (vlTOPp->i_reset) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->o_vga_select)))) {
	    if ((1U & (~ (IData)(vlTOPp->o_cpu_rw)))) {
		if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
			      >> 7U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				  >> 6U)))) {
			if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				      >> 5U)))) {
			    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					  >> 4U)))) {
				if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					      >> 3U)))) {
				    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
						  >> 2U)))) {
					if ((2U & (IData)(vlTOPp->o_cpu_a_bus))) {
					    if ((1U 
						 & (~ (IData)(vlTOPp->o_cpu_a_bus)))) {
						vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x 
						    = vlTOPp->io_cpu_d_bus;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at ../../VGA_CTL.v:81
    if (vlTOPp->i_reset) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->o_vga_select)))) {
	    if ((1U & (~ (IData)(vlTOPp->o_cpu_rw)))) {
		if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
			      >> 7U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				  >> 6U)))) {
			if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				      >> 5U)))) {
			    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					  >> 4U)))) {
				if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					      >> 3U)))) {
				    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
						  >> 2U)))) {
					if ((1U & (~ 
						   ((IData)(vlTOPp->o_cpu_a_bus) 
						    >> 1U)))) {
					    if ((1U 
						 & (~ (IData)(vlTOPp->o_cpu_a_bus)))) {
						vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select 
						    = vlTOPp->io_cpu_d_bus;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
}

VL_INLINE_OPT void Vchartest::_sequent__TOP__3(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_sequent__TOP__3\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../../VGA_modes.v:30
    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__row 
	= ((2U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config))
	    ? ((0x20U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__row)) 
	       | (0x1fU & ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_y) 
			   >> 5U))) : (0x3fU & ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_y) 
						>> 4U)));
    // ALWAYS at ../../VGA_modes.v:30
    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_y 
	= (0xfU & ((2U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config))
		    ? ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_y) 
		       >> 1U) : (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_y)));
    // ALWAYS at ../../VGA_modes.v:30
    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__column 
	= ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config))
	    ? ((0x40U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__column)) 
	       | (0x3fU & ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x) 
			   >> 4U))) : (0x7fU & ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x) 
						>> 3U)));
    // ALWAYS at ../../VGA_modes.v:30
    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_x 
	= (7U & ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config))
		  ? ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x) 
		     >> 1U) : (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x)));
    // ALWAYS at ../../VGA_modes.v:139
    if (vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_raster_active) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state = 1U;
	vlTOPp->chartest__DOT__vga_interface_0__DOT__bmp_rgb_out = 0U;
    } else {
	if (vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state) {
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state 
		= (1U & (~ (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state)));
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__int_bmp_a_bus 
		= (0xffffffU & (((IData)(0x140U) * 
				 (0x1ffU & ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_y) 
					    >> 1U))) 
				+ (0x1ffU & ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x) 
					     >> 1U))));
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__bmp_rgb_out 
		= vlTOPp->i_vram_data;
	} else {
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state = 1U;
	}
    }
    // ALWAYS at ../../VGA_modes.v:47
    if (vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_raster_active) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state = 1U;
	vlTOPp->chartest__DOT__vga_interface_0__DOT__txt_rgb_out = 0U;
    } else {
	if (vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state) {
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__int_txt_a_bus 
		= (0xffffffU & ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config))
				 ? 0x28U : 0x50U));
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val 
		= vlTOPp->i_vram_data;
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state = 0U;
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__int_txt_a_bus 
		= (0xffffffU & ((vlTOPp->chartest__DOT__vga_interface_0__DOT__int_txt_a_bus 
				 * (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__row)) 
				+ (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__column)));
	} else {
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__int_txt_a_bus 
		= (0xffffffU & ((IData)(0x960U) + (
						   ((IData)(0x50U) 
						    * (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__row)) 
						   + (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__column))));
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__mem_val 
		= vlTOPp->i_vram_data;
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state = 1U;
	}
	vlTOPp->chartest__DOT__vga_interface_0__DOT__txt_rgb_out 
	    = ((4U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config))
	        ? ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__pixel_out)
		    ? ((8U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
		        ? ((4U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			    ? ((2U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			        ? ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				    ? 0xffU : 0xf8U)
			        : ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				    ? 0xc7U : 0xc0U))
			    : ((2U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			        ? ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				    ? 0x3fU : 0x38U)
			        : ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				    ? 7U : 0x5bU)))
		        : ((4U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			    ? ((2U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			        ? ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				    ? 0xadU : 0xe8U)
			        : ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				    ? 0x85U : 0x80U))
			    : ((2U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			        ? ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				    ? 0x1bU : 0x18U)
			        : ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				    ? 3U : 0U)))) : 
		   ((0x80U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
		     ? ((0x40U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			 ? ((0x20U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			     ? ((0x10U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				 ? 0xffU : 0xf8U) : 
			    ((0x10U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			      ? 0xc7U : 0xc0U)) : (
						   (0x20U 
						    & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
						    ? 
						   ((0x10U 
						     & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
						     ? 0x3fU
						     : 0x38U)
						    : 
						   ((0x10U 
						     & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
						     ? 7U
						     : 0x5bU)))
		     : ((0x40U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			 ? ((0x20U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			     ? ((0x10U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
				 ? 0xadU : 0xe8U) : 
			    ((0x10U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
			      ? 0x85U : 0x80U)) : (
						   (0x20U 
						    & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
						    ? 
						   ((0x10U 
						     & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
						     ? 0x1bU
						     : 0x18U)
						    : 
						   ((0x10U 
						     & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val))
						     ? 3U
						     : 0U)))))
	        : ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__pixel_out)
		    ? (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val)
		    : 0U));
    }
    // ALWAYS at ../../VGA_CTL.v:65
    if (((((0x300U & ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_hi) 
		      << 8U)) | (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_lo)) 
	  == (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y)) 
	 & (0U == (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)))) {
	vlTOPp->i_vga_interrupt = 0U;
    }
    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__pixel_out 
	= (1U & (vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__charset_rom__DOT__romdata
		 [(((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__mem_val) 
		    << 4U) | (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_y))] 
		 >> (7U & (~ (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_x)))));
    // ALWAYS at ../../Misc.v:9
    vlTOPp->chartest__DOT__sysclk = (1U & ((~ (IData)(vlTOPp->i_reset)) 
					   & (~ (IData)(vlTOPp->chartest__DOT__sysclk))));
}

void Vchartest::_settle__TOP__4(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_settle__TOP__4\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../../VGA_CTL.v:49
    if ((1U & (~ ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select) 
		  >> 1U)))) {
	if ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select))) {
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out1 
		= vlTOPp->chartest__DOT__vga_interface_0__DOT__int_bmp_a_bus;
	}
    }
    // ALWAYS at ../../VGA_CTL.v:49
    if ((1U & (~ ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select) 
		  >> 1U)))) {
	if ((1U & (~ (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select)))) {
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out2 
		= vlTOPp->chartest__DOT__vga_interface_0__DOT__int_txt_a_bus;
	}
    }
    // ALWAYS at ../../VGA_CTL.v:49
    vlTOPp->chartest__DOT__vga_rgb = ((2U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select))
				       ? 0U : ((1U 
						& (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select))
					        ? (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__bmp_rgb_out)
					        : (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__txt_rgb_out)));
    vlTOPp->o_vga_hsync = (1U & (((0x290U < (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)) 
				  & (0x2f0U > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)))
				  ? 0U : 1U));
    vlTOPp->o_vga_vsync = (1U & (((0x1eaU < (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y)) 
				  & (0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y)))
				  ? 0U : 1U));
    // ALWAYS at ../../VGA_CTL.v:178
    vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_y 
	= (0x3ffU & (((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y) 
		      >= (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y))
		      ? ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y) 
			 - (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y))
		      : 0U));
    // ALWAYS at ../../VGA_CTL.v:178
    vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_raster_active 
	= (1U & ((~ (((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x) 
		      >= (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x)) 
		     & ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y) 
			>= (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y)))) 
		 | (((0x1eaU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y)) 
		     & (0x290U > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)))
		     ? 0U : 1U)));
    // ALWAYS at ../../VGA_CTL.v:178
    vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x 
	= (0x3ffU & (((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x) 
		      >= (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x))
		      ? ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x) 
			 - (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x))
		      : 0U));
    vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__pixel_out 
	= (1U & (vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__charset_rom__DOT__romdata
		 [(((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__mem_val) 
		    << 4U) | (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_y))] 
		 >> (7U & (~ (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_x)))));
    vlTOPp->o_vram_addr = (((((1U & ((0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
				      ? 0U : 1U)) ? 0U
			       : (vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out1 
				  | vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out2)) 
			     & ((1U & ((0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
				        ? 0U : 1U))
				 ? 0U : 0xffffffU)) 
			    & ((1U & ((0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
				       ? 0U : 1U)) ? 0U
			        : 0xffffffU)) & ((1U 
						  & ((0x1ecU 
						      > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
						      ? 0U
						      : 1U))
						  ? 0U
						  : 0xffffffU));
    vlTOPp->o_vga_red = (0xe0U & ((IData)(vlTOPp->chartest__DOT__vga_rgb) 
				  << 5U));
    vlTOPp->o_vga_grn = (0xe0U & ((IData)(vlTOPp->chartest__DOT__vga_rgb) 
				  << 2U));
    vlTOPp->o_vga_blu = (0xc0U & (IData)(vlTOPp->chartest__DOT__vga_rgb));
    // ALWAYS at ../../VGA_modes.v:115
    if ((0U == (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x))) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state = 1U;
    }
    // ALWAYS at ../../VGA_modes.v:154
    if ((0U == (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x))) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state = 1U;
    }
}

VL_INLINE_OPT void Vchartest::_sequent__TOP__5(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_sequent__TOP__5\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../../VGA_CTL.v:49
    if ((1U & (~ ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select) 
		  >> 1U)))) {
	if ((1U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select))) {
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out1 
		= vlTOPp->chartest__DOT__vga_interface_0__DOT__int_bmp_a_bus;
	}
    }
    // ALWAYS at ../../VGA_CTL.v:49
    if ((1U & (~ ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select) 
		  >> 1U)))) {
	if ((1U & (~ (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select)))) {
	    vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out2 
		= vlTOPp->chartest__DOT__vga_interface_0__DOT__int_txt_a_bus;
	}
    }
    // ALWAYS at ../../VGA_CTL.v:49
    vlTOPp->chartest__DOT__vga_rgb = ((2U & (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select))
				       ? 0U : ((1U 
						& (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select))
					        ? (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__bmp_rgb_out)
					        : (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__txt_rgb_out)));
    vlTOPp->o_vga_red = (0xe0U & ((IData)(vlTOPp->chartest__DOT__vga_rgb) 
				  << 5U));
    vlTOPp->o_vga_grn = (0xe0U & ((IData)(vlTOPp->chartest__DOT__vga_rgb) 
				  << 2U));
    vlTOPp->o_vga_blu = (0xc0U & (IData)(vlTOPp->chartest__DOT__vga_rgb));
    // ALWAYS at ../../VGA_CTL.v:81
    if (vlTOPp->i_reset) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->o_vga_select)))) {
	    if ((1U & (~ (IData)(vlTOPp->o_cpu_rw)))) {
		if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
			      >> 7U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				  >> 6U)))) {
			if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				      >> 5U)))) {
			    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					  >> 4U)))) {
				if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					      >> 3U)))) {
				    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
						  >> 2U)))) {
					if ((1U & (~ 
						   ((IData)(vlTOPp->o_cpu_a_bus) 
						    >> 1U)))) {
					    if ((1U 
						 & (IData)(vlTOPp->o_cpu_a_bus))) {
						vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config 
						    = vlTOPp->io_cpu_d_bus;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at ../../VGA_CTL.v:81
    if (vlTOPp->i_reset) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_hi = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->o_vga_select)))) {
	    if ((1U & (~ (IData)(vlTOPp->o_cpu_rw)))) {
		if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
			      >> 7U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				  >> 6U)))) {
			if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				      >> 5U)))) {
			    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					  >> 4U)))) {
				if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					      >> 3U)))) {
				    if ((4U & (IData)(vlTOPp->o_cpu_a_bus))) {
					if ((2U & (IData)(vlTOPp->o_cpu_a_bus))) {
					    if ((1U 
						 & (~ (IData)(vlTOPp->o_cpu_a_bus)))) {
						vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_hi 
						    = vlTOPp->io_cpu_d_bus;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
    // ALWAYS at ../../VGA_CTL.v:81
    if (vlTOPp->i_reset) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_lo = 0U;
    } else {
	if ((1U & (~ (IData)(vlTOPp->o_vga_select)))) {
	    if ((1U & (~ (IData)(vlTOPp->o_cpu_rw)))) {
		if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
			      >> 7U)))) {
		    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				  >> 6U)))) {
			if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
				      >> 5U)))) {
			    if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					  >> 4U)))) {
				if ((1U & (~ ((IData)(vlTOPp->o_cpu_a_bus) 
					      >> 3U)))) {
				    if ((4U & (IData)(vlTOPp->o_cpu_a_bus))) {
					if ((1U & (~ 
						   ((IData)(vlTOPp->o_cpu_a_bus) 
						    >> 1U)))) {
					    if ((1U 
						 & (IData)(vlTOPp->o_cpu_a_bus))) {
						vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_lo 
						    = vlTOPp->io_cpu_d_bus;
					    }
					}
				    }
				}
			    }
			}
		    }
		}
	    }
	}
    }
}

VL_INLINE_OPT void Vchartest::_sequent__TOP__6(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_sequent__TOP__6\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG16(__Vdly__chartest__DOT__vga_interface_0__DOT__px_address_x,9,0);
    VL_SIG16(__Vdly__chartest__DOT__vga_interface_0__DOT__px_address_y,9,0);
    // Body
    __Vdly__chartest__DOT__vga_interface_0__DOT__px_address_y 
	= vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y;
    __Vdly__chartest__DOT__vga_interface_0__DOT__px_address_x 
	= vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x;
    // ALWAYS at ../../VGA_sync_generator.v:32
    if (vlTOPp->i_reset) {
	__Vdly__chartest__DOT__vga_interface_0__DOT__px_address_x = 0U;
	__Vdly__chartest__DOT__vga_interface_0__DOT__px_address_y = 0U;
    } else {
	if ((0x31fU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x))) {
	    __Vdly__chartest__DOT__vga_interface_0__DOT__px_address_x 
		= (0x3ffU & ((IData)(1U) + (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)));
	} else {
	    __Vdly__chartest__DOT__vga_interface_0__DOT__px_address_y 
		= (0x3ffU & ((0x208U > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
			      ? ((IData)(1U) + (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
			      : 0U));
	    __Vdly__chartest__DOT__vga_interface_0__DOT__px_address_x = 0U;
	}
    }
    vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y 
	= __Vdly__chartest__DOT__vga_interface_0__DOT__px_address_y;
    vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x 
	= __Vdly__chartest__DOT__vga_interface_0__DOT__px_address_x;
    vlTOPp->o_vga_vsync = (1U & (((0x1eaU < (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y)) 
				  & (0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y)))
				  ? 0U : 1U));
    vlTOPp->o_vga_hsync = (1U & (((0x290U < (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)) 
				  & (0x2f0U > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)))
				  ? 0U : 1U));
}

VL_INLINE_OPT void Vchartest::_multiclk__TOP__7(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_multiclk__TOP__7\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ../../VGA_CTL.v:178
    vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_y 
	= (0x3ffU & (((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y) 
		      >= (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y))
		      ? ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y) 
			 - (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y))
		      : 0U));
    vlTOPp->o_vram_addr = (((((1U & ((0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
				      ? 0U : 1U)) ? 0U
			       : (vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out1 
				  | vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out2)) 
			     & ((1U & ((0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
				        ? 0U : 1U))
				 ? 0U : 0xffffffU)) 
			    & ((1U & ((0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
				       ? 0U : 1U)) ? 0U
			        : 0xffffffU)) & ((1U 
						  & ((0x1ecU 
						      > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
						      ? 0U
						      : 1U))
						  ? 0U
						  : 0xffffffU));
    // ALWAYS at ../../VGA_CTL.v:178
    vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_raster_active 
	= (1U & ((~ (((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x) 
		      >= (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x)) 
		     & ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y) 
			>= (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y)))) 
		 | (((0x1eaU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y)) 
		     & (0x290U > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)))
		     ? 0U : 1U)));
    // ALWAYS at ../../VGA_CTL.v:178
    vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x 
	= (0x3ffU & (((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x) 
		      >= (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x))
		      ? ((IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x) 
			 - (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x))
		      : 0U));
    // ALWAYS at ../../VGA_modes.v:115
    if ((0U == (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x))) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state = 1U;
    }
    // ALWAYS at ../../VGA_modes.v:154
    if ((0U == (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x))) {
	vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state = 1U;
    }
}

void Vchartest::_eval(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_eval\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
	 | ((IData)(vlTOPp->i_reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_reset))))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
	vlTOPp->__Vm_traceActivity = (2U | vlTOPp->__Vm_traceActivity);
    }
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
	vlTOPp->__Vm_traceActivity = (4U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk))) 
	 | ((IData)(vlTOPp->i_reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_reset))))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
	vlTOPp->__Vm_traceActivity = (8U | vlTOPp->__Vm_traceActivity);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__chartest__DOT__sysclk) 
	  & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__chartest__DOT__sysclk))) 
	 | ((IData)(vlTOPp->i_reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_reset))))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x10U | vlTOPp->__Vm_traceActivity);
    }
    if (((((IData)(vlTOPp->__VinpClk__TOP__chartest__DOT__sysclk) 
	   & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__chartest__DOT__sysclk))) 
	  | ((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) 
	 | ((IData)(vlTOPp->i_reset) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_reset))))) {
	vlTOPp->_multiclk__TOP__7(vlSymsp);
	vlTOPp->__Vm_traceActivity = (0x20U | vlTOPp->__Vm_traceActivity);
    }
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->__Vclklast__TOP__i_reset = vlTOPp->i_reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__chartest__DOT__sysclk 
	= vlTOPp->__VinpClk__TOP__chartest__DOT__sysclk;
    vlTOPp->__VinpClk__TOP__chartest__DOT__sysclk = vlTOPp->chartest__DOT__sysclk;
}

void Vchartest::_eval_initial(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_eval_initial\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->__Vclklast__TOP__i_reset = vlTOPp->i_reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__chartest__DOT__sysclk 
	= vlTOPp->__VinpClk__TOP__chartest__DOT__sysclk;
}

void Vchartest::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::final\n"); );
    // Variables
    Vchartest__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vchartest::_eval_settle(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_eval_settle\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
    vlTOPp->__Vm_traceActivity = (1U | vlTOPp->__Vm_traceActivity);
}

VL_INLINE_OPT QData Vchartest::_change_request(Vchartest__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_change_request\n"); );
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->chartest__DOT__sysclk ^ vlTOPp->__Vchglast__TOP__chartest__DOT__sysclk));
    VL_DEBUG_IF( if(__req && ((vlTOPp->chartest__DOT__sysclk ^ vlTOPp->__Vchglast__TOP__chartest__DOT__sysclk))) VL_DBG_MSGF("        CHANGE: chartest.v:39: chartest.sysclk\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__chartest__DOT__sysclk 
	= vlTOPp->chartest__DOT__sysclk;
    return __req;
}

#ifdef VL_DEBUG
void Vchartest::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
	Verilated::overWidthError("i_clk");}
    if (VL_UNLIKELY((i_pixclk & 0xfeU))) {
	Verilated::overWidthError("i_pixclk");}
    if (VL_UNLIKELY((i_reset & 0xfeU))) {
	Verilated::overWidthError("i_reset");}
    if (VL_UNLIKELY((i_test & 0xfeU))) {
	Verilated::overWidthError("i_test");}
    if (VL_UNLIKELY((i_hm_width & 0xe000U))) {
	Verilated::overWidthError("i_hm_width");}
    if (VL_UNLIKELY((i_hm_porch & 0xe000U))) {
	Verilated::overWidthError("i_hm_porch");}
    if (VL_UNLIKELY((i_hm_synch & 0xe000U))) {
	Verilated::overWidthError("i_hm_synch");}
    if (VL_UNLIKELY((i_hm_raw & 0xe000U))) {
	Verilated::overWidthError("i_hm_raw");}
    if (VL_UNLIKELY((i_vm_height & 0xf800U))) {
	Verilated::overWidthError("i_vm_height");}
    if (VL_UNLIKELY((i_vm_porch & 0xf800U))) {
	Verilated::overWidthError("i_vm_porch");}
    if (VL_UNLIKELY((i_vm_synch & 0xf800U))) {
	Verilated::overWidthError("i_vm_synch");}
    if (VL_UNLIKELY((i_vm_raw & 0xf800U))) {
	Verilated::overWidthError("i_vm_raw");}
    if (VL_UNLIKELY((o_cpu_rw & 0xfeU))) {
	Verilated::overWidthError("o_cpu_rw");}
    if (VL_UNLIKELY((o_vga_select & 0xfeU))) {
	Verilated::overWidthError("o_vga_select");}
}
#endif // VL_DEBUG

void Vchartest::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vchartest::_ctor_var_reset\n"); );
    // Body
    i_clk = VL_RAND_RESET_I(1);
    i_pixclk = VL_RAND_RESET_I(1);
    i_reset = VL_RAND_RESET_I(1);
    i_test = VL_RAND_RESET_I(1);
    i_hm_width = VL_RAND_RESET_I(13);
    i_hm_porch = VL_RAND_RESET_I(13);
    i_hm_synch = VL_RAND_RESET_I(13);
    i_hm_raw = VL_RAND_RESET_I(13);
    i_vm_height = VL_RAND_RESET_I(11);
    i_vm_porch = VL_RAND_RESET_I(11);
    i_vm_synch = VL_RAND_RESET_I(11);
    i_vm_raw = VL_RAND_RESET_I(11);
    o_vga_vsync = VL_RAND_RESET_I(1);
    o_vga_hsync = VL_RAND_RESET_I(1);
    o_vga_red = VL_RAND_RESET_I(8);
    o_vga_grn = VL_RAND_RESET_I(8);
    o_vga_blu = VL_RAND_RESET_I(8);
    o_interrupt = VL_RAND_RESET_I(1);
    i_vram_data = VL_RAND_RESET_I(8);
    o_vram_addr = VL_RAND_RESET_I(24);
    o_cpu_rw = VL_RAND_RESET_I(1);
    o_vga_select = VL_RAND_RESET_I(1);
    i_vga_interrupt = VL_RAND_RESET_I(1);
    o_cpu_ack = VL_RAND_RESET_I(1);
    o_cpu_a_bus = VL_RAND_RESET_I(8);
    io_cpu_d_bus = VL_RAND_RESET_I(8);
    chartest__DOT__vga_rgb = VL_RAND_RESET_I(8);
    chartest__DOT__sysclk = VL_RAND_RESET_I(1);
    chartest__DOT__o_vga_blanking = VL_RAND_RESET_I(1);
    chartest__DOT__vga_interface_0__DOT__int_bmp_a_bus = VL_RAND_RESET_I(24);
    chartest__DOT__vga_interface_0__DOT__int_txt_a_bus = VL_RAND_RESET_I(24);
    chartest__DOT__vga_interface_0__DOT__vga_mode_bmp = VL_RAND_RESET_I(1);
    chartest__DOT__vga_interface_0__DOT__vga_mode_txt = VL_RAND_RESET_I(1);
    chartest__DOT__vga_interface_0__DOT__bmp_rgb_out = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__txt_rgb_out = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__reg_scroll_x = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__reg_scroll_y = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__reg_misc_0 = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__reg_raster_lo = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__reg_raster_hi = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__out_buff = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__mod_raster_active = VL_RAND_RESET_I(1);
    chartest__DOT__vga_interface_0__DOT__px_address_x = VL_RAND_RESET_I(10);
    chartest__DOT__vga_interface_0__DOT__px_address_y = VL_RAND_RESET_I(10);
    chartest__DOT__vga_interface_0__DOT__mod_px_address_x = VL_RAND_RESET_I(10);
    chartest__DOT__vga_interface_0__DOT__mod_px_address_y = VL_RAND_RESET_I(10);
    chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out1 = VL_RAND_RESET_I(24);
    chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out2 = VL_RAND_RESET_I(24);
    chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__mem_val = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__column = VL_RAND_RESET_I(7);
    chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__row = VL_RAND_RESET_I(6);
    chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_x = VL_RAND_RESET_I(3);
    chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_y = VL_RAND_RESET_I(4);
    chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state = VL_RAND_RESET_I(1);
    chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__pixel_out = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<4096; ++__Vi0) {
	    chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__charset_rom__DOT__romdata[__Vi0] = VL_RAND_RESET_I(8);
    }}
    chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__mem_val = VL_RAND_RESET_I(8);
    chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state = VL_RAND_RESET_I(1);
    __VinpClk__TOP__chartest__DOT__sysclk = VL_RAND_RESET_I(1);
    __Vchglast__TOP__chartest__DOT__sysclk = VL_RAND_RESET_I(1);
    __Vm_traceActivity = VL_RAND_RESET_I(32);
}
