#ifndef WORLD_WEATHER_HH
#define WORLD_WEATHER_HH

#include "prelude.h"
#include "resource_handle.hh"
#include "obj_tile_collection.hh"
#include "world_runtime.hh"

struct GameObject;
struct HardwareDmaQueue;
struct WorldSpriteDrawBuffer;
struct GameSceneWorld;

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
    T const & operator[](u32 index) const { return reinterpret_cast<T const *>(storage)[index]; }

    u32 count;
    u32 storage[(Capacity * sizeof(T) + 3) / 4];
};

struct WorldWeatherResource {
    WorldWeatherResource(IndexedResourceGroupResult const & source)
        : group(source), tiles(0) {}
    IndexedResourceGroupResult group;
    ObjTileCollectionEntry tiles;
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
    void PrepareResources(HardwareDmaQueue & queue);
    void UpdateParticles();
    void Draw(WorldSpriteDrawBuffer * buffer);

    GameObject * world;
    WorldWeatherRecords<WorldWeatherResource, 5> resources;
    GameScenePaletteIndices palette_indices;
    u8 kind;
    u8 resources_need_upload;
    u8 draw_second_half;
    WorldWeatherRecords<WorldWeatherParticle, 32> particles;
};



extern "C" WorldWeatherMotion const gWorldWeatherParticleMotion[2][2];

#endif
