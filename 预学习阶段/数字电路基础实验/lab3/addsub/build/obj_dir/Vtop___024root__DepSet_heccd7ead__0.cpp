// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ top__DOT____Vcellout__adder__zero;
    top__DOT____Vcellout__adder__zero = 0;
    CData/*0:0*/ top__DOT____Vcellout__adder__overflow;
    top__DOT____Vcellout__adder__overflow = 0;
    CData/*0:0*/ top__DOT____Vcellout__adder__carray;
    top__DOT____Vcellout__adder__carray = 0;
    CData/*3:0*/ top__DOT____Vcellout__adder__out;
    top__DOT____Vcellout__adder__out = 0;
    CData/*3:0*/ top__DOT__adder__DOT__subs;
    top__DOT__adder__DOT__subs = 0;
    // Body
    vlSelf->VGA_CLK = vlSelf->clk;
    top__DOT__adder__DOT__subs = 0U;
    if ((0x100U & (IData)(vlSelf->sw))) {
        top__DOT__adder__DOT__subs = (0xfU & ((IData)(1U) 
                                              + (~ 
                                                 ((IData)(vlSelf->sw) 
                                                  >> 4U))));
        vlSelf->top__DOT__adder__DOT__full_result = 
            (0x1fU & ((0xfU & (IData)(vlSelf->sw)) 
                      + (IData)(top__DOT__adder__DOT__subs)));
    } else {
        vlSelf->top__DOT__adder__DOT__full_result = 
            (0x1fU & ((0xfU & (IData)(vlSelf->sw)) 
                      + (0xfU & ((IData)(vlSelf->sw) 
                                 >> 4U))));
    }
    top__DOT____Vcellout__adder__carray = (1U & ((IData)(vlSelf->top__DOT__adder__DOT__full_result) 
                                                 >> 4U));
    top__DOT____Vcellout__adder__out = (0xfU & (IData)(vlSelf->top__DOT__adder__DOT__full_result));
    top__DOT____Vcellout__adder__overflow = ((0x100U 
                                              & (IData)(vlSelf->sw))
                                              ? (((1U 
                                                   & ((IData)(vlSelf->sw) 
                                                      >> 3U)) 
                                                  != 
                                                  (1U 
                                                   & ((IData)(top__DOT__adder__DOT__subs) 
                                                      >> 3U))) 
                                                 & ((1U 
                                                     & ((IData)(top__DOT____Vcellout__adder__out) 
                                                        >> 3U)) 
                                                    != 
                                                    (1U 
                                                     & ((IData)(vlSelf->sw) 
                                                        >> 3U))))
                                              : (((1U 
                                                   & ((IData)(vlSelf->sw) 
                                                      >> 3U)) 
                                                  == 
                                                  (1U 
                                                   & ((IData)(vlSelf->sw) 
                                                      >> 7U))) 
                                                 & ((1U 
                                                     & ((IData)(top__DOT____Vcellout__adder__out) 
                                                        >> 3U)) 
                                                    != 
                                                    (1U 
                                                     & ((IData)(vlSelf->sw) 
                                                        >> 3U)))));
    top__DOT____Vcellout__adder__zero = (0U == (IData)(top__DOT____Vcellout__adder__out));
    vlSelf->ledr = ((0xff80U & (IData)(vlSelf->ledr)) 
                    | (((IData)(top__DOT____Vcellout__adder__zero) 
                        << 6U) | (((IData)(top__DOT____Vcellout__adder__overflow) 
                                   << 5U) | (((IData)(top__DOT____Vcellout__adder__carray) 
                                              << 4U) 
                                             | (IData)(top__DOT____Vcellout__adder__out)))));
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    // Body
    if (vlSelf->__VicoTriggered.at(0U)) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
}

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
}

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Init
    CData/*0:0*/ __VicoContinue;
    VlTriggerVec<0> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    vlSelf->__VicoIterCount = 0U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        __VicoContinue = 0U;
        Vtop___024root___eval_triggers__ico(vlSelf);
        if (vlSelf->__VicoTriggered.any()) {
            __VicoContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VicoIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__ico(vlSelf);
#endif
                VL_FATAL_MT("/home/luyoung/ysyx_details/预学习阶段/数字电路基础实验/lab3/add/vsrc/top.v", 38, "", "Input combinational region did not converge.");
            }
            vlSelf->__VicoIterCount = ((IData)(1U) 
                                       + vlSelf->__VicoIterCount);
            Vtop___024root___eval_ico(vlSelf);
        }
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vtop___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vtop___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("/home/luyoung/ysyx_details/预学习阶段/数字电路基础实验/lab3/add/vsrc/top.v", 38, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vtop___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("/home/luyoung/ysyx_details/预学习阶段/数字电路基础实验/lab3/add/vsrc/top.v", 38, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vtop___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->btn & 0xe0U))) {
        Verilated::overWidthError("btn");}
    if (VL_UNLIKELY((vlSelf->sw & 0xfc00U))) {
        Verilated::overWidthError("sw");}
    if (VL_UNLIKELY((vlSelf->ps2_clk & 0xfeU))) {
        Verilated::overWidthError("ps2_clk");}
    if (VL_UNLIKELY((vlSelf->ps2_data & 0xfeU))) {
        Verilated::overWidthError("ps2_data");}
    if (VL_UNLIKELY((vlSelf->uart_rx & 0xfeU))) {
        Verilated::overWidthError("uart_rx");}
}
#endif  // VL_DEBUG
