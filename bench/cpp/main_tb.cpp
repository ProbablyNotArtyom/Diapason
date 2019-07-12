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

const char *vram_preload = {
		"The 601 is the first implementation of the PowerPC family of RISC microprocessors. The 601 implements the 32-bit portion of the PowerPC architecture, which provides 32-bit effective addresses, integer data types of 8, 16, and 32 bits, and floating-point data types of 32 and 64 bits. For 64-bit PowerPC implementations, the PowerPC architecture provides 64-bit integer data types, 64-bit addressing, and other features required to complete the 64-bit architecture. The 601 is a superscalar processor capable of issuing and retiring three instructions per clock, one to each of three execution units. Instructions can complete out of order for increased performance; however, the 601 makes execution appear sequential. The 601 integrates three execution units—an integer unit (IU), a branch processing unit (BPU), and a floating-point unit (FPU). The ability to execute three instructions in parallel and the use of simple instructions with rapid execution times yield high efficiency and throughput for 601-based systems. Most integer instructions execute in one clock cycle. The FPU is pipelined so a single-precision multiply-add instruction can be issued every clock cycle. The 601 provides an on-chip, 32-Kbyte, eight-way set-associative, physically addressed, unified instruction and data cache and an on-chip memory management unit (MMU). The MMU contains a 256-entry, two-way set-associative, unified translation lookaside buffer (UTLB) and provides support for demand-paged virtual memory address translation and variable-sized block translation. Both the UTLB and the cache use least recently used (LRU) replacement algorithms. The 601 has a 64-bit data bus and a 32-bit address bus. The 601 interface protocol allows multiple masters to compete for system resources through a central external arbiter. Additionally, on-chip snooping logic maintains cache coherency in multiprocessor applications. The 601 supports single-beat and burst data transfers for memory accesses; it also supports both memory-mapped I/O and direct-store addressing. The 601 uses an advanced CMOS (complementary metal-oxide semiconductor) process technology and maintains full interface compatibility with TTL devices. The 601v is functionally equivalent to the 601, but operates with reduced internal voltages and with reduced power dissipation. "
};

vluint64_t main_time = 0;	// Current simulation time (64-bit unsigned)
char *vram_mem_array;
double sc_time_stamp () {	// Called by $time in Verilog
    return main_time;		// Note does conversion to real, to match SystemC
}

// No particular "parameters" need definition or redefinition here.
class	TESTBENCH : public TESTB<Vchartest> {
private:
	unsigned long	m_tx_busy_count;
	bool		m_done, m_test;
public:
	VGAWIN		m_vga;
private:

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

	void	tick(void) {
		if (m_done)
			return;

		m_vga((m_core->o_vga_vsync)?1:0, (m_core->o_vga_hsync)?1:0,
			m_core->o_vga_red,
			m_core->o_vga_grn,
			m_core->o_vga_blu);


		m_core->i_vram_data = vram_mem_array[m_core->o_vram_addr];
		TESTB<Vchartest>::tick();
		m_core->i_vram_data = vram_mem_array[m_core->o_vram_addr];
		TESTB<Vchartest>::tick();
	}

	bool	on_tick(void) {
		for(int i=0; i<5; i++)
			tick();
		return true;
	}
};

TESTBENCH	*tb;

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
	while((opt = getopt(argc, argv, "d:hti:g")) != -1) {
		const char DELIMITERS[] = "x, ";
		switch(opt) {
		case 'd':
			if (verbose_flag)
				fprintf(stderr, "Opening trace file, %s\n", optarg);
			trace_file = strdup(optarg);
			break;
		case 'g':		// GRAPHICS TEST
			for (int v = 0; v < 240; v++){
				for (int i = 0; i < 320; i++){
					vram_mem_array[(v*320)+i] = i;
				}
			}
			mode_valid = true;
			break;
		case 't':
			memcpy((char*)(vram_mem_array), optarg, strlen(optarg));
			memset((char*)vram_mem_array+2400, 0xFF, 2400);
			mode_valid = true;
			break;
		case 'i':
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
			mode_valid = true;
			break;
		}
	}
	if (!mode_valid) {
		strcpy((char*)vram_mem_array, vram_preload);
		for (int i = 0; i < 2400; i++){
			vram_mem_array[i+2400] = i;
		}
	}

	if ((hres != 1280)||(vres != 1024)) {
		fprintf(stderr, "WARNING: Memory mapped mode not supported for %d x %d, switching to test mode\n", hres, vres);
		test_data = true;
	}



	tb = new TESTBENCH(hres, vres);
	tb->test_input(test_data);
	tb->reset();


	if ((trace_file)&&(trace_file[0]))
		tb->opentrace(trace_file);
	Gtk::Main::run(tb->m_vga);

	exit(0);
}
