#include "prelude.h"
#pragma implementation "scene_special_merchant_shop.hh"
#include "scene_special_merchant_shop.hh"

void GameScene::OpenSpecialMerchantShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_SPECIAL_MERCHANT_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new SpecialMerchantShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

SpecialMerchantShopScene::SpecialMerchantShopScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructSpecialMerchantShopSceneCore(
          ::operator new(0x710), image))), continuation(next)
{
}

SpecialMerchantShopScene::~SpecialMerchantShopScene()
{
}

SceneTransitionOwner SpecialMerchantShopScene::Run()
{
    RunSpecialMerchantShopSceneCore(reinterpret_cast<SpecialMerchantShopSceneCore *>(core.value));
    return continuation;
}

SceneOwner SpecialMerchantShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__24SpecialMerchantShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(SpecialMerchantShopScene)), &next, save));
}
