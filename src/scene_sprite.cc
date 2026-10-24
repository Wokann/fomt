#include "prelude.h"
#pragma implementation "scene_sprite.hh"
#include "entity_actor.hh"
#include "world_runtime.hh"
#include "hardware_dma_queue.hh"

#include "scene_sprite.hh"

GameSceneSpriteBase::GameSceneSpriteBase(GameObject * source, u32 size_shift,
    i32 const * palette_kinds, u32 palette_count)
    : world(source), tiles(size_shift), tile_index(tiles.GetTileIndex()),
      palettes(palette_count)
{
    i32 const * current = palette_kinds;
    for (u32 index = 0; index < palette_count; ++index)
        palettes[index] = source->vfunc_48(*current++);
}

GameSceneSpriteBase::GameSceneSpriteBase(GameObject * source, u32 size_shift, i32 palette_kind)
    : world(source), tiles(size_shift), tile_index(tiles.GetTileIndex()), palettes(1)
{
    palettes[0] = source->vfunc_48(palette_kind);
}

GameSceneSpriteBase::~GameSceneSpriteBase()
{
    for (u32 index = 0; index < palettes.count; ++index)
        world->ClearSpritePaletteResourceFlag(palettes[index]);
}

void GameSceneSpriteBase::QueueTileUpload(HardwareDmaQueue & queue,
    IndexedResourceDescriptor32Range const & range)
{
    IndexedResourceArchiveDescriptor32 const * source = range.data;
    u32 byte_count = 0;
    if (source != nullptr)
        byte_count = range.byte_count;
    if (byte_count != 0) {
        DmaTransferDescriptor transfer(source,
            reinterpret_cast<void *>(0x06010000u + tiles.GetTileIndex() * 32), byte_count);
        queue.PushBack(transfer);
    }
}

void GameSceneSpriteBase::UploadPalettes(IndexedResourceDescriptor32Range const & range, u8 unk)
{
    u32 byte_count = range.data ? range.byte_count : 0;
    if (byte_count != 0) {
        GameObject * object = world;
        u32 count = byte_count / 32;
        u8 const * current = reinterpret_cast<u8 const *>(range.data);
        for (u32 index = 0; index < count; ++index, current += 32) {
            object->SetSpritePaletteColors(current, palettes[index], unk);
        }
    }
}

GameSceneIndexedSprite::GameSceneIndexedSprite(IndexedResourceProvider * resource,
    u32 index, GameObject * world, u32 size_shift, i32 const * palette_kinds,
    u32 palette_count, bool unk_3D)
    : GameSceneSpriteBase(world, size_shift, palette_kinds, palette_count),
      handle(resource, index, 0x100), unk_3C(1), unk_3D(unk_3D), unk_3E(0)
{
}

GameSceneIndexedSprite::GameSceneIndexedSprite(IndexedResourceProvider * resource,
    u32 index, GameObject * world, u32 size_shift, i32 palette_kind, bool unk_3D)
    : GameSceneSpriteBase(world, size_shift, palette_kind),
      handle(resource, index, 0x100), unk_3C(1), unk_3D(unk_3D), unk_3E(0)
{
}

u32 GameSceneSpriteBase::Submit(WorldSpriteDrawBuffer * buffer, i32 x, i32 y,
    u32 priorities, u32 sort_key, IndexedResourceSpriteRange const & range,
    GameObject * palette_source) const
{
    bool has_handle = tiles.handle != 0;
    if (has_handle) {
        u32 first_tile = tile_index;
        GameScenePaletteIndices const & palette_indices = palettes;
        return SubmitWorldSpriteRecords(buffer, x, y, priorities, sort_key,
            range, palette_source, first_tile, palette_indices);
    }
    return 0;
}

// GameSceneGroupSprite deliberately uses its implicit destructor: only the
// real base owns cleanup. The compiler emits the native flag-forwarding entry
// without the extra vptr store of a user-written empty destructor.
