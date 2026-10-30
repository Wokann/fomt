#include "prelude.h"
#pragma implementation "scene_shelf.hh"
#include "scene_shelf.hh"

void GameScene::OpenShelf()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_SHELF);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ShelfTransition(continuation, current->save);
    current->script_state = 0x18;
}

ShelfScene::ShelfScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructShelfSceneCore(
          ::operator new(0x10C), image))), continuation(next)
{
}

ShelfScene::~ShelfScene()
{
}

SceneTransitionOwner ShelfScene::Run()
{
    RunShelfSceneCore(reinterpret_cast<ShelfSceneCore *>(core.value));
    return continuation;
}

SceneOwner ShelfTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__10ShelfSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(ShelfScene)), &next, save));
}
