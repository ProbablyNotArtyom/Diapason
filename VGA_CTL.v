// TODO:
// Scroll register

	`default_nettype wire

	//`define ROM_CHARSET_FILE "VGA8_ROM.list"
	`define ROM_CHARSET_FILE "VGA_PS2.list"

//==================================

module VGA_CTL(
	input		clk_main,	// 50MHz base clock
	input		reset_in,	// System reset
	output		clk_system,	// Sysclk

	input		cs_vgamem,

	output	wire 	[23:0]	vram_a_bus,
	input 	wire	[7:0]	vram_d_bus,

	input 	wire	[7:0]	cpu_a_bus,
	input 	wire	[7:0]	cpu_d_bus,
	input 					cpu_rw,				// Read high, write low
	input 					vga_select,
	output reg 				cpu_ack,			// Acknowledge & grant the CPU transfer request
	output reg 				vga_interrupt,


	output	vga_blank,
	output	vga_hsync,
	output	vga_vsync,
	output 	reg [7:0]		vga_rgb_out
);

//----------Clock Dividers----------

clk_div_x2 clkgen_stage_1(clk_main, reset_in, clk_system);

reg 	[23:0] int_vram_a_bus;
wire 	[23:0] int_bmp_a_bus;
wire 	[23:0] int_txt_a_bus;
wire 			vga_mode_bmp, vga_mode_txt;
wire 	[7:0]	bmp_rgb_out;
wire 	[7:0]	txt_rgb_out;

assign vram_a_bus = (raster_visible == 0) ? int_vram_a_bus : 24'bz;

/* Multiplexers for display modes */
always @(*) begin
	if (reg_gfx_mode_select[1] == 0) begin
		if (reg_gfx_mode_select[0] == 1) begin
			int_vram_a_bus = int_bmp_a_bus;
			vga_rgb_out = bmp_rgb_out;
		end else begin
			int_vram_a_bus = int_txt_a_bus;
			vga_rgb_out = txt_rgb_out;
		end
	end else begin
		int_vram_a_bus = 24'bz;
		vga_rgb_out = 8'h00;
	end
end

/* IRQ Generation */
always @(posedge clk_main) begin
	if ({reg_raster_hi[1:0], reg_raster_lo} == px_address_y && px_address_x == 0)
		vga_interrupt <= 1'b0;
end

//-----------Register Map-----------

reg [7:0] reg_gfx_mode_select;		// 0	[1](1 = display disable, 0 = enable) [0](1 = graphics, 0 = text)
reg [7:0] reg_gfx_mode_config;		// 1
reg [7:0] reg_scroll_x;				// 2
reg [7:0] reg_scroll_y;				// 3
reg [7:0] reg_misc_0;				// 4	[7](1 = vblank irq enable) [6](1 = raster irq enable) [5](1 = irq triggered)
reg [7:0] reg_raster_lo;			// 5	[1:0](raster irq high)
reg [7:0] reg_raster_hi;			// 6

reg [7:0] out_buff;
always @(posedge clk_main or posedge reset_in) begin
	if (reset_in == 1) begin
		reg_gfx_mode_select <= 8'h00;
		reg_gfx_mode_config <= 8'h00;
		reg_scroll_x <= 8'h00;
		reg_scroll_y <= 8'h00;
		reg_misc_0 <= 8'h00;
		reg_raster_lo <= 8'h00;
		reg_raster_hi <= 8'h00;
		cpu_ack <= 1;
	end else if (vga_select == 0) begin
		cpu_ack <= 0;
		if (cpu_rw == 1) begin				// CPU read
			case (cpu_a_bus)
				8'h00: 		out_buff <= reg_gfx_mode_select;
				8'h01: 		out_buff <= reg_gfx_mode_config;
				8'h02: 		out_buff <= reg_scroll_x;
				8'h03: 		out_buff <= reg_scroll_y;
				8'h04:	begin
							out_buff <= reg_misc_0;
							vga_interrupt <= 1'b1;
						end
				8'h05: 		out_buff <= reg_raster_lo;
				8'h06: 		out_buff <= reg_raster_hi;
				default: 	out_buff <= 0;
			endcase
		end else begin						// CPU write
			case (cpu_a_bus)
				8'h00: 		reg_gfx_mode_select <= cpu_d_bus;
				8'h01: 		reg_gfx_mode_config <= cpu_d_bus;
				8'h02: 		reg_scroll_x <= cpu_d_bus;
				8'h03: 		reg_scroll_y <= cpu_d_bus;
				8'h04: 		reg_misc_0 <= cpu_d_bus;
				8'h05: 		reg_raster_lo <= cpu_d_bus;
				8'h06: 		reg_raster_hi <= cpu_d_bus;
				default:	begin end
			endcase
		end
	end else if (cpu_ack == 0 && vga_select == 1)
		cpu_ack <= 1;
end

//--------VGA Generation------------

wire	raster_visible;
wire	raster_active;
reg  	mod_raster_active;

wire	[9:0]	px_address_x;
wire	[9:0]	px_address_y;
reg		[9:0]	mod_px_address_x;
reg		[9:0]	mod_px_address_y;

sync_generator #(
	.X_RES(640),
	.Y_RES(480)
)vga_sync_gen(
	.clk(clk_system),
	.reset(reset_in),
	.hsync_out(vga_hsync),
	.vsync_out(vga_vsync),
	.raster_visible(raster_visible),
	.active(raster_active),
	.raster_x(px_address_x),
	.raster_y(px_address_y)
);

vga_mode_txt vga_text_gen(
	.clk_in(clk_main),
	.raster_x(mod_px_address_x),
	.raster_y(mod_px_address_y),
	.rgb_out(txt_rgb_out),
	.active(mod_raster_active),
	.mode_config(reg_gfx_mode_config),
	//.mode_config(px_address_x[9:4] + px_address_y[9:5]),
	.address_out(int_txt_a_bus),
	.data_in(vram_d_bus)
);

vga_mode_320x240_bmp vga_bmp_gen(
	.clk_in(clk_main),
	.raster_x(mod_px_address_x),
	.raster_y(mod_px_address_y),
	.rgb_out(bmp_rgb_out),
	.active(mod_raster_active),
	.mode_config(reg_gfx_mode_config),
	.address_out(int_bmp_a_bus),
	.data_in(vram_d_bus)
);

//---------Video Modifiers----------

//always @(posedge clk_main) begin
//	reg_scroll_x <= (px_address_y == 0 && px_address_x == 0)? reg_scroll_x + 2 : reg_scroll_x;
//	reg_scroll_y <= (px_address_x == 0 && px_address_y == 0)? reg_scroll_y + 2 : reg_scroll_y;
//end

always @(*) begin
	mod_px_address_x = (px_address_x >= reg_scroll_x)? px_address_x - reg_scroll_x : 0;
	mod_px_address_y = (px_address_y >= reg_scroll_y)? px_address_y - reg_scroll_y : 0;
	if (px_address_x >= reg_scroll_x && px_address_y >= reg_scroll_y)
		mod_raster_active = raster_active;
	else
		mod_raster_active = 1;
end

//----------------------------------

endmodule

module charmem(
	input 	clk,
	input 	[7:0] ascii_in,
	input	[2:0] col,
	input	[3:0] row,
	output	bit_out
);

reg [7:0] romdata[0:4095]; // 256 chars, 16 scans, 8 pixels
initial $readmemh (`ROM_CHARSET_FILE, romdata);
assign bit_out = romdata[{ascii_in[7:0], row[3:0]}][~col];

//----------------------------------
endmodule
