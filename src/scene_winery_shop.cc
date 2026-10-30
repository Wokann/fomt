#include "prelude.h"
#pragma implementation "scene_winery_shop.hh"
#include "scene_winery_shop.hh"

void GameScene::OpenWineryShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_WINERY_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new WineryShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

WineryShopScene::WineryShopScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructWineryShopSceneCore(
          ::operator new(0x710), image))), continuation(next)
{
}

WineryShopScene::~WineryShopScene()
{
}

SceneTransitionOwner WineryShopScene::Run()
{
    RunWineryShopSceneCore(reinterpret_cast<WineryShopSceneCore *>(core.value));
    return continuation;
}

SceneOwner WineryShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__15WineryShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(WineryShopScene)), &next, save));
}
