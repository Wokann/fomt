#ifndef HARDWARE_DISPLAY_OUTPUT_HH
#define HARDWARE_DISPLAY_OUTPUT_HH

#include "prelude.h"

#ifdef __cplusplus
// Display writes are halfword-sized even though this compiler rounds a
// standalone C++ value object up to a word.  Store through a halfword
// reference so a field assignment never becomes a wider bitfield update.
inline void WriteHardwareDisplayHalfword(u16 & destination, u16 value)
{
    destination = value;
}

struct HardwareDisplayRegisterValue {
    u16 value;

    HardwareDisplayRegisterValue(u16 input)
    {
        WriteHardwareDisplayHalfword(value, input);
    }

    HardwareDisplayRegisterValue(HardwareDisplayRegisterValue const & input)
    {
        WriteHardwareDisplayHalfword(value, input.value);
    }
};
#endif

struct HardwareDisplayState {
    u32 control;
    u16 status;
    u8 unk_06[0x1A];
    u16 matrix_a[4];
    u8 unk_28[8];
    u16 matrix_b[4];
    u8 unk_38[0x18];
    u16 blend_control;
    u16 blend_alpha;
    u16 blend_brightness;
    u16 unk_56;
#ifdef __cplusplus
    HardwareDisplayState() asm("func_080096B0");

    void SetBlendControl(HardwareDisplayRegisterValue const & control)
    {
        WriteHardwareDisplayHalfword(blend_control, control.value);
    }
#endif
};

typedef char HardwareDisplayState_size_check[(sizeof(struct HardwareDisplayState) == 0x58) ? 1 : -1];
typedef char HardwareDisplayState_blend_control_offset_check[(offsetof(struct HardwareDisplayState, blend_control) == 0x50) ? 1 : -1];

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
