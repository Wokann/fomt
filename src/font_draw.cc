#pragma implementation "font_draw.hh"
#include "font_draw.hh"

#include "gbasvc.h"
#include "font.hh"

EXTERN_C

static inline i32 IsFontTileAligned(u32 pixel)
{
    return (pixel & 7) == 0;
}

static inline u32 *FontBufferTile(void *buffer, u32 width, u32 const &column, u32 row)
{
    return (width * row + column) * 8 + static_cast<u32 *>(buffer);
}

static inline void CopyFontTile(void *destination, u32 const (&source)[8])
{
    CpuFastSet(source, destination, ARRAY_COUNT(source));
}

i32 DrawCharacterGlyphTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    i32 character)
{
    // Native tile order: upper-left, upper-right, lower-left, lower-right.
    u32 glyph[4][8];
    u32 glyph_width = DrawCharacterGlyph(glyph, character);
    if (glyph_width - 1 <= 1)
    {
        u32 const &column = static_cast<u32>(x) >> 3;
        u32 row = static_cast<u32>(y) >> 3;
        u32 width = static_cast<u16>(size);
        u16 height = size >> 16;
        if (column < width && row < height)
        {
            if (IsFontTileAligned(x) && IsFontTileAligned(y))
            {
                bool right = column + 1 < width;
                bool lower = row + 1 < height;
                u32 *first = reinterpret_cast<u32 *>((row * width + column) * sizeof(glyph[0])
                    + reinterpret_cast<uptr>(buffer));
                CopyFontTile(first, glyph[0]);
                if (lower)
                    CopyFontTile(FontBufferTile(buffer, width, column, row + 1), glyph[2]);
                if (right && glyph_width > 1)
                {
                    uptr right_tile = reinterpret_cast<uptr>(first + ARRAY_COUNT(glyph[0]));
                    CopyFontTile(reinterpret_cast<u32 *>(right_tile), glyph[1]);
                    if (lower)
                    {
                        right_tile = column + width * (row + 1);
                        right_tile = right_tile * sizeof(glyph[0]) + reinterpret_cast<uptr>(buffer);
                        CopyFontTile(reinterpret_cast<u32 *>(right_tile) + ARRAY_COUNT(glyph[0]), glyph[3]);
                    }
                }
            }
            else
                DrawCharacterGlyphTo2DGfxBufferUnaligned(size, buffer, x, y, glyph);
        }
        return glyph_width;
    }
    return 0;
}

static inline u32 ExpandFontColor(u32 color)
{
    u32 fill = color & 15;
    fill |= fill << 4;
    fill |= fill << 8;
    fill |= fill << 16;
    return fill;
}

static inline void RecolorFontTile(uptr base, uptr byte_offset, u32 const (&tile)[8],
    i32 background, i32 foreground)
{
    i32 difference = foreground - background;
    u32 fill = ExpandFontColor(background);
    u32 *destination = reinterpret_cast<u32 *>(byte_offset + base);
    u32 const *source = tile;
    u32 const *end = tile + ARRAY_COUNT(tile);
    while (source != end)
    {
        u32 pixels = *source++;
        u32 low = pixels & 0x11111111;
        u32 high = (pixels >> 1) & 0x11111111;
        *destination++ = fill + (low | high) * difference + high;
    }
}

i32 DrawCharacterGlyphTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    i32 character, i32 background, i32 foreground)
{
    u32 glyph[4][8];
    u32 glyph_width = DrawCharacterGlyph(glyph, character);
    if (glyph_width - 1 <= 1)
    {
        u32 column = static_cast<u32>(x) >> 3;
        u32 row = static_cast<u32>(y) >> 3;
        u32 width = static_cast<u16>(size);
        u16 height = size >> 16;
        if (column < width && row < height)
        {
            if (IsFontTileAligned(x) && IsFontTileAligned(y))
            {
                bool right = column + 1 < width;
                bool lower = row + 1 < height;
                RecolorFontTile(reinterpret_cast<uptr>(buffer), (row * width + column) * sizeof(glyph[0]),
                    glyph[0], background, foreground);
                if (lower)
                    RecolorFontTile(reinterpret_cast<uptr>(buffer), (column + width * (row + 1)) * sizeof(glyph[0]),
                        glyph[2], background, foreground);
                if (right && glyph_width > 1)
                {
                    uptr top_left = width * row + column;
                    top_left = top_left * sizeof(glyph[0]) + reinterpret_cast<uptr>(buffer);
                    RecolorFontTile(top_left, sizeof(glyph[0]), glyph[1], background, foreground);
                    if (lower)
                    {
                        uptr bottom_left = column + width * (row + 1);
                        bottom_left = bottom_left * sizeof(glyph[0]) + reinterpret_cast<uptr>(buffer);
                        RecolorFontTile(bottom_left, sizeof(glyph[0]), glyph[3], background, foreground);
                    }
                }
            }
            else
                DrawCharacterGlyphTo2DGfxBufferExtUnaligned(size, buffer, x, y,
                    glyph, background, foreground);
        }
        return glyph_width;
    }
    return 0;
}

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

void Clear2DGfxBufferRect(u32 size, void *buffer, u32 x, u32 y, u32 rect_width,
    u32 rect_height, u32 color)
{
    u32 color_word = ExpandFontColor(color);
    u32 fill_color;
    u32 width = static_cast<u16>(size);
    u16 height = size >> 16;
    u32 pixel_width = width << 3;
    u32 pixel_height = height << 3;
    if (x == 0 && y == 0 && rect_width >= pixel_width && rect_height >= pixel_height)
    {
        u32 byte_count = width * (height << 5);
        fill_color = color_word;
        CpuFastSet(&fill_color, buffer,
            CPUSET_SRC_FIXED | ((byte_count >> 2) & 0x1FFFFF));
    }
    // The native early limits are tile counts; subsequent clipping and
    // alignment tests use pixel coordinates.
    else if (x < width && y < height)
    {
        if (x + rect_width >= pixel_width)
            rect_width = pixel_width - x;
        if (y + rect_height >= pixel_height)
            rect_height = pixel_height - y;
        if (IsFontTileAligned(x) && IsFontTileAligned(y) &&
            IsFontTileAligned(rect_width) && IsFontTileAligned(rect_height))
        {
            rect_height >>= 3;
            u8 *destination = static_cast<u8 *>(buffer) +
                ((y >> 3) * width + (x >> 3)) * 32;
            do
            {
                fill_color = color_word;
                CpuFastSet(&fill_color, destination,
                    CPUSET_SRC_FIXED | (((((rect_width >> 3) << 5) >> 2)) & 0x1FFFFF));
                destination += width * 32;
            } while (--rect_height != 0);
        }
    }
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
    u8 const *string, i32 background, i32 foreground)
{
    u8 const *current = string;
    i32 maximum_x = (size << 16) >> 13;
    i32 character = 0;
    u8 byte = *current;

    while (byte != 0 && (u32)x < (u32)maximum_x) {
        u32 glyph_width;

        character |= byte;
        glyph_width = DrawCharacterGlyphTo2DGfxBufferExt(size, buffer, x, y,
            character, background, foreground);
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
    i32 x, i32 y, void *glyph, i32 background, i32 foreground)
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
