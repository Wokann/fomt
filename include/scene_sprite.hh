#ifndef SCENE_SPRITE_HH
#define SCENE_SPRITE_HH

#include "prelude.h"
#include "resource_handle.hh"
#include "obj_tile_collection_storage.hh"
#include <string.h>

struct GameObject;

struct GameScenePaletteIndices {
private:
    void Initialize(u32 input_count, u8 const & initial)
    {
        count = 0;
        if (input_count <= ARRAY_COUNT(values)) {
            memset(values, initial, input_count);
            count = input_count;
        }
    }

public:
    GameScenePaletteIndices() : count(0) {}

    GameScenePaletteIndices(GameScenePaletteIndices const & other) : count(0)
    {
        u32 input_count = other.count;
        u8 const * first = other.values;
        u8 * destination = values;
        u8 const * last = first + input_count;
        if (last != first)
            memmove(destination, first, last - first);
        count = input_count;
    }

    explicit GameScenePaletteIndices(u32 input_count)
    {
        Initialize(input_count, 0);
    }

    u32 count;
    union {
        u8 values[16];
        u32 storage[4];
    };

    u8 * End() { return &reinterpret_cast<u8 *>(storage)[count]; }

    u8 & operator[](u32 index) { return values[index]; }
};

typedef char GameScenePaletteIndicesSizeCheck[sizeof(GameScenePaletteIndices) == 20 ? 1 : -1];
typedef char GameScenePaletteIndexValuesCheck[offsetof(GameScenePaletteIndices, values) == 4 ? 1 : -1];


#pragma interface "scene_sprite.hh"

struct HardwareDmaQueue;
struct WorldSpriteDrawBuffer;

// Native base owns OBJ tiles and the palette slots returned by GameObject.
struct GameSceneSpriteBase {
    GameObject * world;
    ObjTileCollectionEntry tiles;
    u16 tile_index;
    GameScenePaletteIndices palettes;

    GameSceneSpriteBase(GameObject * world, u32 size_shift,
        i32 const * palette_kinds, u32 palette_count);
    GameSceneSpriteBase(GameObject * world, u32 size_shift, i32 palette_kind);
    GameSceneSpriteBase(GameSceneSpriteBase const & other);
    virtual ~GameSceneSpriteBase();

    void QueueTileUpload(HardwareDmaQueue & queue, IndexedResourceTileRange const & range);
    void UploadPalettes(IndexedResourcePaletteRange const & range, u8 unk);

    u32 Submit(WorldSpriteDrawBuffer * buffer, i32 x, i32 y, u32 priorities,
        u32 sort_key, IndexedResourceSpriteRange const & range, GameObject * palette_source) const;
};

typedef char GameSceneSpriteBaseSizeCheck[sizeof(GameSceneSpriteBase) == 0x28 ? 1 : -1];
typedef char GameSceneSpriteBaseTilesCheck[offsetof(GameSceneSpriteBase, tiles) == 4 ? 1 : -1];
typedef char GameSceneSpriteBasePaletteCountCheck[offsetof(GameSceneSpriteBase, palettes.count) == 0x10 ? 1 : -1];
typedef char GameSceneSpriteBasePaletteIndicesCheck[offsetof(GameSceneSpriteBase, palettes.values) == 0x14 ? 1 : -1];
EXTERN_C

// ARM entry in IWRAM, distinct from the direct hardware OAM submission path.
// priorities packs a two-bit destination priority for each source priority.
// sort_key occupies the high bits of each queued key; the low seven are the
// sprite index. The return counts visible records even when the queue is full.
u32 SubmitWorldSpriteRecords(WorldSpriteDrawBuffer * buffer, i32 x, i32 y,
    u32 priorities, u32 sort_key, IndexedResourceSpriteRange const & range,
    GameObject * palette_source, u32 tile_offset,
    GameScenePaletteIndices const & palette_map) __attribute__((long_call));

EXTERN_C_END


#endif // SCENE_SPRITE_HH
