#include "ui_text_window.hh"

static inline void DrawUiTextWindowRow(u16 * row, u32 first, u32 width,
    u16 left, u16 middle, u16 right)
{
    u16 * cursor = row + first;
    *cursor++ = left;
    u16 * end = row + (first + width - 1);
    do {
        *cursor++ = middle;
    } while (cursor != end);
    *cursor = right;
}

void DrawUiTextWindowBorder(u16 * tilemap, u32 x, u32 y,
    u32 width, u32 height, u32 first_tile, u32 palette)
{
    x &= 31;
    if (x + width > 32)
        width = 32 - x;
    y &= 31;
    if (y + height > 32)
        height = 32 - y;
    u16 const base = (first_tile & 0x3FF) | ((palette << 12) & 0xF000);
    u16 * row = tilemap + y * 32;
    u16 const top_middle = base + 1;
    u16 const top_right = base + 4;
    DrawUiTextWindowRow(row, x, width, base, top_middle, top_right);
    row += 32;
    u16 const middle_left = base + 2;
    u16 const middle_fill = base + 3;
    u16 const middle_right = base + 8;
    y += height;
    u16 * end = tilemap + (y * 32 - 32);
    do {
        DrawUiTextWindowRow(row, x, width, middle_left, middle_fill, middle_right);
        row += 32;
    } while (row != end);
    u16 const bottom_left = base + 5;
    u16 const bottom_middle = base + 7;
    u16 const bottom_right = base + 6;
    DrawUiTextWindowRow(row, x, width, bottom_left, bottom_middle, bottom_right);
}
