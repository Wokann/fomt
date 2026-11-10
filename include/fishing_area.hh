#ifndef FISHING_AREA_HH
#define FISHING_AREA_HH

#include "prelude.h"

struct Location;

enum {
    FISHING_AREA_COUNT = 7,
    FISHING_AREA_NONE = FISHING_AREA_COUNT,
};

struct FishingAreaBoundary {
    u32 map_id;
    i32 minimum_x;
    i32 minimum_y;
    i32 maximum_x;
    i32 maximum_y;
    u32 area;
};

extern "C" u32 GetFishingArea(Location const & location);
extern FishingAreaBoundary const gFishingAreaBoundaries[];

#endif // FISHING_AREA_HH
