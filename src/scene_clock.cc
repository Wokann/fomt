#include "prelude.h"
#include "scene.hh"
#include "map_clock_status.hh"
#include "new_game_menu.hh"
#include "world_map.hh"

#pragma implementation "scene_clock.hh"
#include "scene_clock.hh"
#include "game_scene.hh"


void GameScene::OpenClock()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CLOCK);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ClockTransition(current->save, continuation);
    current->script_state = 0x18;
}

void GameScene::PrepareClockMenuTransition()
{
    state->game_object.value->PrepareClockMenuTransition();
}

void GameScene::RestoreAfterClockMenu()
{
    state->game_object.value->RestoreAfterClockMenu();
}

SceneOwner ClockTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(new NewGameMenuScene(save, next));
}
