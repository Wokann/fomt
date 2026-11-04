#ifndef SRAM_ACCESS_HH
#define SRAM_ACCESS_HH

#include "prelude.h"
#include "interrupt.hh"

EXTERN_C

// The error/status word and one-time initialization flag belong to the SRAM
// service, not to the unknown per-caller context storage below.
extern u16 gSramAccessStatus;
extern u8 gSramAccessInitialized;

void func_0800063C(void);
// The low two bits of context[4] select Timer 0..3. The other fields remain unknown.
InterruptHandler ExchangeTimerInterruptHandler(u8 const *context, InterruptHandler handler);

EXTERN_C_END

// The startup local and the name-entry core both reserve two words for this
// access context. Its constructor initializes the shared SRAM service;
// the contents of the context itself remain unknown here.
struct SramAccess
{
    u32 unk_00[2];
#ifdef __cplusplus
    SramAccess();
    // Preserve the native full-SRAM erase: ignore individual write failures.
    bool Erase();
    bool Read(void * destination, u32 offset, u32 size);
    bool Write(u32 offset, void const *source, u32 size);
    void AddStatusFlag(u16 flag);
#endif
};

typedef char SramAccessSizeCheck[(sizeof(struct SramAccess) == 8) ? 1 : -1];

#endif // SRAM_ACCESS_HH
