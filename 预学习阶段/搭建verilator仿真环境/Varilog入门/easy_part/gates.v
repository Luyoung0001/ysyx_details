// y1 = a & b;
// y2 = a | b;
// y3 = a ^ b;
// y4 = ~(a & b);
// y5 = ~(a | b);

module gates(
    input [3:0] a,
    input [3:0] b,
    output [3:0] y1,
    output [3:0] y2,
    output [3:0] y3,
    output [3:0] y4,
    output [3:0] y5
);
assign y1 = a & b;
assign y2 = a | b;
assign y3 = a ^ b;
assign y4 = ~(a & b);
assign y5 = ~(a | b);

endmodule