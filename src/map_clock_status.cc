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

MapClockStatusHudContent::~MapClockStatusHudContent()
{
    delete state;
}

static inline bool HudHasHandle(HardwareResourceEntry const & entry)
{
    return entry.handle != 0;
}

static inline bool HudHasHandle(HardwareStateEntry const & entry)
{
    return entry.handle != 0;
}

static inline void QueueHudCopy(HardwareDmaCopyLink & link,
    void const * source, void * destination, u32 bytes, HardwareLinkedList * queue)
{
    link.source = source;
    link.destination = destination;
    link.byte_count = bytes;
    queue->Append(&link);
}

static inline void SubmitHudSprite(HardwareSpriteBufferState * buffer,
    HardwareSpriteOamRecord const & sprite)
{
    u32 const & position_and_mode = reinterpret_cast<u32 const &>(sprite);
    u32 count = buffer->sprite_count;
    if (count < ARRAY_COUNT(buffer->sprites)) {
        HardwareSpriteOamRecord & destination = buffer->sprites[count];
        reinterpret_cast<u32 *>(&destination)[0] = position_and_mode;
        reinterpret_cast<u16 *>(&destination)[2] = reinterpret_cast<u16 const *>(&sprite)[2];
        buffer->sprite_count = count + 1;
    }
}

static inline u32 HudPaletteBank(HardwareResourceEntry & entry)
{
    return GetHardwarePoolHandleIndex(&entry, entry.handle);
}

static inline void DrawHudTileBuffer(MapClockStatusHudTileBuffer & tiles,
    i32 x, i32 y, u32 palette, HardwareSpriteBufferState * buffer, HardwareLinkedList * queue)
{
    if (HudHasHandle(tiles.state)) {
        u32 tile = tiles.state.GetTileIndex();
        if (tiles.dirty && !tiles.upload.IsQueued()) {
            QueueHudCopy(tiles.upload, tiles.tiles,
                reinterpret_cast<void *>(0x06010000 + tile * 32), 256, queue);
            tiles.dirty = 0;
        }
        HardwareSpriteOamRecord sprite = {};
        sprite.mosaic = 1;
        sprite.shape = 1;
        sprite.size = 2;
        sprite.y = y;
        sprite.x = x;
        sprite.tile_index = tile;
        sprite.palette_bank = static_cast<u16>(palette);
        SubmitHudSprite(buffer, sprite);
    }
}

void DrawMapClockStatusHud(MapClockStatusHudContent const * hud, i32 x, i32 y,
    HardwareSpriteBufferState * buffer, HardwareLinkedList * queue)
{
    MapClockStatusHudData * state = hud->state;
    if (!HudHasHandle(state->palette)) return;
    u32 palette = HudPaletteBank(state->palette);
    if (state->palette_dirty && !state->palette_upload.IsQueued()) {
        QueueHudCopy(state->palette_upload,
            state->unk_archive_000.GetGroupData(0).fifth.data,
            reinterpret_cast<void *>(0x05000200 + palette * 32), 32, queue);
        state->palette_dirty = 0;
    }
    i32 draw_x = x + 4;
    i32 draw_y = y + 4;
    DrawHudTileBuffer(state->date_tiles, draw_x, draw_y, palette, buffer, queue);
    DrawHudTileBuffer(state->time_tiles, draw_x + 32, draw_y, palette, buffer, queue);
    HardwareSpriteOamRecord base = {};
    base.mosaic = 1;
    base.size = 1;
    if (HudHasHandle(state->unk_state_2D0)) {
        u32 tile = state->unk_state_2D0.GetTileIndex();
        if (state->unk_selector_dirty && !state->unk_dma_2D8.IsQueued()) {
            IndexedResourceGroupResult group = ResolveIndexedResourceGroup(&state->unk_archive_000, state->unk_selector);
            QueueHudCopy(state->unk_dma_2D8, group.fourth.data,
                reinterpret_cast<void *>(0x06010000 + tile * 32), 128, queue);
            state->unk_selector_dirty = 0;
        }
        HardwareSpriteOamRecord sprite = base;
        sprite.y = draw_y;
        sprite.x = draw_x + 64;
        sprite.tile_index = tile;
        sprite.palette_bank = static_cast<u16>(palette);
        SubmitHudSprite(buffer, sprite);
    }
    if (!HudHasHandle(state->unk_state_314) || !HudHasHandle(state->unk_pool_2F4)) return;
    HardwareSpriteOamRecord sprite = base;
    sprite.y = draw_y;
    sprite.x = draw_x + 88;
    if (state->unk_value_active) {
        u32 tile = state->unk_state_314.GetTileIndex();
        u32 value_palette = HudPaletteBank(state->unk_pool_2F4);
        if (state->unk_value_dirty) {
            IndexedResourceGroupResult group = ResolveIndexedResourceGroup(&state->unk_archive_030, state->unk_value);
            if (!state->unk_dma_31C.IsQueued()) {
                QueueHudCopy(state->unk_dma_31C, group.fourth.data,
                    reinterpret_cast<void *>(0x06010000 + tile * 32), 128, queue);
            }
            if (!state->unk_dma_2FC.IsQueued()) {
                QueueHudCopy(state->unk_dma_2FC, group.fifth.data,
                    reinterpret_cast<void *>(0x05000200 + value_palette * 32), 32, queue);
            }
            state->unk_value_dirty = 0;
        }
        sprite.tile_index = tile;
        sprite.palette_bank = static_cast<u16>(value_palette);
        SubmitHudSprite(buffer, sprite);
    }
    if (HudHasHandle(state->unk_state_338)) {
        u32 tile = state->unk_state_338.GetTileIndex();
        if (state->unk_358 && !state->unk_dma_340.IsQueued()) {
            IndexedResourceGroupResult group = ResolveIndexedResourceGroup(&state->unk_archive_000, 5);
            QueueHudCopy(state->unk_dma_340, group.fourth.data,
                reinterpret_cast<void *>(0x06010000 + tile * 32), 128, queue);
            state->unk_358 = 0;
        }
        HardwareSpriteOamRecord & record = sprite;
        record.tile_index = tile;
        record.palette_bank = palette;
        SubmitHudSprite(buffer, sprite);
    }
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

void ClearMapClockStatusWidgetUnkValue(MapClockStatusHudWidget const * widget)
{
    ClearMapClockStatusHudUnkValue(&widget->content);
}

void SetMapClockStatusWidgetUnkValue(MapClockStatusHudWidget const * widget, u32 value)
{
    SetMapClockStatusHudUnkValue(&widget->content, value);
}

void SetMapClockStatusWidgetUnkSelector(MapClockStatusHudWidget const * widget, u32 value)
{
    SetMapClockStatusHudUnkSelector(&widget->content, value);
}

void SetMapClockStatusWidgetMinuteDigits(MapClockStatusHudWidget const * widget, u32 value)
{
    SetMapClockStatusHudMinuteDigits(&widget->content, value);
}

void SetMapClockStatusWidgetColonVisible(MapClockStatusHudWidget const * widget, u8 visible)
{
    SetMapClockStatusHudColonVisible(&widget->content, visible);
}

void SetMapClockStatusWidgetHour(MapClockStatusHudWidget const * widget, u32 hour)
{
    SetMapClockStatusHudHour(&widget->content, hour);
}

void SetMapClockStatusWidgetDayAndWeekday(MapClockStatusHudWidget const * widget, u32 day, u32 weekday)
{
    SetMapClockStatusHudDayAndWeekday(&widget->content, day, weekday);
}

void SetMapClockStatusWidgetSeason(MapClockStatusHudWidget const * widget, int season)
{
    SetMapClockStatusHudSeason(&widget->content, season);
}

void UpdateMapClockStatusWidgetCalendar(MapClockStatusHudWidget const * widget,
    GameCalendar const & calendar, u8 show_colon)
{
    UpdateMapClockStatusHudCalendar(&widget->content, calendar, show_colon);
}

u32 DrawMapClockStatusWidget(MapClockStatusHudWidget * widget,
    HardwareSpriteBufferState * sprites, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands)
{
    u32 const state = UpdateControlWidget(widget, display, uploads, commands);
    if (state == 3) {
        i32 x = widget->vtable->get_x(widget);
        i32 y = widget->vtable->get_y(widget);
        DrawMapClockStatusHud(&widget->content, x, y, sprites, uploads);
    }
    return state;
}
