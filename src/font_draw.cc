#include "font.hh"

#include "gbasvc.h"

EXTERN_C

// Fill every tile in a packed two-dimensional 4bpp buffer with one palette
// nibble. The size word carries tile width in its low half and height in its
// high half.
void Clear2DGfxBuffer(u32 size, void *buffer, u32 color)
{
    // These bindings reproduce the original leaf-frame register allocation;
    // they are C++ register bindings, not inline assembly.
    register u32 color_word asm("r3") = color & 0xF;
    register u32 temporary asm("r2");

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

// Fill an 8-pixel-aligned rectangle in a packed two-dimensional 4bpp tile
// buffer. A rectangle covering the whole buffer takes the single-copy path.
void Clear2DGfxBufferRect(u32 size, void *buffer, u32 x, u32 y, u32 width,
    u32 height, u32 color)
{
    // Keep the state which survives CpuFastSet in the same registers as the
    // original routine. These are register bindings only, not inline asm.
    register u32 destination asm("r8");
    register u32 x_position asm("r5");
    register u32 rectangle_width asm("r12");
    register u32 rectangle_height asm("r6");
    register u32 y_position asm("r3") = y;
    register u32 fill_color asm("r9");
    register u32 color_value asm("r1");
    register u32 color_temporary asm("r2");
    u32 fill_value;

    destination = (u32)buffer;
    x_position = x;
    rectangle_width = width;
    rectangle_height = height;

    color_value = color;
    color_temporary = 0xF;
    color_value &= color_temporary;
    color_temporary = color_value << 4;
    color_value |= color_temporary;
    color_temporary = color_value << 8;
    color_value |= color_temporary;
    color_temporary = color_value << 16;
    color_temporary |= color_value;
    fill_color = color_temporary;
    {
        register u32 buffer_pixel_width asm("r1") = size << 16;
        register u32 buffer_width asm("r2") = buffer_pixel_width >> 16;
        register u32 buffer_height asm("r0") = size >> 16;
        u32 buffer_pixel_height;

        buffer_pixel_width = buffer_width << 3;
        buffer_pixel_height = buffer_height << 3;
        {
            if (x_position == 0 && y_position == 0
                && rectangle_width >= buffer_pixel_width
                && rectangle_height >= buffer_pixel_height) {
                register u32 fill_copy asm("r7") = fill_color;

                buffer_height <<= 5;
                buffer_width *= buffer_height;
                fill_value = fill_copy;
                {
                    register u32 full_control asm("r2") = buffer_width;

                    full_control >>= 2;
                    full_control &= 0x1FFFFF;
                    full_control |= CPUSET_SRC_FIXED;
                    CpuFastSet(&fill_value,
                        reinterpret_cast<void *>(destination), full_control);
                }
                return;
            }

            if (x_position >= buffer_width || y_position >= buffer_height)
                return;

            if (x_position + rectangle_width >= buffer_pixel_width)
                rectangle_width = buffer_pixel_width - x_position;
            if (y_position + rectangle_height >= buffer_pixel_height)
                rectangle_height = buffer_pixel_height - y_position;

            register u32 aligned asm("r1") = 0;
            register u32 alignment_mask asm("r4") = 7;
            register u32 alignment_value asm("r0");

            alignment_value = x_position;
            alignment_value &= alignment_mask;
            if (alignment_value == 0)
                aligned = 1;
            if (aligned == 0)
                return;
            aligned = 0;
            alignment_value = y_position;
            alignment_value &= alignment_mask;
            if (alignment_value == 0)
                aligned = 1;
            if (aligned == 0)
                return;
            aligned = 0;
            alignment_value = rectangle_width;
            alignment_value &= alignment_mask;
            if (alignment_value == 0)
                aligned = 1;
            if (aligned == 0)
                return;
            aligned = 0;
            alignment_value = rectangle_height;
            alignment_value &= alignment_mask;
            if (alignment_value == 0)
                aligned = 1;
            if (aligned == 0)
                return;

            rectangle_height >>= 3;
            {
                register u32 row_offset asm("r0") = y_position;
                register u32 column_offset asm("r1") = x_position;

                row_offset >>= 3;
                row_offset *= buffer_width;
                column_offset >>= 3;
                row_offset += column_offset;
                x_position = destination + (row_offset << 5);
            }

            u32 row_stride = buffer_width << 5;
            u32 row_control = 0x3FFFFFF8;

            row_control &= rectangle_width;
            row_control &= 0x1FFFFF;
            destination = CPUSET_SRC_FIXED;

            do {
                fill_value = fill_color;
                CpuFastSet(&fill_value, reinterpret_cast<void *>(x_position),
                    destination | row_control);
                x_position += row_stride;
                rectangle_height--;
            } while (rectangle_height != 0);
        }
    }
}

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
