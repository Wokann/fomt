#ifndef MAP_CLOCK_STATUS_HH
#define MAP_CLOCK_STATUS_HH

#include "prelude.h"

#include "hardware_dma_link.hh"
#include "hardware_resource.hh"
#include "hardware_state_clear.hh"
#include "resource_handle.hh"

#pragma interface "map_clock_status.hh"

// Native allocation is 0x35C in all four regions. Resource/handle/link members
// are confirmed independently by construction and reverse-order destruction.
struct MapClockStatusHudData {
    IndexedResourceArchive unk_archive_000;
    IndexedResourceArchive unk_archive_030;
    HardwareResourceEntry unk_pool_060;
    HardwareDmaCopyLink date_dma;
    u8 unk_080;
    u32 season_tiles[2][8];
    u32 day_digit_tiles[2][8];
#if defined(REGION_DE)
    u32 unk_104[24];
    u32 hour_tens_tile[8];
#else
    u32 meridiem_tile[8];
    u32 unk_124[8];
    u32 hour_tens_tile[8];
    u32 hour_ones_tile[8];
#endif
    HardwareStateEntry date_tiles_state;
    u8 date_tiles_dirty;
    HardwareDmaCopyLink time_dma;
#if defined(REGION_JP)
    u32 unk_1A8[16];
    u32 weekday_tiles[1][8];
#else
    u32 weekday_tiles[3][8];
#endif
    u32 unk_208[8];
#if defined(REGION_DE)
    u32 hour_ones_tile[8];
#endif
    u32 colon_tile[8];
    u32 minute_digit_tiles[2][8];
#if !defined(REGION_DE)
    u32 unk_288[8];
#endif
    HardwareStateEntry time_tiles_state;
    u8 time_tiles_dirty;
    HardwareDmaCopyLink unk_dma_2B4;
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
    // The still-native content constructor initializes this aggregate.
    MapClockStatusHudData();
};

struct MapClockStatusHudContent {
    MapClockStatusHudData * state;
    // This constructor remains native while its member initialization is recovered.
    MapClockStatusHudContent();
    ~MapClockStatusHudContent() { delete state; }
};

typedef char MapClockStatusHudDataSize[sizeof(MapClockStatusHudData) == 0x35C ? 1 : -1];
typedef char MapClockStatusArchiveOffset[offsetof(MapClockStatusHudData, unk_archive_030) == 0x30 ? 1 : -1];
typedef char MapClockStatusDateDmaOffset[offsetof(MapClockStatusHudData, date_dma) == 0x68 ? 1 : -1];
typedef char MapClockStatusDateStateOffset[offsetof(MapClockStatusHudData, date_tiles_state) == 0x184 ? 1 : -1];
typedef char MapClockStatusTimeDmaOffset[offsetof(MapClockStatusHudData, time_dma) == 0x190 ? 1 : -1];
typedef char MapClockStatusTimeStateOffset[offsetof(MapClockStatusHudData, time_tiles_state) == 0x2A8 ? 1 : -1];
typedef char MapClockStatusUnknownStateOffset[offsetof(MapClockStatusHudData, unk_state_338) == 0x338 ? 1 : -1];
typedef char MapClockStatusLastDmaOffset[offsetof(MapClockStatusHudData, unk_dma_340) == 0x340 ? 1 : -1];

typedef char MapClockStatusSeasonTilesOffset[offsetof(MapClockStatusHudData, season_tiles) == 0x84 ? 1 : -1];
typedef char MapClockStatusDayDigitsOffset[offsetof(MapClockStatusHudData, day_digit_tiles) == 0xC4 ? 1 : -1];
#if defined(REGION_JP)
typedef char MapClockStatusWeekdayOffset[offsetof(MapClockStatusHudData, weekday_tiles) == 0x1E8 ? 1 : -1];
#else
typedef char MapClockStatusWeekdayOffset[offsetof(MapClockStatusHudData, weekday_tiles) == 0x1A8 ? 1 : -1];
#endif
typedef char MapClockStatusDateDirtyOffset[offsetof(MapClockStatusHudData, date_tiles_dirty) == 0x18C ? 1 : -1];
#if defined(REGION_DE)
typedef char MapClockStatusHourTensOffset[offsetof(MapClockStatusHudData, hour_tens_tile) == 0x164 ? 1 : -1];
typedef char MapClockStatusHourOnesOffset[offsetof(MapClockStatusHudData, hour_ones_tile) == 0x228 ? 1 : -1];
typedef char MapClockStatusColonOffset[offsetof(MapClockStatusHudData, colon_tile) == 0x248 ? 1 : -1];
typedef char MapClockStatusMinuteDigitsOffset[offsetof(MapClockStatusHudData, minute_digit_tiles) == 0x268 ? 1 : -1];
#else
typedef char MapClockStatusMeridiemOffset[offsetof(MapClockStatusHudData, meridiem_tile) == 0x104 ? 1 : -1];
typedef char MapClockStatusHourTensOffset[offsetof(MapClockStatusHudData, hour_tens_tile) == 0x144 ? 1 : -1];
typedef char MapClockStatusHourOnesOffset[offsetof(MapClockStatusHudData, hour_ones_tile) == 0x164 ? 1 : -1];
typedef char MapClockStatusColonOffset[offsetof(MapClockStatusHudData, colon_tile) == 0x228 ? 1 : -1];
typedef char MapClockStatusMinuteDigitsOffset[offsetof(MapClockStatusHudData, minute_digit_tiles) == 0x248 ? 1 : -1];
#endif
typedef char MapClockStatusTimeDirtyOffset[offsetof(MapClockStatusHudData, time_tiles_dirty) == 0x2B0 ? 1 : -1];
typedef char MapClockStatusSelectorOffset[offsetof(MapClockStatusHudData, unk_selector) == 0x2CC ? 1 : -1];
typedef char MapClockStatusSelectorDirtyOffset[offsetof(MapClockStatusHudData, unk_selector_dirty) == 0x2F0 ? 1 : -1];
typedef char MapClockStatusValueActiveOffset[offsetof(MapClockStatusHudData, unk_value_active) == 0x2F1 ? 1 : -1];
typedef char MapClockStatusValueOffset[offsetof(MapClockStatusHudData, unk_value) == 0x2F2 ? 1 : -1];
typedef char MapClockStatusValueDirtyOffset[offsetof(MapClockStatusHudData, unk_value_dirty) == 0x334 ? 1 : -1];
typedef char MapClockStatusContentSize[sizeof(MapClockStatusHudContent) == 4 ? 1 : -1];

EXTERN_C
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
