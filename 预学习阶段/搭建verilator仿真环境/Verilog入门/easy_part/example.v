// 这里可以注释
// y = abc + ab

module example (
    input a,
    input b,
    input c,
    output y
);
    assign y = a & b & c | a & b; // 这里依然可以使用括号进行优先级定义
endmodule