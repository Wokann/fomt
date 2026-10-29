#include "prelude.h"
#pragma implementation "entity_auxiliary_sprites.hh"
#include "game_world.hh"
#include "scene_sprite.hh"
#include "hardware_dma_queue.hh"
#include "entity_auxiliary_sprites.hh"

EntityAuxiliarySprites::~EntityAuxiliarySprites()
{
    // Match native cleanup: release the first index, then destroy all three
    // retained tile entries in reverse member-array order.
    world->ClearSpritePaletteResourceFlag(indices[0]);
}

void EntityAuxiliarySprites::PrepareResources(HardwareDmaQueue & queue)
{
    // Each retained group gets a queued OBJ tile copy, including an empty range.
    for (u32 index = 0; index < ARRAY_COUNT(entries); ++index) {
        IndexedResourceTileRange & range = entries[index].group.tiles;
        IndexedResourceTileUnit const * source = range.data;
        u32 tile_index = entries[index].tiles.GetTileIndex();
        u32 byte_count = range.data ? range.byte_count : 0;
        DmaTransferDescriptor transfer(source,
            reinterpret_cast<void *>(0x06010000u + tile_index * 32), byte_count);
        queue.PushBack(transfer);
    }
    // All three groups use the first group's palette and retained index.
    world->SetSpritePaletteColors(
        reinterpret_cast<u8 const *>(entries[0].group.palettes.data), indices[0], 1);
}

void EntityAuxiliarySprites::Draw(WorldSpriteDrawBuffer * buffer, i32 x, i32 y, u32 kind) const
{
    EntityAuxiliarySpriteEntry const & entry = entries[kind];
    u16 tile_offset = entry.tile_index;
    // Auxiliary groups retain a fixed depth key, independent of actor Y.
    u32 sort_key = 0x8000;
    GameObject * source = world;
    GameScenePaletteIndices const & palette_indices = indices;
    // All four source priorities map to hardware OBJ priority 2.
    SubmitWorldSpriteRecords(buffer, x, y, 0xAA, sort_key, entry.group.sprites,
        source, tile_offset, palette_indices);
}
