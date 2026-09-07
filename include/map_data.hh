#ifndef MAP_DATA_HH
#define MAP_DATA_HH

#include "prelude.h"

EXTERN_C

struct MapData
{
    void const * compressed_layers[6];
    void const * terrain_data;
    void const * terrain_map;
    u16 width;
    u16 height;
    u8 flags;
    u8 padding[3];
};

#define MAP_DATA_COUNT 66

extern MapData const gMapData[MAP_DATA_COUNT];

MapData const * GetMapData(u32 map_id);

EXTERN_C_END

#endif // MAP_DATA_HH
