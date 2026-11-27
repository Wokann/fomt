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

inline void WriteHardwareDisplayFlags(u16 & destination, u16 flags)
{
    destination = ReadHardwareDisplayHalfword(flags);
}

inline void WriteHardwareDisplayRegister(u16 & destination, u16 input)
{
    u16 const & value = input;
    destination = value;
}

struct HardwareDisplayRegisterValue {
    u16 value;

    HardwareDisplayRegisterValue() {}

    template<class Integer>
    HardwareDisplayRegisterValue & operator=(Integer input)
    {
        WriteHardwareDisplayHalfword(value, input);
        return *this;
    }

    HardwareDisplayRegisterValue & operator=(u16 const & input)
    {
        WriteHardwareDisplayHalfword(value, input);
        return *this;
    }

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

    void SetDisplayFlags(u16 flags)
    {
        control.dispcnt = ReadHardwareDisplayHalfword(flags);
    }

    void SetBackgroundFlags(u32 layer, u16 flags)
    {
        background_control[layer] = ReadHardwareDisplayHalfword(flags);
    }

    void SetHorizontalOffset(u32 layer, u16 offset)
    {
        u16 const & value = offset;
        background_scroll[layer][0] = value;
    }

    void SetVerticalOffset(u32 layer, u16 offset)
    {
        u16 const & value = offset;
        background_scroll[layer][1] = value;
    }

    void SetDisplayControl(HardwareDisplayRegisterValue const & input)
    {
        WriteHardwareDisplayHalfword(control.dispcnt, input.value);
    }

    void SetBlendControl(HardwareDisplayRegisterValue const & control)
    {
        WriteHardwareDisplayHalfword(blend_control, control.value);
    }

    void SetBackgroundX(unsigned int index, HardwareDisplayRegisterValue const & input)
    {
        WriteHardwareDisplayHalfword(background_scroll[index][0],
            ReadHardwareDisplayHalfword(input.value));
    }

    void SetBackgroundY(unsigned int index, HardwareDisplayRegisterValue const & input)
    {
        WriteHardwareDisplayHalfword(background_scroll[index][1],
            ReadHardwareDisplayHalfword(input.value));
    }

    void SetBackgroundControl(unsigned int index, HardwareDisplayRegisterValue const & input)
    {
        WriteHardwareDisplayHalfword(background_control[index],
            ReadHardwareDisplayHalfword(input.value));
    }
#endif
};
#ifdef __cplusplus
inline void WriteHardwareDisplayRegister(HardwareDisplayState & display,
    u16 HardwareDisplayState::* field, u16 input)
{
    u16 const & value = input;
    display.*field = value;
}
#endif




EXTERN_C

// Upload the display shadow with DMA, then write BLDY as a halfword.
void WriteHardwareDisplayState(struct HardwareDisplayState * state);
// This original BIOS path ends with a separate BG1 scroll write.
void WriteHardwareDisplayStateWithBios(struct HardwareDisplayState * state);

EXTERN_C_END

#endif // HARDWARE_DISPLAY_STATE_HH
