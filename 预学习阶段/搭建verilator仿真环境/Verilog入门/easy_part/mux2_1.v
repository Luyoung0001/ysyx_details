module mux2
#(parameter width = 8)
(
input [width-1:0] d0,d1,
input s,
output [width-1:0] y
);
assign y = s ? d1 : d0;
endmodule

module s(
// 参数

);
mux2 myMux(d0,d1,s,out);
mux2 #12 lowmux(d0,d1,s,out);

endmodule