#include "prelude.h"
#include "ui_state.hh"
#pragma implementation "ui_text_window.hh"
#include "ui_text_window.hh"
#include "gbasvc.h"

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

static inline void FillUiTextWindowTilemap(void * destination, u32 value)
{
    // The native window clears the first ten rows of its screen block.
    CpuFastSet(&value, destination, 0x010000A0);
}

static inline void UploadUiTextWindowPalette(u32 palette)
{
    CpuFastSet(gUiSharedPalette, reinterpret_cast<void *>(0x05000000 + (palette << 5)), 8);
}

bool UiTextWindowBorderCommand::Run()
{
    u16 entry = ((first_tile + 3) & 0x3FF) | (palette << 12);
    u32 value = entry | (static_cast<u32>(entry) << 16);
    FillUiTextWindowTilemap(reinterpret_cast<void *>(0x06000000 + (screen_block << 11)),
        value);
    DrawUiTextWindowBorder(reinterpret_cast<u16 *>(0x06000000 + (screen_block << 11)),
        x, 0, width, height, first_tile, palette);
    UploadUiTextWindowPalette(palette);
    return false;
}

void UiTextWindow::Open()
{
    u32 previous = phase;
    if (previous == HIDDEN) {
        u32 copy_mode = mode;
        if (copy_mode != 1)
            pending_uploads.Append(&upload);
        pending_uploads.Append(&border);
        frame = previous;
    }
    switch (phase) {
    case HIDDEN:
    case OPENING:
    case CLOSING:
        phase = OPENING;
        break;
    case VISIBLE:
        break;
    default:
        break;
    }
}

void UiTextWindow::OpenImmediate()
{
    Open();
    phase = VISIBLE;
    frame = 9;
}

void UiTextWindow::Close()
{
    if (phase != HIDDEN)
        phase = CLOSING;
}

void UiTextWindow::CloseImmediate()
{
    if (phase != HIDDEN)
        phase = HIDDEN;
}

UiTextWindowBorderCommand::UiTextWindowBorderCommand(i32 x, i32 y,
    u32 width, u32 height, u32 screen, u32 tile, u32 bank)
    : x(x), y(y), width(width), height(height), screen_block(screen),
      first_tile(tile), palette(bank)
{
}

bool UiTextWindowTileUploadCommand::Run()
{
    u32 const * current_source = source;
    u32 * current_destination = destination;
    if (dither != 0) {
        u32 * end = current_destination + tile_count * 8;
        u32 next_phase = phase;
        next_phase ^= 1;
        phase = next_phase;
        u32 mask = 0x0F0F0F0Fu << (next_phase * 4);
        u32 inverse = ~mask;
        do {
            *current_destination++ = *current_source++ & mask;
            *current_destination++ = *current_source++ & inverse;
            *current_destination++ = *current_source++ & mask;
            *current_destination++ = *current_source++ & inverse;
            *current_destination++ = *current_source++ & mask;
            *current_destination++ = *current_source++ & inverse;
            *current_destination++ = *current_source++ & mask;
            *current_destination++ = *current_source++ & inverse;
        } while (current_destination != end);
        return true;
    }
    CpuFastSet(current_source, current_destination, tile_count * 8);
    return false;
}
