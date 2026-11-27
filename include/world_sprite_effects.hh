#ifndef WORLD_SPRITE_EFFECTS_HH
#define WORLD_SPRITE_EFFECTS_HH

// World construction owns this transient sprite pool. Native setup initializes
// ten frame-resource records and sixteen live instances. Its constructor stays
// imported until that whole body matches; unknown state remains unnamed.
#include "unknown_types.hh"
#include "resource_archive.hh"
#include "obj_tile_collection.hh"
#include "world_runtime.hh"

#pragma interface "world_sprite_effects.hh"

struct WorldSpriteDrawBuffer;
struct HardwareDmaQueue;

struct WorldSpriteEffectFrames {
    // Allocated handles are released when every active instance expires.
    bool tiles_allocated;
    // Drawing clears this after uploading the cached groups.
    bool tiles_upload_pending;
    IndexedResourceGroupResult groups[2];
    ObjTileCollectionEntry tiles[2];

    void PrepareResources(HardwareDmaQueue & queue);

    void ReleaseTiles()
    {
        for (u32 index = 0; index < ARRAY_COUNT(tiles); ++index)
            tiles[index].Clear();
        tiles_allocated = false;
        tiles_upload_pending = false;
    }

    WorldSpriteEffectFrames & operator=(WorldSpriteEffectFrames const & other);
};


struct WorldSpriteEffectInstance {
    i16 x;
    i16 y;
    bool active;
    u8 lifetime;
    u8 kind;
    u8 unk_07;
};

struct WorldSpriteEffectsState {
    GameObject * world;
    // Farm/forest/mountain-mid winter data select the snow resource variant.
    bool use_snow_resources;
    bool tiles_upload_pending;
    bool palette_upload_pending;
    WorldSpriteEffectFrames frames[10];
    GameScenePaletteIndices palettes;
    // Activation selects which cached frame supplies the next palette upload.
    u8 palette_source_kind;
    WorldSpriteEffectInstance instances[16];

    // Release cached tiles only when all instances active at entry expire now.
    // No active instances is deliberately a no-op, matching the native update.
    void Update()
    {
        u32 active_count = 0;
        u32 expired_count = 0;
        for (u32 index = 0; index < ARRAY_COUNT(instances); ++index) {
            WorldSpriteEffectInstance & instance = instances[index];
            if (instance.active) {
                ++active_count;
                if (instance.lifetime > 1)
                    --instance.lifetime;
                else {
                    instance.active = false;
                    ++expired_count;
                }
            }
        }
        if (active_count != 0 && expired_count == active_count) {
            for (u32 kind = 0; kind < ARRAY_COUNT(frames); ++kind) {
                WorldSpriteEffectFrames & frame = frames[kind];
                if (frame.tiles_allocated) {
                    frame.ReleaseTiles();
                }
            }
        }
    }

    void Draw(WorldSpriteDrawBuffer * buffer, HardwareDmaQueue & queue);

    ~WorldSpriteEffectsState()
    {
        world->ClearSpritePaletteResourceFlag(palettes[0]);
    }
};

struct WorldSpriteEffects {
    WorldSpriteEffectsState * state;
    WorldSpriteEffects(GameObject * world, i32 map_data);
    ~WorldSpriteEffects();
    void Update();
    // Drawing shares the world priority buffer and DMA queue.
    void Draw(WorldSpriteDrawBuffer * buffer, HardwareDmaQueue & queue);
};



EXTERN_C
void SpawnWorldSpriteEffect(WorldSpriteEffects * effects, i32 x, i32 y, u32 kind);
EXTERN_C_END


#endif // WORLD_SPRITE_EFFECTS_HH
