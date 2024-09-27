#include "Vmux21c.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vmux21c* top = new Vmux21c;  // 创建模块实例

    Verilated::traceEverOn(true);  // 打开波形跟踪
    VerilatedVcdC* vcd = new VerilatedVcdC;
    top->trace(vcd, 99);
    vcd->open("dump.vcd");

    for (int i = 0; i < 10; ++i) {
        top->s = i % 2;
        top->a = 0;  // 输入 a
        top->b = 1;  // 输入 b
        top->eval();

        vcd->dump(i);  // 保存当前状态到 VCD

        // 打印输出以便验证
        std::cout << "At time " << i << " s=" << (top->s ? "1" : "0") << " y=" << (top->y ? "1" : "0") << std::endl;
    }

    vcd->close();  // 关闭 VCD 文件
    delete top;  // 清理
    exit(0);
}
