#ifndef TOWN_MAP_AREA_DATA_HH
#define TOWN_MAP_AREA_DATA_HH

#include "prelude.h"

EXTERN_C

// Native Town Map selection scans each subtable until its all-zero record.
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
};

struct TownMapAreaBoundsTables
{
    TownMapAreaBounds map_000[TOWN_MAP_AREA_BOUNDS_000_COUNT];
    TownMapAreaBounds map_003[TOWN_MAP_AREA_BOUNDS_003_COUNT];
    TownMapAreaBounds map_005[TOWN_MAP_AREA_BOUNDS_005_COUNT];
    TownMapAreaBounds map_007[TOWN_MAP_AREA_BOUNDS_007_COUNT];
    TownMapAreaBounds map_001[TOWN_MAP_AREA_BOUNDS_001_COUNT];
};

extern TownMapAreaBoundsTables const gTownMapAreaBounds;

EXTERN_C_END

#endif // TOWN_MAP_AREA_DATA_HH