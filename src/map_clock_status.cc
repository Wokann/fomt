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

void SetMapClockStatusHudDayAndWeekday(MapClockStatusHudContent const * hud,
    u32 day, u32 weekday)
{
    MapClockStatusHudDataPrefix * state = hud->state;
    i32 tens = day / 10;
    u32 ones = day % 10;
    if (tens > 0) {
        u8 const * tile = GetMapClockStatusGlyph(tens);
        memcpy(state->day_digit_tiles[0], tile, 32);
        state->date_tiles_dirty = 1;
    } else {
        u8 blank[32];
        memset(blank, 0, sizeof(blank));
        u8 const * pixels = blank;
        memcpy(state->day_digit_tiles[0], pixels, 32);
        state->date_tiles_dirty = 1;
    }
    u8 const * ones_tile = GetMapClockStatusGlyph(ones);
    memcpy(state->day_digit_tiles[1], ones_tile, 32);
    state->date_tiles_dirty = 1;
#if defined(REGION_JP)
    u8 const * weekday_tile = GetMapClockStatusGlyph(weekday + 21);
    memcpy(state->weekday_tiles[0], weekday_tile, 32);
    state->time_tiles_dirty = 1;
#else
    u32 tiles[3];
    switch (weekday) {
    default:
    case DAY_OF_WEEK_SUNDAY:    tiles[0] = 96;  tiles[1] = 97;  tiles[2] = 98;  break;
    case DAY_OF_WEEK_MONDAY:    tiles[0] = 99;  tiles[1] = 100; tiles[2] = 101; break;
    case DAY_OF_WEEK_TUESDAY:   tiles[0] = 102; tiles[1] = 103; tiles[2] = 104; break;
    case DAY_OF_WEEK_WEDNESDAY: tiles[0] = 105; tiles[1] = 106; tiles[2] = 107; break;
    case DAY_OF_WEEK_THURSDAY:  tiles[0] = 108; tiles[1] = 109; tiles[2] = 110; break;
    case DAY_OF_WEEK_FRIDAY:    tiles[0] = 111; tiles[1] = 112; tiles[2] = 113; break;
    case DAY_OF_WEEK_SATURDAY:  tiles[0] = 114; tiles[1] = 115; tiles[2] = 116; break;
    }
    memcpy(state->weekday_tiles[0], gMapClockStatusGlyphTiles[tiles[0]], 32);
    state->time_tiles_dirty = 1;
    u8 const * second_tile = GetMapClockStatusGlyph(tiles[1]);
    memcpy(state->weekday_tiles[1], second_tile, 32);
    state->time_tiles_dirty = 1;
    u8 const * third_tile = GetMapClockStatusGlyph(tiles[2]);
    memcpy(state->weekday_tiles[2], third_tile, 32);
    state->time_tiles_dirty = 1;
#endif
}

void SetMapClockStatusHudHour(MapClockStatusHudContent const * hud, u32 hour)
{
    MapClockStatusHudDataPrefix * state = hud->state;
#if !defined(REGION_DE)
    u32 meridiem = 30;
    if (hour <= 11)
        meridiem = 28;
    u8 const * meridiem_tile = GetMapClockStatusGlyph(meridiem);
    memcpy(state->meridiem_tile, meridiem_tile, 32);
    state->date_tiles_dirty = 1;
#if defined(REGION_JP)
    u32 display_hour = hour;
#else
    u32 display_hour = 12;
#endif
    // Meridiem and both digits share this date-component dirty byte.
    u8 & date_dirty = state->date_tiles_dirty;
#if defined(REGION_JP)
    if (display_hour > 11)
        display_hour -= 12;
#else
    if (hour != 12) {
        display_hour = hour;
        if (display_hour > 11)
            display_hour -= 12;
    }
#endif
#else
    u32 display_hour = hour;
#endif
    i32 tens = display_hour / 10;
    u32 ones = display_hour % 10;
    if (tens > 0) {
        u8 const * tile = GetMapClockStatusGlyph(tens);
        memcpy(state->hour_tens_tile, tile, 32);
#if defined(REGION_DE)
        state->date_tiles_dirty = 1;
#else
        date_dirty = 1;
#endif
    } else {
        u8 blank[32];
        memset(blank, 0, sizeof(blank));
        u8 const * pixels = blank;
        memcpy(state->hour_tens_tile, pixels, 32);
#if defined(REGION_DE)
        state->date_tiles_dirty = 1;
#else
        date_dirty = 1;
#endif
    }
    u8 const * ones_tile = GetMapClockStatusGlyph(ones);
    memcpy(state->hour_ones_tile, ones_tile, 32);
#if defined(REGION_DE)
    // The DE ones digit belongs to the separate time component.
    state->time_tiles_dirty = 1;
#else
    date_dirty = 1;
#endif
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
