#include "game_scene.hh"
#pragma implementation "scene_chicken_festival.hh"
#include "scene_chicken_festival.hh"
#include "harvest_sprite.hh"

void GameScene::RunChickenFestivalContest()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CHICKEN_FESTIVAL_CONTEST);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ChickenFestivalContestTransition(continuation, current->save);
    current->script_state = 0x18;
}

ChickenFestivalEntrant::ChickenFestivalEntrant()
    : name(gText_HarvestSpriteMiniGameAnimalHusbandryEmpty), year(0), affection(0)
{
}

bool ChickenFestivalMinigameScene::HasWon() const
{
    return HasWonChickenFestivalMinigame(core);
}

SceneTransitionOwner ChickenFestivalMinigameScene::Run()
{
    return RunChickenFestivalMinigame(core);
}

SceneOwner ChickenFestivalContestTransition::CreateScene()
{
    return SceneOwner(new ChickenFestivalContestScene(continuation, save));
}
