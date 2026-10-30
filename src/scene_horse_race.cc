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
