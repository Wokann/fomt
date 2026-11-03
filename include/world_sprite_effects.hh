#ifndef WORLD_SPRITE_EFFECTS_HH
#define WORLD_SPRITE_EFFECTS_HH

// World construction owns this transient sprite pool. Native setup initializes
// ten frame-resource records and sixteen live instances. Its constructor stays
// imported until that whole body matches; unknown state remains unnamed.
#include "unknown_types.hh"
#include "resource_archive.hh"
#include "hardware_state_clear.hh"

struct WorldSpriteEffectFrames {
    // Allocated handles are released when every active instance expires.
    bool tiles_allocated;
    // Drawing clears this after uploading the cached groups.
    bool tiles_upload_pending;
    IndexedResourceGroupResult groups[2];
    HardwareStateEntry tiles[2];

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

struct WorldSpriteEffectPaletteList {
    u32 count;
    u8 indices[16];
    u32 unk_14;
    u8 & operator[](u32 index) { return indices[index]; }
};

struct WorldSpriteEffectsState {
    GameObject * world;
    // Farm/forest/mountain-mid winter data select the snow resource variant.
    bool use_snow_resources;
    bool tiles_upload_pending;
    bool palette_upload_pending;
    WorldSpriteEffectFrames frames[10];
    WorldSpriteEffectPaletteList palettes;
    WorldSpriteEffectInstance instances[16];

    ~WorldSpriteEffectsState()
    {
        world->ClearSpritePaletteResourceFlag(palettes[0]);
    }
};

struct WorldSpriteEffects {
    WorldSpriteEffectsState * state;
    WorldSpriteEffects(GameObject * world, i32 map_data);
    ~WorldSpriteEffects();
};

typedef char WorldSpriteEffectsStateSizeCheck[sizeof(WorldSpriteEffectsState) == 0x3E8 ? 1 : -1];
typedef char WorldSpriteEffectInstanceSizeCheck[sizeof(WorldSpriteEffectInstance) == 8 ? 1 : -1];
typedef char WorldSpriteEffectsStateFramesCheck[offsetof(WorldSpriteEffectsState, frames) == 8 ? 1 : -1];
typedef char WorldSpriteEffectsStatePaletteCheck[offsetof(WorldSpriteEffectsState, palettes) == 0x350 ? 1 : -1];
typedef char WorldSpriteEffectsStateInstancesCheck[offsetof(WorldSpriteEffectsState, instances) == 0x368 ? 1 : -1];
typedef char WorldSpriteEffectsSizeCheck[sizeof(WorldSpriteEffects) == 4 ? 1 : -1];

#endif // WORLD_SPRITE_EFFECTS_HH
