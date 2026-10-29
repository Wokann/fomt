#include "prelude.h"
#pragma implementation "scene_won_shop.hh"
#include "game_scene.hh"
#include "scene_won_shop.hh"

void GameScene::OpenWonShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_WON_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new WonShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

WonShopScene::WonShopScene(SceneTransitionOwner next, GameStateSaveImage * image)
    // Preserve the verified 0x710-byte native allocation until the core is typed.
    : core(ConstructWonShopSceneCore(::operator new(0x710), image)), continuation(next)
{
}

SceneTransitionOwner WonShopScene::Run()
{
    RunWonShopSceneCore(core);
    return continuation;
}

SceneOwner WonShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__12WonShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(::operator new(sizeof(WonShopScene)), &next, save));
}
