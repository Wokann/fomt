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



#pragma interface "scene_sprite.hh"

struct HardwareDmaQueue;
struct WorldSpriteDrawBuffer;

struct GameSceneSpriteDrawContext {
    HardwareDmaQueue * queue;
    WorldSpriteDrawBuffer * buffer;

    GameSceneSpriteDrawContext(HardwareDmaQueue * queue, WorldSpriteDrawBuffer * buffer)
        : queue(queue), buffer(buffer) {}
};

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

static inline u32 SubmitGameSceneSprite(GameSceneSpriteBase const * sprite,
    WorldSpriteDrawBuffer * buffer, i32 x, i32 y, u32 priorities, u32 sort_key,
    IndexedResourceSpriteRange const & range, GameObject * palette_source)
{
    bool has_handle = sprite->tiles.HasHandle();
    if (has_handle) {
        u32 first_tile = sprite->tile_index;
        GameScenePaletteIndices const & palette_indices = sprite->palettes;
        return SubmitWorldSpriteRecords(buffer, x, y, priorities, sort_key,
            range, palette_source, first_tile, palette_indices);
    }
    return 0;
}


#endif // SCENE_SPRITE_HH
