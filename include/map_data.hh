#ifndef MAP_DATA_HH
#define MAP_DATA_HH

#include "prelude.h"

extern "C" {

struct MapData
{
    u8 const * tiles;
    u8 const * palettes[2];
    u8 const * tilemaps[3];
    void const * terrain_data;
    void const * terrain_map;
    u16 width;
    u16 height;
    u8 flags;
    u8 padding[3];
};

typedef char MapDataSizeCheck[sizeof(MapData) == 0x28 ? 1 : -1];
typedef char MapDataPalettesCheck[offsetof(MapData, palettes) == 4 ? 1 : -1];
typedef char MapDataTilemapsCheck[offsetof(MapData, tilemaps) == 0xC ? 1 : -1];
typedef char MapDataWidthCheck[offsetof(MapData, width) == 0x20 ? 1 : -1];
typedef char MapDataHeightCheck[offsetof(MapData, height) == 0x22 ? 1 : -1];

enum
{
    MAP_DATA_COUNT = 66,
};

extern MapData const gMapData[MAP_DATA_COUNT];

MapData const * GetMapData(u32 map_id);

}

#endif // MAP_DATA_HH
