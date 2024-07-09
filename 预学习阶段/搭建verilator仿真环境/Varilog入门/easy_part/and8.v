// y = a[7] & a[6] & a[5] & a[4] & a[3] & a[2] & a[1] & a[0];

module and8(
    input [7:0]  a,
    output y

);
    assign y = &a; // 当然也可以一个一个进行与运算，但前面这种写法很简单
endmodule