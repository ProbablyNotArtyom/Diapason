
module chartest(
i_clk, i_pixclk, i_reset, i_test,

i_hm_width, i_hm_porch, i_hm_synch, i_hm_raw,
i_vm_height,i_vm_porch, i_vm_synch, i_vm_raw,

o_vga_vsync, o_vga_hsync, o_vga_red, o_vga_grn, o_vga_blu, o_interrupt,

o_vram_addr, i_vram_data,

o_cpu_a_bus, io_cpu_d_bus, o_cpu_rw, o_vga_select, i_vga_interrupt, o_cpu_ack
);

	parameter	BW=32,
				FW=13,	// Log_2 of the maximum width or FIFO size
				LW=11;	// Log_2 of the number of lines

	localparam	AW=(FW+LW);
	input	wire	i_clk, i_pixclk, i_reset;
	input	wire	i_test;

	input	wire	[FW-1:0] i_hm_width, i_hm_porch, i_hm_synch, i_hm_raw;
	input	wire	[LW-1:0] i_vm_height,i_vm_porch, i_vm_synch, i_vm_raw;

	output	wire			o_vga_vsync, o_vga_hsync;
	output	wire	[7:0]	o_vga_red, o_vga_grn, o_vga_blu;
	output	wire			o_interrupt;

	input 	wire 	[7:0]	i_vram_data;
	output 	wire  	[23:0]	o_vram_addr;


	wire [7:0]	vga_rgb;
	assign	o_vga_red = {vga_rgb[2:0], 5'b0};
	assign	o_vga_grn = {vga_rgb[5:3], 5'b0};
	assign	o_vga_blu = {vga_rgb[7:6], 6'b0};

	wire sysclk, o_vga_blanking;

	input 	wire 			o_cpu_rw, o_vga_select;
	output 	wire  			i_vga_interrupt, o_cpu_ack;
	input 	wire 	[7:0]	o_cpu_a_bus;
	input 	wire 	[7:0]	io_cpu_d_bus;


VGA_CTL	vga_interface_0(
	.clk_main(i_clk),
	.reset_in(i_reset),
	.clk_system(sysclk),
	.cs_vgamem(i_test),

	.vga_blank(o_vga_blanking),
	.vga_hsync(o_vga_hsync),
	.vga_vsync(o_vga_vsync),
	.vga_rgb_out(vga_rgb),

	.vram_a_bus(o_vram_addr),
	.vram_d_bus(i_vram_data),

	.cpu_a_bus(o_cpu_a_bus),
	.cpu_d_bus(io_cpu_d_bus),
	.cpu_rw(o_cpu_rw),
	.vga_select(o_vga_select),
	.vga_interrupt(i_vga_interrupt),
	.cpu_ack(o_cpu_ack)
);

	always @(*)
	begin
		assume(13'h10 < i_hm_width);
		assume(i_hm_width < i_hm_porch);
		assume(i_hm_porch < i_hm_synch);
		assume(i_hm_synch < i_hm_raw);

		assume(11'h10 < i_vm_height);
		assume(i_vm_height < i_vm_porch);
		assume(i_vm_porch  < i_vm_synch);
		assume(i_vm_synch  < i_vm_raw);
	end

endmodule
