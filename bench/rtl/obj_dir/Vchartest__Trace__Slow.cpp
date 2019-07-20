// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vchartest__Syms.h"


//======================

void Vchartest::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addCallback(&Vchartest::traceInit, &Vchartest::traceFull, &Vchartest::traceChg, this);
}
void Vchartest::traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->open()
    Vchartest* t=(Vchartest*)userthis;
    Vchartest__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    if (!Verilated::calcUnusedSigs()) {
	VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vcdp->scopeEscape(' ');
    t->traceInitThis(vlSymsp, vcdp, code);
    vcdp->scopeEscape('.');
}
void Vchartest::traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code) {
    // Callback from vcd->dump()
    Vchartest* t=(Vchartest*)userthis;
    Vchartest__Syms* __restrict vlSymsp = t->__VlSymsp;  // Setup global symbol table
    t->traceFullThis(vlSymsp, vcdp, code);
}

//======================


void Vchartest::traceInitThis(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    vcdp->module(vlSymsp->name());  // Setup signal names
    // Body
    {
	vlTOPp->traceInitThis__1(vlSymsp, vcdp, code);
    }
}

void Vchartest::traceFullThis(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vlTOPp->traceFullThis__1(vlSymsp, vcdp, code);
    }
    // Final
    vlTOPp->__Vm_traceActivity = 0U;
}

void Vchartest::traceInitThis__1(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->declBit(c+32,"i_clk",-1);
	vcdp->declBit(c+33,"i_pixclk",-1);
	vcdp->declBit(c+34,"i_reset",-1);
	vcdp->declBit(c+35,"i_test",-1);
	vcdp->declBus(c+36,"i_hm_width",-1,12,0);
	vcdp->declBus(c+37,"i_hm_porch",-1,12,0);
	vcdp->declBus(c+38,"i_hm_synch",-1,12,0);
	vcdp->declBus(c+39,"i_hm_raw",-1,12,0);
	vcdp->declBus(c+40,"i_vm_height",-1,10,0);
	vcdp->declBus(c+41,"i_vm_porch",-1,10,0);
	vcdp->declBus(c+42,"i_vm_synch",-1,10,0);
	vcdp->declBus(c+43,"i_vm_raw",-1,10,0);
	vcdp->declBit(c+44,"o_vga_vsync",-1);
	vcdp->declBit(c+45,"o_vga_hsync",-1);
	vcdp->declBus(c+46,"o_vga_red",-1,7,0);
	vcdp->declBus(c+47,"o_vga_grn",-1,7,0);
	vcdp->declBus(c+48,"o_vga_blu",-1,7,0);
	vcdp->declBit(c+49,"o_interrupt",-1);
	vcdp->declBus(c+50,"i_vram_data",-1,7,0);
	vcdp->declBus(c+51,"o_vram_addr",-1,23,0);
	vcdp->declBit(c+52,"o_cpu_rw",-1);
	vcdp->declBit(c+53,"o_vga_select",-1);
	vcdp->declBit(c+54,"i_vga_interrupt",-1);
	vcdp->declBit(c+55,"o_cpu_ack",-1);
	vcdp->declBus(c+56,"o_cpu_a_bus",-1,7,0);
	vcdp->declBus(c+57,"io_cpu_d_bus",-1,7,0);
	vcdp->declBus(c+58,"chartest BW",-1,31,0);
	vcdp->declBus(c+59,"chartest FW",-1,31,0);
	vcdp->declBus(c+60,"chartest LW",-1,31,0);
	vcdp->declBus(c+61,"chartest AW",-1,31,0);
	vcdp->declBit(c+32,"chartest i_clk",-1);
	vcdp->declBit(c+33,"chartest i_pixclk",-1);
	vcdp->declBit(c+34,"chartest i_reset",-1);
	vcdp->declBit(c+35,"chartest i_test",-1);
	vcdp->declBus(c+36,"chartest i_hm_width",-1,12,0);
	vcdp->declBus(c+37,"chartest i_hm_porch",-1,12,0);
	vcdp->declBus(c+38,"chartest i_hm_synch",-1,12,0);
	vcdp->declBus(c+39,"chartest i_hm_raw",-1,12,0);
	vcdp->declBus(c+40,"chartest i_vm_height",-1,10,0);
	vcdp->declBus(c+41,"chartest i_vm_porch",-1,10,0);
	vcdp->declBus(c+42,"chartest i_vm_synch",-1,10,0);
	vcdp->declBus(c+43,"chartest i_vm_raw",-1,10,0);
	vcdp->declBit(c+44,"chartest o_vga_vsync",-1);
	vcdp->declBit(c+45,"chartest o_vga_hsync",-1);
	vcdp->declBus(c+46,"chartest o_vga_red",-1,7,0);
	vcdp->declBus(c+47,"chartest o_vga_grn",-1,7,0);
	vcdp->declBus(c+48,"chartest o_vga_blu",-1,7,0);
	vcdp->declBit(c+49,"chartest o_interrupt",-1);
	vcdp->declBus(c+50,"chartest i_vram_data",-1,7,0);
	vcdp->declBus(c+51,"chartest o_vram_addr",-1,23,0);
	vcdp->declBus(c+4,"chartest vga_rgb",-1,7,0);
	vcdp->declBit(c+14,"chartest sysclk",-1);
	vcdp->declBit(c+62,"chartest o_vga_blanking",-1);
	vcdp->declBit(c+52,"chartest o_cpu_rw",-1);
	vcdp->declBit(c+53,"chartest o_vga_select",-1);
	vcdp->declBit(c+54,"chartest i_vga_interrupt",-1);
	vcdp->declBit(c+55,"chartest o_cpu_ack",-1);
	vcdp->declBus(c+56,"chartest o_cpu_a_bus",-1,7,0);
	vcdp->declBus(c+57,"chartest io_cpu_d_bus",-1,7,0);
	vcdp->declBit(c+32,"chartest vga_interface_0 clk_main",-1);
	vcdp->declBit(c+34,"chartest vga_interface_0 reset_in",-1);
	vcdp->declBit(c+14,"chartest vga_interface_0 clk_system",-1);
	vcdp->declBit(c+35,"chartest vga_interface_0 cs_vgamem",-1);
	vcdp->declBus(c+51,"chartest vga_interface_0 vram_a_bus",-1,23,0);
	vcdp->declBus(c+50,"chartest vga_interface_0 vram_d_bus",-1,7,0);
	vcdp->declBus(c+56,"chartest vga_interface_0 cpu_a_bus",-1,7,0);
	vcdp->declBus(c+57,"chartest vga_interface_0 cpu_d_bus",-1,7,0);
	vcdp->declBit(c+52,"chartest vga_interface_0 cpu_rw",-1);
	vcdp->declBit(c+53,"chartest vga_interface_0 vga_select",-1);
	vcdp->declBit(c+55,"chartest vga_interface_0 cpu_ack",-1);
	vcdp->declBit(c+54,"chartest vga_interface_0 vga_interrupt",-1);
	vcdp->declBit(c+62,"chartest vga_interface_0 vga_blank",-1);
	vcdp->declBit(c+45,"chartest vga_interface_0 vga_hsync",-1);
	vcdp->declBit(c+44,"chartest vga_interface_0 vga_vsync",-1);
	vcdp->declBus(c+4,"chartest vga_interface_0 vga_rgb_out",-1,7,0);
	vcdp->declBus(c+5,"chartest vga_interface_0 int_vram_a_bus",-1,23,0);
	vcdp->declBus(c+15,"chartest vga_interface_0 int_bmp_a_bus",-1,23,0);
	vcdp->declBus(c+16,"chartest vga_interface_0 int_txt_a_bus",-1,23,0);
	vcdp->declBit(c+63,"chartest vga_interface_0 vga_mode_bmp",-1);
	vcdp->declBit(c+64,"chartest vga_interface_0 vga_mode_txt",-1);
	vcdp->declBus(c+17,"chartest vga_interface_0 bmp_rgb_out",-1,7,0);
	vcdp->declBus(c+18,"chartest vga_interface_0 txt_rgb_out",-1,7,0);
	vcdp->declBus(c+9,"chartest vga_interface_0 reg_gfx_mode_select",-1,7,0);
	vcdp->declBus(c+25,"chartest vga_interface_0 reg_gfx_mode_config",-1,7,0);
	vcdp->declBus(c+10,"chartest vga_interface_0 reg_scroll_x",-1,7,0);
	vcdp->declBus(c+11,"chartest vga_interface_0 reg_scroll_y",-1,7,0);
	vcdp->declBus(c+12,"chartest vga_interface_0 reg_misc_0",-1,7,0);
	vcdp->declBus(c+26,"chartest vga_interface_0 reg_raster_lo",-1,7,0);
	vcdp->declBus(c+27,"chartest vga_interface_0 reg_raster_hi",-1,7,0);
	vcdp->declBus(c+13,"chartest vga_interface_0 out_buff",-1,7,0);
	vcdp->declBit(c+28,"chartest vga_interface_0 raster_visible",-1);
	vcdp->declBit(c+29,"chartest vga_interface_0 raster_active",-1);
	vcdp->declBit(c+6,"chartest vga_interface_0 mod_raster_active",-1);
	vcdp->declBus(c+30,"chartest vga_interface_0 px_address_x",-1,9,0);
	vcdp->declBus(c+31,"chartest vga_interface_0 px_address_y",-1,9,0);
	vcdp->declBus(c+7,"chartest vga_interface_0 mod_px_address_x",-1,9,0);
	vcdp->declBus(c+8,"chartest vga_interface_0 mod_px_address_y",-1,9,0);
	vcdp->declBit(c+32,"chartest vga_interface_0 clkgen_stage_1 clk_in",-1);
	vcdp->declBit(c+34,"chartest vga_interface_0 clkgen_stage_1 reset_in",-1);
	vcdp->declBit(c+14,"chartest vga_interface_0 clkgen_stage_1 clk_out",-1);
	vcdp->declBit(c+14,"chartest vga_interface_0 vga_sync_gen clk",-1);
	vcdp->declBit(c+34,"chartest vga_interface_0 vga_sync_gen reset",-1);
	vcdp->declBit(c+45,"chartest vga_interface_0 vga_sync_gen hsync_out",-1);
	vcdp->declBit(c+44,"chartest vga_interface_0 vga_sync_gen vsync_out",-1);
	vcdp->declBit(c+28,"chartest vga_interface_0 vga_sync_gen raster_visible",-1);
	vcdp->declBit(c+29,"chartest vga_interface_0 vga_sync_gen active",-1);
	vcdp->declBus(c+30,"chartest vga_interface_0 vga_sync_gen raster_x",-1,9,0);
	vcdp->declBus(c+31,"chartest vga_interface_0 vga_sync_gen raster_y",-1,9,0);
	vcdp->declBus(c+65,"chartest vga_interface_0 vga_sync_gen X_RES",-1,31,0);
	vcdp->declBus(c+66,"chartest vga_interface_0 vga_sync_gen Y_RES",-1,31,0);
	vcdp->declBus(c+67,"chartest vga_interface_0 vga_sync_gen hpixels",-1,31,0);
	vcdp->declBus(c+68,"chartest vga_interface_0 vga_sync_gen vlines",-1,31,0);
	vcdp->declBus(c+69,"chartest vga_interface_0 vga_sync_gen hpulse",-1,31,0);
	vcdp->declBus(c+70,"chartest vga_interface_0 vga_sync_gen vpulse",-1,31,0);
	vcdp->declBus(c+71,"chartest vga_interface_0 vga_sync_gen hbp",-1,31,0);
	vcdp->declBus(c+72,"chartest vga_interface_0 vga_sync_gen hfp",-1,31,0);
	vcdp->declBus(c+73,"chartest vga_interface_0 vga_sync_gen vbp",-1,31,0);
	vcdp->declBus(c+74,"chartest vga_interface_0 vga_sync_gen vfp",-1,31,0);
	vcdp->declBit(c+32,"chartest vga_interface_0 vga_text_gen clk_in",-1);
	vcdp->declBit(c+6,"chartest vga_interface_0 vga_text_gen active",-1);
	vcdp->declBus(c+7,"chartest vga_interface_0 vga_text_gen raster_x",-1,9,0);
	vcdp->declBus(c+8,"chartest vga_interface_0 vga_text_gen raster_y",-1,9,0);
	vcdp->declBus(c+25,"chartest vga_interface_0 vga_text_gen mode_config",-1,7,0);
	vcdp->declBus(c+18,"chartest vga_interface_0 vga_text_gen rgb_out",-1,7,0);
	vcdp->declBus(c+16,"chartest vga_interface_0 vga_text_gen address_out",-1,23,0);
	vcdp->declBus(c+50,"chartest vga_interface_0 vga_text_gen data_in",-1,7,0);
	vcdp->declBus(c+19,"chartest vga_interface_0 vga_text_gen mem_val",-1,7,0);
	vcdp->declBus(c+20,"chartest vga_interface_0 vga_text_gen attr_val",-1,7,0);
	vcdp->declBus(c+21,"chartest vga_interface_0 vga_text_gen column",-1,6,0);
	vcdp->declBus(c+22,"chartest vga_interface_0 vga_text_gen row",-1,5,0);
	vcdp->declBus(c+23,"chartest vga_interface_0 vga_text_gen char_x",-1,2,0);
	vcdp->declBus(c+24,"chartest vga_interface_0 vga_text_gen char_y",-1,3,0);
	vcdp->declBit(c+2,"chartest vga_interface_0 vga_text_gen b_state",-1);
	vcdp->declBit(c+1,"chartest vga_interface_0 vga_text_gen pixel_out",-1);
	vcdp->declBit(c+32,"chartest vga_interface_0 vga_text_gen charset_rom clk",-1);
	vcdp->declBus(c+19,"chartest vga_interface_0 vga_text_gen charset_rom ascii_in",-1,7,0);
	vcdp->declBus(c+23,"chartest vga_interface_0 vga_text_gen charset_rom col",-1,2,0);
	vcdp->declBus(c+24,"chartest vga_interface_0 vga_text_gen charset_rom row",-1,3,0);
	vcdp->declBit(c+1,"chartest vga_interface_0 vga_text_gen charset_rom bit_out",-1);
	// Tracing: chartest vga_interface_0 vga_text_gen charset_rom romdata // Ignored: Wide memory > --trace-max-array ents at ../../VGA_CTL.v:199
	vcdp->declBit(c+32,"chartest vga_interface_0 vga_bmp_gen clk_in",-1);
	vcdp->declBit(c+6,"chartest vga_interface_0 vga_bmp_gen active",-1);
	vcdp->declBus(c+7,"chartest vga_interface_0 vga_bmp_gen raster_x",-1,9,0);
	vcdp->declBus(c+8,"chartest vga_interface_0 vga_bmp_gen raster_y",-1,9,0);
	vcdp->declBus(c+25,"chartest vga_interface_0 vga_bmp_gen mode_config",-1,7,0);
	vcdp->declBus(c+17,"chartest vga_interface_0 vga_bmp_gen rgb_out",-1,7,0);
	vcdp->declBus(c+15,"chartest vga_interface_0 vga_bmp_gen address_out",-1,23,0);
	vcdp->declBus(c+50,"chartest vga_interface_0 vga_bmp_gen data_in",-1,7,0);
	vcdp->declBus(c+75,"chartest vga_interface_0 vga_bmp_gen mem_val",-1,7,0);
	vcdp->declBit(c+3,"chartest vga_interface_0 vga_bmp_gen b_state",-1);
    }
}

void Vchartest::traceFullThis__1(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) {
    Vchartest* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    int c=code;
    if (0 && vcdp && c) {}  // Prevent unused
    // Body
    {
	vcdp->fullBit(c+1,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__pixel_out));
	vcdp->fullBit(c+2,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state));
	vcdp->fullBit(c+3,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state));
	vcdp->fullBus(c+4,(vlTOPp->chartest__DOT__vga_rgb),8);
	vcdp->fullBus(c+5,((vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out1 
			    | vlTOPp->chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out2)),24);
	vcdp->fullBit(c+6,(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_raster_active));
	vcdp->fullBus(c+7,(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_x),10);
	vcdp->fullBus(c+8,(vlTOPp->chartest__DOT__vga_interface_0__DOT__mod_px_address_y),10);
	vcdp->fullBus(c+9,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select),8);
	vcdp->fullBus(c+10,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_x),8);
	vcdp->fullBus(c+11,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_scroll_y),8);
	vcdp->fullBus(c+12,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_misc_0),8);
	vcdp->fullBus(c+13,(vlTOPp->chartest__DOT__vga_interface_0__DOT__out_buff),8);
	vcdp->fullBit(c+14,(vlTOPp->chartest__DOT__sysclk));
	vcdp->fullBus(c+15,(vlTOPp->chartest__DOT__vga_interface_0__DOT__int_bmp_a_bus),24);
	vcdp->fullBus(c+16,(vlTOPp->chartest__DOT__vga_interface_0__DOT__int_txt_a_bus),24);
	vcdp->fullBus(c+17,(vlTOPp->chartest__DOT__vga_interface_0__DOT__bmp_rgb_out),8);
	vcdp->fullBus(c+18,(vlTOPp->chartest__DOT__vga_interface_0__DOT__txt_rgb_out),8);
	vcdp->fullBus(c+19,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__mem_val),8);
	vcdp->fullBus(c+20,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val),8);
	vcdp->fullBus(c+21,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__column),7);
	vcdp->fullBus(c+22,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__row),6);
	vcdp->fullBus(c+23,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_x),3);
	vcdp->fullBus(c+24,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_y),4);
	vcdp->fullBus(c+25,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config),8);
	vcdp->fullBus(c+26,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_lo),8);
	vcdp->fullBus(c+27,(vlTOPp->chartest__DOT__vga_interface_0__DOT__reg_raster_hi),8);
	vcdp->fullBit(c+28,((1U & ((0x1ecU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y))
				    ? 0U : 1U))));
	vcdp->fullBit(c+29,((1U & (((0x1eaU > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y)) 
				    & (0x290U > (IData)(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x)))
				    ? 0U : 1U))));
	vcdp->fullBus(c+30,(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_x),10);
	vcdp->fullBus(c+31,(vlTOPp->chartest__DOT__vga_interface_0__DOT__px_address_y),10);
	vcdp->fullBit(c+32,(vlTOPp->i_clk));
	vcdp->fullBit(c+33,(vlTOPp->i_pixclk));
	vcdp->fullBit(c+34,(vlTOPp->i_reset));
	vcdp->fullBit(c+35,(vlTOPp->i_test));
	vcdp->fullBus(c+36,(vlTOPp->i_hm_width),13);
	vcdp->fullBus(c+37,(vlTOPp->i_hm_porch),13);
	vcdp->fullBus(c+38,(vlTOPp->i_hm_synch),13);
	vcdp->fullBus(c+39,(vlTOPp->i_hm_raw),13);
	vcdp->fullBus(c+40,(vlTOPp->i_vm_height),11);
	vcdp->fullBus(c+41,(vlTOPp->i_vm_porch),11);
	vcdp->fullBus(c+42,(vlTOPp->i_vm_synch),11);
	vcdp->fullBus(c+43,(vlTOPp->i_vm_raw),11);
	vcdp->fullBit(c+44,(vlTOPp->o_vga_vsync));
	vcdp->fullBit(c+45,(vlTOPp->o_vga_hsync));
	vcdp->fullBus(c+46,(vlTOPp->o_vga_red),8);
	vcdp->fullBus(c+47,(vlTOPp->o_vga_grn),8);
	vcdp->fullBus(c+48,(vlTOPp->o_vga_blu),8);
	vcdp->fullBit(c+49,(vlTOPp->o_interrupt));
	vcdp->fullBus(c+50,(vlTOPp->i_vram_data),8);
	vcdp->fullBus(c+51,(vlTOPp->o_vram_addr),24);
	vcdp->fullBit(c+52,(vlTOPp->o_cpu_rw));
	vcdp->fullBit(c+53,(vlTOPp->o_vga_select));
	vcdp->fullBit(c+54,(vlTOPp->i_vga_interrupt));
	vcdp->fullBit(c+55,(vlTOPp->o_cpu_ack));
	vcdp->fullBus(c+56,(vlTOPp->o_cpu_a_bus),8);
	vcdp->fullBus(c+57,(vlTOPp->io_cpu_d_bus),8);
	vcdp->fullBus(c+58,(0x20U),32);
	vcdp->fullBus(c+59,(0xdU),32);
	vcdp->fullBus(c+60,(0xbU),32);
	vcdp->fullBus(c+61,(0x18U),32);
	vcdp->fullBit(c+62,(vlTOPp->chartest__DOT__o_vga_blanking));
	vcdp->fullBit(c+63,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_mode_bmp));
	vcdp->fullBit(c+64,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_mode_txt));
	vcdp->fullBus(c+65,(0x280U),32);
	vcdp->fullBus(c+66,(0x1e0U),32);
	vcdp->fullBus(c+67,(0x320U),32);
	vcdp->fullBus(c+68,(0x209U),32);
	vcdp->fullBus(c+69,(0x60U),32);
	vcdp->fullBus(c+70,(2U),32);
	vcdp->fullBus(c+71,(0x2f0U),32);
	vcdp->fullBus(c+72,(0x290U),32);
	vcdp->fullBus(c+73,(0x1ecU),32);
	vcdp->fullBus(c+74,(0x1eaU),32);
	vcdp->fullBus(c+75,(vlTOPp->chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__mem_val),8);
    }
}
