#include "font.hh"
#include "hardware_linked_list.hh"
#include "ui_state.hh"

#include <string.h>

// Converts one Shift-JIS two-byte code to the index used by the font's
// double-width glyph map. Returns -1 for a code outside that map.
i32 GetShiftJisGlyphMapIndex(i32 character)
{
    u32 low_byte;
    u32 high_byte;
    u32 row;

    if ((u32)character > 0xFFFF)
        return -1;

    low_byte = character & 0xFF;
    high_byte = (character & 0xFF00) >> 8;
    if ((u32)(low_byte - 0x40) > 0xBC
        || high_byte <= 0x80
        || high_byte > 0xEA
        || (u32)(high_byte - 0xA0) <= 0x3F) {
        return -1;
    }

    if (high_byte <= 0x9F)
        high_byte -= 0x81;
    else
        high_byte -= 0xC1;

    low_byte -= 0x40;
    row = high_byte * 3;
    return (row << 6) - row + low_byte;
}

// Fixed-width formatting retains the original truncation and padding rules.
// Width zero emits at most ten ASCII characters before expanding each glyph.
void FormatFullWidthDecimal(i32 value, char * output, u32 width)
{
    char ascii[12];
    char reversed[12];
    if (width != 0) {
        bool negative = false;
        if (value < 0) {
            value = -value;
            negative = true;
        }
        i32 count = 0;
        for (; count < width; count++) {
            reversed[count] = value % 10 + '0';
            value /= 10;
            if (value == 0) {
                count++;
                for (; count < width; count++)
                    reversed[count] = ' ';
                break;
            }
        }
        if (negative)
            reversed[count] = '-';
        for (u32 index = 0; index < width; index++)
            ascii[width - index - 1] = reversed[index];
        ascii[width] = '\0';
    } else {
        i32 remaining = value;
        char * end = ascii;
        if (remaining < 0) {
            *end++ = '-';
            remaining = -remaining;
        }
        FormatUnsignedDecimal(remaining, end);
        ascii[10] = '\0';
    }
    u8 const * cursor = reinterpret_cast<u8 const *>(ascii);
    u8 character;
    while ((character = *cursor) != '\0') {
        char const * glyph;
        if ((u8)(character - '0') <= 9)
            glyph = gUnk_PreUiTextLayoutDigitRows[character - '0'];
        else if (character == ' ')
            glyph = gUnk_PreUiTextLayoutFullWidthSpace;
        else if (character == '-')
            glyph = gUnk_PreUiTextLayoutFullWidthHyphen;
        else
            break;
        output[0] = glyph[0];
        output[1] = glyph[1];
        output += 2;
        cursor++;
    }
    *output = '\0';
}

void FormatSignedDecimal(i32 value, char * output, u32 width)
{
    char reversed[12];
    bool negative = value < 0;
    u32 count = 0;
    i32 remaining = value;
    if (remaining < 0)
        remaining = -remaining;

    do {
        reversed[count++] = remaining % 10 + '0';
        remaining /= 10;
    } while (remaining > 0 && count + 1 <= 10);

    if (width != 0) {
        if (width < count)
            count = width;
        else {
            for (; width > count; count++)
                reversed[count] = ' ';
        }
    }
    if (negative)
        reversed[count++] = '-';
    for (count--; count != 0xFFFFFFFF; count--)
        *output++ = reversed[count];
    *output = '\0';
}

void DrawDecimalTo2x2Tilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride)
{
    u32 first_tile = static_cast<u16>(base_tile);
    u16 palette_index = palette;
    u16 * cursor = right_tile;
    u32 attributes = palette_index << 12;
    do {
        u32 quotient = value / 10;
        u32 tile = first_tile + (value - quotient * 10) * 4;
        cursor[0] = (tile + 1) | attributes;
        cursor[-1] = attributes | tile;
        cursor[row_stride] = (tile + 3) | attributes;
        cursor[row_stride - 1] = (tile + 2) | attributes;
        value = quotient;
        cursor -= 2;
    } while (value != 0);
}

FontTilemapDecimalCommand::FontTilemapDecimalCommand(u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride)
{
    this->value = value;
    this->right_tile = right_tile;
    this->base_tile = base_tile;
    this->palette = palette;
    this->row_stride = row_stride;
}

FontTilemapDecimalCommand::~FontTilemapDecimalCommand()
{
}

#if !defined(REGION_JP)
void DrawDecimalTo1x2Tilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride)
{
    u32 first_tile = static_cast<u16>(base_tile);
    u16 palette_index = palette;
    u16 * cursor = right_tile;
    u32 attributes = palette_index << 12;
    do {
        u32 quotient = value / 10;
        u32 tile = first_tile + (value - quotient * 10) * 2;
        cursor[0] = attributes | tile;
        cursor[row_stride] = (tile + 1) | attributes;
        value = quotient;
        cursor--;
    } while (value != 0);
}

FontTilemapTallDecimalCommand::FontTilemapTallDecimalCommand(u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride)
{
    this->value = value;
    this->right_tile = right_tile;
    this->base_tile = base_tile;
    this->palette = palette;
    this->row_stride = row_stride;
}

FontTilemapTallDecimalCommand::~FontTilemapTallDecimalCommand()
{
}
#endif

void DrawDecimalToTilemap(u32 value, u16 * right_tile, u32 base_tile,
    u32 palette, u32 row_stride)
{
    u32 first_tile = static_cast<u16>(base_tile);
    u16 palette_index = palette;
    u16 * cursor = right_tile;
    u32 attributes = palette_index << 12;
    do {
        u32 quotient = value / 10;
        u32 tile = first_tile + (value - quotient * 10);
        cursor[0] = tile | attributes;
        value = quotient;
        cursor--;
    } while (value != 0);
}

FontTilemapSingleTileDecimalCommand::FontTilemapSingleTileDecimalCommand(u32 value, u16 * right_tile,
    u16 base_tile, u16 palette, u32 row_stride)
{
    this->value = value;
    this->right_tile = right_tile;
    this->base_tile = base_tile;
    this->palette = palette;
    this->row_stride = row_stride;
}

FontTilemapSingleTileDecimalCommand::~FontTilemapSingleTileDecimalCommand()
{
}

bool FontTilemapSingleTileDecimalCommand::Run()
{
    DrawDecimalToTilemap(value, right_tile, base_tile, palette, row_stride);
    return false;
}

#if !defined(REGION_JP)
bool FontTilemapTallDecimalCommand::Run()
{
    DrawDecimalTo1x2Tilemap(value, right_tile, base_tile, palette, row_stride);
    return false;
}
#endif

bool FontTilemapDecimalCommand::Run()
{
    DrawDecimalTo2x2Tilemap(value, right_tile, base_tile, palette, row_stride);
    return false;
}

void FormatUnsignedDecimal(u32 value, char * output)
{
    char * end = output + 1;
    u32 maximum_power = 0xFFFFFFFFu / 10;
    u32 power = 10;
    while (value >= power) {
        ++end;
        if (power > maximum_power)
            break;
        power *= 10;
    }
    *end = '\0';
    do {
        --end;
        u32 quotient = value / 10;
        *end = value - quotient * 10 + '0';
        value = quotient;
    } while (value != 0);
}

#include FOMT_TEXT_INCLUDE(font.cc)

#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
// The US glyph resolver selects these contiguous 12-byte glyph bitmaps and
// passes them to DrawGlyph1Tile. Their individual display meanings remain unknown.
extern u8 const gFontSpecialGlyphBlocks[14][12] __attribute__((aligned(4))) = {
    { 0x00, 0x00, 0x00, 0x48, 0xB4, 0x84, 0x84, 0x48, 0x30, 0x00, 0x00, 0x00 },
    { 0x10, 0x10, 0x10, 0x28, 0x44, 0x28, 0x28, 0x28, 0x54, 0x6C, 0x44, 0x00 },
    { 0x10, 0x10, 0x10, 0x38, 0x7C, 0x38, 0x38, 0x38, 0x7C, 0x6C, 0x44, 0x00 },
    { 0x38, 0x44, 0x44, 0x44, 0x38, 0x10, 0x10, 0x7C, 0x10, 0x10, 0x10, 0x00 },
    { 0x10, 0x38, 0x54, 0x10, 0x10, 0x10, 0x38, 0x44, 0x44, 0x44, 0x38, 0x00 },
    { 0x10, 0x18, 0x1C, 0x14, 0x14, 0x14, 0x18, 0x10, 0x30, 0x70, 0x60, 0x00 },
    { 0x48, 0x48, 0x00, 0x78, 0x84, 0x04, 0x7C, 0x84, 0x84, 0x7C, 0x00, 0x00 },
    { 0x48, 0x48, 0x00, 0x84, 0x84, 0x84, 0x84, 0x84, 0x48, 0x38, 0x00, 0x00 },
    { 0x48, 0x48, 0x00, 0x78, 0x84, 0x84, 0x84, 0x84, 0x84, 0x78, 0x00, 0x00 },
    { 0x38, 0x44, 0x44, 0x44, 0x58, 0x44, 0x44, 0x44, 0x64, 0x58, 0x40, 0x00 },
    { 0x60, 0x60, 0x20, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
    { 0x00, 0x54, 0x44, 0x28, 0x10, 0x54, 0x10, 0x28, 0x44, 0x54, 0x00, 0x00 },
    { 0x28, 0x28, 0x10, 0x10, 0x10, 0x28, 0x28, 0x28, 0x38, 0x44, 0x44, 0x00 },
    { 0x28, 0x28, 0x00, 0x38, 0x44, 0x44, 0x44, 0x44, 0x44, 0x44, 0x38, 0x00 },
};

// Input code 0x00C3 selects this final single-width glyph.
extern u8 const gFontSpecialGlyphC3[12] __attribute__((aligned(4))) = {
    0x28, 0x28, 0x00, 0x44, 0x44, 0x44,
    0x44, 0x44, 0x44, 0x38, 0x00, 0x00,
};
#else
// Input code 0x81CD selects this double-width Shift-JIS glyph.
extern u8 const gFontSpecialGlyph81CD[24] __attribute__((aligned(4))) = {
    0x18, 0xC0, 0x25, 0x20, 0x42, 0x10,
    0x40, 0x10, 0x40, 0x10, 0x40, 0x10,
    0x20, 0x20, 0x10, 0x40, 0x08, 0x80,
    0x05, 0x00, 0x02, 0x00, 0x00, 0x00,
};
#endif // REGION_US || REGION_EU || REGION_DE

// Resolves an encoded character to its glyph and writes it to the renderer's
// 16x16-tile scratch buffer. The return value is the display width in tiles.
i32 DrawCharacterGlyph(void *destination, i32 character)
{
    i32 glyph_width = 0;
    i32 glyph_index = -1;

#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    switch (character - 0xB1) {
    // Preserve the original physical case order; the switch table still maps
    // each encoded character to its corresponding glyph.
    case 3:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[0], destination);
        return 1;
    case 5:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[1], destination);
        return 1;
    case 6:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[2], destination);
        return 1;
    case 0:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[3], destination);
        return 1;
    case 1:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[4], destination);
        return 1;
    case 2:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[5], destination);
        return 1;
    case 10:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[6], destination);
        return 1;
    case 11:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[7], destination);
        return 1;
    case 12:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[8], destination);
        return 1;
    case 13:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[9], destination);
        return 1;
    case 14:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[10], destination);
        return 1;
    case 15:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[11], destination);
        return 1;
    case 16:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[12], destination);
        return 1;
    case 17:
        DrawGlyph1Tile(gFontSpecialGlyphBlocks[13], destination);
        return 1;
    case 18:
        DrawGlyph1Tile(gFontSpecialGlyphC3, destination);
        return 1;
    }
#else
    if (character == 0x81CD) {
        u8 const *glyph = gFontSpecialGlyph81CD;
        void *output = destination;

        DrawGlyph2Tile(glyph, output);
        return 2;
    }
#endif

    if (character > 0) {
        if (character <= 0xFF) {
            glyph_index = gFontSingleByteGlyphIndices[character];
            glyph_width = 1;
        } else if (character <= 0xFFFF) {
            i32 shift_jis_index = GetShiftJisGlyphMapIndex(character);

            if (shift_jis_index >= 0) {
                glyph_index = gFontShiftJisGlyphIndices[shift_jis_index];
                glyph_width = 2;
            }
        }
    }

    if (destination != nullptr) {
        if (glyph_index >= 0) {
            if (glyph_width != 1) {
                u8 const *glyph = gFontDoubleWidthGlyphData + glyph_index * 24;

                DrawGlyph2Tile(glyph, destination);
            } else {
                u8 const *glyph = gFontSingleWidthGlyphData + glyph_index * 12;

                DrawGlyph1Tile(glyph, destination);
            }
        } else {
            memset(destination, 0, 0x80);
        }
    }

    i32 result = 0;

    if (glyph_index >= 0)
        result = glyph_width;
    return result;
}
