// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vreg1bit.h for the primary calling header

#ifndef VERILATED_VREG1BIT___024ROOT_H_
#define VERILATED_VREG1BIT___024ROOT_H_  // guard

#include "verilated.h"

class Vreg1bit__Syms;

class Vreg1bit___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(rst_n,0,0);
    VL_IN8(d,0,0);
    VL_OUT8(q,0,0);
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vreg1bit__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vreg1bit___024root(Vreg1bit__Syms* symsp, const char* v__name);
    ~Vreg1bit___024root();
    VL_UNCOPYABLE(Vreg1bit___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
