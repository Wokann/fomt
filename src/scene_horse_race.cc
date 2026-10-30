#include "game_scene.hh"
#pragma implementation "scene_horse_race.hh"
#include "scene_horse_race.hh"

void GameScene::RunHorseRace(MaryFestivalHorseRaceMode mode)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HORSE_RACE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HorseRaceTransition(continuation, current->save,
        mode != FESTIVAL_HORSE_RACE_MODE_BETTING);
    current->script_state = 0x18;
}

SceneOwner HorseRaceTransition::CreateScene()
{
    return SceneOwner(new HorseRaceScene(continuation, save, player_competes));
}

void GameScene::OpenHorseRaceMedalExchange()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HORSE_RACE_MEDAL_EXCHANGE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HorseRaceMedalExchangeTransition(continuation, current->save);
    current->script_state = 0x18;
}

SceneOwner HorseRaceMedalExchangeTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__27HorseRaceMedalExchangeSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(HorseRaceMedalExchangeScene)), &next, save));
}
