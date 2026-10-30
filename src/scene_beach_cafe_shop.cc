#include "prelude.h"
#pragma implementation "scene_beach_cafe_shop.hh"
#include "scene_beach_cafe_shop.hh"

void GameScene::OpenBeachCafeShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_BEACH_CAFE_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new BeachCafeShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

BeachCafeShopScene::BeachCafeShopScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructBeachCafeShopSceneCore(
          ::operator new(0x6B0), image))), continuation(next)
{
}

BeachCafeShopScene::~BeachCafeShopScene()
{
}

SceneTransitionOwner BeachCafeShopScene::Run()
{
    RunBeachCafeShopSceneCore(reinterpret_cast<BeachCafeShopSceneCore *>(core.value));
    return continuation;
}

SceneOwner BeachCafeShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__18BeachCafeShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(BeachCafeShopScene)), &next, save));
}
