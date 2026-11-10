#ifndef GAME_SCENE_CONTROLLER_LIFETIMES_HH
#define GAME_SCENE_CONTROLLER_LIFETIMES_HH

#include "game_state.hh"
#include "game_scene_controller.hh"

#pragma interface "game_scene_controller_lifetimes.hh"

// Real construction needs the complete saved-image type and member operations.
inline GameSceneScriptController::GameSceneScriptController(char const * farm_name,
    char const * player_name, GameDate birthday, char const * dog_name)
    : save(new GameStateSaveImage(farm_name, player_name, birthday, dog_name)),
      script_engine(save.get()), unk_364(1), unk_368(0xAB)
{
    gCurrentGameSceneScriptController = this;
}

inline GameSceneScriptController::GameSceneScriptController(GameStateSaveImageOwner input)
    : save(input.release()), script_engine(save.get()), unk_364(0)
{
    gCurrentGameSceneScriptController = this;
}

#endif // GAME_SCENE_CONTROLLER_LIFETIMES_HH
