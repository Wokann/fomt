#ifndef SRAM_PROXY_HH
#define SRAM_PROXY_HH

#include "prelude.h"

extern u16 gUnk_03000400;

// Fixed 32-byte header used to identify a valid FOMT SRAM image.
extern char const gSramImageSignature[32];

u32 func_080006A4(void *destination, u32 offset, void const *source, u32 size);
u32 func_080006E4(void *source, void *destination, u32 offset, u32 size);

#endif // SRAM_PROXY_HH
