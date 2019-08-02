
`default_nettype none

`define	CFG_TEXT_40COL	8'b00000001
`define	CFG_TEXT_15ROW	8'b00000010

//----------------------------------

module vga_mode_txt(
	input	wire	clk_in,
	input	wire 	active,
	input	wire	[9:0]	raster_x,
	input	wire	[9:0]	raster_y,
	input	wire 	[7:0]	mode_config,
	output 	reg 	[7:0]	rgb_out,

	output 	reg 	[23:0]	address_out,
	input 	wire	[7:0]	data_in
);

reg		[7:0]		mem_val;		// Character to be displayed
reg		[7:0]		attr_val;		// Attribute byte of the character
reg  	[6:0]		column;			// Current character column the raster is in
reg  	[5:0]		row;			// Current character row the raster is in
reg  	[2:0]		char_x;			// Horizontal location of the raster within the character cell grid
reg  	[3:0]		char_y;			// Vertical location of the raster within the character cell grid

reg		b_state;					// Current mode of the bus. 0 = fetching char data, 1 = fetching attribute

always @(posedge clk_in) begin
	if (mode_config[0]) begin
		column[5:0] = raster_x[9:4];
		char_x = raster_x[3:1];
	end else begin
		column[6:0] = raster_x[9:3];
		char_x = raster_x[2:0];
	end
	if (mode_config[1]) begin
		row[4:0] = raster_y[9:5];
		char_y = raster_y[4:1];
	end else begin
		row[5:0] = raster_y[9:4];
		char_y = raster_y[3:0];
	end
end

always @(posedge clk_in) begin
	if (active == 0) begin
		if (b_state) begin
			address_out = ((80 >> (mode_config[0])) * row) + column;
			attr_val = data_in;
			b_state = 0;
		end else begin
			address_out = (80 * row) + column + 2400;
			mem_val = data_in;
			b_state = 1;
		end

		if (mode_config[2])
			if (pixel_out == 1)
				case(attr_val[3:0])
					4'h0 : rgb_out = 8'b00000000;
					4'h1 : rgb_out = 8'b00000011;
					4'h2 : rgb_out = 8'b00011000;
					4'h3 : rgb_out = 8'b00011011;
					4'h4 : rgb_out = 8'b10000000;
					4'h5 : rgb_out = 8'b10000101;
					4'h6 : rgb_out = 8'b11101000;
					4'h7 : rgb_out = 8'b10101101;
					4'h8 : rgb_out = 8'b01011011;
					4'h9 : rgb_out = 8'b00000111;
					4'hA : rgb_out = 8'b00111000;
					4'hB : rgb_out = 8'b00111111;
					4'hC : rgb_out = 8'b11000000;
					4'hD : rgb_out = 8'b11000111;
					4'hE : rgb_out = 8'b11111000;
					4'hF : rgb_out = 8'b11111111;
				endcase
			else
				case(attr_val[7:4])
					4'h0 : rgb_out = 8'b00000000;
					4'h1 : rgb_out = 8'b00000011;
					4'h2 : rgb_out = 8'b00011000;
					4'h3 : rgb_out = 8'b00011011;
					4'h4 : rgb_out = 8'b10000000;
					4'h5 : rgb_out = 8'b10000101;
					4'h6 : rgb_out = 8'b11101000;
					4'h7 : rgb_out = 8'b10101101;
					4'h8 : rgb_out = 8'b01011011;
					4'h9 : rgb_out = 8'b00000111;
					4'hA : rgb_out = 8'b00111000;
					4'hB : rgb_out = 8'b00111111;
					4'hC : rgb_out = 8'b11000000;
					4'hD : rgb_out = 8'b11000111;
					4'hE : rgb_out = 8'b11111000;
					4'hF : rgb_out = 8'b11111111;
				endcase
		else
			rgb_out = (pixel_out == 1) ? attr_val : 8'h00;
	end else begin
		b_state = 1;
		rgb_out = 8'h00;
	end
end

wire pixel_out;
charmem charset_rom(
	.ascii_in(mem_val),
	.col(char_x),
	.row(char_y),
	.clk(clk_in),
	.bit_out(pixel_out)
);

endmodule

//----------------------------------

module vga_mode_320x240_bmp(
	input	wire	clk_in,
	input	wire 	active,
	input	wire	[9:0]	raster_x,
	input	wire	[9:0]	raster_y,
	input 	wire	[7:0]	mode_config,
	output 	wire 	[7:0]	rgb_out,

	output 	wire	[23:0]	address_out,
	input 	wire	[7:0]	data_in
);

reg [7:0]	mem_val;
reg			b_state;

assign address_out = ((320 * raster_y[9:1]) + raster_x[9:1]);
assign rgb_out = data_in;

endmodule
