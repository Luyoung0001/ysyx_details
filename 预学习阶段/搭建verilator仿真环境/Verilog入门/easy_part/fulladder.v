// {cout, s} = a + b + cin;
module fulladder(
    input a,
    input b,
    input cin,
    output cout,
    output s
);
wire p,g;
assign p = a^b;
assign g = a&b;

assign s = p ^ cin;
assign cout = g | (p & cin);

endmodule