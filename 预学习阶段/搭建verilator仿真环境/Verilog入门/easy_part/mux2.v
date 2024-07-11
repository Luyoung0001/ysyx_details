module mux2(
input [3:0] d0,
input [3:0] d1,
input  s,
output [3:0] y
);
assign y = s ? d1 : d0;

endmodule

module mux2_8(
input [7:0] d0,
input [7:0] d1,
input s,
output [7:0] y
);

mux2 lsbmux(d0[3:0], d1[3:0], s, y[3:0]);
mux2 msbmux(
.d0 (d0[7:4]),
.d1 (d1[7:4]),
.s  (s),
.y  (y[7:4])
);
endmodule