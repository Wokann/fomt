#ifndef INTERRUPT_HH
#define INTERRUPT_HH

#include "prelude.h"

EXTERN_C

typedef void (*InterruptHandler)(void);

// Each IRQ slot has a nesting-enable mask and a callback. The ARM dispatcher
// intersects this mask with IE before invoking the corresponding callback.
extern u16 gInterruptNestingMasks[16];
extern InterruptHandler gInterruptHandlers[16];

// Exchange one slot without adding bounds checks absent from the original.
InterruptHandler ExchangeInterruptHandler(u32 index, InterruptHandler handler);
u16 ExchangeInterruptNestingMask(u32 index, u16 value);

// Low input halfword disables IE bits; the high halfword enables them.
// ROM callers additionally force Game Pak IRQ enabled and leave IME at one.
// The native IRQ-dispatcher path instead receives its mask in ip/r12 and
// restores the previous IME; do not invoke that path as an ordinary C call.
// The entry executes in IWRAM: use the actual indirect interworking call.
u16 ApplyInterruptEnableMask(u32 value) __attribute__((long_call));

void InitializeInterrupts(void);
u16 EnableInterrupts(u32 value);
u16 AcknowledgeAndEnableInterrupts(u16 value);
u16 DisableInterrupts(u16 value);
u16 SetInterruptNestingMask(u32 index, u16 value);
// Preserve the distinct native BIOS arguments: IntrWait(0, flags) and (1, flags).
void WaitForInterruptFlags(u16 value);
void WaitForNextInterrupt(u16 value);
u32 func_0800057C(u32 unused, u32 value);
u32 func_08000580(u32 unused, u32 value);

EXTERN_C_END

#endif // INTERRUPT_HH
