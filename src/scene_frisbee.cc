#include "game_scene.hh"
#pragma implementation "scene_frisbee.hh"
#include "scene_frisbee.hh"

// VM DA normalizes the shared Mary mode before entering this bool ABI.
void GameScene::RunFrisbeeGame(bool contest)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_FRISBEE_GAME);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new FrisbeeTransition(continuation, current->save, contest);
    current->script_state = 0x18;
}

SceneOwner FrisbeeTransition::CreateScene()
{
    return SceneOwner(new FrisbeeScene(continuation, save, contest_mode));
}

FrisbeeScene::FrisbeeScene(SceneTransitionOwner next, GameStateSaveImage * image, bool contest)
    : core(new FrisbeeCore(image, contest)), continuation(next)
{
}

FrisbeeScene::~FrisbeeScene()
{
}

SceneTransitionOwner FrisbeeScene::Run()
{
    core->Run();
    return continuation;
}
