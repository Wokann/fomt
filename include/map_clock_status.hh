#ifndef MAP_CLOCK_STATUS_HH
#define MAP_CLOCK_STATUS_HH

#include "prelude.h"
#include "ui_text_window.hh"
#include "hardware_dma.hh"
#include "obj_palette_collection.hh"
#include "obj_tile_collection.hh"
#include "resource_archive.hh"
#include <string.h>


#include "map_clock_status_lifetimes.hh"

struct MapClockStatusHudContent {
    MapClockStatusHudData * state;
    MapClockStatusHudContent();
    ~MapClockStatusHudContent();
};

enum {
#if defined(REGION_DE)
    MAP_CLOCK_DATE_HOUR_TENS_TILE = 7,
    MAP_CLOCK_TIME_COLON_TILE = 5,
    MAP_CLOCK_TIME_MINUTE_TENS_TILE = 6,
#elif defined(REGION_JP) || defined(REGION_US) || defined(REGION_EU)
    MAP_CLOCK_DATE_HOUR_TENS_TILE = 6,
    MAP_CLOCK_TIME_COLON_TILE = 4,
    MAP_CLOCK_TIME_MINUTE_TENS_TILE = 5,
#endif
#if defined(REGION_JP)
    MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE = 2,
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
    MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE = 0,
#endif
};

typedef char MapClockStatusContentSize[sizeof(MapClockStatusHudContent) == 4 ? 1 : -1];

struct HardwareSpriteBufferState;

#pragma interface "map_clock_status.hh"

// The clock owns its HUD content after the shared eight-byte control base.
struct MapClockStatusHudWidget : ControlWidget {
    MapClockStatusHudWidget(u32 background, u32 screen, u32 palette, u32 mode);
    virtual ~MapClockStatusHudWidget();
    virtual u32 Draw(HardwareSpriteBufferState * sprites, HardwareDisplayState * display,
        HardwareLinkedList * uploads, HardwareLinkedList * commands);
    MapClockStatusHudContent content;
};

struct GameCalendar;
typedef char MapClockStatusWidgetContentOffset[offsetof(MapClockStatusHudWidget, content) == 8 ? 1 : -1];
typedef char MapClockStatusWidgetSize[sizeof(MapClockStatusHudWidget) == 12 ? 1 : -1];

EXTERN_C
// Calendar composition remains native; its callers use this one shared name.
void UpdateMapClockStatusHudCalendar(MapClockStatusHudContent const * hud,
    GameCalendar const & calendar, u8 show_colon);

void ClearMapClockStatusWidgetUnkValue(MapClockStatusHudWidget const * widget);
void SetMapClockStatusWidgetUnkValue(MapClockStatusHudWidget const * widget, u32 value);
void SetMapClockStatusWidgetUnkSelector(MapClockStatusHudWidget const * widget, u32 value);
void SetMapClockStatusWidgetMinuteDigits(MapClockStatusHudWidget const * widget, u32 value);
void SetMapClockStatusWidgetColonVisible(MapClockStatusHudWidget const * widget, u8 visible);
void SetMapClockStatusWidgetHour(MapClockStatusHudWidget const * widget, u32 hour);
void SetMapClockStatusWidgetDayAndWeekday(MapClockStatusHudWidget const * widget, u32 day, u32 weekday);
void SetMapClockStatusWidgetSeason(MapClockStatusHudWidget const * widget, int season);
void UpdateMapClockStatusWidgetCalendar(MapClockStatusHudWidget const * widget,
    GameCalendar const & calendar, u8 show_colon);

extern u8 const gUnk_0875B444[];
#if defined(REGION_JP)
extern u8 const gUnk_083ED9FC[];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern u8 const gUnk_086678A0[];
#endif

void DrawMapClockStatusHud(MapClockStatusHudContent const * hud, i32 x, i32 y,
    HardwareSpriteBufferState * buffer, HardwareLinkedList * queue);

// Invalid signed values use the spring tile pair, as in the native switch.
void SetMapClockStatusHudSeason(MapClockStatusHudContent const * hud, int season);
// The day is one-based. JP callers provide weekday 0..6; overseas invalid
// weekday values retain the native Sunday fallback. No day clamp is added.
void SetMapClockStatusHudDayAndWeekday(MapClockStatusHudContent const * hud,
    u32 day, u32 weekday);
// Regional native atlas: 31 tiles in JP, 128 overseas; no shared count.
extern u8 const gMapClockStatusGlyphTiles[][32];
// DE retains 24-hour digits; JP and US/EU keep their distinct 12-hour rules.
// Callers own the valid-hour policy: this setter does not clamp or wrap.
void SetMapClockStatusHudHour(MapClockStatusHudContent const * hud, u32 hour);
// Nonzero byte copies the colon glyph; zero clears its entire tile.
void SetMapClockStatusHudColonVisible(MapClockStatusHudContent const * hud, u8 visible);
// Copies both decimal tiles; rounding and range policy belong to callers.
void SetMapClockStatusHudMinuteDigits(MapClockStatusHudContent const * hud, u32 value);
// Values above 4 leave the selector unchanged. The visual meaning of
// these five native states is not established; do not infer weather.
void SetMapClockStatusHudUnkSelector(MapClockStatusHudContent const * hud, u32 value);
// Compare the full input word before storing its low 16 bits.
void SetMapClockStatusHudUnkValue(MapClockStatusHudContent const * hud, u32 value);
void ClearMapClockStatusHudUnkValue(MapClockStatusHudContent const * hud);
EXTERN_C_END


#endif // MAP_CLOCK_STATUS_HH
