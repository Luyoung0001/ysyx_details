module sillyfunction (
    input a,
    input b,
    input c,
    output y
);
assign y = ~b & ~c | a & ~b;
endmodule

module testbench1(); // 将被测模块实例化，被测模块的输入信号定义成 reg 类型，输出信号定义成 wire 类型。
reg a,b,c;
wire y;

sillyfunction dut(a,b,c,y);

initial begin // 通过 initial 块构造输入信号的波形，
            // 同一 initial 块内部的语句是串行执行的，多个 initial 块之间并发执行。
    a = 0; b = 0;c = 0; #10;
    c = 1; #10;
    b = 1;c = 0; #10;
    c = 1; #10;
    a = 1; b = 0;c = 0; #10;
    c = 1; #10;
    b = 1;c = 0; #10;
    c = 1; #10;

end
endmodule