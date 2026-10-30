#include "prelude.h"
#pragma implementation "scene_gift_wrapping.hh"
#include "scene_gift_wrapping.hh"

void GameScene::OpenGiftWrappingMenu()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_GIFT_WRAPPING);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new GiftWrappingTransition(continuation, current->save);
    current->script_state = 0x18;
}

GiftWrappingScene::GiftWrappingScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructGiftWrappingSceneCore(
          ::operator new(0x10C), image))), continuation(next)
{
}

GiftWrappingScene::~GiftWrappingScene()
{
}

SceneTransitionOwner GiftWrappingScene::Run()
{
    RunGiftWrappingSceneCore(reinterpret_cast<GiftWrappingSceneCore *>(core.value));
    return continuation;
}

SceneOwner GiftWrappingTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__17GiftWrappingSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(GiftWrappingScene)), &next, save));
}
