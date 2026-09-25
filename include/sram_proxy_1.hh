#ifndef SRAM_PROXY_1_HH
#define SRAM_PROXY_1_HH

#include "prelude.h"

EXTERN_C

// Fixed 32-byte header used to identify a valid FOMT SRAM image.
extern char const gSramImageSignature[32];

u8 func_080002E0(void *source);
void func_08000358(void *destination);
u32 func_080003A0(void *source);
u32 func_080003DC(u32 unused, u32 index);
void func_080003E8(void *source, u32 index);
void func_0800042C(void *source, u32 index);
void func_08000470(void *destination, u32 value);
u32 func_08000488(void *source);

EXTERN_C_END

#endif // SRAM_PROXY_1_HH
