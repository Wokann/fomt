#include "prelude.h"

#include <string.h>

#pragma implementation "scroll_state.hh"
#include "scroll_state.hh"
#include "hardware_dma.hh"

extern "C" void UploadScrollBufferRows(ScrollState * state, i32 first, i32 last)
{
    if (state->upload.IsQueued() || (first == 0 && last == 0))
        return;
    // Preserve the original arithmetic for requests wider than one screen block.
    if (last - first > 32)
        first = last + 32;
    u32 wrapped = last & 31;
    i32 count = last - first;
    if (wrapped < static_cast<u32>(count) && wrapped != 0) {
        i32 before_wrap = count - wrapped;
        state->upload.SetTransfers(
            &state->rows[first],
            state->destination + (32 - before_wrap) * 64, before_wrap * 64,
            &state->rows[first + before_wrap],
            state->destination, wrapped * 64);
        state->commands->Append(&state->upload);
    } else {
        state->upload.SetTransfers(
            &state->rows[first],
            state->destination + (first & 31) * 64, count * 64,
            nullptr, nullptr, 0);
        state->commands->Append(&state->upload);
    }
    state->scroll_offset = state->position - state->position % 8;
}

extern "C" void ResetScrollPosition(ScrollState * state, u16 value)
{
    state->last_rendered_position = 0xFFFF;
    state->scroll_offset = -1;
    SetScrollPosition(state, static_cast<i16>(value));
}

extern "C" void ClearScrollBuffer(ScrollState * state)
{
    u8 * first = reinterpret_cast<u8 *>(state->rows.first);
    u8 * last = reinterpret_cast<u8 *>(state->rows.last);
    u32 size = ((last - first) >> 6) << 6;
    memset(first, 0xFF, size);
}

bool ScrollBufferUploadCommand::Run()
{
    CopyHardwareDma3(first_source, first_destination, first_bytes);
    if (second_destination != nullptr)
        CopyHardwareDma3(second_source, second_destination, second_bytes);
    return false;
}

extern "C" void SetScrollBottomLimit(ScrollState * state, i16 limit)
{
    if (limit <= state->height)
        state->bottom_limit = limit;
    else
        state->bottom_limit = state->height;
    if (state->bottom_limit < 160)
        state->bottom_limit = 160;
}
