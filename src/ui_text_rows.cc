// The text-output types contain the actual inline row/pixel allocations.
#include <new>
#include "ui_text_rows.hh"
#include "ui_state.hh"
#include "font.hh"
#include "resource_handle.hh"
#include "ui_graphics_sizes.hh"
#include "ui_text_window.hh"

bool UiTextTileCopyCommand::Run()
{
    UiTextTileCopyCommand * command = this;
    u32 const * source = command->source;
    u32 * destination = command->destination;
    if (command->alternate_nibbles) {
        u32 * end = destination + command->tile_count * (TILE_SIZE_4BPP / sizeof(u32));
        u32 phase = command->nibble_phase ^ 1;
        command->nibble_phase = phase;
        u32 mask = 0x0F0F0F0Fu << (phase * 4);
        u32 alternate = ~mask;
        do {
            *destination++ = *source++ & mask;
            *destination++ = *source++ & alternate;
            *destination++ = *source++ & mask;
            *destination++ = *source++ & alternate;
            *destination++ = *source++ & mask;
            *destination++ = *source++ & alternate;
            *destination++ = *source++ & mask;
            *destination++ = *source++ & alternate;
        } while (destination != end);
        return true;
    }
    CpuFastSet(source, destination, command->tile_count * (TILE_SIZE_4BPP / sizeof(u32)));
    return false;
}

bool UnkUiSelectionData::Emit(u32 code)
{
    u32 column = unk_14;
    UnkUiSelectionRow * row = rows[GetUiTextPhysicalRow(this, unk_16)].Get();
    UnkUiSelectionEntry * entry = &row->Entry(column >> 2);
    u32 advanced = DrawUiTextEntry(entry, code, column & 3);
    if (advanced == 0)
        return false;
    if (advanced > 2)
        return false;
    u32 next = column + advanced;
    if (next > 27)
        next %= 28;
    unk_14 = next;
    if (code != 0x20 && code != 0x8140)
        unk_1b = 1;
    unk_1a = 1;
    return true;
}

void UnkUiSelectionData::CarriageReturn()
{
    unk_14 = 0;
}

void UnkUiSelectionData::LineFeed()
{
    if (unk_16 <= 1)
        ++unk_16;
    else {
        if (++unk_18 > 2)
            unk_18 = 0;
        int row = GetUiTextPhysicalRow(this, 2);
        UnkUiSelectionRow * row_buffer = rows[row].Get();
        for (int column = 0; column <= 6; ++column) {
            UnkUiSelectionEntry * entry = &row_buffer->Entry(column);
            UnkUiSelectionTileBuffer * pixels = entry->pixels.value;
            UnkUiSelectionDimensions dimensions(4, 2);
            Clear2DGfxBuffer(reinterpret_cast<u32 const &>(dimensions), pixels->tiles, 0);
            entry->changed = entry->state.handle != 0;
        }
        unk_19 = 1;
        unk_1a = 1;
    }
}

void UnkUiSelectionData::NextPage()
{
    for (int row = 0; row <= 2; ++row) {
        for (int column = 0; column <= 6; ++column) {
            UnkUiSelectionEntry * entry = &GetUiTextEntry(*this, row, column);
            ClearUiTextEntry(entry);
        }
    }
    unk_16 = 0;
    unk_14 = 0;
    unk_19 = 1;
    unk_1a = 1;
    unk_1b = 0;
}

u8 UnkUiSelectionData::ShouldStop()
{
    return unk_19;
}

bool UiTextInputAdapter::Fast()
{
    UiTextInputAdapter const * input = this;
    return HasUiTextAdvanceKeys(static_cast<u8>(input->pressed));
}

bool UiTextInputAdapter::WaitForInput()
{
    return true;
}

bool UiTextInputAdapter::Resume()
{
    UiTextInputAdapter const * input = this;
    bool result = false;
    if (input->allow_resume) {
        if (HasUiTextAdvanceKeys(static_cast<u8>(input->pressed)))
            result = true;
    }
    return result;
}

bool UiTextWindowSetupCommand::Run()
{
    UiTextWindowSetupCommand * command = this;
    u16 tile = ((command->first_tile + 3) & 0x3FF) | (command->background_palette << 12);
    u32 fill = tile | (static_cast<u32>(tile) << 16);
    FillUiFastWords(fill, reinterpret_cast<void *>(BG_SCREEN_ADDR(command->screen_block)),
        160);
    DrawUiTextWindowBorder(reinterpret_cast<u16 *>(BG_SCREEN_ADDR(command->screen_block)),
        16, 0, 14, 3, command->first_tile, command->background_palette);
    DrawUiTextWindowBorder(reinterpret_cast<u16 *>(BG_SCREEN_ADDR(command->screen_block)),
        0, 3, 30, 7, command->first_tile, command->background_palette);
    u32 palette = command->background_palette;
    CpuFastSet(gUiSharedPalette, reinterpret_cast<void *>(BG_PLTT + palette * PLTT_SIZE_4BPP), PLTT_SIZE_4BPP / sizeof(u32));
    CpuFastSet(IndexedResourceArchive(gUiHandCursorArchive).GetGroupData(0).palettes.data,
        reinterpret_cast<void *>(OBJ_PLTT + command->cursor_palette * PLTT_SIZE_4BPP), PLTT_SIZE_4BPP / sizeof(u32));
    return false;
}
