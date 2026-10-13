#ifndef INTERRUPT_HH
#define INTERRUPT_HH

#include "prelude.h"

EXTERN_C

// The ROM-facing packed-mask entry executes ARM code in IWRAM. Request the
// ordinary indirect interworking call, rather than an out-of-range Thumb BL.
u16 func_03000A1C(u32 value) __attribute__((long_call));

void func_080004C4(void);
u16 func_080004F4(u32 value);
u16 func_0800050C(u16 value);
u16 func_08000528(u16 value);
u16 func_08000540(u32 index, u16 value);
void func_08000554(u16 value);
void func_08000568(u16 value);
u32 func_0800057C(u32 unused, u32 value);
u32 func_08000580(u32 unused, u32 value);
void *func_08000584(u32 size);
void func_08000590(void *pointer);

EXTERN_C_END

#endif // INTERRUPT_HH
