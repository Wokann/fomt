#include "scene_clock.hh"
#include "game_scene.hh"

void GameScene::PrepareClockMenuTransition()
{
    state->game_object.value->PrepareClockMenuTransition();
}

void GameScene::RestoreAfterClockMenu()
{
    state->game_object.value->RestoreAfterClockMenu();
}
