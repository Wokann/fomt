#include "font.hh"

// GCC 2.9 retains a hard-register local only while it appears in an asm
// operand. Each empty constraint below emits no instruction or data; it only
// records the current C local's register lifetime for this legacy compiler.
// No function-specific post-processing or ROM-byte rule is involved.

// Draws the four possible 8x8 tile quadrants of one glyph with the supplied
// palette pair. The unaligned case intentionally delegates to the original
// no-op fallback, matching both regional ROMs.
i32 DrawCharacterGlyphTo2DGfxBufferExt(u32 size, void *buffer, i32 x, i32 y,
    i32 character, i32 foreground, i32 background)
{
    register u32 packed_size asm("r4");
    register void *tile_buffer asm("r10");
    register i32 x_position asm("r5");
    register i32 y_position asm("r6");
    register u32 x_tile asm("r12");
    register u32 y_tile asm("r3");
    register u32 buffer_width asm("r8");
    register u32 aligned asm("r1");
    register u32 alignment_mask asm("r2");
    register u32 alignment_value asm("r0");
    register i32 saved_color_delta asm("r9");
    u32 glyph[32];
    i32 glyph_width;
    u32 buffer_height;
    u32 buffer_height_for_check;
    u32 has_right_tile;
    u32 has_bottom_tile;
    u32 next_y_tile;
    u32 top_row;

    packed_size = size;
    tile_buffer = buffer;
    x_position = x;
    y_position = y;
    glyph_width = DrawCharacterGlyph(glyph, character);
    if ((u32)(glyph_width - 1) > 1)
        goto invalid_glyph;

    x_tile = (u32)x_position >> 3;
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

    {
        register u32 has_right_value asm("r1") = 0;

        if (x_tile + 1 < buffer_width)
            has_right_value = 1;
        has_right_tile = has_right_value;
    }
    {
        register u32 has_bottom_value asm("r0") = 0;
        register u32 next_y_value asm("r1") = y_tile + 1;

        next_y_tile = next_y_value;
        if (next_y_value < buffer_height)
            has_bottom_value = 1;
        has_bottom_tile = has_bottom_value;
    }

    {
        register u32 row asm("r3");
        u32 *destination;
        register u32 x_tile_for_offset asm("r1");
        u32 const *source;
        register u32 const *source_end asm("r2");

        {
            register u32 row_product asm("r0");

            row_product = buffer_width;
            __asm__ volatile ("" : "+r"(row_product));
            row_product *= y_tile;
            __asm__ volatile ("" : "+r"(row_product));
            row = row_product;
        }
        x_tile_for_offset = x_tile;
        __asm__ volatile ("" : "+r"(x_tile_for_offset));
        {
            register u32 destination_offset asm("r2");
            register u32 color_source asm("r1");
            register u32 color_value asm("r0");

            destination_offset = row;
            destination_offset += x_tile_for_offset;
            destination_offset <<= 5;
            color_value = background;
            __asm__ volatile ("" : "+r"(color_value));
            color_source = foreground;
            __asm__ volatile ("" : "+r"(color_source));
            y_position = color_value - color_source;
            color_value = 0xF;
            color_value &= color_source;
            color_source = color_value << 4;
            color_value |= color_source;
            color_source = color_value << 8;
            color_value |= color_source;
            x_position = color_value << 16;
            x_position |= color_value;
            color_value = (u32)tile_buffer;
            __asm__ volatile ("" : "+r"(color_value));
            destination = (u32 *)(destination_offset + color_value);
        }
        source = glyph;
        source_end = glyph + 8;
        top_row = row;
        saved_color_delta = y_position;
        if (source != source_end) {
            register u32 glyph_mask asm("r3");

            glyph_mask = 0x11111111;
            do {
                register u32 color asm("r1");
                u32 glyph_word;

                glyph_word = *source++;
                color = glyph_word;
                color &= glyph_mask;
                glyph_word >>= 1;
                glyph_word &= glyph_mask;
                color |= glyph_word;
                *destination++ = (u32)x_position + color * (u32)y_position
                    + glyph_word;
            } while (source != source_end);
        }
    }

    {
        register u32 has_bottom_for_draw asm("r1");

        has_bottom_for_draw = has_bottom_tile;
        __asm__ volatile ("" : "+r"(has_bottom_for_draw));
        if (has_bottom_for_draw) {
            register u32 *destination asm("r6");
            register u32 color_delta asm("r7");
            register u32 foreground_color asm("r3");

            {
                register u32 destination_offset asm("r2");
                register u32 foreground_source asm("r1");
                register u32 foreground_value asm("r0");

                foreground_value = next_y_tile;
                __asm__ volatile ("" : "+r"(foreground_value));
                destination_offset = buffer_width;
                destination_offset *= foreground_value;
                destination_offset += x_tile;
                destination_offset <<= 5;
                color_delta = (u32)saved_color_delta;
                foreground_value = 0xF;
                foreground_source = foreground;
                __asm__ volatile ("" : "+r"(foreground_source));
                foreground_value &= foreground_source;
                foreground_source = foreground_value << 4;
                foreground_value |= foreground_source;
                foreground_source = foreground_value << 8;
                foreground_value |= foreground_source;
                foreground_color = foreground_value << 16;
                foreground_color |= foreground_value;
                foreground_value = (u32)tile_buffer;
                __asm__ volatile ("" : "+r"(foreground_value));
                destination = (u32 *)(destination_offset + foreground_value);
            }
            {
                register u32 const *source asm("r2") = glyph + 16;
                register u32 const *source_end asm("r4") = glyph + 24;
                register u32 glyph_mask asm("r5");

                if (source != source_end) {
                    glyph_mask = 0x11111111;
                    do {
                        register u32 color asm("r1");
                        u32 glyph_word;

                        glyph_word = *source++;
                        color = glyph_word;
                        color &= glyph_mask;
                        glyph_word >>= 1;
                        glyph_word &= glyph_mask;
                        color |= glyph_word;
                        *destination++ = foreground_color + color * color_delta
                            + glyph_word;
                    } while (source != source_end);
                }
            }
        }
    }

    {
        register u32 has_right_for_draw asm("r1");

        has_right_for_draw = has_right_tile;
        __asm__ volatile ("" : "+r"(has_right_for_draw));
        if (has_right_for_draw) {
            register u32 glyph_width_for_draw asm("r0");

            glyph_width_for_draw = (u32)glyph_width;
            __asm__ volatile ("" : "+r"(glyph_width_for_draw));
            if (glyph_width_for_draw > 1) {
                {
                    register u32 foreground_color asm("r2");
                    register u32 *destination asm("r6");
                    register u32 color_delta asm("r7");
                    register u32 destination_tile asm("r3");

                    {
                        register u32 pixel_offset asm("r0");
                        register u32 buffer_base asm("r1");

                        destination_tile = top_row;
                        __asm__ volatile ("" : "+r"(destination_tile));
                        destination_tile += x_tile;
                        pixel_offset = destination_tile << 5;
                        __asm__ volatile ("" : "+r"(pixel_offset));
                        buffer_base = (u32)tile_buffer;
                        __asm__ volatile ("" : "+r"(buffer_base));
                        destination_tile = pixel_offset + buffer_base;
                    }
                    color_delta = (u32)saved_color_delta;
                    {
                        register u32 foreground_source asm("r1");
                        register u32 foreground_value asm("r0");

                        foreground_value = 0xF;
                        foreground_source = foreground;
                        __asm__ volatile ("" : "+r"(foreground_source));
                        foreground_value &= foreground_source;
                        foreground_source = foreground_value << 4;
                        foreground_value |= foreground_source;
                        foreground_source = foreground_value << 8;
                        foreground_value |= foreground_source;
                        foreground_color = foreground_value << 16;
                        foreground_color |= foreground_value;
                    }
                    destination = (u32 *)destination_tile;
                    destination += 8;
                    {
                        u32 const *source = glyph + 8;
                        register u32 const *source_end asm("r4") = source + 8;
                        register u32 glyph_mask asm("r3");

                        if (source != source_end) {
                            glyph_mask = 0x11111111;
                            do {
                                register u32 color asm("r1");
                                u32 glyph_word;

                                glyph_word = *source++;
                                color = glyph_word;
                                color &= glyph_mask;
                                glyph_word >>= 1;
                                glyph_word &= glyph_mask;
                                color |= glyph_word;
                                *destination++ = foreground_color + color * color_delta
                                    + glyph_word;
                            } while (source != source_end);
                        }
                    }
                }

                {
                    register u32 has_bottom_for_draw asm("r0");

                    has_bottom_for_draw = has_bottom_tile;
                    __asm__ volatile ("" : "+r"(has_bottom_for_draw));
                    if (has_bottom_for_draw) {
                        register u32 foreground_color asm("r4");
                        register u32 *destination asm("r6");
                        register u32 color_delta asm("r7");
                        register u32 destination_base asm("r2");

                        {
                            register u32 offset asm("r0");
                            register u32 factor asm("r1");

                            factor = next_y_tile;
                            __asm__ volatile ("" : "+r"(factor));
                            offset = buffer_width;
                            __asm__ volatile ("" : "+r"(offset));
                            offset *= factor;
                            factor = x_tile;
                            __asm__ volatile ("" : "+r"(factor));
                            destination_base = factor + offset;
                            offset = destination_base << 5;
                            __asm__ volatile ("" : "+r"(offset));
                            factor = (u32)tile_buffer;
                            __asm__ volatile ("" : "+r"(factor));
                            destination_base = offset + factor;
                        }
                        color_delta = (u32)saved_color_delta;
                        {
                            register u32 foreground_source asm("r1");
                            register u32 foreground_value asm("r0");

                            foreground_value = 0xF;
                            foreground_source = foreground;
                            __asm__ volatile ("" : "+r"(foreground_source));
                            foreground_value &= foreground_source;
                            foreground_source = foreground_value << 4;
                            foreground_value |= foreground_source;
                            foreground_source = foreground_value << 8;
                            foreground_value |= foreground_source;
                            foreground_color = foreground_value << 16;
                            foreground_color |= foreground_value;
                        }
                        destination = (u32 *)destination_base;
                        destination += 8;
                        {
                            register u32 const *source asm("r3") = glyph + 24;
                            register u32 const *source_end asm("r2") = glyph + 32;
                            register u32 glyph_mask asm("r5");

                            if (source != source_end) {
                                glyph_mask = 0x11111111;
                                do {
                                    register u32 color asm("r1");
                                    u32 glyph_word;

                                    glyph_word = *source++;
                                    color = glyph_word;
                                    color &= glyph_mask;
                                    glyph_word >>= 1;
                                    glyph_word &= glyph_mask;
                                    color |= glyph_word;
                                    *destination++ = foreground_color + color * color_delta
                                        + glyph_word;
                                } while (source != source_end);
                            }
                        }
                    }
                }
            }
        }
    }
    goto return_glyph_width;

draw_unaligned:
    // These GNU C expression blocks keep formation of the two stacked ABI
    // arguments in source order. Their empty constraints still emit no bytes.
    DrawCharacterGlyphTo2DGfxBufferExtUnaligned(packed_size, tile_buffer,
        x_position, y_position,
        ({
            register u32 *glyph_argument asm("r0") = glyph;
            __asm__ volatile ("" : "+r"(glyph_argument));
            glyph_argument;
        }),
        ({
            register i32 foreground_argument asm("r1") = foreground;
            __asm__ volatile ("" : "+r"(foreground_argument));
            foreground_argument;
        }),
        background);

return_glyph_width:
    return glyph_width;

invalid_glyph:
    return 0;
}
