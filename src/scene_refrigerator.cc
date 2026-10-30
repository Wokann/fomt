#include "prelude.h"
#pragma implementation "scene_refrigerator.hh"
#include "scene_refrigerator.hh"

void GameScene::OpenRefrigerator()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_REFRIGERATOR);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new RefrigeratorTransition(continuation, current->save);
    current->script_state = 0x18;
}

RefrigeratorScene::RefrigeratorScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructRefrigeratorSceneCore(
          ::operator new(0x10C), image))), continuation(next)
{
}

RefrigeratorScene::~RefrigeratorScene()
{
}

SceneTransitionOwner RefrigeratorScene::Run()
{
    RunRefrigeratorSceneCore(reinterpret_cast<RefrigeratorSceneCore *>(core.value));
    return continuation;
}

SceneOwner RefrigeratorTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__17RefrigeratorSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(RefrigeratorScene)), &next, save));
}
