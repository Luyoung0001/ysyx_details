module fsm(e,w,clk,z,state);
input wire e;
input wire w;
input wire clk;
output reg z;
output reg[3:0] state;

always @(clk) begin
     if(e) begin
        state <= {w,state[3:1]};
        case (state)
            4'b0000:z = 1'b1;
            4'b1111:z = 1'b1;
            default:z = 1'b0;
        endcase
     end else begin
            z = 1'b0;
            state <= 4'b0000;
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

    fsm FSM(
             .e(sw[0]),
             .w(sw[1]),
             .clk(sw[2]),
             .z(ledr[0]),
             .state(ledr[4:1])
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

