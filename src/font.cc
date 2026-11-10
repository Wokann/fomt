#include "font.hh"

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

// Native runtime literal preceding the glyphs; its emission site is not yet recovered.

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

asm_unified(
    ".pushsection .iwram, \"ax\", %progbits\n"
    ".include \"asm/macro.inc\"\n"
    "arm_func_start DrawGlyph2Tile\n"
    "DrawGlyph2Tile:\n"
    "    @ r0 is a 24-byte, 16-pixel-wide 1bpp glyph; r1 is the 16x16-tile\n"
    "    @ scratch buffer. Each source row becomes 4bpp pixels plus its shadow.\n"
    "    push {r4, r5, r6, r7, r8, r9, sl, lr}\n"
    "    sub sp, sp, #4\n"
    "    mov sl, r0\n"
    "    mov lr, r1\n"
    "    mov r9, #0\n"
    "    mov r2, r9\n"
    "    mov r5, r9\n"
    "    mov r3, r5\n"
    ".LDrawGlyph2TileClear:\n"
    "    str r3, [lr, #32]\n"
    "    add r5, r5, #1\n"
    "    str r3, [lr], #4\n"
    "    cmp r5, #1\n"
    "    bls .LDrawGlyph2TileClear\n"
    ".LDrawGlyph2TileLine:\n"
    "    mov r1, #1\n"
    "    mov r4, #128\n"
    "    mov ip, #0\n"
    "    mov r0, ip\n"
    "    tst sl, #3\n"
    "    ldreq r6, [sl]\n"
    "    lsrne r6, r6, #16\n"
    "    add sl, sl, #2\n"
    "    mov r7, r2, lsr #28\n"
    "    mov r9, r9, lsl #4\n"
    "    mov r2, r2, lsl #4\n"
    "    str r2, [sp]\n"
    ".LDrawGlyph2TilePixel:\n"
    "    tst r6, r4\n"
    "    orr r3, ip, r1\n"
    "    movne ip, r3\n"
    "    ands r2, r6, r4, lsl #8\n"
    "    orr r3, r0, r1\n"
    "    movne r0, r3\n"
    "    mov r1, r1, lsl #4\n"
    "    movs r4, r4, lsr #1\n"
    "    bne .LDrawGlyph2TilePixel\n"
    "    mov r3, ip, lsr #28\n"
    "    orr r0, r3, r0, lsl #4\n"
    "    mov ip, ip, lsl #4\n"
    "    mov r8, r0, lsl #4\n"
    "    orr r2, r8, r7\n"
    "    mov r7, ip, lsr #28\n"
    "    orr r3, r7, r9\n"
    "    orr r3, r2, r3\n"
    "    bic r3, r3, r0\n"
    "    orr r1, r0, r3, lsl #1\n"
    "    mov r9, r0\n"
    "    add r5, r5, #1\n"
    "    ldr r2, [sp]\n"
    "    cmp r5, #8\n"
    "    orr r3, r2, ip, lsl #4\n"
    "    bic r3, r3, ip\n"
    "    str r1, [lr, #32]\n"
    "    orr r3, ip, r3, lsl #1\n"
    "    str r3, [lr], #4\n"
    "    mov r2, ip\n"
    "    add r3, lr, #32\n"
    "    moveq lr, r3\n"
    "    cmp r5, #13\n"
    "    bls .LDrawGlyph2TileLine\n"
    "    orr r3, r8, r7\n"
    "    mov r9, r4\n"
    "    mov r3, r3, lsl #1\n"
    "    mov r2, r2, lsl #5\n"
    "    str r3, [lr, #32]\n"
    "    add r5, r5, #1\n"
    "    str r2, [lr], #4\n"
    "    cmp r5, #8\n"
    "    add r3, lr, #32\n"
    "    moveq lr, r3\n"
    "    cmp r5, #15\n"
    "    bhi .LDrawGlyph2TileDone\n"
    "    mov r2, r9\n"
    ".LDrawGlyph2TileBottomPadding:\n"
    "    str r2, [lr, #32]\n"
    "    add r5, r5, #1\n"
    "    str r2, [lr], #4\n"
    "    cmp r5, #8\n"
    "    add r3, lr, #32\n"
    "    moveq lr, r3\n"
    "    cmp r5, #15\n"
    "    bls .LDrawGlyph2TileBottomPadding\n"
    ".LDrawGlyph2TileDone:\n"
    "    add sp, sp, #4\n"
    "    pop {r4, r5, r6, r7, r8, r9, sl, lr}\n"
    "    bx lr\n"
    "\n"
    "arm_func_start DrawGlyph1Tile\n"
    "DrawGlyph1Tile:\n"
    "    @ r0 is a 12-byte, 8-pixel-wide 1bpp glyph; r1 is the same scratch\n"
    "    @ buffer. The right-hand tile receives the generated shadow pixels.\n"
    "    push {r4, r5, r6, r7, r8, lr}\n"
    "    mov r4, r0\n"
    "    mov r0, #0\n"
    "    mov r8, r0\n"
    "    mov r3, r0\n"
    ".LDrawGlyph1TileClear:\n"
    "    str r3, [r1, #32]\n"
    "    add r0, r0, #1\n"
    "    str r3, [r1], #4\n"
    "    cmp r0, #1\n"
    "    bls .LDrawGlyph1TileClear\n"
    ".LDrawGlyph1TileLine:\n"
    "    mov lr, #1\n"
    "    mov r6, #128\n"
    "    mov ip, #0\n"
    "    tst r4, #3\n"
    "    ldreq r5, [r4]\n"
    "    lsrne r5, r5, #8\n"
    "    add r4, r4, #1\n"
    "    mov r7, r8, lsr #28\n"
    "    mov r2, r8, lsl #4\n"
    ".LDrawGlyph1TilePixel:\n"
    "    tst r5, r6\n"
    "    orr r3, ip, lr\n"
    "    movne ip, r3\n"
    "    mov lr, lr, lsl #4\n"
    "    movs r6, r6, lsr #1\n"
    "    bne .LDrawGlyph1TilePixel\n"
    "    mov ip, ip, lsl #4\n"
    "    orr r3, r2, ip, lsl #4\n"
    "    bic r3, r3, ip\n"
    "    mov r8, ip\n"
    "    mov lr, ip, lsr #28\n"
    "    orr r2, lr, r7\n"
    "    mov r2, r2, lsl #1\n"
    "    orr r3, ip, r3, lsl #1\n"
    "    str r2, [r1, #32]\n"
    "    add r0, r0, #1\n"
    "    str r3, [r1], #4\n"
    "    cmp r0, #8\n"
    "    add r3, r1, #32\n"
    "    moveq r1, r3\n"
    "    cmp r0, #13\n"
    "    bls .LDrawGlyph1TileLine\n"
    "    mov r3, lr, lsl #1\n"
    "    mov r2, r8, lsl #5\n"
    "    mov r8, r6\n"
    "    str r3, [r1, #32]\n"
    "    add r0, r0, #1\n"
    "    str r2, [r1], #4\n"
    "    cmp r0, #8\n"
    "    add r3, r1, #32\n"
    "    moveq r1, r3\n"
    "    cmp r0, #15\n"
    "    bhi .LDrawGlyph1TileDone\n"
    "    mov r2, r8\n"
    ".LDrawGlyph1TileBottomPadding:\n"
    "    str r2, [r1, #32]\n"
    "    add r0, r0, #1\n"
    "    str r2, [r1], #4\n"
    "    cmp r0, #8\n"
    "    add r3, r1, #32\n"
    "    moveq r1, r3\n"
    "    cmp r0, #15\n"
    "    bls .LDrawGlyph1TileBottomPadding\n"
    ".LDrawGlyph1TileDone:\n"
    "    pop {r4, r5, r6, r7, r8, lr}\n"
    "    bx lr\n"
    ".popsection\n"
    ".thumb\n"
);
