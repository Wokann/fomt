#include "actor_terrain.hh"

#include "entity_actor.hh"
#include "map_data.hh"

static inline FieldRenderTileAttributes const * GetTerrainTile(
    MapTerrainView const & terrain, u32 x, u32 y)
{
    FieldRenderTileAttributes const * attributes = terrain.attributes;
    u32 width = terrain.width;
    if (attributes != nullptr && x <= width && y <= terrain.height) {
        u8 const * indices = terrain.indices;
        u32 index = y * width + x;
        if (indices != nullptr)
            return attributes + indices[index];
        return attributes + index;
    }
    return nullptr;
}

bool IsActorTerrainBlocked(AActorEntity const & actor)
{
    GameObject * world = actor.game_object;
    u32 map = actor.location_map;
    MapTerrainView const & terrain = world->GetMapTerrain(map);
    Box box_value = UnkMapBox(actor.GetBox());
    Box & box = box_value;
    if (IsMapTerrainBoxBlocked(terrain, box))
        return true;
    // Native mine collision tests bits 2..16 together; individual flag meanings remain unknown.
    if (map >= MAP_SPRING_MINE_FLOOR_0 && map <= MAP_LAKE_MINE_FLOOR_255) {
        FieldRenderTileAttributes const * tile = GetTerrainTile(terrain, box.x1 / 8, box.y1 / 8);
        if (tile != nullptr && (*reinterpret_cast<u32 const *>(tile) & 0x1FFFC) != 0)
            return true;
        tile = GetTerrainTile(terrain, box.x1 / 8, (box.y2 - 1) / 8);
        if (tile != nullptr && (*reinterpret_cast<u32 const *>(tile) & 0x1FFFC) != 0)
            return true;
        tile = GetTerrainTile(terrain, (box.x2 - 1) / 8, box.y1 / 8);
        if (tile != nullptr && (*reinterpret_cast<u32 const *>(tile) & 0x1FFFC) != 0)
            return true;
        tile = GetTerrainTile(terrain, (box.x2 - 1) / 8, (box.y2 - 1) / 8);
        if (tile != nullptr && (*reinterpret_cast<u32 const *>(tile) & 0x1FFFC) != 0)
            return true;
    }
    return false;
}
