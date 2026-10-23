#include "map_clock_status.hh"

#include <string.h>

void SetMapClockStatusHudMinuteDigits(MapClockStatusHudContent const * hud, u32 value)
{
    MapClockStatusHudDataPrefix * state = hud->state;
    u32 tens = value / 10;
    u32 ones = value % 10;
    u8 const * tens_tile = gMapClockStatusGlyphTiles[tens];
    memcpy(state->minute_digit_tiles[0], tens_tile, 32);
    state->time_tiles_dirty = 1;
    u8 const * ones_tile = gMapClockStatusGlyphTiles[ones];
    memcpy(state->minute_digit_tiles[1], ones_tile, 32);
    state->time_tiles_dirty = 1;
}

void SetMapClockStatusHudUnkSelector(MapClockStatusHudContent const * hud, u32 value)
{
    MapClockStatusHudDataPrefix * state = hud->state;
    u32 next = state->unk_selector;
    switch (value) {
    case 0: next = 0; break;
    case 1: next = 1; break;
    case 2: next = 2; break;
    case 3: next = 3; break;
    case 4: next = 4; break;
    }
    if (next != state->unk_selector) {
        state->unk_selector = next;
        state->unk_selector_dirty = 1;
    }
}

void SetMapClockStatusHudUnkValue(MapClockStatusHudContent const * hud, u32 value)
{
    MapClockStatusHudDataPrefix * state = hud->state;
    if (state->unk_value_active == 0 || value != state->unk_value) {
        state->unk_value_active = 1;
        state->unk_value = value;
        state->unk_value_dirty = 1;
    }
}

void ClearMapClockStatusHudUnkValue(MapClockStatusHudContent const * hud)
{
    MapClockStatusHudDataPrefix * state = hud->state;
    if (state->unk_value_active != 0) {
        state->unk_value_active = 0;
        state->unk_value_dirty = 1;
    }
}
