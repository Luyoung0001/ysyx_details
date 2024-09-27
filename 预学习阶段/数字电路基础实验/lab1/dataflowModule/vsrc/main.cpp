#include <iostream>
#include "Vreg1bit.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vreg1bit* reg = new Vreg1bit;

    Verilated::traceEverOn(true);
    VerilatedVcdC* vcd = new VerilatedVcdC;
    reg->trace(vcd, 99);
    vcd->open("dump.vcd");

    // 仿真周期
    for (int i = 0; i < 10; ++i) {
        // 根据时间设置输入信号

        if (i % 2 == 0) {
            reg->d = 1;
            reg->rst_n = 0;
        } else {
            reg->d = 0;
            reg->rst_n = 1;
        }
        reg->eval();
        vcd->dump(i);
        std::cout << "At time " << i << " d=" << (reg->d ? "1" : "0") << " rst_n=" << (reg->rst_n ? "1" : "0")  <<  " q=" << (reg->q ? "1" : "0")<< std::endl;
    }

    vcd->close();
    delete reg;
    return 0;
}
