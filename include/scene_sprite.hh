#ifndef SCENE_SPRITE_HH
#define SCENE_SPRITE_HH

#include "prelude.h"
#include "resource_handle.hh"
#include "world_runtime.hh"

#pragma interface "scene_sprite.hh"

struct HardwareDmaQueue;
struct WorldSpriteDrawBuffer;

// Native base owns OBJ tiles and the palette slots returned by GameObject.
struct GameSceneSpriteBase {
    GameObject * world;
    HardwareStateEntry tiles;
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

struct GameSceneIndexedSprite : GameSceneSpriteBase {
    GameSceneIndexedSprite(IndexedResourceProvider * resource, u32 index,
        GameObject * world, u32 size_shift, i32 const * palette_kinds,
        u32 palette_count, bool unk_3D);
    GameSceneIndexedSprite(IndexedResourceProvider * resource, u32 index,
        GameObject * world, u32 size_shift, i32 palette_kind, bool unk_3D);

    IndexedResourceHandle handle;
    u8 unk_3C;
    u8 unk_3D;
    u8 unk_3E;
    u8 unk_3F;

    IndexedResourceUpdateResult UpdateAnimation()
    {
        if (unk_3F == 0) {
            IndexedResourceUpdateResult result = UpdateIndexedResourceHandle(&handle);
            if (result.flags.group_changed)
                unk_3C = 1;
            return result;
        }
        unk_3F = 0;
        IndexedResourceUpdateResult initial;
        initial.value = INDEXED_RESOURCE_GROUP_CHANGED;
        return initial;
    }
};

typedef char GameSceneSpriteBaseSizeCheck[sizeof(GameSceneSpriteBase) == 0x28 ? 1 : -1];
typedef char GameSceneSpriteBaseTilesCheck[offsetof(GameSceneSpriteBase, tiles) == 4 ? 1 : -1];
typedef char GameSceneSpriteBasePaletteCountCheck[offsetof(GameSceneSpriteBase, palettes.count) == 0x10 ? 1 : -1];
typedef char GameSceneSpriteBasePaletteIndicesCheck[offsetof(GameSceneSpriteBase, palettes.values) == 0x14 ? 1 : -1];
typedef char GameSceneIndexedSpriteSizeCheck[sizeof(GameSceneIndexedSprite) == 0x40 ? 1 : -1];
typedef char GameSceneIndexedSpriteHandleCheck[offsetof(GameSceneIndexedSprite, handle) == 0x28 ? 1 : -1];
typedef char GameSceneIndexedSpriteFlagsCheck[offsetof(GameSceneIndexedSprite, unk_3C) == 0x3C ? 1 : -1];

// Both world event icons and entity-owned graphics embed this same group
// sprite. A group is resolved once; the indexed sprite instead keeps a handle.
// The byte at +0x48 is initialized by native factories, but its full meaning
// is not yet established. Preserve that uncertainty rather than naming a flag.
struct GameSceneGroupSprite : GameSceneSpriteBase {
    GameSceneGroupSprite(IndexedResourceProvider * resource, u32 index,
        GameObject * world, u32 size_shift, i32 palette_kind)
        : GameSceneSpriteBase(world, size_shift, palette_kind),
          group(ResolveIndexedResourceGroup(resource, index)),
          unk_48(1)
    {
    }

    IndexedResourceGroupResult group;
    u8 unk_48;

    // No default construction path has been recovered.
private:
    GameSceneGroupSprite();
};

typedef char GameSceneGroupSpriteSizeCheck[sizeof(GameSceneGroupSprite) == 0x4C ? 1 : -1];
typedef char GameSceneGroupSpriteGroupCheck[offsetof(GameSceneGroupSprite, group) == 0x28 ? 1 : -1];
typedef char GameSceneGroupSpriteByteCheck[offsetof(GameSceneGroupSprite, unk_48) == 0x48 ? 1 : -1];

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
