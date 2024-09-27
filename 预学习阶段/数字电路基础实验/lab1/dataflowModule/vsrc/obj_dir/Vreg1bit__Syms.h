// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VREG1BIT__SYMS_H_
#define VERILATED_VREG1BIT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vreg1bit.h"

// INCLUDE MODULE CLASSES
#include "Vreg1bit___024root.h"

// SYMS CLASS (contains all model state)
class Vreg1bit__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vreg1bit* const __Vm_modelp;
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vreg1bit___024root             TOP;

    // CONSTRUCTORS
    Vreg1bit__Syms(VerilatedContext* contextp, const char* namep, Vreg1bit* modelp);
    ~Vreg1bit__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
