#ifndef MAP_DATA_HH
#define MAP_DATA_HH

#include "prelude.h"

// Rectangle patches copy all four bytes. Plot refreshes change bit 0 and
// the upper halfword's bits 1..15; rectangle blocking checks bits 0 and 1.
struct FieldRenderTileAttributes
{
    bool unk_00_00 : 1;
    bool unk_00_01 : 1;
    u32 unk_00_02 : 14;
    u16 unk_02_00 : 1;
    u16 unk_02_01 : 15;
};

typedef char FieldRenderTileAttributesSizeCheck[sizeof(FieldRenderTileAttributes) == 4 ? 1 : -1];

// A direct tile grid or an indexed view of a table of tile attributes.
// This is a borrowed view; it does not own either input buffer.
struct MapTerrainView
{
    MapTerrainView(FieldRenderTileAttributes const * attributes, u32 width, u32 height)
        : attributes(attributes), indices(nullptr), width(width), height(height) {}

    MapTerrainView(FieldRenderTileAttributes const * attributes, u8 const * indices,
        u32 width, u32 height)
        : attributes(attributes), indices(indices), width(width), height(height) {}

    FieldRenderTileAttributes const * attributes;
    u8 const * indices;
    u16 width;
    u16 height;
};

typedef char MapTerrainViewSizeCheck[sizeof(MapTerrainView) == 12 ? 1 : -1];
typedef char MapTerrainViewIndicesCheck[offsetof(MapTerrainView, indices) == 4 ? 1 : -1];
typedef char MapTerrainViewWidthCheck[offsetof(MapTerrainView, width) == 8 ? 1 : -1];
typedef char MapTerrainViewHeightCheck[offsetof(MapTerrainView, height) == 10 ? 1 : -1];

struct Box;

extern "C" {

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

typedef char MapDataSizeCheck[sizeof(MapData) == 0x28 ? 1 : -1];
typedef char MapDataWidthCheck[offsetof(MapData, width) == 0x20 ? 1 : -1];
typedef char MapDataHeightCheck[offsetof(MapData, height) == 0x22 ? 1 : -1];

enum
{
    MAP_DATA_COUNT = 66,
};

extern MapData const gMapData[MAP_DATA_COUNT];

MapData const * GetMapData(u32 map_id);

// The selector remains native; all regions use the same actual symbol.
u32 SelectMapDataId(u32 map, u32 season, u32 house, u32 coop, u32 barn);
bool IsMapTerrainBoxBlocked(MapTerrainView const & map, Box const & box);

}

#endif // MAP_DATA_HH
