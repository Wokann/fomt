#include "interrupt.hh"
#include "gbaio.h"
#include "gbasvc.h"

u16 gInterruptNestingMasks[16];
InterruptHandler gInterruptHandlers[16];

void InitializeInterrupts(void)
{
    u32 index;
    DisableInterrupts(0xFFFF);
    INTR_VECTOR = DispatchInterrupt;
    for (index = 0; index <= 13; index++)
        ExchangeInterruptHandler(index, 0);
}

u16 EnableInterrupts(u32 value)
{
    return ApplyInterruptEnableMask(value << 16);
}

u16 AcknowledgeAndEnableInterrupts(u16 value)
{
    REG_IF = value;
    return EnableInterrupts(value);
}

u16 DisableInterrupts(u16 value)
{
    return ApplyInterruptEnableMask(value);
}

u16 SetInterruptNestingMask(u32 index, u16 value)
{
    return ExchangeInterruptNestingMask(index, value);
}

void WaitForInterruptFlags(u16 value)
{
    IntrWait(0, value);
}

void WaitForNextInterrupt(u16 value)
{
    IntrWait(1, value);
}

// These two forwarding entries have no identified callers and retain unknown
// names; do not infer an IRQ API from physical adjacency alone.
u32 func_0800057C(u32 unused, u32 value)
{
    return value;
}

u32 func_08000580(u32 unused, u32 value)
{
    return value;
}
