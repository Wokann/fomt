#include "fishing_area.hh"
#include "actor.hh"

FishingAreaBoundary const gFishingAreaBoundaries[] = {
    { 0x00000000, 0x00000021, 0x0000002A, 0x00000048, 0x00000044, 0x00000000 },
    { 0x00000000, 0x00000035, 0x00000020, 0x0000007D, 0x00000029, 0x00000001 },
    { 0x00000000, 0x00000075, 0x0000002A, 0x00000095, 0x00000033, 0x00000002 },
    { 0x00000002, 0x00000000, 0x0000002F, 0x0000007F, 0x00000057, 0x00000003 },
    { 0x00000001, 0x00000019, 0x00000000, 0x0000003F, 0x00000049, 0x00000004 },
    { 0x0000002B, 0x00000001, 0x00000000, 0x0000001C, 0x0000000A, 0x00000005 },
    { 0x00000000, 0x0000006E, 0x00000038, 0x00000075, 0x0000003D, 0x00000006 },
    { 0x00000007, 0x00000020, 0x0000003A, 0x000000AC, 0x0000003F, 0x00000003 },
};

// Coordinates are signed pixels / 8; rectangles include both endpoints.
extern "C" u32 GetFishingArea(Location const & location)
{
    u32 result = 7;
    i32 x = location.x / 8;
    i32 y = location.y / 8;
    for (i32 index = 0; index < static_cast<i32>(ARRAY_COUNT(gFishingAreaBoundaries)); ++index) {
        if (location.map == gFishingAreaBoundaries[index].map_id
            && x >= gFishingAreaBoundaries[index].minimum_x
            && x <= gFishingAreaBoundaries[index].maximum_x
            && y >= gFishingAreaBoundaries[index].minimum_y
            && y <= gFishingAreaBoundaries[index].maximum_y) {
            result = gFishingAreaBoundaries[index].area;
            break;
        }
    }
    return result;
}
