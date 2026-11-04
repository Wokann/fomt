#ifndef HARDWARE_SPRITE_BUFFER_HH
#define HARDWARE_SPRITE_BUFFER_HH

#include "prelude.h"

// OAM field values, using the hardware names shared with pokeemerald.
#define ST_OAM_OBJ_NORMAL 0
#define ST_OAM_OBJ_BLEND 1
#define ST_OAM_OBJ_WINDOW 2
#define ST_OAM_SQUARE 0
#define ST_OAM_H_RECTANGLE 1
#define ST_OAM_V_RECTANGLE 2
#define ST_OAM_SIZE_0 0
#define ST_OAM_SIZE_1 1
#define ST_OAM_SIZE_2 2
#define ST_OAM_SIZE_3 3

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
    HardwareSpriteBufferState(u8 byte1, u8 byte3);
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
// The IWRAM renderer loads each width/height pair as one little-endian
// halfword. Keep the real two-byte layout in both C and old agbcp.
struct HardwareSpriteDimensions {
    u8 width;
    u8 height;
} PACKED;

typedef char HardwareSpriteDimensionsSizeCheck[sizeof(struct HardwareSpriteDimensions) == 2 ? 1 : -1];
typedef char HardwareSpriteDimensionsHeightCheck[offsetof(struct HardwareSpriteDimensions, height) == 1 ? 1 : -1];

EXTERN_C

// Shape rows: square, horizontal, vertical. Columns are OAM size 0..3.
extern struct HardwareSpriteDimensions const gHardwareSpriteDimensions[3][4];

void ResetHardwareSpriteBuffer(struct HardwareSpriteBufferState * object);
void WriteAndResetHardwareSpriteBuffer(struct HardwareSpriteBufferState * object);
void WriteAndResetHardwareSpriteBufferWithBios(struct HardwareSpriteBufferState * object);
void WriteAndResetPrioritizedHardwareSpriteBuffer(struct HardwareSpriteBufferState * object);


void WriteHardwareSpriteBuffer(struct HardwareSpriteBufferState * buffer);
void WriteHardwareSpriteBufferWithBios(struct HardwareSpriteBufferState * buffer);
void WritePrioritizedHardwareSpriteBuffer(struct HardwareSpriteBufferState * buffer);

EXTERN_C_END

#endif // HARDWARE_SPRITE_BUFFER_HH
