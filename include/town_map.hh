#ifndef TOWN_MAP_HH
#define TOWN_MAP_HH

#include "prelude.h"

EXTERN_C

struct TownMapHotspot
{
    char const * primary_text;
    char const * alternate_text;
    u32 map_id;
    u16 map_x;
    u16 map_y;
    u8 min_cursor_x;
    u8 min_cursor_y;
    u8 max_cursor_x;
    u8 max_cursor_y;
};

// Native Town Map selection scans these records until either minimum coordinate
// is no longer less than its corresponding maximum coordinate. The final
// all-zero record in every subtable is therefore a terminator, not padding.
struct TownMapAreaBounds
{
    u16 min_x;
    u16 min_y;
    u16 max_x;
    u16 max_y;
    u32 unk_08;
};

enum
{
    TOWN_MAP_AREA_BOUNDS_000_COUNT = 18,
    TOWN_MAP_AREA_BOUNDS_003_COUNT = 11,
    TOWN_MAP_AREA_BOUNDS_005_COUNT = 27,
    TOWN_MAP_AREA_BOUNDS_007_COUNT = 17,
    TOWN_MAP_AREA_BOUNDS_001_COUNT = 3,
    TOWN_MAP_HOTSPOT_COUNT = 40,
    TOWN_MAP_AREA_LOOKUP_COUNT = 0x34,
};

// The source field order follows the physical ROM order, which differs from
// the lookup-table order.
struct TownMapAreaBoundsTables
{
    TownMapAreaBounds map_000[TOWN_MAP_AREA_BOUNDS_000_COUNT];
    TownMapAreaBounds map_003[TOWN_MAP_AREA_BOUNDS_003_COUNT];
    TownMapAreaBounds map_005[TOWN_MAP_AREA_BOUNDS_005_COUNT];
    TownMapAreaBounds map_007[TOWN_MAP_AREA_BOUNDS_007_COUNT];
    TownMapAreaBounds map_001[TOWN_MAP_AREA_BOUNDS_001_COUNT];
};

struct TownMapAreaLookup
{
    u32 lookup_key;
    TownMapAreaBounds const * bounds;
};

extern TownMapHotspot const gTownMapHotspots[TOWN_MAP_HOTSPOT_COUNT];
extern u16 const gTownMapResourceIds[];
extern TownMapAreaBoundsTables const gTownMapAreaBounds;
extern TownMapAreaLookup const gTownMapAreaLookup[TOWN_MAP_AREA_LOOKUP_COUNT];
extern TownMapAreaLookup const gTownMapAreaLookupFallback_034To133;
extern TownMapAreaLookup const gTownMapAreaLookupFallback_134To233;

void CopyBgMap30x13(void const *, u32 map_block, u16 const * source);

void CopyBgMapRect(
    void const *,
    u32 map_block,
    u32 x,
    u32 y,
    u32 width,
    u32 height,
    u16 const * source);

bool TownMapHotspotContains(
    void const *, u32 cursor_x, u32 cursor_y, TownMapHotspot const * hotspot);

EXTERN_C_END

#endif // TOWN_MAP_HH
