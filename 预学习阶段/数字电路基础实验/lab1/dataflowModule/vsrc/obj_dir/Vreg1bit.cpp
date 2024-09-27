// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vreg1bit.h"
#include "Vreg1bit__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vreg1bit::Vreg1bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vreg1bit__Syms(contextp(), _vcname__, this)}
    , rst_n{vlSymsp->TOP.rst_n}
    , d{vlSymsp->TOP.d}
    , q{vlSymsp->TOP.q}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vreg1bit::Vreg1bit(const char* _vcname__)
    : Vreg1bit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vreg1bit::~Vreg1bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vreg1bit___024root___eval_debug_assertions(Vreg1bit___024root* vlSelf);
#endif  // VL_DEBUG
void Vreg1bit___024root___eval_static(Vreg1bit___024root* vlSelf);
void Vreg1bit___024root___eval_initial(Vreg1bit___024root* vlSelf);
void Vreg1bit___024root___eval_settle(Vreg1bit___024root* vlSelf);
void Vreg1bit___024root___eval(Vreg1bit___024root* vlSelf);

void Vreg1bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vreg1bit::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vreg1bit___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vreg1bit___024root___eval_static(&(vlSymsp->TOP));
        Vreg1bit___024root___eval_initial(&(vlSymsp->TOP));
        Vreg1bit___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vreg1bit___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vreg1bit::eventsPending() { return false; }

uint64_t Vreg1bit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vreg1bit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vreg1bit___024root___eval_final(Vreg1bit___024root* vlSelf);

VL_ATTR_COLD void Vreg1bit::final() {
    Vreg1bit___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vreg1bit::hierName() const { return vlSymsp->name(); }
const char* Vreg1bit::modelName() const { return "Vreg1bit"; }
unsigned Vreg1bit::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vreg1bit::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vreg1bit___024root__trace_init_top(Vreg1bit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vreg1bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vreg1bit___024root*>(voidSelf);
    Vreg1bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vreg1bit___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vreg1bit___024root__trace_register(Vreg1bit___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vreg1bit::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vreg1bit::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vreg1bit___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
