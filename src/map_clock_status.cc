#include "prelude.h"
#pragma implementation "map_clock_status.hh"
#include "map_clock_status.hh"

#include "fomt_constants.mary.h"

#include <string.h>

static inline u8 const * GetMapClockStatusGlyph(u32 index)
{
    return gMapClockStatusGlyphTiles[index];
}

inline MapClockStatusHudData::MapClockStatusHudData()
    : unk_archive_000(gUnk_0875B444),
#if defined(REGION_JP)
      unk_archive_030(gUnk_083ED9FC),
#else
      unk_archive_030(gUnk_086678A0),
#endif
      palette_dirty(1), unk_selector(0), unk_state_2D0(2),
      unk_selector_dirty(1), unk_value_active(0), unk_state_314(2),
      unk_value_dirty(1), unk_state_338(2), unk_358(1)
{
#if defined(REGION_DE)
    u8 const * middle_glyph = GetMapClockStatusGlyph(29);
    u32 (&first_label_tile)[8] = date_tiles.tiles[4];
    date_tiles.SetTile(5, middle_glyph);
    date_tiles.SetTile(first_label_tile, GetMapClockStatusGlyph(28));
    date_tiles.SetTile(6, GetMapClockStatusGlyph(30));
#else
    date_tiles.SetTile(5, GetMapClockStatusGlyph(29));
#endif
#if defined(REGION_JP)
    time_tiles.SetTile(0, GetMapClockStatusGlyph(21));
    time_tiles.SetTile(1, GetMapClockStatusGlyph(19));
    // Slot 2 belongs to the weekday setter; this fixed glyph occupies slot 3.
    time_tiles.SetTile(3, GetMapClockStatusGlyph(20));
#endif
    u8 blank[32];
    memset(blank, 0, sizeof(blank));
    time_tiles.SetTile(7, blank);
#if !defined(REGION_JP)
    time_tiles.SetTile(3, blank);
#endif
}

MapClockStatusHudContent::MapClockStatusHudContent()
    : state(new MapClockStatusHudData)
{
}

void SetMapClockStatusHudSeason(MapClockStatusHudContent const * hud, int season)
{
    MapClockStatusHudData * state = hud->state;
    u32 tiles[2];
    switch (season) {
    default:
    case SEASON_SPRING: tiles[0] = 11; tiles[1] = 12; break;
    case SEASON_SUMMER: tiles[0] = 13; tiles[1] = 14; break;
    case SEASON_FALL:   tiles[0] = 15; tiles[1] = 16; break;
    case SEASON_WINTER: tiles[0] = 17; tiles[1] = 18; break;
    }
    memcpy(state->date_tiles.tiles[0], gMapClockStatusGlyphTiles[tiles[0]], 32);
    state->date_tiles.dirty = 1;
    u8 const * second_tile = gMapClockStatusGlyphTiles[tiles[1]];
    memcpy(state->date_tiles.tiles[1], second_tile, 32);
    state->date_tiles.dirty = 1;
}

void SetMapClockStatusHudDayAndWeekday(MapClockStatusHudContent const * hud,
    u32 day, u32 weekday)
{
    MapClockStatusHudData * state = hud->state;
    i32 tens = day / 10;
    u32 ones = day % 10;
    if (tens > 0) {
        u8 const * tile = GetMapClockStatusGlyph(tens);
        memcpy(state->date_tiles.tiles[2], tile, 32);
        state->date_tiles.dirty = 1;
    } else {
        u8 blank[32];
        memset(blank, 0, sizeof(blank));
        u8 const * pixels = blank;
        memcpy(state->date_tiles.tiles[2], pixels, 32);
        state->date_tiles.dirty = 1;
    }
    u8 const * ones_tile = GetMapClockStatusGlyph(ones);
    memcpy(state->date_tiles.tiles[3], ones_tile, 32);
    state->date_tiles.dirty = 1;
#if defined(REGION_JP)
    u8 const * weekday_tile = GetMapClockStatusGlyph(weekday + 21);
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE], weekday_tile, 32);
    state->time_tiles.dirty = 1;
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
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE], gMapClockStatusGlyphTiles[tiles[0]], 32);
    state->time_tiles.dirty = 1;
    u8 const * second_tile = GetMapClockStatusGlyph(tiles[1]);
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE + 1], second_tile, 32);
    state->time_tiles.dirty = 1;
    u8 const * third_tile = GetMapClockStatusGlyph(tiles[2]);
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE + 2], third_tile, 32);
    state->time_tiles.dirty = 1;
#endif
}

void SetMapClockStatusHudHour(MapClockStatusHudContent const * hud, u32 hour)
{
    MapClockStatusHudData * state = hud->state;
#if !defined(REGION_DE)
    u32 meridiem = 30;
    if (hour <= 11)
        meridiem = 28;
    u8 const * meridiem_tile = GetMapClockStatusGlyph(meridiem);
    memcpy(state->date_tiles.tiles[4], meridiem_tile, 32);
    state->date_tiles.dirty = 1;
#if defined(REGION_JP)
    u32 display_hour = hour;
#else
    u32 display_hour = 12;
#endif
    // Meridiem and both digits share this date-component dirty byte.
    u8 & date_dirty = state->date_tiles.dirty;
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
        memcpy(state->date_tiles.tiles[MAP_CLOCK_DATE_HOUR_TENS_TILE], tile, 32);
#if defined(REGION_DE)
        state->date_tiles.dirty = 1;
#else
        date_dirty = 1;
#endif
    } else {
        u8 blank[32];
        memset(blank, 0, sizeof(blank));
        u8 const * pixels = blank;
        memcpy(state->date_tiles.tiles[MAP_CLOCK_DATE_HOUR_TENS_TILE], pixels, 32);
#if defined(REGION_DE)
        state->date_tiles.dirty = 1;
#else
        date_dirty = 1;
#endif
    }
    u8 const * ones_tile = GetMapClockStatusGlyph(ones);
#if defined(REGION_DE)
    memcpy(state->time_tiles.tiles[4], ones_tile, 32);
#else
    memcpy(state->date_tiles.tiles[7], ones_tile, 32);
#endif
#if defined(REGION_DE)
    // The DE ones digit belongs to the separate time component.
    state->time_tiles.dirty = 1;
#else
    date_dirty = 1;
#endif
}

void SetMapClockStatusHudColonVisible(MapClockStatusHudContent const * hud, u8 visible)
{
    MapClockStatusHudData * state = hud->state;
    if (visible != 0) {
        u8 const * colon = GetMapClockStatusGlyph(10);
        memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_COLON_TILE], colon, 32);
        state->time_tiles.dirty = 1;
    } else {
        u8 blank[32];
        memset(blank, 0, sizeof(blank));
        u8 const * pixels = blank;
        memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_COLON_TILE], pixels, 32);
        state->time_tiles.dirty = 1;
    }
}

void SetMapClockStatusHudMinuteDigits(MapClockStatusHudContent const * hud, u32 value)
{
    MapClockStatusHudData * state = hud->state;
    u32 tens = value / 10;
    u32 ones = value % 10;
    u8 const * tens_tile = gMapClockStatusGlyphTiles[tens];
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_MINUTE_TENS_TILE], tens_tile, 32);
    state->time_tiles.dirty = 1;
    u8 const * ones_tile = gMapClockStatusGlyphTiles[ones];
    memcpy(state->time_tiles.tiles[MAP_CLOCK_TIME_MINUTE_TENS_TILE + 1], ones_tile, 32);
    state->time_tiles.dirty = 1;
}

void SetMapClockStatusHudUnkSelector(MapClockStatusHudContent const * hud, u32 value)
{
    MapClockStatusHudData * state = hud->state;
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
    MapClockStatusHudData * state = hud->state;
    if (state->unk_value_active == 0 || value != state->unk_value) {
        state->unk_value_active = 1;
        state->unk_value = value;
        state->unk_value_dirty = 1;
    }
}

void ClearMapClockStatusHudUnkValue(MapClockStatusHudContent const * hud)
{
    MapClockStatusHudData * state = hud->state;
    if (state->unk_value_active != 0) {
        state->unk_value_active = 0;
        state->unk_value_dirty = 1;
    }
}
