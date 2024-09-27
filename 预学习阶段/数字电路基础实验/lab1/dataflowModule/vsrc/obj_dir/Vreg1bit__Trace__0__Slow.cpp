// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vreg1bit__Syms.h"


VL_ATTR_COLD void Vreg1bit___024root__trace_init_sub__TOP__0(Vreg1bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg1bit___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+1,"rst_n", false,-1);
    tracep->declBit(c+2,"d", false,-1);
    tracep->declBit(c+3,"q", false,-1);
    tracep->pushNamePrefix("reg1bit ");
    tracep->declBit(c+1,"rst_n", false,-1);
    tracep->declBit(c+2,"d", false,-1);
    tracep->declBit(c+3,"q", false,-1);
    tracep->popNamePrefix(1);
}

VL_ATTR_COLD void Vreg1bit___024root__trace_init_top(Vreg1bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg1bit___024root__trace_init_top\n"); );
    // Body
    Vreg1bit___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vreg1bit___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vreg1bit___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vreg1bit___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vreg1bit___024root__trace_register(Vreg1bit___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg1bit___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vreg1bit___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vreg1bit___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vreg1bit___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vreg1bit___024root__trace_full_sub_0(Vreg1bit___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vreg1bit___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg1bit___024root__trace_full_top_0\n"); );
    // Init
    Vreg1bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vreg1bit___024root*>(voidSelf);
    Vreg1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vreg1bit___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vreg1bit___024root__trace_full_sub_0(Vreg1bit___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vreg1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vreg1bit___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->rst_n));
    bufp->fullBit(oldp+2,(vlSelf->d));
    bufp->fullBit(oldp+3,(vlSelf->q));
}
