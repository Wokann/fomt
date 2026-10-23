#include "map_clock_status.hh"

#include "fomt_constants.mary.h"

#include <string.h>

static inline u8 const * GetMapClockStatusGlyph(u32 index)
{
    return gMapClockStatusGlyphTiles[index];
}

void SetMapClockStatusHudSeason(MapClockStatusHudContent const * hud, int season)
{
    MapClockStatusHudDataPrefix * state = hud->state;
    u32 tiles[2];
    switch (season) {
    default:
    case SEASON_SPRING: tiles[0] = 11; tiles[1] = 12; break;
    case SEASON_SUMMER: tiles[0] = 13; tiles[1] = 14; break;
    case SEASON_FALL:   tiles[0] = 15; tiles[1] = 16; break;
    case SEASON_WINTER: tiles[0] = 17; tiles[1] = 18; break;
    }
    memcpy(state->season_tiles[0], gMapClockStatusGlyphTiles[tiles[0]], 32);
    state->date_tiles_dirty = 1;
    u8 const * second_tile = gMapClockStatusGlyphTiles[tiles[1]];
    memcpy(state->season_tiles[1], second_tile, 32);
    state->date_tiles_dirty = 1;
}

void SetMapClockStatusHudColonVisible(MapClockStatusHudContent const * hud, u8 visible)
{
    MapClockStatusHudDataPrefix * state = hud->state;
    if (visible != 0) {
        u8 const * colon = GetMapClockStatusGlyph(10);
        memcpy(state->colon_tile, colon, 32);
        state->time_tiles_dirty = 1;
    } else {
        u8 blank[32];
        memset(blank, 0, sizeof(blank));
        u8 const * pixels = blank;
        memcpy(state->colon_tile, pixels, 32);
        state->time_tiles_dirty = 1;
    }
}

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
