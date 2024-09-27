module reg1bit (rst_n,d,q);
    input rst_n,d;
    output reg q;
    always @(*)
        if (rst_n == 1)
            q = 1'b0;  // Reset the output to 0
        else
            q = d;     // On clock edge, load the input data

endmodule
