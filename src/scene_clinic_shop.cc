#include "prelude.h"
#pragma implementation "scene_clinic_shop.hh"
#include "scene_clinic_shop.hh"

void GameScene::OpenClinicShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CLINIC_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ClinicShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

ClinicShopScene::ClinicShopScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructClinicShopSceneCore(
          ::operator new(0x710), image))), continuation(next)
{
}

ClinicShopScene::~ClinicShopScene()
{
}

SceneTransitionOwner ClinicShopScene::Run()
{
    RunClinicShopSceneCore(reinterpret_cast<ClinicShopSceneCore *>(core.value));
    return continuation;
}

SceneOwner ClinicShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__15ClinicShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(ClinicShopScene)), &next, save));
}
