// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlab.h for the primary calling header

#include "verilated.h"

#include "Vlab___024root.h"

VL_ATTR_COLD void Vlab___024root___eval_static(Vlab___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vlab___024root___eval_initial__TOP(Vlab___024root* vlSelf);

VL_ATTR_COLD void Vlab___024root___eval_initial(Vlab___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root___eval_initial\n"); );
    // Body
    Vlab___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vlab___024root___eval_initial__TOP(Vlab___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->bit_operations__DOT__a = 0xbU;
    vlSelf->bit_operations__DOT__b = 5U;
    VL_WRITEF("c = a << 3: 1000\nc = b >> 2: 0001\nc = a | b: 1111\nc = a ^ b: 1110\n");
    vlSelf->bit_operations__DOT__c = 1U;
    VL_WRITEF("c = a & b: 0001\na || b: 1\na && b: 1\n!a: 0\n&b: 0\n|a: 1\n");
    vlSelf->bit_operations__DOT__result = 1U;
    VL_WRITEF("^a: 1\n");
    VL_FINISH_MT("lab.v", 48, "");
}

VL_ATTR_COLD void Vlab___024root___eval_final(Vlab___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vlab___024root___eval_settle(Vlab___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlab___024root___dump_triggers__act(Vlab___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlab___024root___dump_triggers__nba(Vlab___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlab___024root___ctor_var_reset(Vlab___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->bit_operations__DOT__a = VL_RAND_RESET_I(4);
    vlSelf->bit_operations__DOT__b = VL_RAND_RESET_I(4);
    vlSelf->bit_operations__DOT__c = VL_RAND_RESET_I(4);
    vlSelf->bit_operations__DOT__result = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
