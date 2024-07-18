module LFSR8(
        input wire clk,
        input wire reset,
        input wire enable,
        output reg [7:0] out,
        output reg [7:0] bcd7seg,
        output reg [7:0] bcd7seg2
    );
    reg new_bit;

    // 初始值非全0，这里设置为 8'b00000001
    initial
        out = 8'b00000001;

    always @(reset or enable) begin
        if (reset) begin
            out <= 8'b00000001;
        end
        else if (enable) begin
            new_bit <= out[4] ^ out[2] ^ out[1] ^ out[0];
            out <= {new_bit, out[7:1]};
        end
        case(out[7:4])
            4'b0000:
                bcd7seg = ~8'b11111101; // 0
            4'b0001:
                bcd7seg = ~8'b01100000; // 1
            4'b0010:
                bcd7seg = ~8'b11011010; // 2
            4'b0011:
                bcd7seg = ~8'b11110010; // 3
            4'b0100:
                bcd7seg = ~8'b01100110; // 4
            4'b0101:
                bcd7seg = ~8'b10110110; // 5
            4'b0110:
                bcd7seg = ~8'b10111110; // 6
            4'b0111:
                bcd7seg = ~8'b11100000; // 7
            4'b1000:
                bcd7seg = ~8'b11111110; // 8
            4'b1001:
                bcd7seg = ~8'b11100110; // 9
            4'b1010:
                bcd7seg = ~8'b11101110; // A
            4'b1011:
                bcd7seg = ~8'b00111110; // b
            4'b1100:
                bcd7seg = ~8'b10011100; // C
            4'b1101:
                bcd7seg = ~8'b01111010; // d
            4'b1110:
                bcd7seg = ~8'b10011110; // e
            4'b1111:
                bcd7seg = ~8'b10001110; // f
            default:
                bcd7seg = ~8'b10001110; // f
        endcase
        case(out[3:0])
             4'b0000:
                bcd7seg2 = ~8'b11111101; // 0
            4'b0001:
                bcd7seg2 = ~8'b01100000; // 1
            4'b0010:
                bcd7seg2 = ~8'b11011010; // 2
            4'b0011:
                bcd7seg2 = ~8'b11110010; // 3
            4'b0100:
                bcd7seg2 = ~8'b01100110; // 4
            4'b0101:
                bcd7seg2 = ~8'b10110110; // 5
            4'b0110:
                bcd7seg2 = ~8'b10111110; // 6
            4'b0111:
                bcd7seg2 = ~8'b11100000; // 7
            4'b1000:
                bcd7seg2 = ~8'b11111110; // 8
            4'b1001:
                bcd7seg2 = ~8'b11100110; // 9
            4'b1010:
                bcd7seg2 = ~8'b11101110; // A
            4'b1011:
                bcd7seg2 = ~8'b00111110; // b
            4'b1100:
                bcd7seg2 = ~8'b10011100; // C
            4'b1101:
                bcd7seg2 = ~8'b01111010; // d
            4'b1110:
                bcd7seg2 = ~8'b10011110; // e
            4'b1111:
                bcd7seg2 = ~8'b10001110; // f
            default:
                bcd7seg2 = ~8'b10001110; // f
        endcase




    end


endmodule

module top(
        input clk,
        input rst,
        input [4:0] btn,
        input [9:0] sw,
        input ps2_clk,
        input ps2_data,
        input uart_rx,
        output uart_tx,
        output [15:0] ledr,
        output VGA_CLK,
        output VGA_HSYNC,
        output VGA_VSYNC,
        output VGA_BLANK_N,
        output [7:0] VGA_R,
        output [7:0] VGA_G,
        output [7:0] VGA_B,
        output [7:0] seg0,
        output [7:0] seg1,
        output [7:0] seg2,
        output [7:0] seg3,
        output [7:0] seg4,
        output [7:0] seg5,
        output [7:0] seg6,
        output [7:0] seg7
    );

    LFSR8 lfsr8(
              .clk(clk),
              .reset(sw[8]),
              .enable(sw[9]),
              .out(ledr[7:0]),
              .bcd7seg(seg0[7:0]),
              .bcd7seg2(seg1[7:0])
          );

    assign VGA_CLK = clk;

    wire [9:0] h_addr;
    wire [9:0] v_addr;
    wire [23:0] vga_data;



    vmem my_vmem(
             .h_addr(h_addr),
             .v_addr(v_addr[8:0]),
             .vga_data(vga_data)
         );



endmodule

module vmem(
        input [9:0] h_addr,
        input [8:0] v_addr,
        output [23:0] vga_data
    );

    reg [23:0] vga_mem [524287:0];

    initial begin
        $readmemh("resource/picture.hex", vga_mem);
    end

    assign vga_data = vga_mem[{h_addr, v_addr}];

endmodule

