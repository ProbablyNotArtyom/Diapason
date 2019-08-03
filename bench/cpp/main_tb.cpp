////////////////////////////////////////////////////////////////////////////////
//
// Filename:	main_tb.cpp
//
// Project:	vgasim, a Verilator based VGA simulator demonstration
//
// Purpose:	This is the main test bench class that holds all the pieces
//		together.  In this case, the test bench consists of little
//	more than a video simulator.
//
// Creator:	Dan Gisselquist, Ph.D.
//		Gisselquist Technology, LLC
//
////////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2017, Gisselquist Technology, LLC
//
// This program is free software (firmware): you can redistribute it and/or
// modify it under the terms of  the GNU General Public License as published
// by the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTIBILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program.  (It's in the $(ROOT)/doc directory.  Run make with no
// target there if the PDF file isn't present.)  If not, see
// <http://www.gnu.org/licenses/> for a copy.
//
// License:	GPL, v3, as defined and found on www.gnu.org,
//		http://www.gnu.org/licenses/gpl.html
//
//
////////////////////////////////////////////////////////////////////////////////
//
//
#include <signal.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <math.h>
#include <iostream>
#include <fstream>

#include "verilated.h"
#include "Vchartest.h"

#include "testb.h"
// #include "twoc.h"
#include "vgasim.h"

#ifdef	NEW_VERILATOR
#define	VVAR(A)	busmaster__DOT_ ## A
#else
#define	VVAR(A)	v__DOT_ ## A
#endif

extern uint8_t _binary___test_data_size[];
extern uint8_t _binary___test_data_end[];
extern uint8_t _binary___test_data_start[];

uint8_t		static_gfx_cfg = 0;
int 		bus_test_mode = 0;
bool 		do_debug = false;
const char *vram_preload = {
		"The 601 is the first implementation of the PowerPC family of RISC microprocessors. The 601 implements the 32-bit portion of the PowerPC architecture, which provides 32-bit effective addresses, integer data types of 8, 16, and 32 bits, and floating-point data types of 32 and 64 bits. For 64-bit PowerPC implementations, the PowerPC architecture provides 64-bit integer data types, 64-bit addressing, and other features required to complete the 64-bit architecture. The 601 is a superscalar processor capable of issuing and retiring three instructions per clock, one to each of three execution units. Instructions can complete out of order for increased performance; however, the 601 makes execution appear sequential. The 601 integrates three execution units—an integer unit (IU), a branch processing unit (BPU), and a floating-point unit (FPU). The ability to execute three instructions in parallel and the use of simple instructions with rapid execution times yield high efficiency and throughput for 601-based systems. Most integer instructions execute in one clock cycle. The FPU is pipelined so a single-precision multiply-add instruction can be issued every clock cycle. The 601 provides an on-chip, 32-Kbyte, eight-way set-associative, physically addressed, unified instruction and data cache and an on-chip memory management unit (MMU). The MMU contains a 256-entry, two-way set-associative, unified translation lookaside buffer (UTLB) and provides support for demand-paged virtual memory address translation and variable-sized block translation. Both the UTLB and the cache use least recently used (LRU) replacement algorithms. The 601 has a 64-bit data bus and a 32-bit address bus. The 601 interface protocol allows multiple masters to compete for system resources through a central external arbiter. Additionally, on-chip snooping logic maintains cache coherency in multiprocessor applications. The 601 supports single-beat and burst data transfers for memory accesses; it also supports both memory-mapped I/O and direct-store addressing. The 601 uses an advanced CMOS (complementary metal-oxide semiconductor) process technology and maintains full interface compatibility with TTL devices. The 601v is functionally equivalent to the 601, but operates with reduced internal voltages and with reduced power dissipation. "
};
uint8_t  sine_wave[256] = {
  0x80, 0x83, 0x86, 0x89, 0x8C, 0x90, 0x93, 0x96,
  0x99, 0x9C, 0x9F, 0xA2, 0xA5, 0xA8, 0xAB, 0xAE,
  0xB1, 0xB3, 0xB6, 0xB9, 0xBC, 0xBF, 0xC1, 0xC4,
  0xC7, 0xC9, 0xCC, 0xCE, 0xD1, 0xD3, 0xD5, 0xD8,
  0xDA, 0xDC, 0xDE, 0xE0, 0xE2, 0xE4, 0xE6, 0xE8,
  0xEA, 0xEB, 0xED, 0xEF, 0xF0, 0xF1, 0xF3, 0xF4,
  0xF5, 0xF6, 0xF8, 0xF9, 0xFA, 0xFA, 0xFB, 0xFC,
  0xFD, 0xFD, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFE, 0xFD,
  0xFD, 0xFC, 0xFB, 0xFA, 0xFA, 0xF9, 0xF8, 0xF6,
  0xF5, 0xF4, 0xF3, 0xF1, 0xF0, 0xEF, 0xED, 0xEB,
  0xEA, 0xE8, 0xE6, 0xE4, 0xE2, 0xE0, 0xDE, 0xDC,
  0xDA, 0xD8, 0xD5, 0xD3, 0xD1, 0xCE, 0xCC, 0xC9,
  0xC7, 0xC4, 0xC1, 0xBF, 0xBC, 0xB9, 0xB6, 0xB3,
  0xB1, 0xAE, 0xAB, 0xA8, 0xA5, 0xA2, 0x9F, 0x9C,
  0x99, 0x96, 0x93, 0x90, 0x8C, 0x89, 0x86, 0x83,
  0x80, 0x7D, 0x7A, 0x77, 0x74, 0x70, 0x6D, 0x6A,
  0x67, 0x64, 0x61, 0x5E, 0x5B, 0x58, 0x55, 0x52,
  0x4F, 0x4D, 0x4A, 0x47, 0x44, 0x41, 0x3F, 0x3C,
  0x39, 0x37, 0x34, 0x32, 0x2F, 0x2D, 0x2B, 0x28,
  0x26, 0x24, 0x22, 0x20, 0x1E, 0x1C, 0x1A, 0x18,
  0x16, 0x15, 0x13, 0x11, 0x10, 0x0F, 0x0D, 0x0C,
  0x0B, 0x0A, 0x08, 0x07, 0x06, 0x06, 0x05, 0x04,
  0x03, 0x03, 0x02, 0x02, 0x02, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x03,
  0x03, 0x04, 0x05, 0x06, 0x06, 0x07, 0x08, 0x0A,
  0x0B, 0x0C, 0x0D, 0x0F, 0x10, 0x11, 0x13, 0x15,
  0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24,
  0x26, 0x28, 0x2B, 0x2D, 0x2F, 0x32, 0x34, 0x37,
  0x39, 0x3C, 0x3F, 0x41, 0x44, 0x47, 0x4A, 0x4D,
  0x4F, 0x52, 0x55, 0x58, 0x5B, 0x5E, 0x61, 0x64,
  0x67, 0x6A, 0x6D, 0x70, 0x74, 0x77, 0x7A, 0x7D
};

vluint64_t main_time = 0;	// Current simulation time (64-bit unsigned)
char *vram_mem_array;
double sc_time_stamp () {	// Called by $time in Verilog
    return main_time;		// Note does conversion to real, to match SystemC
}

// No particular "parameters" need definition or redefinition here.
class	TESTBENCH : public TESTB<Vchartest> {
public:
	unsigned long	m_tx_busy_count;
	bool		m_done, m_test;
	int			m_written_configs = 0;
	int			m_irq_count = 0;
	bool		m_irq_cycle = false;

	VGAWIN		m_vga;

	void	init(void) {
		m_core->i_hm_width  = m_vga.width();
		m_core->i_hm_porch  = m_vga.hporch();
		m_core->i_hm_synch  = m_vga.hsync();
		m_core->i_hm_raw    = m_vga.raw_width();
		//
		m_core->i_vm_height = m_vga.height();
		m_core->i_vm_porch  = m_vga.vporch();
		m_core->i_vm_synch  = m_vga.vsync();
		m_core->i_vm_raw    = m_vga.raw_height();
		//
		m_core->i_test      = (m_test) ? 1 : 0;
		//
		m_done = false;

		Glib::signal_idle().connect(sigc::mem_fun((*this),&TESTBENCH::on_tick));

	}
public:

	TESTBENCH(void) : m_test(false), m_vga(640, 480) {
		init();
	}

	TESTBENCH(int hres, int vres) : m_test(false), m_vga(hres, vres) {
		init();
	}

	void	trace(const char *vcd_trace_file_name) {
		fprintf(stderr, "Opening TRACE(%s)\n", vcd_trace_file_name);
		opentrace(vcd_trace_file_name);
	}

	void	close(void) {
		// TESTB<BASECLASS>::closetrace();
		m_done = true;
	}

	void	test_input(bool test_data) {
		m_test = test_data;
		m_core->i_test = (m_test) ? 1:0;
	}

#define		B_READ			1
#define		B_WRITE			0
#define 	bus_cycle(a, b, c)		\
	m_core->o_cpu_a_bus = a;   		\
	m_core->io_cpu_d_bus = b;  		\
	m_core->o_vga_select = 0;     	\
	m_core->o_cpu_rw = c;
#define 	u16_get_hi(val)		(uint8_t)((val >> 8) & 0x00FF)
#define 	u16_get_lo(val)		(uint8_t)(val & 0x00FF)

//=========================== RASTER SPLITS ===========================

#define		GFX_BMP		1
#define		GFX_TXT		0

#define 	GCFG_LOWRES_X 	0b00000001
#define 	GCFG_LOWRES_Y	0b00000010

uint32_t	total_frames = 0;

//---------------------------------------------------------------------

uint16_t	i0_split_end = 120;
uint16_t	i1_split_end = 240;
uint16_t	i2_split_end = 360;
uint16_t	i3_split_end = 482;

uint8_t		i0_scroll_x = 0,		i0_x_inc = 0;
uint8_t		i0_scroll_y = 0,		i0_y_inc = 0;
uint8_t		i0_gfx_mode = GFX_TXT;
uint8_t 	i0_gfx_cfg  = 0;

uint8_t		i1_scroll_x = 0,		i1_x_inc = 1;
uint8_t		i1_scroll_y = 0,		i1_y_inc = 3;
uint8_t		i1_gfx_mode = GFX_BMP;
uint8_t 	i1_gfx_cfg  = GCFG_LOWRES_X;

uint8_t		i2_scroll_x = 0,		i2_x_inc = 0;
uint8_t		i2_scroll_y = 0,		i2_y_inc = 0;
uint8_t		i2_gfx_mode = GFX_TXT;
uint8_t 	i2_gfx_cfg  = 0;

uint8_t		i3_scroll_x = 0,		i3_x_inc = 2;
uint8_t		i3_scroll_y = 0,		i3_y_inc = 1;
uint8_t		i3_gfx_mode = GFX_BMP;
uint8_t 	i3_gfx_cfg  = GCFG_LOWRES_X | GCFG_LOWRES_Y;


uint8_t 	tektek_scroll = 0;

//=====================================================================

// Delay the first bus cycle by however many frames
#define		BUS_CYCLE_DELAY	0
char		vsync_state_last = 0;
char		blank_state_last = 0;
int			bustest_delay_start = BUS_CYCLE_DELAY;
uint16_t 	scanline = 0;
uint16_t 	next_raster = 0;

	void 	tick(void) {
		if (m_done)
			return;

		m_vga((m_core->o_vga_vsync)?1:0, (m_core->o_vga_hsync)?1:0,
			m_core->o_vga_red,
			m_core->o_vga_grn,
			m_core->o_vga_blu);

		if (blank_state_last == 0 && m_core->o_vga_blanking == 1) {
			blank_state_last = 1;
			total_frames++;
		} else if (blank_state_last == 1 && m_core->o_vga_blanking == 0) {
			blank_state_last = 0;
		}

		if (m_core->o_vga_blanking == 1) {
			scanline = 0;
			vsync_state_last = 0;
			if (bus_test_mode == 3) {
				m_irq_count = 0;
				tektek_scroll = total_frames;
			}
		} else if (vsync_state_last == 0 && m_core->o_vga_hsync == 1) {
			scanline = (scanline > 480)? 0 : scanline + 1;
			vsync_state_last = 1;
		} else if (vsync_state_last == 1 && m_core->o_vga_hsync == 0) {
			vsync_state_last = 0;
		}
		next_raster = scanline+1;

		/* write the specified data only once, just after startup */
		if (m_core->o_cpu_ack == 1) {
			if (m_core->i_vga_interrupt == 0) {
				m_irq_cycle = true;
				if (m_irq_count == 0)
					m_written_configs = 200;
			}

//===================================== Bus Test Mode 0 =====================================

			if (bus_test_mode == 0) {
				if (m_written_configs == 0){ 		bus_cycle(0, GFX_BMP, B_WRITE);}
				else if (m_written_configs == 1){ 	bus_cycle(5, 0, B_WRITE);}
				else if (m_written_configs == 2){ 	bus_cycle(6, 0, B_WRITE);}
				else if (m_written_configs == 3){	bus_cycle(2, 0, B_WRITE);}
				else if (m_written_configs == 4){	bus_cycle(3, 0, B_WRITE);}
				else if (m_written_configs == 5){	bus_cycle(1, static_gfx_cfg, B_WRITE);}

//===================================== Bus Test Mode 1 =====================================

			} else if (bus_test_mode == 1) {
				if (m_written_configs == 0){ 		bus_cycle(0, GFX_TXT, B_WRITE);}
				else if (m_written_configs == 1){ 	bus_cycle(5, 0, B_WRITE);}
				else if (m_written_configs == 2){ 	bus_cycle(6, 0, B_WRITE);}
				else if (m_written_configs == 3){	bus_cycle(2, 0, B_WRITE);}
				else if (m_written_configs == 4){	bus_cycle(3, 0, B_WRITE);}
				else if (m_written_configs == 5){	bus_cycle(1, static_gfx_cfg, B_WRITE);}

//===================================== Bus Test Mode 2 =====================================

			} else if (bus_test_mode == 2) {
				if (m_written_configs == 0){ 		bus_cycle(0, i0_gfx_mode, B_WRITE);}
				else if (m_written_configs == 1){ 	bus_cycle(5, u16_get_lo(i0_split_end), B_WRITE);}
				else if (m_written_configs == 2){ 	bus_cycle(6, u16_get_hi(i0_split_end), B_WRITE);}
				else if (m_written_configs == 3){	bus_cycle(2, i0_scroll_x+=i0_x_inc, B_WRITE);}
				else if (m_written_configs == 4){	bus_cycle(3, i0_scroll_y+=i0_y_inc, B_WRITE);}
				else if (m_written_configs == 5){ 	bus_cycle(4, 0b01000000, B_WRITE);}

				if (m_irq_cycle == true) {
					if (m_written_configs == 200){ 		bus_cycle(4, 0, B_READ);}
					else if (m_written_configs == 201){ bus_cycle(5, u16_get_lo(i0_split_end), B_WRITE);}
					else if (m_written_configs == 202){ bus_cycle(6, u16_get_hi(i0_split_end), B_WRITE);}
					else if (m_written_configs == 203){	bus_cycle(2, i0_scroll_x+=i0_x_inc, B_WRITE);}
					else if (m_written_configs == 204){	bus_cycle(3, i0_scroll_y+=i0_y_inc, B_WRITE);}
					else if (m_written_configs == 205){	bus_cycle(0, i0_gfx_mode, B_WRITE);}
					else if (m_written_configs == 206){	bus_cycle(1, i0_gfx_cfg, B_WRITE);}
					else if (m_written_configs == 207){	m_written_configs = 250;}
					else if (m_written_configs == 250) {
						m_written_configs = 300;
						m_irq_cycle = false;
						if (do_debug)
							printf("(0) scroll_x: %02X, scroll_y: %02X   ", i0_scroll_x, i0_scroll_y);
					}

					else if (m_written_configs == 300){ bus_cycle(4, 0, B_READ);}
					else if (m_written_configs == 301){ bus_cycle(5, u16_get_lo(i1_split_end), B_WRITE);}
					else if (m_written_configs == 302){ bus_cycle(6, u16_get_hi(i1_split_end), B_WRITE);}
					else if (m_written_configs == 303){	bus_cycle(2, i1_scroll_x+=i1_x_inc, B_WRITE);}
					else if (m_written_configs == 304){	bus_cycle(3, i1_scroll_y+=i1_y_inc, B_WRITE);}
					else if (m_written_configs == 305){	bus_cycle(0, i1_gfx_mode, B_WRITE);}
					else if (m_written_configs == 306){	bus_cycle(1, i1_gfx_cfg, B_WRITE);}
					else if (m_written_configs == 307){	m_written_configs = 350;}
					else if (m_written_configs == 350) {
						m_written_configs = 400;
						m_irq_cycle = false;
						if (do_debug)
							printf("(1) scroll_x: %02X, scroll_y: %02X   ", i1_scroll_x, i1_scroll_y);
					}

					else if (m_written_configs == 400){ bus_cycle(4, 0, B_READ);}
					else if (m_written_configs == 401){ bus_cycle(5, u16_get_lo(i2_split_end), B_WRITE);}
					else if (m_written_configs == 402){ bus_cycle(6, u16_get_hi(i2_split_end), B_WRITE);}
					else if (m_written_configs == 403){	bus_cycle(2, i2_scroll_x+=i2_x_inc, B_WRITE);}
					else if (m_written_configs == 404){	bus_cycle(3, i2_scroll_y+=i2_y_inc, B_WRITE);}
					else if (m_written_configs == 405){	bus_cycle(0, i2_gfx_mode, B_WRITE);}
					else if (m_written_configs == 406){	bus_cycle(1, i2_gfx_cfg, B_WRITE);}
					else if (m_written_configs == 407){	m_written_configs = 450;}
					else if (m_written_configs == 450) {
						m_written_configs = 500;
						m_irq_cycle = false;
						if (do_debug)
							printf("(2) scroll_x: %02X, scroll_y: %02X   ", i2_scroll_x, i2_scroll_y);
					}

					else if (m_written_configs == 500){ bus_cycle(4, 0, B_READ);}
					else if (m_written_configs == 501){ bus_cycle(5, u16_get_lo(i3_split_end), B_WRITE);}
					else if (m_written_configs == 502){ bus_cycle(6, u16_get_hi(i3_split_end), B_WRITE);}
					else if (m_written_configs == 503){	bus_cycle(2, i3_scroll_x+=i3_x_inc, B_WRITE);}
					else if (m_written_configs == 504){	bus_cycle(3, i3_scroll_y+=i3_y_inc, B_WRITE);}
					else if (m_written_configs == 505){	bus_cycle(0, i3_gfx_mode, B_WRITE);}
					else if (m_written_configs == 506){	bus_cycle(1, i3_gfx_cfg++, B_WRITE);}
					else if (m_written_configs == 507){	m_written_configs = 550;}
					else if (m_written_configs == 550) {
						m_written_configs = 200;
						m_irq_cycle = false;
						if (do_debug)
							printf("(3) scroll_x: %02X, scroll_y: %02X\n", i3_scroll_x, i3_scroll_y);
					}
				}

//===================================== Bus Test Mode 3 =====================================

			} else if (bus_test_mode == 3) {
				if (m_written_configs == 0){ 		bus_cycle(0, GFX_BMP, B_WRITE);}
				else if (m_written_configs == 1){ 	bus_cycle(5, u16_get_lo(next_raster), B_WRITE);}
				else if (m_written_configs == 2){ 	bus_cycle(6, u16_get_hi(next_raster), B_WRITE);}
				else if (m_written_configs == 3){	bus_cycle(2, 0, B_WRITE);}
				else if (m_written_configs == 4){	bus_cycle(3, 0, B_WRITE);}
				else if (m_written_configs == 5){ 	bus_cycle(4, 0b01000000, B_WRITE);}

				if (m_irq_cycle == true) {
					if (m_written_configs == 200){ 		bus_cycle(4, 0, B_READ);}
					else if (m_written_configs == 201){ bus_cycle(5, u16_get_lo(next_raster), B_WRITE);}
					else if (m_written_configs == 202){ bus_cycle(6, u16_get_hi(next_raster), B_WRITE);}
					else if (m_written_configs == 203){	bus_cycle(2, sine_wave[tektek_scroll]/2, B_WRITE);}
					else if (m_written_configs == 204){	bus_cycle(3, 0, B_WRITE);}
					else if (m_written_configs == 205){	bus_cycle(0, GFX_BMP, B_WRITE);}
					else if (m_written_configs == 206){	bus_cycle(1, 0, B_WRITE);}
					else if (m_written_configs == 207){	m_written_configs = 250;}
					else if (m_written_configs == 250) {
						m_written_configs = 500;
						m_irq_cycle = false;
						if (do_debug)
							printf("(0) next_raster: %d, bval: 0x%02X%02X\n", next_raster, u16_get_hi(next_raster), u16_get_lo(next_raster));
					}

					else if (m_written_configs == 500){ bus_cycle(4, 0, B_READ);}
					else if (m_written_configs == 501){ bus_cycle(5, u16_get_lo(next_raster), B_WRITE);}
					else if (m_written_configs == 502){ bus_cycle(6, u16_get_hi(next_raster), B_WRITE);}
					else if (m_written_configs == 503){	bus_cycle(2, sine_wave[tektek_scroll++]/2, B_WRITE);}
					else if (m_written_configs == 504){	bus_cycle(3, 0, B_WRITE);}
					else if (m_written_configs == 505){	bus_cycle(0, GFX_BMP, B_WRITE);}
					else if (m_written_configs == 506){	bus_cycle(1, 0, B_WRITE);}
					else if (m_written_configs == 507){	m_written_configs = 550;}
					else if (m_written_configs == 550) {
						m_written_configs = 200;
						m_irq_cycle = false;
						if (do_debug)
							printf("(1) next_raster: %d, bval: 0x%02X%02X\n", next_raster, u16_get_hi(next_raster), u16_get_lo(next_raster));
					}
				}
			}
		}

		m_core->i_vram_data = vram_mem_array[m_core->o_vram_addr];
		TESTB<Vchartest>::tick();
		m_core->i_vram_data = vram_mem_array[m_core->o_vram_addr];
		TESTB<Vchartest>::tick();

		/* once the VGA controller sees our bus request it will pull ACK low */
		/* after that, its safe to end the bus cycle */
		if (m_core->o_cpu_ack == 0) {
			m_core->o_cpu_a_bus = 0x00;
			m_core->io_cpu_d_bus = 0x00;
			m_core->o_vga_select = 1;
			m_core->o_cpu_rw = 1;
			m_written_configs++;
			if (m_irq_cycle == true)
				m_irq_count = 1;
		}
	}

	bool	on_tick(void) {
		for(int i=0; i<5; i++)
			tick();
		return true;
	}
};

TESTBENCH	*tb;

const char *helptxt = {
	"\n"
	"Diapason Verilog VGA controller core, simulated using verilator.\n"
	"From NotArtyom 2019\n"
	"\t-b <val>              Sets the bus cycle testing mode. Setting this option ignores all others:\n"
	"\t                         00 : 320x240x8 bitmap mode, Fullscreen\n"
	"\t                         01 : 80x30 textmode, Fullscreen\n"
	"\t                         02 : 4-way raster-split\n"
	"\t                         03 : interlaced text & video raster\n"
	"\t-d                    enables debug status output.\n"
	"\t-h                    displays this help text.\n"
	"\t-i <file>             loads VRAM with the binary data from the input file.\n"
	"\t                         I use GIMP to generate the VRAM dumps loaded here. Either create or convert and image to \n"
	"\t                         320x240 resolution, then apply the Diapason palette file (Image->Mode->Indexed). Next, export\n"
	"\t                         using .data as the file extension. The last menu prompts for the binary format; Select Planar\n"
	"\t                         for the first option, Normal for the second option, then export the final binary dump.\n"
	"\t-g                    fills VRAM with an RGB test pattern.\n"
	"\t-r                    randomizes the graphics configuration.\n"
	"\t-t \"string\"           loads VRAM with the ASCII characters of the string; Used to test text modes.\n"
	"\t-x                    fills VRAM with a builtin text blob; Used for testing text modes.\n"
	"\t-z                    fills VRAM with a builtin test bitmap; Used for testing bitmap modes.\n"
	"\n"
};

void init_bus_testbench(int benchNum) {
	if (benchNum == 0) {
		memcpy((char*)(vram_mem_array), _binary___test_data_start, _binary___test_data_end - _binary___test_data_start);
	} else if (benchNum == 1) {
		strcpy((char*)vram_mem_array, vram_preload);
		for (int i = 0; i < 2400; i++)
			vram_mem_array[i+2400] = i;
	} else if (benchNum == 2) {
		memcpy((char*)(vram_mem_array), _binary___test_data_start, _binary___test_data_end - _binary___test_data_start);
	} else if (benchNum == 3) {
		memcpy((char*)(vram_mem_array), _binary___test_data_start, _binary___test_data_end - _binary___test_data_start);
	} else {
		for (int v = 0; v < 240; v++){
			for (int i = 0; i < 320; i++){
				vram_mem_array[(v*320)+i] = i;
			}
		}
	}
}

int	main(int argc, char **argv) {
	Gtk::Main	main_instance(argc, argv);
	Verilated::commandArgs(argc, argv);
	bool	test_data = false, verbose_flag = false;;
	char	*ptr = NULL, *trace_file = NULL;
	int	hres = 640, vres = 480;
	vram_mem_array = new char[200000];
	if (!vram_mem_array) {
		printf("VRAM Allocation Failed!\n");
		exit(1);
	}
	int	opt;
	bool mode_valid = false;
	bool has_user_vram = false;

	if (argc > 1) {
		while((opt = getopt(argc, argv, "dgt:i:b:xhzr")) != -1) {
			const char DELIMITERS[] = "x, ";
			switch(opt) {
				case 'd': {
					do_debug = true;
				} break;
				case 'g': {		// GRAPHICS TEST
					for (int v = 0; v < 240; v++){
						for (int i = 0; i < 320; i++){
							vram_mem_array[(v*320)+i] = i;
						}
					}
					if (!mode_valid) {
						bus_test_mode = 0;
						mode_valid = true;
					}
					has_user_vram = true;
				} break;
				case 't': {
					memcpy((char*)(vram_mem_array), optarg, strlen(optarg));
					memset((char*)vram_mem_array+2400, 0xFF, 2400);
					if (!mode_valid) {
						bus_test_mode = 1;
						mode_valid = true;
					}
					has_user_vram = true;
				} break;
				case 'i': {
					std::ifstream image;
					std::streampos size;
					image.open(optarg, std::ios::in | std::ios::binary | std::ios::ate);
					if (!image.is_open()) {
						printf("Image file not found.\n");
						exit(1);
					}
					size = image.tellg();
					image.seekg(0, std::ios::beg);
					image.read(vram_mem_array, size);
					image.close();
					has_user_vram = true;
				} break;
				case 'x': {
					strcpy((char*)vram_mem_array, vram_preload);
					for (int i = 0; i < 2400; i++)
						vram_mem_array[i+2400] = i;
					if (!mode_valid) {
						bus_test_mode = 1;
						mode_valid = true;
					}
					has_user_vram = true;
				} break;
				case 'z': {
					memcpy((char*)(vram_mem_array), _binary___test_data_start, _binary___test_data_end - _binary___test_data_start);
					if (!mode_valid) {
						bus_test_mode = 0;
						mode_valid = true;
					}
					has_user_vram = true;
				} break;
				case 'r': {
					static_gfx_cfg = rand() % 4;
				} break;
				case 'b': {
					bus_test_mode = atoi(optarg);
					if (has_user_vram == false) {
						init_bus_testbench(bus_test_mode);
					}
					mode_valid = true;
				} break;
				case 'h': {
				default:
					mode_valid = false;
				} break;
			}
		}
	} else {
		srand (time(NULL));
		bus_test_mode = rand() % 4;
		static_gfx_cfg = rand() % 4;
		init_bus_testbench(bus_test_mode);
		mode_valid = true;
	}

	if (!mode_valid) {
		printf(helptxt);
		return -1;
	}

	tb = new TESTBENCH(hres, vres);
	tb->test_input(test_data);
	tb->reset();

	if ((trace_file)&&(trace_file[0]))
		tb->opentrace(trace_file);
	Gtk::Main::run(tb->m_vga);

	exit(0);
}
