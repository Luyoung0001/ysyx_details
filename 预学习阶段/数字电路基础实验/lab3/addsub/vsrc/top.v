module add(sub_add_tag,in1,in2,out,carray,zero,overflow);
    input sub_add_tag;
    input [3:0] in1;
    input [3:0] in2;
    output reg [3:0] out;
    output reg carray;
    output reg zero;
    output reg overflow;

    reg [3:0] subs;
    reg [4:0] full_result;

    always @(*) begin
        subs = 4'b0000;
        full_result = 5'b00000;
        if (sub_add_tag) begin
            subs = ~(in2) + 1;
            full_result = in1 + subs;
        end
        else begin
            full_result = in1 + in2;
        end
        carray = full_result[4];
        out = full_result[3:0];
        zero = (out == 4'b0000);
        if (sub_add_tag) begin
            // 减法
            overflow = (in1[3] != subs[3]) && (out[3] != in1[3]);
        end
        else begin
            // 加法
            overflow = (in1[3] == in2[3]) && (out[3] != in1[3]);
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

    add adder(
            .sub_add_tag(sw[8]),
            .in1(sw[3:0]),
            .in2(sw[7:4]),
            .out(ledr[3:0]),
            .carray(ledr[4]),
            .overflow(ledr[5]),
            .zero(ledr[6])
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


