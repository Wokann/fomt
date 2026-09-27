#ifndef HARDWARE_DISPLAY_OUTPUT_HH
#define HARDWARE_DISPLAY_OUTPUT_HH

#include "prelude.h"

struct HardwareDisplayState {
    u32 control;
    u8 unk_04[0x1C];
    u16 matrix_a[4];
    u8 unk_28[8];
    u16 matrix_b[4];
    u8 unk_38[0x20];
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
