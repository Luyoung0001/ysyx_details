module ps2_keyboard(clk,resetn,ps2_clk,ps2_data,reg0,reg1,reg2,reg3,reg4,reg5);
    input clk,resetn,ps2_clk,ps2_data;

    // 次数
    output reg [7:0] reg0;
    reg [7:0] decimal;
    reg [7:0] ge;
    reg [7:0] shi;
    output reg [7:0] reg1;

    // ascii 码
    output reg [7:0] reg2;
    output reg [7:0] reg3;
    // 键码
    reg [7:0] codes;
    output reg [7:0] reg4;
    output reg [7:0] reg5;

    reg [9:0] buffer;        // ps2_data bits
    reg [3:0] count;  // count ps2_data bits
    reg [2:0] ps2_clk_sync;
    reg [7:0] ch_counter;
    reg [15:0] longbuffer;

    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (resetn == 0) begin // reset
            count <= 0;
            ch_counter <= 0;
        end
        else begin
            if (sampling) begin
                if (count == 4'd10) begin
                    if ((buffer[0] == 0) &&
                            (ps2_data)       &&
                            (^buffer[9:1])) begin // 奇校验
                        longbuffer = {buffer[8:1],longbuffer[15:8]};
                        if(buffer[8:1] == 8'b11110000) begin
                            ch_counter  <= ch_counter + 8'd1;
                        end
                        else begin

                            codes = buffer[8:1];
                            // 显示信息
                            // 次数
                            decimal = ch_counter;
                            shi = (decimal / 8'b00001010);
                            ge = decimal % 8'b00001010;
                            case (shi[3:0])
                                4'd0:
                                    reg0 = ~8'b11111101; // 0
                                4'd1:
                                    reg0 = ~8'b01100000; // 1
                                4'd2:
                                    reg0 = ~8'b11011010; // 2
                                4'd3:
                                    reg0 = ~8'b11110010; // 3
                                4'd4:
                                    reg0 = ~8'b01100110; // 4
                                4'd5:
                                    reg0 = ~8'b10110110; // 5
                                4'd6:
                                    reg0 = ~8'b10111110; // 6
                                4'd7:
                                    reg0 = ~8'b11100000; // 7
                                4'd8:
                                    reg0 = ~8'b11111110; // 8
                                4'd9:
                                    reg0 = ~8'b11100110; // 9
                                default:
                                    reg0 = ~8'b11111101;
                            endcase
                            case (ge[3:0])
                                4'd0:
                                    reg1 = ~8'b11111101; // 0
                                4'd1:
                                    reg1 = ~8'b01100000; // 1
                                4'd2:
                                    reg1 = ~8'b11011010; // 2
                                4'd3:
                                    reg1 = ~8'b11110010; // 3
                                4'd4:
                                    reg1 = ~8'b01100110; // 4
                                4'd5:
                                    reg1 = ~8'b10110110; // 5
                                4'd6:
                                    reg1 = ~8'b10111110; // 6
                                4'd7:
                                    reg1 = ~8'b11100000; // 7
                                4'd8:
                                    reg1 = ~8'b11111110; // 8
                                4'd9:
                                    reg1 = ~8'b11100110; // 9
                                default:
                                    reg1 = ~8'b11111101;
                            endcase

                            // ascii 码
                            case(codes[3:0])
                                4'b0000:
                                    reg2 = ~8'b11111101; // 0
                                4'b0001:
                                    reg2 = ~8'b01100000; // 1
                                4'b0010:
                                    reg2 = ~8'b11011010; // 2
                                4'b0011:
                                    reg2 = ~8'b11110010; // 3
                                4'b0100:
                                    reg2 = ~8'b01100110; // 4
                                4'b0101:
                                    reg2 = ~8'b10110110; // 5
                                4'b0110:
                                    reg2 = ~8'b10111110; // 6
                                4'b0111:
                                    reg2 = ~8'b11100000; // 7
                                4'b1000:
                                    reg2 = ~8'b11111110; // 8
                                4'b1001:
                                    reg2 = ~8'b11100110; // 9
                                4'b1010:
                                    reg2 = ~8'b11101110; // A
                                4'b1011:
                                    reg2 = ~8'b00111110; // b
                                4'b1100:
                                    reg2 = ~8'b10011100; // C
                                4'b1101:
                                    reg2 = ~8'b01111010; // d
                                4'b1110:
                                    reg2 = ~8'b10011110; // e
                                4'b1111:
                                    reg2 = ~8'b10001110; // f
                                default:
                                    reg2 = ~8'b10001110; // f
                            endcase
                            case(codes[7:4])
                                4'b0000:
                                    reg3 = ~8'b11111101; // 0
                                4'b0001:
                                    reg3 = ~8'b01100000; // 1
                                4'b0010:
                                    reg3 = ~8'b11011010; // 2
                                4'b0011:
                                    reg3 = ~8'b11110010; // 3
                                4'b0100:
                                    reg3 = ~8'b01100110; // 4
                                4'b0101:
                                    reg3 = ~8'b10110110; // 5
                                4'b0110:
                                    reg3 = ~8'b10111110; // 6
                                4'b0111:
                                    reg3 = ~8'b11100000; // 7
                                4'b1000:
                                    reg3 = ~8'b11111110; // 8
                                4'b1001:
                                    reg3 = ~8'b11100110; // 9
                                4'b1010:
                                    reg3 = ~8'b11101110; // A
                                4'b1011:
                                    reg3 = ~8'b00111110; // b
                                4'b1100:
                                    reg3 = ~8'b10011100; // C
                                4'b1101:
                                    reg3 = ~8'b01111010; // d
                                4'b1110:
                                    reg3 = ~8'b10011110; // e
                                4'b1111:
                                    reg3 = ~8'b10001110; // f
                                default:
                                    reg3 = ~8'b10001110; // f
                            endcase
                            // 通码
                            case(codes[3:0])
                                4'b0000:
                                    reg5 = ~8'b11111101; // 0
                                4'b0001:
                                    reg5 = ~8'b01100000; // 1
                                4'b0010:
                                    reg5 = ~8'b11011010; // 2
                                4'b0011:
                                    reg5 = ~8'b11110010; // 3
                                4'b0100:
                                    reg5 = ~8'b01100110; // 4
                                4'b0101:
                                    reg5 = ~8'b10110110; // 5
                                4'b0110:
                                    reg5 = ~8'b10111110; // 6
                                4'b0111:
                                    reg5 = ~8'b11100000; // 7
                                4'b1000:
                                    reg5 = ~8'b11111110; // 8
                                4'b1001:
                                    reg5 = ~8'b11100110; // 9
                                4'b1010:
                                    reg5 = ~8'b11101110; // A
                                4'b1011:
                                    reg5 = ~8'b00111110; // b
                                4'b1100:
                                    reg5 = ~8'b10011100; // C
                                4'b1101:
                                    reg5 = ~8'b01111010; // d
                                4'b1110:
                                    reg5 = ~8'b10011110; // e
                                4'b1111:
                                    reg5 = ~8'b10001110; // f
                                default:
                                    reg5 = ~8'b10001110; // f
                            endcase
                            case(codes[7:4])
                                4'b0000:
                                    reg4 = ~8'b11111101; // 0
                                4'b0001:
                                    reg4 = ~8'b01100000; // 1
                                4'b0010:
                                    reg4 = ~8'b11011010; // 2
                                4'b0011:
                                    reg4 = ~8'b11110010; // 3
                                4'b0100:
                                    reg4 = ~8'b01100110; // 4
                                4'b0101:
                                    reg4 = ~8'b10110110; // 5
                                4'b0110:
                                    reg4 = ~8'b10111110; // 6
                                4'b0111:
                                    reg4 = ~8'b11100000; // 7
                                4'b1000:
                                    reg4 = ~8'b11111110; // 8
                                4'b1001:
                                    reg4 = ~8'b11100110; // 9
                                4'b1010:
                                    reg4 = ~8'b11101110; // A
                                4'b1011:
                                    reg4 = ~8'b00111110; // b
                                4'b1100:
                                    reg4 = ~8'b10011100; // C
                                4'b1101:
                                    reg4 = ~8'b01111010; // d
                                4'b1110:
                                    reg4 = ~8'b10011110; // e
                                4'b1111:
                                    reg4 = ~8'b10001110; // f
                                default:
                                    reg4 = ~8'b10001110; // f
                            endcase
                            if(longbuffer[7:0] == 8'b11110000) begin
                                reg2 = 8'b11111111;
                                reg3 = 8'b11111111;
                                reg4 = 8'b11111111;
                                reg5 = 8'b11111111;
                                $display("receive %x", longbuffer);
                            end
                        end
                    end
                    count <= 0;     // for next
                end
                else begin
                    buffer[count] <= ps2_data;  // store ps2_data
                    count <= count + 3'b1;
                end
            end
        end
    end
endmodule

module top(
        input clk,
        input rst,
        input [4:0] btn,
        input [7:0] sw,
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


    assign VGA_CLK = clk;

    wire [9:0] h_addr;
    wire [9:0] v_addr;
    wire [23:0] vga_data;


    ps2_keyboard my_keyboard(
                     .clk(clk),
                     .resetn(~rst),
                     .ps2_clk(ps2_clk),
                     .ps2_data(ps2_data),
                     .reg4(seg0),
                     .reg5(seg1),
                     .reg3(seg2),
                     .reg2(seg3),
                     .reg1(seg4),
                     .reg0(seg5)
                 );



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
