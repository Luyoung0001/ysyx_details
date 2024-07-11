module divideby3FSM(
    input clk,
    input reset,
    output q
);
parameter s0 = 2'b00;
parameter s1 = 2'b01;
parameter s2 = 2'b10;

reg [1:0] state;
reg [1:0] nextstate;

always@(posedge clk, posedge reset)
    if(reset) state <= s0;
    else state <= nextstate;

always@(*)
    case (state)
        s0: nextstate = s1;
        s1: nextstate  =s2;
        s2: nextstate = s0;
        default: nextstate = s0;
    endcase

assign q = (state == s0);
endmodule