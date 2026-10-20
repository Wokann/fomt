#include "world_control.hh"
#include "game_world.hh"
#include "game_state.hh"

EC bool IsWorldTimePaused(GameSceneWorldPrefix const & world)
{
    if (world.updates_suspended == 0
        && GetMapData(world.data.map.value->map_data_id)->flags == 0)
        return false;
    return true;
}

EC void SuspendWorldUpdates(GameSceneWorldPrefix & world)
{
    world.updates_suspended = 1;
    if (world.save->scripted_npc_control) {
        // The original control path still notifies every actor here.
        AEntity ** it = world.data.entities;
        AEntity ** end = world.data.entities + ARRAY_COUNT(world.data.entities);
        for (; it != end; ++it) {
            if (*it != nullptr)
                (*it)->vfunc_20();
        }
    } else {
        AEntity ** it = world.data.entities;
        AEntity ** end = world.data.entities + ARRAY_COUNT(world.data.entities);
        for (; it != end; ++it) {
            if (*it != nullptr)
                (*it)->vfunc_20();
        }
    }
}

EC void ResumeWorldUpdates(GameSceneWorldPrefix & world)
{
    world.updates_suspended = 0;
    if (world.save->scripted_npc_control) {
        world.data.entities[0]->vfunc_24();
    } else {
        AEntity ** it = world.data.entities;
        AEntity ** end = world.data.entities + ARRAY_COUNT(world.data.entities);
        for (; it != end; ++it) {
            if (*it != nullptr)
                (*it)->vfunc_24();
        }
    }
}
