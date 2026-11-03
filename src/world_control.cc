#include "world_control.hh"
#include "game_world.hh"
#include "game_state.hh"

EC bool IsWorldTimePaused(GameSceneWorld const & world)
{
    if (world.updates_suspended == 0
        && GetMapData(world.data.map.value->map_data_id)->flags == 0)
        return false;
    return true;
}

EC void SuspendWorldUpdates(GameSceneWorld & world)
{
    world.updates_suspended = 1;
    if (world.save->scripted_npc_control) {
        // The original control path still notifies every actor here.
        AEntity ** it = world.data.entities;
        AEntity ** end = world.data.entities + ARRAY_COUNT(world.data.entities);
        for (; it != end; ++it) {
            if (*it != nullptr)
                (*it)->SuspendNormalUpdates();
        }
    } else {
        AEntity ** it = world.data.entities;
        AEntity ** end = world.data.entities + ARRAY_COUNT(world.data.entities);
        for (; it != end; ++it) {
            if (*it != nullptr)
                (*it)->SuspendNormalUpdates();
        }
    }
}

EC void ResumeWorldUpdates(GameSceneWorld & world)
{
    world.updates_suspended = 0;
    if (world.save->scripted_npc_control) {
        world.data.entities[0]->ResumeNormalUpdates();
    } else {
        AEntity ** it = world.data.entities;
        AEntity ** end = world.data.entities + ARRAY_COUNT(world.data.entities);
        for (; it != end; ++it) {
            if (*it != nullptr)
                (*it)->ResumeNormalUpdates();
        }
    }
}

EC void ClearWorldWeatherEffect(GameSceneWorld & world)
{
    world.weather_effect = nullptr;
}
