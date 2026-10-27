#include "world_weather.hh"
#include "game_world.hh"
#include "entity_ui.hh"

WorldWeatherParticle::WorldWeatherParticle(IndexedResourceHandle const & source,
    i32 camera_x, i32 camera_y) : animation(source)
{
    ResetPosition(camera_x, camera_y);
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
        // Move wrapped flag bit 2 to the sign bit, as other native consumers do.
        if (static_cast<i32>(UpdateIndexedResourceHandle(&particle.animation) << 29) < 0)
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

EC void ClearWorldWeatherEffect(GameSceneWorldPrefix & world)
{
    world.weather_effect = nullptr;
}
