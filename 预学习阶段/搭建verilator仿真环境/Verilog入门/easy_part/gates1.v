module gates(
    input [3:0] a,
    input [3:0] b,
    output reg [3:0] y1,
    output reg [3:0] y2,
    output reg [3:0] y3,
    output reg [3:0] y4,
    output reg [3:0] y5
);
always@(*)
    // always 块内被赋值的信号应定义成 reg 类型，即使此信号在实际电路中是线型。
    // always 语句实现组合逻辑应采用阻塞赋值方式。
begin
    y1 = a & b;
    y2 = a | b;
    y3 = a ^ b;
    y4 = ~(a&b);
    y5 = ~(a|b);
end
endmodule