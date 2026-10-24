#ifndef MAP_CLOCK_STATUS_HH
#define MAP_CLOCK_STATUS_HH

#include "prelude.h"
#include "control_widget.hh"
#include "hardware_dma_link.hh"
#include "hardware_resource.hh"
#include "hardware_state_clear.hh"
#include "resource_archive.hh"
#include <string.h>

#pragma interface "map_clock_status.hh"

// Confirmed by both native rendering paths: each buffer uploads eight OBJ
// tiles when dirty and when its DMA node is no longer linked.
// The state entry owns eight OBJ tiles; the DMA link follows its dirty byte.
struct MapClockStatusHudTileBuffer {
    u32 tiles[8][8];
    HardwareStateEntry state;
    u8 dirty;
    HardwareDmaCopyLink upload;

    MapClockStatusHudTileBuffer() : state(3), dirty(1) {}
    void SetTile(u32 (&tile)[8], u8 const * glyph)
    {
        memcpy(tile, glyph, 32);
        dirty = 1;
    }
    void SetTile(u32 index, u8 const * glyph)
    {
        memcpy(tiles[index], glyph, 32);
        dirty = 1;
    }
};

// Full native 0x35C allocation; unresolved selector/value storage stays unk.
struct MapClockStatusHudData {
    IndexedResourceArchive unk_archive_000;
    IndexedResourceArchive unk_archive_030;
    HardwareResourceEntry palette;
    HardwareDmaCopyLink palette_upload;
    u8 palette_dirty;
    MapClockStatusHudTileBuffer date_tiles;
    MapClockStatusHudTileBuffer time_tiles;
    u8 unk_selector;
    HardwareStateEntry unk_state_2D0;
    HardwareDmaCopyLink unk_dma_2D8;
    u8 unk_selector_dirty;
    u8 unk_value_active;
    u16 unk_value;
    HardwareResourceEntry unk_pool_2F4;
    HardwareDmaCopyLink unk_dma_2FC;
    HardwareStateEntry unk_state_314;
    HardwareDmaCopyLink unk_dma_31C;
    u8 unk_value_dirty;
    HardwareStateEntry unk_state_338;
    HardwareDmaCopyLink unk_dma_340;
    u8 unk_358;

private:
    friend struct MapClockStatusHudContent;
    MapClockStatusHudData();
};

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
#else
    MAP_CLOCK_DATE_HOUR_TENS_TILE = 6,
    MAP_CLOCK_TIME_COLON_TILE = 4,
    MAP_CLOCK_TIME_MINUTE_TENS_TILE = 5,
#endif
#if defined(REGION_JP)
    MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE = 2,
#else
    MAP_CLOCK_TIME_WEEKDAY_FIRST_TILE = 0,
#endif
};

typedef char MapClockStatusHudDataSize[sizeof(MapClockStatusHudData) == 0x35C ? 1 : -1];
typedef char MapClockStatusBufferSize[sizeof(MapClockStatusHudTileBuffer) == 0x124 ? 1 : -1];
typedef char MapClockStatusBufferStateOffset[offsetof(MapClockStatusHudTileBuffer, state) == 0x100 ? 1 : -1];
typedef char MapClockStatusBufferDirtyOffset[offsetof(MapClockStatusHudTileBuffer, dirty) == 0x108 ? 1 : -1];
typedef char MapClockStatusBufferUploadOffset[offsetof(MapClockStatusHudTileBuffer, upload) == 0x10C ? 1 : -1];
typedef char MapClockStatusDateOffset[offsetof(MapClockStatusHudData, date_tiles) == 0x84 ? 1 : -1];
typedef char MapClockStatusTimeOffset[offsetof(MapClockStatusHudData, time_tiles) == 0x1A8 ? 1 : -1];
typedef char MapClockStatusPaletteUploadOffset[offsetof(MapClockStatusHudData, palette_upload) == 0x68 ? 1 : -1];
typedef char MapClockStatusSelectorOffset[offsetof(MapClockStatusHudData, unk_selector) == 0x2CC ? 1 : -1];
typedef char MapClockStatusSelectorDirtyOffset[offsetof(MapClockStatusHudData, unk_selector_dirty) == 0x2F0 ? 1 : -1];
typedef char MapClockStatusValueActiveOffset[offsetof(MapClockStatusHudData, unk_value_active) == 0x2F1 ? 1 : -1];
typedef char MapClockStatusValueOffset[offsetof(MapClockStatusHudData, unk_value) == 0x2F2 ? 1 : -1];
typedef char MapClockStatusValueDirtyOffset[offsetof(MapClockStatusHudData, unk_value_dirty) == 0x334 ? 1 : -1];
typedef char MapClockStatusContentSize[sizeof(MapClockStatusHudContent) == 4 ? 1 : -1];

// The native control's state/table prefix occupies eight bytes; the
// four-byte content owner follows it. Its remaining implementation is native.
struct MapClockStatusHudWidget : ControlWidget {
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
#else
extern u8 const gUnk_086678A0[];
#endif

u32 DrawMapClockStatusWidget(MapClockStatusHudWidget * widget,
    HardwareSpriteBufferState * sprites, HardwareDisplayState * display,
    HardwareLinkedList * uploads, HardwareLinkedList * commands);

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

#pragma implementation

#endif // MAP_CLOCK_STATUS_HH
