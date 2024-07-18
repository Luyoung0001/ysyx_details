module move(ctl,out,clk,in,in1);
    input wire clk;
    input wire [7:0] in;
    input reg[2:0] ctl;
    input wire in1;
    output reg [7:0] out;
    reg temp_reg;
    always @(clk) begin
        case(ctl)
            3'b000:
                out <= 8'b0000_0000;
            3'b001:
                out <= in;
            3'b010:
                out <= {1'b0,out[7:1]};
            3'b011:
                out <= {out[6:0],1'b0};
            3'b100:
                out <= {out[7],out[7:1]};
            3'b101:
                out <= {in1,out[6:0]};
            3'b110:
                out <= {out[0],out[7:1]};
            3'b111:
                out <= {out[6:0],out[7]};
            default:
                out <=8'b0000_0000;
        endcase
    end
endmodule;

module top(
        input clk,
        input rst,
        input [4:0] btn,
        input [12:0] sw,
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

    move mv(
             .in(sw[7:0]),
             .in1(sw[8]),
             .clk(sw[9]),
             .out(ledr[7:0]),
             .ctl(sw[12:10])
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

