#include "font.hh"

EXTERN_C

// Draws a terminated Shift-JIS byte stream. A double-width character is
// accumulated from two input bytes when the first byte produces no glyph.
void DrawStringTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    u8 const *string)
{
    // These long-lived values use the original callee-saved registers. This
    // is a register binding only, not inline assembly.
    register u8 const *current asm("r6") = string;
    i32 maximum_x = (size << 16) >> 13;
    register i32 character asm("r5") = 0;
    u8 byte = *current;

    while (byte != 0 && (u32)x < (u32)maximum_x) {
        u32 glyph_width;

        character |= byte;
        glyph_width = DrawCharacterGlyphTo2DGfxBuffer(size, buffer, x, y,
            character);
        if (glyph_width == 1)
            goto render_single_width;
        if (glyph_width < 1)
            goto advance_character;
        if (glyph_width == 2)
            goto render_double_width;
        return;

render_single_width:
        character = 0;
        x += 8;
        goto advance_character;

render_double_width:
        character = 0;
        x += 16;

advance_character:
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
    // Match the ordinary walker: keep the byte cursor and accumulated code
    // in the original callee-saved registers across the compositor call.
    register u8 const *current asm("r6") = string;
    i32 maximum_x = (size << 16) >> 13;
    register i32 character asm("r5") = 0;
    u8 byte = *current;

    while (byte != 0 && (u32)x < (u32)maximum_x) {
        u32 glyph_width;

        character |= byte;
        glyph_width = DrawCharacterGlyphTo2DGfxBufferExt(size, buffer, x, y,
            character, foreground, background);
        if (glyph_width == 1)
            goto render_single_width;
        if (glyph_width < 1)
            goto advance_character;
        if (glyph_width == 2)
            goto render_double_width;
        return;

render_single_width:
        character = 0;
        x += 8;
        goto advance_character;

render_double_width:
        character = 0;
        x += 16;

advance_character:
        current++;
        byte = *current;
        character <<= 8;
    }
}

EXTERN_C_END
