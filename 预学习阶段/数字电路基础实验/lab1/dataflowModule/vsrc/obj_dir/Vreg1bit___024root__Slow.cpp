// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vreg1bit.h for the primary calling header

#include "verilated.h"

#include "Vreg1bit__Syms.h"
#include "Vreg1bit___024root.h"

void Vreg1bit___024root___ctor_var_reset(Vreg1bit___024root* vlSelf);

Vreg1bit___024root::Vreg1bit___024root(Vreg1bit__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vreg1bit___024root___ctor_var_reset(this);
}

void Vreg1bit___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vreg1bit___024root::~Vreg1bit___024root() {
}
