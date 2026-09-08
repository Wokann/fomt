#include "font.hh"

#include "gbasvc.h"

EXTERN_C

// The original non-aligned path is present but intentionally has no visual
// effect; keep it as a separate call so its known ROM behavior remains
// visible while the core aligned compositor stays ordinary C++.
extern void DrawCharacterGlyphTo2DGfxBufferUnaligned(u32 size, void *buffer,
    i32 x, i32 y, void *glyph) asm("func_0804E9C8");

i32 DrawCharacterGlyphTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    i32 character) SECTION(".text.font_draw_normal");

// Draw one decoded glyph into an 8-pixel-aligned position of a packed 4bpp
// tile buffer. DrawCharacterGlyph writes four 32-byte tile quadrants into the
// scratch area; this wrapper copies only the quadrants which fit in the
// destination buffer.
i32 DrawCharacterGlyphTo2DGfxBuffer(u32 size, void *buffer, i32 x, i32 y,
    i32 character)
{
    register u32 packed_size asm("r5");
    register void *tile_buffer asm("r9");
    register i32 x_position asm("r6");
    register i32 y_position asm("r7");
    register i32 glyph_width asm("r10");
    register u32 x_tile asm("r4");
    register u32 y_tile asm("r2");
    register u32 buffer_width asm("r8");
    register u32 buffer_height asm("r12");
    register u32 aligned asm("r1");
    register u32 alignment_mask asm("r3");
    register u32 alignment_value asm("r0");
    register u32 has_right_tile_for_draw asm("r0");
    register u32 glyph_width_for_draw asm("r1");
    register u8 *tile_buffer_for_bottom asm("r2");
    u32 glyph[32];
    u32 saved_x_tile;
    u32 has_right_tile;
    u32 has_bottom_tile;
    u32 next_y_tile;
    u32 buffer_height_for_check;
    u8 *top_destination;
    i32 result;

    packed_size = size;
    tile_buffer = buffer;
    x_position = x;
    y_position = y;
    glyph_width = DrawCharacterGlyph(glyph, character);
    if ((u32)(glyph_width - 1) > 1)
        goto invalid_glyph;

    x_tile = (u32)x_position >> 3;
    saved_x_tile = x_tile;
    y_tile = (u32)y_position >> 3;
    buffer_width = (u16)packed_size;
    buffer_height_for_check = packed_size >> 16;
    buffer_height = buffer_height_for_check;

    if (x_tile >= buffer_width || y_tile >= buffer_height_for_check)
        goto return_glyph_width;

    aligned = 0;
    alignment_mask = 7;
    alignment_value = x_position;
    alignment_value &= alignment_mask;
    if (alignment_value == 0)
        aligned = 1;
    if (aligned == 0)
        goto draw_unaligned;

    aligned = 0;
    alignment_value = y_position;
    alignment_value &= alignment_mask;
    if (alignment_value == 0)
        aligned = 1;
    if (aligned == 0)
        goto draw_unaligned;

    has_right_tile = 0;
    if (x_tile + 1 < buffer_width)
        has_right_tile = 1;

    has_bottom_tile = 0;
    next_y_tile = y_tile + 1;
    if (next_y_tile < buffer_height)
        has_bottom_tile = 1;

    top_destination = reinterpret_cast<u8 *>(((y_tile * buffer_width + x_tile)
        << 5) + reinterpret_cast<u32>(tile_buffer));

    CpuFastSet(glyph, top_destination, 8);
    if (has_bottom_tile != 0) {
        register u8 *bottom_destination asm("r1");
        register u32 *bottom_glyph asm("r0");

        bottom_destination = reinterpret_cast<u8 *>(tile_buffer)
            + ((next_y_tile * buffer_width + x_tile) << 5);
        bottom_glyph = glyph + 16;
        CpuFastSet(bottom_glyph, bottom_destination, 8);
    }

    has_right_tile_for_draw = has_right_tile;
    if (has_right_tile_for_draw != 0) {
        glyph_width_for_draw = (u32)glyph_width;

        if (glyph_width_for_draw <= 1)
            goto return_glyph_width;
        {
            register u8 *right_destination asm("r1") = top_destination + 0x20;
            register u32 *right_glyph asm("r0") = glyph + 8;

            CpuFastSet(right_glyph, right_destination, 8);
        }
        if (has_bottom_tile != 0) {
            register u8 *bottom_right_destination asm("r1");
            register u32 *bottom_right_glyph asm("r0");

            has_right_tile_for_draw = buffer_width;
            has_right_tile_for_draw *= next_y_tile;
            glyph_width_for_draw = saved_x_tile;
            glyph_width_for_draw += has_right_tile_for_draw;
            has_right_tile_for_draw = glyph_width_for_draw << 5;
            tile_buffer_for_bottom = reinterpret_cast<u8 *>(tile_buffer);
            bottom_right_destination = tile_buffer_for_bottom
                + has_right_tile_for_draw + 0x20;
            bottom_right_glyph = glyph + 24;
            CpuFastSet(bottom_right_glyph, bottom_right_destination, 8);
        }
    }

    goto return_glyph_width;

draw_unaligned:
    DrawCharacterGlyphTo2DGfxBufferUnaligned(packed_size, tile_buffer,
        x_position, y_position, glyph);

return_glyph_width:
    result = glyph_width;
    goto return_result;

invalid_glyph:
    result = 0;

return_result:
    return result;
}

// The extended palette compositor immediately follows this function in the
// original ROM. It remains in the raw block until its standard C++ form can
// reproduce every register allocation and instruction byte exactly.

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
