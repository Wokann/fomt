#ifndef WORLD_SPRITE_EFFECTS_HH
#define WORLD_SPRITE_EFFECTS_HH

// World construction owns this transient sprite pool. Native setup initializes
// ten frame-resource records and sixteen live instances. Its constructor stays
// imported until that whole body matches; unknown state remains unnamed.
#include "unknown_types.hh"
#include "resource_archive.hh"
#include "hardware_state_clear.hh"
#include "world_runtime.hh"

struct WorldSpriteEffectFrames {
    // Allocated handles are released when every active instance expires.
    bool tiles_allocated;
    // Drawing clears this after uploading the cached groups.
    bool tiles_upload_pending;
    IndexedResourceGroupResult groups[2];
    HardwareStateEntry tiles[2];

    void ReleaseTiles()
    {
        for (u32 index = 0; index < ARRAY_COUNT(tiles); ++index)
            tiles[index].Clear();
        tiles_allocated = false;
        tiles_upload_pending = false;
    }

    WorldSpriteEffectFrames & operator=(WorldSpriteEffectFrames const & other);
};

typedef char WorldSpriteEffectFramesSizeCheck[sizeof(WorldSpriteEffectFrames) == 0x54 ? 1 : -1];
typedef char WorldSpriteEffectFramesGroupsCheck[offsetof(WorldSpriteEffectFrames, groups) == 4 ? 1 : -1];
typedef char WorldSpriteEffectFramesTilesCheck[offsetof(WorldSpriteEffectFrames, tiles) == 0x44 ? 1 : -1];

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
};

typedef char WorldSpriteEffectsStateSizeCheck[sizeof(WorldSpriteEffectsState) == 0x3E8 ? 1 : -1];
typedef char WorldSpriteEffectInstanceSizeCheck[sizeof(WorldSpriteEffectInstance) == 8 ? 1 : -1];
typedef char WorldSpriteEffectsStateFramesCheck[offsetof(WorldSpriteEffectsState, frames) == 8 ? 1 : -1];
typedef char WorldSpriteEffectsStatePaletteCheck[offsetof(WorldSpriteEffectsState, palettes) == 0x350 ? 1 : -1];
typedef char WorldSpriteEffectsStatePaletteSourceCheck[offsetof(WorldSpriteEffectsState, palette_source_kind) == 0x364 ? 1 : -1];
typedef char WorldSpriteEffectsStatePaletteSourceSizeCheck[sizeof(((WorldSpriteEffectsState *)0)->palette_source_kind) == 1 ? 1 : -1];

typedef char WorldSpriteEffectsStateInstancesCheck[offsetof(WorldSpriteEffectsState, instances) == 0x368 ? 1 : -1];
typedef char WorldSpriteEffectsSizeCheck[sizeof(WorldSpriteEffects) == 4 ? 1 : -1];

#endif // WORLD_SPRITE_EFFECTS_HH
