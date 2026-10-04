#ifndef HARDWARE_STATE_PROPERTIES_HH
#define HARDWARE_STATE_PROPERTIES_HH

#include "prelude.h"

EXTERN_C

extern u8 * gUnk_03000408;

u16 func_08007E8C(void);
u32 func_08007EA0(void);
void func_08007EA8(u8 * state);
void func_08007EC8(u8 * state);
void func_08007EE8(u8 * state, u32 offset, u32 length);
void func_08007F84(u8 * state, u32 offset, u32 length);
void func_080080A0(u8 * state, u32 offset, u32 kind);
u8 func_080080EC(u8 const * state);
u8 func_080080F0(u8 const * state);

EXTERN_C_END

#endif // HARDWARE_STATE_PROPERTIES_HH
