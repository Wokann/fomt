#pragma implementation "ui_text_window_commands.cc"
#include "ui_text_window.hh"

bool UiTextWindowTileUploadCommand::Run()
{
    u32 const * current_source = source;
    u32 * current_destination = destination;
    if (dither != 0) {
        u32 * end = current_destination + tile_count * (TILE_SIZE_4BPP / sizeof(u32));
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
    CpuFastSet(current_source, current_destination, tile_count * (TILE_SIZE_4BPP / sizeof(u32)));
    return false;
}
