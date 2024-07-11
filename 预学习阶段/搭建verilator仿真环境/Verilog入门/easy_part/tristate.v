//高阻态，Verilog 中，信号共有 4 种状态 0、1、x、z，分别表示低电平、高电平、不确定态和高阻态。
// 对于没有进行初始化的信号，一般处于不确定态（x），高阻态表示该信号没有被其他信号驱动，经常用于有多个驱动源的总线型数据上。

module tristate(
input [3:0] a,
input       en,
output [3:0] y
);
assign y = en ? a : 4'bz; // 4位宽，用二进制表示，高组态
endmodule

