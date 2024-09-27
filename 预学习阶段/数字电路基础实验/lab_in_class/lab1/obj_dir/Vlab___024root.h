// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlab.h for the primary calling header

#ifndef VERILATED_VLAB___024ROOT_H_
#define VERILATED_VLAB___024ROOT_H_  // guard

#include "verilated.h"

class Vlab__Syms;

class Vlab___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*3:0*/ bit_operations__DOT__a;
    CData/*3:0*/ bit_operations__DOT__b;
    CData/*3:0*/ bit_operations__DOT__c;
    CData/*0:0*/ bit_operations__DOT__result;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 1> __Vm_traceActivity;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vlab__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vlab___024root(Vlab__Syms* symsp, const char* v__name);
    ~Vlab___024root();
    VL_UNCOPYABLE(Vlab___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
