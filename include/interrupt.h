#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "interrupt_table.h"

EXTERN_C

// Low input halfword disables IE bits; the high halfword enables them.
// ROM callers additionally force Game Pak IRQ enabled and leave IME at one.
// The native IRQ-dispatcher path instead receives its mask in ip/r12 and
// restores the previous IME; do not invoke that path as an ordinary C call.
// The entry executes in IWRAM: use the actual indirect interworking call.
u16 ApplyInterruptEnableMask(u32 value) __attribute__((long_call));

// The BIOS calls the native ARM dispatcher in IWRAM.
void DispatchInterrupt(void);

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

#endif // INTERRUPT_H
