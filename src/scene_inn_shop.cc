#include "prelude.h"
#pragma implementation "scene_inn_shop.hh"
#include "scene_inn_shop.hh"

void GameScene::OpenInnShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_INN_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new InnShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

InnShopScene::InnShopScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructInnShopSceneCore(
          ::operator new(0x6B0), image))), continuation(next)
{
}

InnShopScene::~InnShopScene()
{
}

SceneTransitionOwner InnShopScene::Run()
{
    RunInnShopSceneCore(reinterpret_cast<InnShopSceneCore *>(core.value));
    return continuation;
}

SceneOwner InnShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__12InnShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(InnShopScene)), &next, save));
}
