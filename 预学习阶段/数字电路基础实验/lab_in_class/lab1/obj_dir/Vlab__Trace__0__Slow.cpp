// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlab__Syms.h"


VL_ATTR_COLD void Vlab___024root__trace_init_sub__TOP__0(Vlab___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushNamePrefix("bit_operations ");
    tracep->declBus(c+1,"a", false,-1, 3,0);
    tracep->declBus(c+2,"b", false,-1, 3,0);
    tracep->declBus(c+3,"c", false,-1, 3,0);
    tracep->declBit(c+4,"result", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vlab___024root__trace_init_top(Vlab___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root__trace_init_top\n"); );
    // Body
    Vlab___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vlab___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vlab___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vlab___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vlab___024root__trace_register(Vlab___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vlab___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vlab___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vlab___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vlab___024root__trace_full_sub_0(Vlab___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vlab___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root__trace_full_top_0\n"); );
    // Init
    Vlab___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlab___024root*>(voidSelf);
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vlab___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vlab___024root__trace_full_sub_0(Vlab___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vlab__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlab___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->bit_operations__DOT__a),4);
    bufp->fullCData(oldp+2,(vlSelf->bit_operations__DOT__b),4);
    bufp->fullCData(oldp+3,(vlSelf->bit_operations__DOT__c),4);
    bufp->fullBit(oldp+4,(vlSelf->bit_operations__DOT__result));
}
