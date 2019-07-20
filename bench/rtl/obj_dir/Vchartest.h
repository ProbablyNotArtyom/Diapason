// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vchartest_H_
#define _Vchartest_H_

#include "verilated.h"

class Vchartest__Syms;
class VerilatedVcd;

//----------

VL_MODULE(Vchartest) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(i_clk,0,0);
    VL_IN8(i_reset,0,0);
    VL_IN8(i_pixclk,0,0);
    VL_IN8(i_test,0,0);
    VL_OUT8(o_vga_vsync,0,0);
    VL_OUT8(o_vga_hsync,0,0);
    VL_OUT8(o_vga_red,7,0);
    VL_OUT8(o_vga_grn,7,0);
    VL_OUT8(o_vga_blu,7,0);
    VL_OUT8(o_interrupt,0,0);
    VL_IN8(i_vram_data,7,0);
    VL_IN8(o_cpu_rw,0,0);
    VL_IN8(o_vga_select,0,0);
    VL_OUT8(i_vga_interrupt,0,0);
    VL_OUT8(o_cpu_ack,0,0);
    VL_IN8(o_cpu_a_bus,7,0);
    VL_IN8(io_cpu_d_bus,7,0);
    VL_IN16(i_hm_width,12,0);
    VL_IN16(i_hm_porch,12,0);
    VL_IN16(i_hm_synch,12,0);
    VL_IN16(i_hm_raw,12,0);
    VL_IN16(i_vm_height,10,0);
    VL_IN16(i_vm_porch,10,0);
    VL_IN16(i_vm_synch,10,0);
    VL_IN16(i_vm_raw,10,0);
    VL_OUT(o_vram_addr,23,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(chartest__DOT__sysclk,0,0);
    VL_SIG8(chartest__DOT__vga_rgb,7,0);
    VL_SIG8(chartest__DOT__o_vga_blanking,0,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_mode_bmp,0,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_mode_txt,0,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__bmp_rgb_out,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__txt_rgb_out,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_select,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__reg_gfx_mode_config,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__reg_scroll_x,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__reg_scroll_y,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__reg_misc_0,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__reg_raster_lo,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__reg_raster_hi,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__out_buff,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__mod_raster_active,0,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__mem_val,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__attr_val,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__column,6,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__row,5,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_x,2,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__char_y,3,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__b_state,0,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__pixel_out,0,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__mem_val,7,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_bmp_gen__DOT__b_state,0,0);
    VL_SIG16(chartest__DOT__vga_interface_0__DOT__px_address_x,9,0);
    VL_SIG16(chartest__DOT__vga_interface_0__DOT__px_address_y,9,0);
    VL_SIG16(chartest__DOT__vga_interface_0__DOT__mod_px_address_x,9,0);
    VL_SIG16(chartest__DOT__vga_interface_0__DOT__mod_px_address_y,9,0);
    VL_SIG(chartest__DOT__vga_interface_0__DOT__int_bmp_a_bus,23,0);
    VL_SIG(chartest__DOT__vga_interface_0__DOT__int_txt_a_bus,23,0);
    VL_SIG8(chartest__DOT__vga_interface_0__DOT__vga_text_gen__DOT__charset_rom__DOT__romdata[4096],7,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__VinpClk__TOP__chartest__DOT__sysclk,0,0);
    VL_SIG8(__Vclklast__TOP__i_clk,0,0);
    VL_SIG8(__Vclklast__TOP__i_reset,0,0);
    VL_SIG8(__Vclklast__TOP____VinpClk__TOP__chartest__DOT__sysclk,0,0);
    VL_SIG8(__Vchglast__TOP__chartest__DOT__sysclk,0,0);
    VL_SIG(chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out1,23,0);
    VL_SIG(chartest__DOT__vga_interface_0__DOT__int_vram_a_bus__out2,23,0);
    VL_SIG(__Vm_traceActivity,31,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vchartest__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vchartest);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vchartest(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vchartest();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options=0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vchartest__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vchartest__Syms* symsp, bool first);
  private:
    static QData _change_request(Vchartest__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vchartest__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vchartest__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vchartest__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(Vchartest__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _multiclk__TOP__7(Vchartest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vchartest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vchartest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vchartest__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vchartest__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vchartest__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void traceChgThis(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__10(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__2(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__3(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__4(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__5(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__6(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__7(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__8(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceChgThis__9(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code);
    static void traceFullThis(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceFullThis__1(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInitThis__1(Vchartest__Syms* __restrict vlSymsp, VerilatedVcd* vcdp, uint32_t code) VL_ATTR_COLD;
    static void traceInit(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceFull(VerilatedVcd* vcdp, void* userthis, uint32_t code);
    static void traceChg(VerilatedVcd* vcdp, void* userthis, uint32_t code);
} VL_ATTR_ALIGNED(128);

#endif // guard
