// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vchartest__Syms.h"


//======================

void Vchartest::traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vchartest* t=(Vchartest*)userthis;
    Vchartest__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (vlSymsp->getClearActivity()) {
	t->traceChgThis(vlSymsp, vcdp, code);
    }
}

//======================


void Vchartest::traceChgThis(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 2U))))) {
	    vlTOPp->traceChgThis__2(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & ((vlTOPp->__Vm_traceActivity 
				| (vlTOPp->__Vm_traceActivity 
				   >> 2U)) | (vlTOPp->__Vm_traceActivity 
					      >> 5U))))) {
	    vlTOPp->traceChgThis__3(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 3U))))) {
	    vlTOPp->traceChgThis__4(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((1U & (vlTOPp->__Vm_traceActivity 
			       | (vlTOPp->__Vm_traceActivity 
				  >> 5U))))) {
	    vlTOPp->traceChgThis__5(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((2U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__6(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((4U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__7(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((8U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__8(vlSymsp, vcdp, code);
	}
	if (VL_UNLIKELY((0x10U & vlTOPp->__Vm_traceActivity))) {
	    vlTOPp->traceChgThis__9(vlSymsp, vcdp, code);
	}
	vlTOPp->traceChgThis__10(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vchartest::traceChgThis__2(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+1,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__pixel_out));
    }
}

void Vchartest::traceChgThis__3(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+2,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state));
	vcdp->chgBit(c+3,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state));
    }
}

void Vchartest::traceChgThis__4(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus(c+4,(vlTOPp->chartest__DOT__vga_rgb),8);
	vcdp->chgBus(c+5,((vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out1 
			   | vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out2)),24);
    }
}

void Vchartest::traceChgThis__5(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+6,(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_raster_active));
	vcdp->chgBus(c+7,(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x),10);
	vcdp->chgBus(c+8,(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_y),10);
    }
}

void Vchartest::traceChgThis__6(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus(c+9,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select),8);
	vcdp->chgBus(c+10,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x),8);
	vcdp->chgBus(c+11,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y),8);
	vcdp->chgBus(c+12,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_misc_0),8);
	vcdp->chgBus(c+13,(vlTOPp->chartest__DOT__vga_interface_0__DOT__out_buff),8);
    }
}

void Vchartest::traceChgThis__7(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+14,(vlTOPp->chartest__DOT__sysclk));
	vcdp->chgBus(c+15,(vlTOPp->chartest__DOT__vga_interface_0__DOT__int_bmp_a_bus),24);
	vcdp->chgBus(c+16,(vlTOPp->chartest__DOT__vga_interface_0__DOT__int_txt_a_bus),24);
	vcdp->chgBus(c+17,(vlTOPp->chartest__DOT__vga_interface_0__DOT__bmp_rgb_out),8);
	vcdp->chgBus(c+18,(vlTOPp->chartest__DOT__vga_interface_0__DOT__txt_rgb_out),8);
	vcdp->chgBus(c+19,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__mem_val),8);
	vcdp->chgBus(c+20,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val),8);
	vcdp->chgBus(c+21,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__column),7);
	vcdp->chgBus(c+22,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__row),6);
	vcdp->chgBus(c+23,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_x),3);
	vcdp->chgBus(c+24,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_y),4);
    }
}

void Vchartest::traceChgThis__8(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBus(c+25,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config),8);
	vcdp->chgBus(c+26,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_lo),8);
	vcdp->chgBus(c+27,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_hi),8);
    }
}

void Vchartest::traceChgThis__9(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+28,((1U & ((0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
				   ? 0U : 1U))));
	vcdp->chgBit(c+29,((1U & (((0x1eaU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y)) 
				   & (0x290U > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)))
				   ? 0U : 1U))));
	vcdp->chgBus(c+30,(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x),10);
	vcdp->chgBus(c+31,(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y),10);
    }
}

void Vchartest::traceChgThis__10(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->chgBit(c+32,(vlTOPp->i_clk));
	vcdp->chgBit(c+33,(vlTOPp->i_pixclk));
	vcdp->chgBit(c+34,(vlTOPp->i_reset));
	vcdp->chgBit(c+35,(vlTOPp->i_test));
	vcdp->chgBus(c+36,(vlTOPp->i_hm_width),13);
	vcdp->chgBus(c+37,(vlTOPp->i_hm_porch),13);
	vcdp->chgBus(c+38,(vlTOPp->i_hm_synch),13);
	vcdp->chgBus(c+39,(vlTOPp->i_hm_raw),13);
	vcdp->chgBus(c+40,(vlTOPp->i_vm_height),11);
	vcdp->chgBus(c+41,(vlTOPp->i_vm_porch),11);
	vcdp->chgBus(c+42,(vlTOPp->i_vm_synch),11);
	vcdp->chgBus(c+43,(vlTOPp->i_vm_raw),11);
	vcdp->chgBit(c+44,(vlTOPp->o_vga_vsync));
	vcdp->chgBit(c+45,(vlTOPp->o_vga_hsync));
	vcdp->chgBus(c+46,(vlTOPp->o_vga_red),8);
	vcdp->chgBus(c+47,(vlTOPp->o_vga_grn),8);
	vcdp->chgBus(c+48,(vlTOPp->o_vga_blu),8);
	vcdp->chgBit(c+49,(vlTOPp->o_interrupt));
	vcdp->chgBus(c+50,(vlTOPp->i_vram_data),8);
	vcdp->chgBus(c+51,(vlTOPp->o_vram_addr),24);
	vcdp->chgBit(c+52,(vlTOPp->o_cpu_rw));
	vcdp->chgBit(c+53,(vlTOPp->o_vga_select));
	vcdp->chgBit(c+54,(vlTOPp->i_vga_interrupt));
	vcdp->chgBit(c+55,(vlTOPp->o_cpu_ack));
	vcdp->chgBus(c+56,(vlTOPp->o_cpu_a_bus),8);
	vcdp->chgBus(c+57,(vlTOPp->io_cpu_d_bus),8);
    }
}
