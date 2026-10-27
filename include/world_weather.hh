#ifndef WORLD_WEATHER_HH
#define WORLD_WEATHER_HH

#include "prelude.h"
#include "resource_handle.hh"
#include "hardware_state_clear.hh"
#include "world_runtime.hh"

struct GameObject;
struct GameSceneWorldPrefix;

struct WorldWeatherMotion {
    i32 x_q16;
    i32 y_q16;
};

// Native construction/destruction manages only the counted records. Capacity
// slots are aligned storage, so declaring this layout does not construct them.
template <typename T, u32 Capacity>
struct WorldWeatherRecords {
    WorldWeatherRecords() : count(0) {}
    T * Begin() { return reinterpret_cast<T *>(storage); }
    T * End() { return &reinterpret_cast<T *>(storage)[count]; }
    T & operator[](u32 index) { return reinterpret_cast<T *>(storage)[index]; }

    u32 count;
    u32 storage[(Capacity * sizeof(T) + 3) / 4];
};

struct WorldWeatherResource {
    WorldWeatherResource(IndexedResourceGroupResult const & source)
        : group(source), tiles(0) {}
    IndexedResourceGroupResult group;
    HardwareStateEntry tiles;
};

struct WorldWeatherParticle {
    WorldWeatherParticle(IndexedResourceHandle const & animation, i32 camera_x, i32 camera_y);
    void ResetPosition(i32 camera_x, i32 camera_y);

    IndexedResourceHandle animation;
    i32 x_q16;
    i32 y_q16;
};

// Mode numbering belongs to this renderer, not to the saved MaryWeather enum.
// The native constructor populates only the counted resource/particle records.
struct GameSceneWeatherEffect {
    enum Kind {
        SNOW = 0,
        RAIN = 1,
    };

    GameSceneWeatherEffect(GameObject * world, IndexedResourceProvider * archive,
        Kind kind, u32 particle_count);
    ~GameSceneWeatherEffect();
    void UpdateParticles();

    GameObject * world;
    WorldWeatherRecords<WorldWeatherResource, 5> resources;
    GameScenePaletteIndices palette_indices;
    u8 kind;
    u8 unk_E5;
    u8 draw_second_half;
    WorldWeatherRecords<WorldWeatherParticle, 32> particles;
};

typedef char WorldWeatherResourceSizeCheck[sizeof(WorldWeatherResource) == 40 ? 1 : -1];
typedef char WorldWeatherResourceTilesCheck[offsetof(WorldWeatherResource, tiles) == 32 ? 1 : -1];
typedef char WorldWeatherParticleSizeCheck[sizeof(WorldWeatherParticle) == 28 ? 1 : -1];
typedef char WorldWeatherParticlePositionCheck[offsetof(WorldWeatherParticle, x_q16) == 20 ? 1 : -1];
typedef char GameSceneWeatherEffectResourcesCheck[offsetof(GameSceneWeatherEffect, resources) == 4 ? 1 : -1];
typedef char GameSceneWeatherEffectPaletteCountCheck[offsetof(GameSceneWeatherEffect, palette_indices) == 0xD0 ? 1 : -1];
typedef char GameSceneWeatherEffectKindCheck[offsetof(GameSceneWeatherEffect, kind) == 0xE4 ? 1 : -1];
typedef char GameSceneWeatherEffectParticlesCheck[offsetof(GameSceneWeatherEffect, particles) == 0xE8 ? 1 : -1];
typedef char GameSceneWeatherEffectSizeCheck[sizeof(GameSceneWeatherEffect) == 0x46C ? 1 : -1];

EXTERN_C
void ClearWorldWeatherEffect(GameSceneWorldPrefix & world);
EXTERN_C_END

#endif
