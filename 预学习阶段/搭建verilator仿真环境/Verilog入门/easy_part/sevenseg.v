module sevenseg(
input [3:0] data,
output reg [6:0] segments
);
always@(*)
    case(data) // 事实上，data 作为一个 4 位二进制数，它是有值的
        // case 语句的各个条件之间没有优先级，且各条件应是互斥的。
        0: segments = 7'b111_1110;
        1: segments = 7'b011_0000;
        2: segments = 7'b111_1110;
        3: segments = 7'b111_1110;
        4: segments = 7'b111_1110;
        5: segments = 7'b111_1110;
        6: segments = 7'b111_1110;
        7: segments = 7'b111_1110;
        8: segments = 7'b111_1110;
        9: segments = 7'b111_1110;
        default:segments = 7'b111_1110; // 要有默认
    endcase
endmodule