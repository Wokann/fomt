#ifndef TERRAIN_MOVEMENT_HH
#define TERRAIN_MOVEMENT_HH

#include "unknown_types.hh"

// Cached signed pixel-distance limits that test terrain bit 0 only.
// This is the separate 0x28-byte layout, not ActorMovementBounds.
struct TerrainMovementBounds
{
    i32 down_limit;
    i32 up_limit;
    i32 left_limit;
    i32 right_limit;
    MapTerrainView terrain;
    Box box;
    i32 max_distance;

    void RefreshDown();
    void RefreshUp();
    void RefreshLeft();
    void RefreshRight();
};

typedef char TerrainMovementBoundsSizeCheck[sizeof(TerrainMovementBounds) == 0x28 ? 1 : -1];
typedef char TerrainMovementBoundsTerrainCheck[offsetof(TerrainMovementBounds, terrain) == 0x10 ? 1 : -1];
typedef char TerrainMovementBoundsBoxCheck[offsetof(TerrainMovementBounds, box) == 0x1C ? 1 : -1];
typedef char TerrainMovementBoundsDistanceCheck[offsetof(TerrainMovementBounds, max_distance) == 0x24 ? 1 : -1];

#endif // TERRAIN_MOVEMENT_HH
