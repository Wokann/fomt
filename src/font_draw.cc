#include "font_draw.hh"

#include "gbasvc.h"

EXTERN_C

// The unmatched aligned compositors and rectangle fill remain explicit
// Thumb assembly in asm/font_draw.s; no register bindings are needed here.

// Fill every tile in a packed two-dimensional 4bpp buffer with one palette
// nibble. The size word carries tile width in its low half and height in its
// high half.
void Clear2DGfxBuffer(u32 size, void *buffer, u32 color)
{
    u32 color_word = color & 0xF;
    u32 temporary;

    temporary = color_word << 4;
    color_word |= temporary;
    temporary = color_word << 8;
    color_word |= temporary;
    temporary = color_word << 16;
    color_word |= temporary;

    temporary = (u16)size;
    temporary *= (size >> 16) << 5;

    u32 fill_color = color_word;
    CpuFastSet(&fill_color, buffer,
        CPUSET_SRC_FIXED | ((temporary >> 2) & 0x1FFFFF));
}

// Draws a terminated Shift-JIS byte stream. A double-width character is
// accumulated from two input bytes when the first byte produces no glyph.
void DrawStringTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string)
{
    u8 const *current = string;
    i32 maximum_x = (size << 16) >> 13;
    i32 character = 0;
    u8 byte = *current;

    while (byte != 0 && (u32)x < (u32)maximum_x) {
        u32 glyph_width;

        character |= byte;
        glyph_width = DrawCharacterGlyphTo2DGfxBuffer(size, buffer, x, y,
            character);
        switch (glyph_width) {
        case 1:
            character = 0;
            x += 8;
            break;
        case 0:
            break;
        case 2:
            character = 0;
            x += 16;
            break;
        default:
            return;
        }

        current++;
        byte = *current;
        character <<= 8;
    }
}

// Equivalent string walker for the extended glyph compositor. The two extra
// values are forwarded unchanged to every resolved character.
void DrawStringTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string, i32 foreground, i32 background)
{
    u8 const *current = string;
    i32 maximum_x = (size << 16) >> 13;
    i32 character = 0;
    u8 byte = *current;

    while (byte != 0 && (u32)x < (u32)maximum_x) {
        u32 glyph_width;

        character |= byte;
        glyph_width = DrawCharacterGlyphTo2DGfxBufferExt(size, buffer, x, y,
            character, foreground, background);
        switch (glyph_width) {
        case 1:
            character = 0;
            x += 8;
            break;
        case 0:
            break;
        case 2:
            character = 0;
            x += 16;
            break;
        default:
            return;
        }

        current++;
        byte = *current;
        character <<= 8;
    }
}

// The original game reserves two ABI-compatible unaligned glyph paths, but
// both are deliberate no-ops. They return zero and leave the destination
// untouched; callers already ignore the return value on their fallback path.
i32 DrawCharacterGlyphTo2DGfxBufferUnaligned(u32 size, void *buffer, i32 x,
    i32 y, void *glyph)
{
    return 0;
}

i32 DrawCharacterGlyphTo2DGfxBufferExtUnaligned(u32 size, void *buffer,
    i32 x, i32 y, void *glyph, i32 foreground, i32 background)
{
    return 0;
}

// Copy a complete packed 4bpp tile buffer. The low and high halves of size
// are its tile width and height respectively.
void Copy2DGfxBuffer(u32 size, void *destination, void const *source)
{
    u32 tile_width = (u16)size;
    u32 tile_height = size >> 16;
    u32 word_count = tile_width * tile_height;

    word_count <<= 5;
    word_count >>= 2;
    word_count &= 0x1FFFFF;
    CpuFastSet(source, destination, word_count);
}

// Fill a tilemap rectangle with sequential tile IDs. The row stride is in
// 16-bit entries, so it may be larger than the visible width.
void Fill2DGfxTilemapRect(u16 *destination, u32 first_tile, u32 width,
    u32 height, u32 palette, u32 row_stride)
{
    u16 tile = first_tile;
    u16 palette_value = palette;
    u16 *row_pointer = destination;

    for (u32 row = 0; row < height; ++row) {
        for (u32 column = 0; column < width; ++column)
            *destination++ = tile++ | (palette_value << 12);

        row_pointer += row_stride;
        destination = row_pointer;
    }
}

EXTERN_C_END

FontTilemapRectCommand::FontTilemapRectCommand(u16 * destination, u16 first_tile,
    u32 width, u32 height, u16 palette, u32 row_stride)
{
    this->destination = destination;
    this->first_tile = first_tile;
    this->width = width;
    this->height = height;
    this->palette = palette;
    this->row_stride = row_stride;
}

FontTilemapRectCommand::~FontTilemapRectCommand()
{
}

bool FontTilemapRectCommand::Run()
{
    Fill2DGfxTilemapRect(destination, first_tile, width, height, palette, row_stride);
    return false;
}
