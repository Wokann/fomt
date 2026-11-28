#include "sprite_oam.h"

struct HardwareSpriteOamEntry InitializeMosaicSpriteOam(
    u32 x, u32 y, u32 tile,
    u32 palette, u32 priority, u32 size, u32 shape)
{
    struct HardwareSpriteOamEntry value = { 0 };
    value.mosaic = 1;
    value.y += y;
    value.x += x;
    value.tile_index += tile;
    value.palette_bank += palette;
    value.priority += priority;
    value.shape += shape;
    value.size += size;
    return value;
}
