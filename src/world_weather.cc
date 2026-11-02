#include "world_weather.hh"
#include "game_world.hh"
#include "entity_ui.hh"
#include "scene_sprite.hh"
#include <memory>
#include <stdlib.h>

template <typename T, u32 Capacity>
static inline void AppendWeatherRecord(WorldWeatherRecords<T, Capacity> & records,
    T const & value)
{
    if ((records.count) < Capacity) {
        std::construct(records.End(), value);
        ++records.count;
    }
}

static inline void AppendWeatherPalette(GameScenePaletteIndices & palettes, u32 value)
{
    if (palettes.count < ARRAY_COUNT(palettes.values)) {
        std::construct(palettes.End(), value);
        ++palettes.count;
    }
}

GameSceneWeatherEffect::GameSceneWeatherEffect(GameObject * source,
    IndexedResourceProvider * archive, Kind mode, u32 count)
    : world(source), palette_indices(), kind(mode), unk_E5(1), draw_second_half(0)
{
    IndexedResourceResult entries = archive->Resolve(0);
    u32 resource_count = entries.Count();
    for (u32 index = 0; index < resource_count; ++index) {
        WorldWeatherResource resource(archive->GetGroupData(entries[index].group_index));
        AppendWeatherRecord(resources, resource);
    }
    i32 palette_kind;
    switch (mode) {
    default:
    case SNOW:
        palette_kind = 16;
        break;
    case RAIN:
        palette_kind = 17;
        break;
    }
    u32 palette = source->vfunc_48(palette_kind);
    AppendWeatherPalette(palette_indices, palette);
    u32 frames = 0;
    for (u32 index = 0; index < resource_count; ++index)
        frames += entries[index].metric;
    i32 camera_x = source->GetCameraX();
    i32 camera_y = source->GetCameraY();
    for (u32 index = 0; index < count; ++index) {
        IndexedResourceHandle animation(archive, 0, 0x100);
        u32 phase = frames != 0 ? rand() % frames : 0;
        if (phase != 0) {
            i32 delta = animation.scroll_delta;
            animation.scroll_delta = phase << 8;
            UpdateIndexedResourceHandle(&animation);
            animation.scroll_delta = delta;
        }
        WorldWeatherParticle particle(animation, camera_x, camera_y);
        AppendWeatherRecord(particles, particle);
    }
}

GameSceneWeatherEffect::~GameSceneWeatherEffect()
{
    world->ClearSpritePaletteResourceFlag(palette_indices[0]);
    std::destroy(particles.Begin(), particles.End());
    std::destroy(resources.Begin(), resources.End());
}

WorldWeatherParticle::WorldWeatherParticle(IndexedResourceHandle const & source,
    i32 camera_x, i32 camera_y) : animation(source)
{
    ResetPosition(camera_x, camera_y);
}

void WorldWeatherParticle::ResetPosition(i32 camera_x, i32 camera_y)
{
    x_q16 = (camera_x + rand() % 240) << 16;
    y_q16 = (camera_y + rand() % 160) << 16;
    animation.scroll_delta = rand();
    animation.scroll_delta &= 0x90;
    animation.scroll_delta += 0x60;
}

void GameSceneWeatherEffect::UpdateParticles()
{
    WorldWeatherMotion const * motion = gWorldWeatherParticleMotion[kind];
    u32 group = 0;
    u32 group_particles = 0;
    u32 group_size;
    switch (kind) {
    default:
    case SNOW:
        group_size = 2;
        break;
    case RAIN:
        group_size = 3;
        break;
    }
    i32 camera_x = world->GetCameraX();
    i32 camera_y = world->GetCameraY();
    u32 count = particles.count;
    for (u32 index = 0; index < count; ++index) {
        WorldWeatherParticle & particle = particles[index];
        // Restart each particle after its animation wraps.
        if (UpdateIndexedResourceHandle(&particle.animation).flags.wrapped)
            particle.ResetPosition(camera_x, camera_y);
        ++group_particles;
        if (group_particles >= group_size) {
            ++group;
            if (group > 1)
                group = 0;
            group_particles = 0;
        }
        particle.x_q16 += motion[group].x_q16;
        particle.y_q16 += motion[group].y_q16;
    }
}

void GameSceneWeatherEffect::Draw(WorldSpriteDrawBuffer * buffer)
{
    // Alternate particle ranges on successive draw calls.
    u32 count = particles.count;
    u32 half = count / 2;
    u32 first;
    u32 end;
    switch (draw_second_half) {
    default:
    case 0:
        first = 0;
        end = half;
        draw_second_half = 1;
        break;
    case 1:
        first = half;
        end = count;
        draw_second_half = 0;
        break;
    }
    i32 camera_x = world->GetCameraX();
    i32 camera_y = world->GetCameraY();
    for (u32 index = first; index < end; ++index) {
        WorldWeatherRecords<WorldWeatherResource, 5> const & groups = resources;
        WorldWeatherParticle const & particle = particles[index];
        u32 group = particle.animation.resolved_resource[
            particle.animation.current_entry_index].group_index;
        // Wrap camera-relative pixels to the native [-8, 247] range.
        i32 x = (((particle.x_q16 >> 16) - camera_x + 8) & 255) - 8;
        i32 y = (((particle.y_q16 >> 16) - camera_y + 8) & 255) - 8;
        WorldWeatherResource const & resource = groups[group];
        u32 tile_index = resource.tiles.GetTileIndex();
        u32 sort_key = 0;
        GameObject * source = world;
        GameScenePaletteIndices const & palettes = palette_indices;
        // All source priorities use hardware OBJ priority 1.
        SubmitWorldSpriteRecords(buffer, x, y, 0x55, sort_key, resource.group.sprites,
            source, tile_index, palettes);
    }
}

EC void ClearWorldWeatherEffect(GameSceneWorld & world)
{
    world.weather_effect = nullptr;
}
