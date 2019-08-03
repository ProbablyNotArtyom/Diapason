
/* This things sole purpose is to turn the bus clock into the pixel clock */
module clk_div_x2(
	input		clk_in,
	input		reset_in,
	output	reg	clk_out
 );

always @(posedge clk_in) begin
	if (reset_in)
		clk_out <= 1'b0;
	else
		clk_out <= ~clk_out;
end

endmodule
