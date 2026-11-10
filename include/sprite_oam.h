#ifndef SPRITE_OAM_H
#define SPRITE_OAM_H

#include "hardware_sprite_buffer.hh"

EXTERN_C

// Builds a regular 4bpp OAM entry with mosaic enabled and zero affine coefficient.
// Coordinates and fields wrap to their hardware widths; returns output unchanged.
struct HardwareSpriteOamRecord * InitializeMosaicSpriteOam(
    struct HardwareSpriteOamRecord * output, i32 x, i32 y, u32 tile,
    u32 palette, u32 priority, u32 size, u32 shape);

EXTERN_C_END

#endif // SPRITE_OAM_H
