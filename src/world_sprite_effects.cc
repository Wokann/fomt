#include "world_sprite_effects.hh"
#include "gbaio.h"
#include "scene_sprite.hh"
#include "hardware_dma_queue.hh"

WorldSpriteEffects::~WorldSpriteEffects()
{
    delete state;
}

WorldSpriteEffectFrames & WorldSpriteEffectFrames::operator=(WorldSpriteEffectFrames const & other)
{
    tiles_allocated = other.tiles_allocated;
    tiles_upload_pending = other.tiles_upload_pending;
    {
        IndexedResourceGroupResult * target = groups;
        u32 count = ARRAY_COUNT(groups) - 1;
        IndexedResourceGroupResult const * source = other.groups;
        do {
            *target = *source;
            ++target;
            ++source;
        } while (count-- != 0);
    }
    {
        HardwareStateEntry * target = tiles;
        u32 count = ARRAY_COUNT(tiles) - 1;
        HardwareStateEntry const * source = other.tiles;
        do {
            *target = *source;
            ++target;
            ++source;
        } while (count-- != 0);
    }
    return *this;
}

void WorldSpriteEffects::Update()
{
    state->Update();
}

inline void WorldSpriteEffectFrames::PrepareResources(HardwareDmaQueue & queue)
{
    for (u32 index = 0; index < ARRAY_COUNT(groups); ++index) {
        IndexedResourceTileUnit const * source = groups[index].tiles.GetData();
        u32 tile_index = tiles[index].GetTileIndex();
        u32 byte_count = groups[index].tiles.GetByteCount();
        DmaTransferDescriptor transfer(source,
            reinterpret_cast<void *>(OBJ_VRAM0 + tile_index * TILE_SIZE_4BPP), byte_count);
        queue.PushBack(transfer);
    }
    tiles_upload_pending = false;
}

inline void WorldSpriteEffectsState::Draw(WorldSpriteDrawBuffer * buffer, HardwareDmaQueue & queue)
{
    WorldSpriteEffectsState * data = this;
    GameObject * world = data->world;
    if (data->tiles_upload_pending) {
        for (u32 kind = 0; kind < ARRAY_COUNT(data->frames); ++kind) {
            WorldSpriteEffectFrames & frame = data->frames[kind];
            if (frame.tiles_allocated && frame.tiles_upload_pending) {
                frame.PrepareResources(queue);
            }
        }
        data->tiles_upload_pending = false;
    }
    if (data->palette_upload_pending) {
        world->SetSpritePaletteColors(
            reinterpret_cast<u8 const *>(data->frames[data->palette_source_kind].groups[0].palettes.GetData()),
            data->palettes[0], 1);
        data->palette_upload_pending = false;
    }
    i32 camera_x = world->GetCameraX();
    i32 camera_y = world->GetCameraY();
    u32 index = 0;
    GameScenePaletteIndices const & palette_indices = data->palettes;
    for (; index < ARRAY_COUNT(data->instances); ++index) {
        WorldSpriteEffectInstance & instance = data->instances[index];
        if (instance.active) {
            WorldSpriteEffectFrames & frame = data->frames[instance.kind];
            u32 frame_index = 0;
            if (instance.lifetime <= 6)
                frame_index = 1;
            i32 world_y = instance.y;
            u32 sort_key = 0x8000 - world_y;
            i32 x = instance.x - camera_x;
            i32 y = world_y - camera_y;
            IndexedResourceGroupResult & group = frame.groups[frame_index];
            // Preserve agbcp's add order using the array's real byte extent.
            HardwareStateEntry const * tile = reinterpret_cast<HardwareStateEntry const *>(
                reinterpret_cast<uptr>(frame.tiles) + frame_index * sizeof(HardwareStateEntry));
            u32 tile_index = tile->GetTileIndex();
            SubmitWorldSpriteRecords(buffer, x, y, 0xAA, sort_key,
                group.sprites, world, tile_index, palette_indices);
        }
    }
}

void WorldSpriteEffects::Draw(WorldSpriteDrawBuffer * buffer, HardwareDmaQueue & queue)
{
    state->Draw(buffer, queue);
}
