#ifndef SPRITE_OAM_H
#define SPRITE_OAM_H

#include "hardware_sprite_buffer.hh"

// Hardware coordinates are wrapped unsigned values; archive OAM records
// use the separate signed-offset view in hardware_sprite_buffer.hh.
struct HardwareSpriteOamEntry {
    u32 y : 8;
    u32 affine_mode : 2;
    u32 object_mode : 2;
    u32 mosaic : 1;
    u32 color_mode : 1;
    u32 shape : 2;
    u32 x : 9;
    u32 affine_index_low : 3;
    u32 horizontal_flip : 1;
    u32 vertical_flip : 1;
    u32 size : 2;
    u16 tile_index : 10;
    u16 priority : 2;
    u16 palette_bank : 4;
    u16 affine_coefficient;
};

EXTERN_C

// Builds a regular 4bpp OAM entry with mosaic enabled and zero affine coefficient.
// Coordinates and fields wrap to their hardware widths.
struct HardwareSpriteOamEntry InitializeMosaicSpriteOam(
    u32 x, u32 y, u32 tile,
    u32 palette, u32 priority, u32 size, u32 shape);

EXTERN_C_END

#endif // SPRITE_OAM_H
