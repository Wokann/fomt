#include "terrain_movement.hh"

void TerrainMovementBounds::RefreshDown()
{
    down_limit = max_distance;
    ClipMapTerrainMovementIgnoringFlag1(terrain, box, &down_limit, 0, 0, 0);
}

void TerrainMovementBounds::RefreshUp()
{
    up_limit = -max_distance;
    ClipMapTerrainMovementIgnoringFlag1(terrain, box, 0, &up_limit, 0, 0);
}

void TerrainMovementBounds::RefreshLeft()
{
    left_limit = -max_distance;
    ClipMapTerrainMovementIgnoringFlag1(terrain, box, 0, 0, &left_limit, 0);
}

void TerrainMovementBounds::RefreshRight()
{
    right_limit = max_distance;
    ClipMapTerrainMovementIgnoringFlag1(terrain, box, 0, 0, 0, &right_limit);
}
