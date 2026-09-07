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

// The second field points into raw rectangular range data.  Its individual
// record format is not fully decoded yet, but func_080782EC verifies bounds
// in the first eight bytes of each record.
struct TownMapAreaLookup
{
    u32 lookup_key;
    u8 const * bounds;
};

enum
{
    TOWN_MAP_HOTSPOT_COUNT = 40,
    TOWN_MAP_AREA_LOOKUP_COUNT = 0x34,
};

extern TownMapHotspot const gTownMapHotspots[TOWN_MAP_HOTSPOT_COUNT];
extern u16 const gTownMapResourceIds[];
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
