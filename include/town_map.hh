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

enum
{
    TOWN_MAP_HOTSPOT_COUNT = 40,
};

extern TownMapHotspot const gTownMapHotspots[TOWN_MAP_HOTSPOT_COUNT];

bool TownMapHotspotContains(
    void const *, u32 cursor_x, u32 cursor_y, TownMapHotspot const * hotspot);

EXTERN_C_END

#endif // TOWN_MAP_HH
