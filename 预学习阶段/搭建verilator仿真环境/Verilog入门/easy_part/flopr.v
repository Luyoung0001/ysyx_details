module flopr(
input clk,
input [3:0] d,
input reset,
output reg [3:0] q
);
always@(posedge clk) //always 块中常用的条件判断语句，可以嵌套，有优先级，
                    //一般来说，应将复位处理逻辑放在第一个 if 语句下，使其具有最高的优先级，该语句只能在 always 块内使用。
    if(reset)
        q <= 4'b0;
    else
        q <= d;

endmodule 