module add(logic_tag,in1,in2,out,carray,zero,overflow);
    input [2:0]logic_tag;
    input [3:0] in1;
    input [3:0] in2;
    output reg [3:0] out;
    output reg carray;
    output reg zero;
    output reg overflow;

    reg [3:0] subs;
    reg [4:0] full_result;
    always@(logic_tag or in1 or in2) begin
        out = 4'b0000;
        subs = 4'b0000;
        case(logic_tag)
            3'b010:
                out = ~in1;
            3'b011:
                out = in1 & in2;
            3'b100:
                out = in1 | in2;
            3'b101:
                out = in1 ^ in2;
            3'b110: begin
                // 直接减
                subs = ~in2;
                {carray,out} = in1 + subs+1'b1;
                overflow = (in1[3] == subs[3]) && (out[3] != in1[3]);
                if(overflow == 0)
                    out = (out[3] == 0? 4'b0000:4'b0001);
                else begin
                    // 如果 out 符号位为 0，说明 A 是负数，B 是正数
                    if(out[3] == 0) out = 4'b0001;
                    else out = 4'b0000;
                end
                    // 如果溢出，原始符号位一定不同，只需要比较符号位就行
                    out = (in1[3] == 0 && in2[3] == 1)?4'b0000 : 4'b0001;


            end
            3'b111:
                out = (in1 == in2) ? 4'b0001:4'b0000;

            default: begin
                subs = ({4{logic_tag[0]}}^in2);
                {carray,out} = in1 + subs +{1'b0,logic_tag};
                overflow = (in1[3] == subs[3]) && (out[3] != in1[3]);
                zero = ~(|out);
            end

        endcase

    end


endmodule

module top(
        input clk,
        input rst,
        input [4:0] btn,
        input [10:0] sw,
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
            .logic_tag(sw[10:8]),
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


