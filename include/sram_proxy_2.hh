#ifndef SRAM_PROXY_2_HH
#define SRAM_PROXY_2_HH

#include "prelude.h"

EXTERN_C

extern u8 gUnk_03000402;

void func_0800063C(void);
void *func_08000640(void *source);
u32 func_08000664(void *destination);
u32 func_080006A4(void *destination, u32 offset, void const *source, u32 size);
u32 func_080006E4(void *source, void *destination, u32 offset, u32 size);
u32 func_08000714(u8 const *context, void (*handler)(void));
void func_08000728(void *destination, u16 flag);

EXTERN_C_END

#endif // SRAM_PROXY_2_HH
