#include "game_scene_actions.hh"
#include "game_scene_controller.hh"
#include "game_scene_state.hh"



extern "C" void StartSceneEventScript(GameSceneState * state, i32 script_id,
    i32 context)
{
    gCurrentGameSceneScriptController->script_engine.LoadById(script_id, context);

    SuspendSceneWorldForScript(state);
}

extern "C" void ChangeSceneMap(GameSceneState * state, u32 map, i32 x, i32 y)
{
    state->game_object.value->ChangeMap(Location(map, x, y), true);
    RefreshSceneNpcSchedules(state);
}

extern "C" void RelocateEntityInSceneMap(GameSceneState * state, i32 entity_id,
    i32 x, i32 y, u32 facing)
{
    u32 map = state->game_object.value->vfunc_14();
    RelocateEntityToMap(state, entity_id, map, x, y, facing);
}
