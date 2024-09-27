// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlab.h for the primary calling header

#include "verilated.h"

#include "Vlab__Syms.h"
#include "Vlab___024root.h"

void Vlab___024root___ctor_var_reset(Vlab___024root* vlSelf);

Vlab___024root::Vlab___024root(Vlab__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vlab___024root___ctor_var_reset(this);
}

void Vlab___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vlab___024root::~Vlab___024root() {
}
