#include "prelude.h"
#include "entity_actor.hh"
#include "world_runtime.hh"
#include "hardware_state_accessors.hh"
#include "new.hh"
#include <memory>
#include <algorithm>

#pragma implementation "scene_sprite.hh"
#include "scene_sprite.hh"

// These queue operations are instantiated by sprite uploads here. Keep their
// standard allocation headers out of the widely included hardware layout.
inline void * HardwareDmaQueue::AllocateDmaBytes(u32 bytes)
{
    void * result = malloc(bytes);
    if (result == nullptr)
        result = RetryMemoryAllocation(bytes);
    return result;
}

inline DmaTransferDescriptor * HardwareDmaQueue::AllocateDmaDescriptors(u32 count)
{
    return count != 0
        ? static_cast<DmaTransferDescriptor *>(AllocateDmaBytes(count * sizeof(DmaTransferDescriptor)))
        : nullptr;
}

inline DmaTransferDescriptor * HardwareDmaQueue::CopyDmaDescriptors(DmaTransferDescriptor const * first,
    DmaTransferDescriptor const * last, DmaTransferDescriptor * result)
{
    DmaTransferDescriptor * current = result;
    for (; first != last; ++first, ++current)
        std::construct(current, *first);
    return current;
}

inline DmaTransferDescriptor * HardwareDmaQueue::FillDmaDescriptors(DmaTransferDescriptor * first,
    u32 count, DmaTransferDescriptor const & value)
{
    DmaTransferDescriptor * current = first;
    for (; count != 0; --count, ++current)
        std::construct(current, value);
    return current;
}

inline void HardwareDmaQueue::Grow(DmaTransferDescriptor * old_end, u32 count,
    DmaTransferDescriptor const & value)
{
    u32 old_size = old_end - first;
    u32 new_size = old_size + std::max(old_size, count);
    DmaTransferDescriptor * replacement = AllocateDmaDescriptors(new_size);
    DmaTransferDescriptor * end = replacement;
    end = CopyDmaDescriptors(first, old_end, end);
    if (count == 1) {
        std::construct(end, value);
        ++end;
    } else {
        end = FillDmaDescriptors(end, count, value);
    }
    std::destroy(first, last);
    if (first != nullptr)
        free(first);
    DmaTransferDescriptor * capacity_end = replacement + new_size;
    first = replacement;
    last = end;
    allocation.end = capacity_end;
}

inline void HardwareDmaQueue::PushBack(DmaTransferDescriptor const & value)
{
    if (last != allocation.end) {
        std::construct(last, value);
        ++last;
    } else {
        Grow(last, 1, value);
    }
}

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
