// 83 优先编码器
module encode83(x,en,y,tag,bcd7seg);
    input [7:0] x;
    input en;
    output reg [2:0] y;
    output reg [7:0] bcd7seg;
    output reg tag;
    integer i;
    always @(x or en) begin
        if(en) begin
            y = 0;
            tag = 0;
            for(i = 0; i <= 7; i = i+1) begin
                if(x[i] == 1) begin
                    y = i[2:0];
                    tag = 1;
                end
            end
        end
        else begin
            tag = 0;
            y = 0;
        end

        // 数码管显示
        begin
            case (y)
                3'b000:
                    bcd7seg = 8'b00000010;  //0
                3'b001:
                    bcd7seg = 8'b10011111;  //1
                3'b010:
                    bcd7seg = 8'b00100101;  //2
                3'b011:
                    bcd7seg = 8'b00001101;  //3
                3'b100:
                    bcd7seg = 8'b10011001;  //4
                3'b101:
                    bcd7seg = 8'b01001001;  //5
                3'b110:
                    bcd7seg = 8'b01000001;  //6
                3'b111:
                    bcd7seg = 8'b00011111;  //7
                default:
                    bcd7seg = 8'b00000010;
            endcase
        end
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

    encode83 encode(
                 .x(sw[7:0]),
                 .en(sw[8]),
                 .y(ledr[2:0]),
                 .tag(ledr[3]),
                 .bcd7seg(seg0[7:0])
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

