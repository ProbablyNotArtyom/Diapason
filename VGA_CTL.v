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
	output 		pixclk,

	input		cs_vgamem,

	output	wire 	[23:0]	vram_a_bus,
	input 	wire	[7:0]	vram_d_bus,

	output	vga_blank,
	output	vga_hsync,
	output	vga_vsync,
	output reg [7:0]	vga_rgb_out
);

//----------Clock Dividers----------

clk_div_x2 clkgen_stage_1(clk_main, reset_in, pixclk);

reg [23:0] int_vram_a_bus;
wire [23:0] int_bmp_a_bus;
wire [23:0] int_txt_a_bus;
wire vga_mode_bmp, vga_mode_txt;
wire [7:0]	bmp_rgb_out;
wire [7:0]	txt_rgb_out;

assign vga_mode_bmp = 1;
assign vga_mode_txt = 0;
assign vram_a_bus = (raster_visible == 0) ? int_vram_a_bus:24'bz;

always @(*) begin
	if (vga_mode_bmp)
		int_vram_a_bus = int_bmp_a_bus;
	else if (vga_mode_txt)
		int_vram_a_bus = int_txt_a_bus;
	else
		int_vram_a_bus = 24'bz;
end

always @(*) begin
	if (vga_mode_bmp)
		vga_rgb_out = bmp_rgb_out;
	else if (vga_mode_txt)
		vga_rgb_out = txt_rgb_out;
	else
		vga_rgb_out = 8'h00;
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
	.clk(pixclk),
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
	.mode_config(8'b00000000),
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
	.mode_config(8'b00000000),
	.address_out(int_bmp_a_bus),
	.data_in(vram_d_bus)
);

//---------Video Modifiers----------

reg [7:0]	scroll_reg_y;
reg [7:0]	scroll_reg_x;

initial begin
		scroll_reg_x = 0;
		scroll_reg_y = 0;
end

always @(negedge clk_main) begin
	mod_px_address_y = px_address_y - scroll_reg_y;
	mod_px_address_x = px_address_x - scroll_reg_x;
	if (px_address_x >= scroll_reg_x && px_address_y >= scroll_reg_y)
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
