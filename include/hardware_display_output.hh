#ifndef HARDWARE_DISPLAY_OUTPUT_HH
#define HARDWARE_DISPLAY_OUTPUT_HH

#include "prelude.h"

struct HardwareDisplayState {
    u32 control;
    u16 status;
    u8 unk_06[0x1A];
    u16 matrix_a[4];
    u8 unk_28[8];
    u16 matrix_b[4];
    u8 unk_38[0x20];
#ifdef __cplusplus
    HardwareDisplayState() asm("func_080096B0");
#endif
};

struct HardwareSpriteBufferState {
    u8 bytes[0x404];
#ifdef __cplusplus
    HardwareSpriteBufferState(u8 byte1, u8 byte3) asm("func_08009744");
#endif
};

struct HardwareSpriteBufferParameters {
    u8 byte1;
    u8 byte3;
};

EXTERN_C

struct HardwareDisplayState * func_080096B0(struct HardwareDisplayState * object);
void func_080096F0(void * object);
void func_08009710(void * object);
void * func_08009744(void * object, u8 byte1, u8 byte3);
void func_0800977C(void * object);
void func_08009790(void * object);
void func_080097A4(u8 * buffer);

EXTERN_C_END

#endif // HARDWARE_DISPLAY_OUTPUT_HH
