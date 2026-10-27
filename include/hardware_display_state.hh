#ifndef HARDWARE_DISPLAY_STATE_HH
#define HARDWARE_DISPLAY_STATE_HH

#include "prelude.h"

#ifdef __cplusplus
// Display writes are halfword-sized even though this compiler rounds a
// standalone C++ value object up to a word.  Store through a halfword
// reference so a field assignment never becomes a wider bitfield update.
inline void WriteHardwareDisplayHalfword(u16 & destination, u16 value)
{
    destination = value;
}

inline u16 ReadHardwareDisplayHalfword(u16 const & value)
{
    return value;
}

struct HardwareDisplayRegisterValue {
    u16 value;

    HardwareDisplayRegisterValue(int input)
    {
        WriteHardwareDisplayHalfword(value, input);
    }

    HardwareDisplayRegisterValue(u16 const & input)
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
    // Full-word initialization and halfword DISPCNT updates are both native.
    union {
        u32 word;
        u16 dispcnt;
    } control;
    u16 status;
    u8 unk_06[2];
    u16 background_control[4];
    u16 background_scroll[4][2];
    u16 matrix_a[4];
    u8 unk_28[8];
    u16 matrix_b[4];
    u8 unk_38[0x14];
    u16 mosaic;
    u16 unk_4E;
    u16 blend_control;
    u16 blend_alpha;
    u16 blend_brightness;
    u16 unk_56;
#ifdef __cplusplus
    HardwareDisplayState();

    void SetBlendControl(HardwareDisplayRegisterValue const & control)
    {
        WriteHardwareDisplayHalfword(blend_control, control.value);
    }

    void SetBackgroundX(unsigned int index, HardwareDisplayRegisterValue const & input)
    {
        WriteHardwareDisplayHalfword(background_scroll[index][0],
            ReadHardwareDisplayHalfword(input.value));
    }
#endif
};

typedef char HardwareDisplayState_size_check[(sizeof(struct HardwareDisplayState) == 0x58) ? 1 : -1];
typedef char HardwareDisplayState_control_offset_check[(offsetof(struct HardwareDisplayState, control) == 0) ? 1 : -1];

typedef char HardwareDisplayState_background_control_offset_check[(offsetof(struct HardwareDisplayState, background_control) == 0x08) ? 1 : -1];
typedef char HardwareDisplayState_background_scroll_offset_check[(offsetof(struct HardwareDisplayState, background_scroll) == 0x10) ? 1 : -1];
typedef char HardwareDisplayState_mosaic_offset_check[(offsetof(struct HardwareDisplayState, mosaic) == 0x4C) ? 1 : -1];
typedef char HardwareDisplayState_blend_control_offset_check[(offsetof(struct HardwareDisplayState, blend_control) == 0x50) ? 1 : -1];

EXTERN_C

// Upload the display shadow with DMA, then write BLDY as a halfword.
void WriteHardwareDisplayState(struct HardwareDisplayState * state);
// This original BIOS path ends with a separate BG1 scroll write.
void WriteHardwareDisplayStateWithBios(struct HardwareDisplayState * state);

EXTERN_C_END

#endif // HARDWARE_DISPLAY_STATE_HH
