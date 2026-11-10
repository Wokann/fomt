#ifndef INTERRUPT_TABLE_H
#define INTERRUPT_TABLE_H

#include "prelude.h"

EXTERN_C

typedef void (*InterruptHandler)(void);

// DispatchInterrupt indexes these tables by the set bit in IE & IF.
enum {
    IRQ_INDEX_VBLANK = 0,
    IRQ_INDEX_VCOUNT = 2,
    IRQ_INDEX_TIMER_0 = 3,
    IRQ_INDEX_KEYPAD = 12,
    IRQ_INDEX_CARTRIDGE = 13
};

// Each IRQ slot has a nesting-enable mask and a callback. The ARM dispatcher
// intersects this mask with IE before invoking the corresponding callback.
extern u16 gInterruptNestingMasks[16];
extern InterruptHandler gInterruptHandlers[16];

// Exchange one slot without adding bounds checks absent from the original.
InterruptHandler ExchangeInterruptHandler(u32 index, InterruptHandler handler);
u16 ExchangeInterruptNestingMask(u32 index, u16 value);

EXTERN_C_END

#endif // INTERRUPT_TABLE_H
