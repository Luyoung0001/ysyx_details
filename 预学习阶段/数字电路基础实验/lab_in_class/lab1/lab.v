module bit_operations;
    // 定义寄存器型输入
    reg [3:0] a, b;
    reg [3:0] c;
    reg result;

    initial begin
        // 初始化值
        a = 4'b1011;
        b = 4'b0101;

        // 执行位运算
        c = a << 3; // 左移3位
        $display("c = a << 3: %b", c);

        c = b >> 2; // 右移2位
        $display("c = b >> 2: %b", c);

        c = a | b; // 按位或
        $display("c = a | b: %b", c);

        c = a ^ b; // 按位异或
        $display("c = a ^ b: %b", c);

        c = a & b; // 按位与
        $display("c = a & b: %b", c);

        // 执行逻辑运算
        result = a || b; // 逻辑或
        $display("a || b: %b", result);

        result = a && b; // 逻辑与
        $display("a && b: %b", result);

        result = !a; // 逻辑非
        $display("!a: %b", result);

        // 执行归约运算
        result = &b; // 按位与归约
        $display("&b: %b", result);

        result = |a; // 按位或归约
        $display("|a: %b", result);

        result = ^a; // 按位异或归约
        $display("^a: %b", result);

        $finish; // 结束仿真
    end
endmodule