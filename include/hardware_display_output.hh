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
    HardwareDisplayState() asm("func_080096B0");

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

// The indexed sprite archive and the hardware buffer use the same native
// eight-byte OAM record. Coordinates are signed offsets in archive records;
// hardware writes retain their wrapped eight-/nine-bit representation.
// The top two matrix-index bits are the flip bits in non-affine mode.
struct HardwareSpriteOamRecord {
    i32 y : 8;
    u32 affine_mode : 2;
    u32 object_mode : 2;
    u32 mosaic : 1;
    u32 color_mode : 1;
    u32 shape : 2;
    i32 x : 9;
    u32 affine_index_low : 3;
    u32 horizontal_flip : 1;
    u32 vertical_flip : 1;
    u32 size : 2;
    u16 tile_index : 10;
    u16 priority : 2;
    u16 palette_bank : 4;
    u16 affine_coefficient;
};

// The UI emitter updates attr1 as a halfword, not as the complete attr0/1
// word. Bits 9..13 select an affine matrix; their upper two bits are the
// non-affine horizontal/vertical flip flags. This view preserves both forms.
struct HardwareSpriteHorizontalAttribute {
    i16 x : 9;
    u16 affine_index : 5;
    u16 size : 2;
} __attribute__((packed, aligned(2)));

struct HardwareSpriteOamAttributes {
    u16 vertical;
    struct HardwareSpriteHorizontalAttribute horizontal;
    u16 tile_palette;
    u16 affine_coefficient;
};

typedef char HardwareSpriteHorizontalAttribute_size_check[
    sizeof(struct HardwareSpriteHorizontalAttribute) == 2 ? 1 : -1];
typedef char HardwareSpriteOamAttributes_size_check[
    sizeof(struct HardwareSpriteOamAttributes) == 8 ? 1 : -1];
typedef char HardwareSpriteOamAttributes_horizontal_offset_check[
    offsetof(struct HardwareSpriteOamAttributes, horizontal) == 2 ? 1 : -1];
typedef char HardwareSpriteOamAttributes_coefficient_offset_check[
    offsetof(struct HardwareSpriteOamAttributes, affine_coefficient) == 6 ? 1 : -1];

struct HardwareSpriteBufferState {
    u8 sprite_count;
    u8 reset_sprite_count;
    u8 matrix_count;
    u8 reset_matrix_count;
    struct HardwareSpriteOamRecord sprites[128];
#ifdef __cplusplus
    HardwareSpriteBufferState(u8 byte1, u8 byte3) asm("func_08009744");
#endif
};

typedef char HardwareSpriteOamRecord_size_check[sizeof(struct HardwareSpriteOamRecord) == 8 ? 1 : -1];
typedef char HardwareSpriteOamRecord_coefficient_offset_check[offsetof(struct HardwareSpriteOamRecord, affine_coefficient) == 6 ? 1 : -1];
typedef char HardwareSpriteBufferState_size_check[sizeof(struct HardwareSpriteBufferState) == 0x404 ? 1 : -1];
typedef char HardwareSpriteBufferState_sprites_offset_check[offsetof(struct HardwareSpriteBufferState, sprites) == 4 ? 1 : -1];

struct HardwareSpriteBufferParameters {
    u8 byte1;
    u8 byte3;
#ifdef __cplusplus
    HardwareSpriteBufferParameters(u8 a_byte1, u8 a_byte3)
        : byte1(a_byte1), byte3(a_byte3) {}
#endif
};

EXTERN_C

struct HardwareBootstrap;
void func_08008724(struct HardwareBootstrap * owner) SECTION(".text.hardware_display_control_commands");
void func_08008774(struct HardwareBootstrap * owner) SECTION(".text.hardware_display_control_commands");

struct HardwareDisplayState * func_080096B0(struct HardwareDisplayState * object);
void WriteHardwareDisplayState(struct HardwareDisplayState * object);
void func_08009710(struct HardwareDisplayState * object);
void * func_08009744(void * object, u8 byte1, u8 byte3);
void func_0800977C(void * object);
void func_08009790(void * object);
void func_080097A4(u8 * buffer);

EXTERN_C_END

#endif // HARDWARE_DISPLAY_OUTPUT_HH
