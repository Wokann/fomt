#include "font.hh"

#include <string.h>

EXTERN_C

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

#if defined(REGION_US)
// This is an ordinary terminated C string. Its two additional trailing zero
// bytes arise from the four-byte alignment of the following object.
extern char const gCppRuntimeBadAlloc_Font[] ALIGN(4) =
    "bad_alloc";

// The US glyph resolver selects these contiguous 12-byte glyph bitmaps and
// passes them to func_0300085C. Their individual display meanings remain unknown.
extern u8 const gFontSpecialGlyphBlocks[14][12] ALIGN(4) = {
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
#endif // REGION_US

extern void DrawGlyph2Tile(u8 const *glyph, void *destination);
extern void DrawGlyph1Tile(u8 const *glyph, void *destination);

// _call_via_r2 is the Thumb-to-ARM bridge used by the original renderer.
// The two C declarations intentionally name separate glyph paths so agbcp
// preserves their original control flow; both bind to the same raw bridge.
extern void CallArmDrawGlyph1Tile(u8 const *glyph, void *destination,
    void (*function)(u8 const *glyph, void *destination)) asm("_call_via_r2");
extern void CallArmDrawGlyph2Tile(u8 const *glyph, void *destination,
    void (*function)(u8 const *glyph, void *destination)) asm("_call_via_r2");

// Resolves an encoded character to its glyph and writes it to the renderer's
// 16x16-tile scratch buffer. The return value is the display width in tiles.
i32 DrawCharacterGlyph(void *destination, i32 character)
{
    i32 glyph_width = 0;
    i32 glyph_index = -1;

#if defined(REGION_US)
    switch (character - 0xB1) {
    // Preserve the original physical case order; the switch table still maps
    // each encoded character to its corresponding glyph.
    case 3:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[0], destination, DrawGlyph1Tile);
        return 1;
    case 5:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[1], destination, DrawGlyph1Tile);
        return 1;
    case 6:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[2], destination, DrawGlyph1Tile);
        return 1;
    case 0:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[3], destination, DrawGlyph1Tile);
        return 1;
    case 1:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[4], destination, DrawGlyph1Tile);
        return 1;
    case 2:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[5], destination, DrawGlyph1Tile);
        return 1;
    case 10:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[6], destination, DrawGlyph1Tile);
        return 1;
    case 11:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[7], destination, DrawGlyph1Tile);
        return 1;
    case 12:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[8], destination, DrawGlyph1Tile);
        return 1;
    case 13:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[9], destination, DrawGlyph1Tile);
        return 1;
    case 14:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[10], destination, DrawGlyph1Tile);
        return 1;
    case 15:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[11], destination, DrawGlyph1Tile);
        return 1;
    case 16:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[12], destination, DrawGlyph1Tile);
        return 1;
    case 17:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphBlocks[13], destination, DrawGlyph1Tile);
        return 1;
    case 18:
        CallArmDrawGlyph1Tile(gFontSpecialGlyphC3, destination, DrawGlyph1Tile);
        return 1;
    }
#else
    if (character == 0x81CD) {
        u8 const *glyph = gFontSpecialGlyph81CD;
        void *output = destination;

        CallArmDrawGlyph2Tile(glyph, output, DrawGlyph2Tile);
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

                CallArmDrawGlyph2Tile(glyph, destination, DrawGlyph2Tile);
            } else {
                u8 const *glyph = gFontSingleWidthGlyphData + glyph_index * 12;

                CallArmDrawGlyph1Tile(glyph, destination, DrawGlyph1Tile);
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

EXTERN_C_END
