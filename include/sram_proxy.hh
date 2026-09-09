#ifndef SRAM_PROXY_HH
#define SRAM_PROXY_HH

#include "types.h"

extern u16 gUnk_03000400;

u32 func_080006A4(void *destination, u32 offset, void const *source, u32 size);
u32 func_080006E4(void *source, void *destination, u32 offset, u32 size);

#endif // SRAM_PROXY_HH
