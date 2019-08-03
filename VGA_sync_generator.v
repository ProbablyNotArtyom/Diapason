
module sync_generator(
	input	clk,			// 25MHz clock input
	input 	reset,
	output	hsync_out,
	output	vsync_out,

	output				raster_visible,
	output				active,
	output	reg [9:0]	raster_x,
	output	reg [9:0]	raster_y
);

parameter	X_RES = 640;
parameter	Y_RES = 480;

parameter 	hpixels = 800;	// horizontal pixels per line
parameter 	vlines = 521; 	// vertical lines per frame
parameter 	hpulse = 96; 	// hsync pulse length
parameter 	vpulse = 2; 	// vsync pulse length
parameter 	hbp = 752; 		// end of horizontal back porch
parameter 	hfp = 656; 		// beginning of horizontal front porch
parameter 	vbp = 492; 		// end of vertical back porch
parameter 	vfp = 490; 		// beginning of vertical front porch

assign	raster_visible = (raster_y < vbp) ? 0:1;
assign	active = ((raster_y < vfp) && (raster_x < hfp)) ? 0:1;
assign	hsync_out = (raster_x > hfp && raster_x < hbp) ? 0:1;
assign	vsync_out = (raster_y > vfp && raster_y < vbp) ? 0:1;

/* Generate VGA timings and blanking intervals */
always @(posedge clk or posedge reset) begin
	if (reset) begin							// Make sure we start counting from 0
		raster_x <= 0;
		raster_y <= 0;
	end else begin
	if (raster_x < hpixels - 1)
		raster_x <= raster_x + 1;
	else begin
		raster_x <= 0;
		if (raster_y < vlines - 1)
			raster_y <= raster_y + 1;
		else
			raster_y <= 0;
		end
	end
end

endmodule
