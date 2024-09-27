// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmux21c.h for the primary calling header

#include "verilated.h"

#include "Vmux21c__Syms.h"
#include "Vmux21c___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux21c___024root___dump_triggers__ico(Vmux21c___024root* vlSelf);
#endif  // VL_DEBUG

void Vmux21c___024root___eval_triggers__ico(Vmux21c___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21c__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21c___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.at(0U) = (0U == vlSelf->__VicoIterCount);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmux21c___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmux21c___024root___dump_triggers__act(Vmux21c___024root* vlSelf);
#endif  // VL_DEBUG

void Vmux21c___024root___eval_triggers__act(Vmux21c___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vmux21c__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmux21c___024root___eval_triggers__act\n"); );
    // Body
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vmux21c___024root___dump_triggers__act(vlSelf);
    }
#endif
}
