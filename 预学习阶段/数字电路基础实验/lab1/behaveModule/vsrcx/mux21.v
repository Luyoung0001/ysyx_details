module mux21c(a,b,s,y);
input a,b,s;
output reg y;

always @ (*)
    if(s==0) y = a;
    else y = b;

endmodule
