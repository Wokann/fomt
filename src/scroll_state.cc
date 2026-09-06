#include "prelude.h"

#include <string.h>

struct ScrollState
{
    u8 unknown_00[6];
    u16 last_rendered_position;
    u8 unknown_08[2];
    i16 scroll_offset;
    u8 unknown_0C[0x0C];
    u8 * buffer_start;
    u8 * buffer_end;
};

extern "C" void func_08075C88(ScrollState * state, i16 position);

extern "C" void ResetScrollPosition(ScrollState * state, u16 position)
    SECTION(".text.reset_scroll_position");

extern "C" void ResetScrollPosition(ScrollState * state, u16 position)
{
    state->last_rendered_position = 0xFFFF;
    state->scroll_offset = -1;
    func_08075C88(state, static_cast<i16>(position));
}

extern "C" void ClearScrollBuffer(ScrollState * state)
    SECTION(".text.clear_scroll_buffer");

extern "C" void ClearScrollBuffer(ScrollState * state)
{
    u8 * buffer_start = state->buffer_start;
    u8 * buffer_end = state->buffer_end;
    u32 size = ((buffer_end - buffer_start) >> 6) << 6;

    memset(buffer_start, 0xFF, size);
}
