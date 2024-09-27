// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlab__Syms.h"


void Vlab___024root__trace_chg_sub_0(Vlab___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vlab___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root__trace_chg_top_0\n"); );
    // Init
    Vlab___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlab___024root*>(voidSelf);
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vlab___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vlab___024root__trace_chg_sub_0(Vlab___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgCData(oldp+0,(vlSelf->bit_operations__DOT__a),4);
        bufp->chgCData(oldp+1,(vlSelf->bit_operations__DOT__b),4);
        bufp->chgCData(oldp+2,(vlSelf->bit_operations__DOT__c),4);
        bufp->chgBit(oldp+3,(vlSelf->bit_operations__DOT__result));
    }
}

void Vlab___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root__trace_cleanup\n"); );
    // Init
    Vlab___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlab___024root*>(voidSelf);
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
}
