#include "prelude.h"
#pragma implementation "scene_carpenter_shop.hh"
#include "game_scene.hh"
#include "scene_carpenter_shop.hh"

void GameScene::OpenCarpenterShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_CARPENTER_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new CarpenterShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

CarpenterShopScene::CarpenterShopScene(SceneTransitionOwner next, GameStateSaveImage * image)
    // Preserve the verified 0x61F4-byte native allocation until the core is typed.
    : core(ConstructCarpenterShopSceneCore(::operator new(0x61F4), image)), continuation(next)
{
}

SceneTransitionOwner CarpenterShopScene::Run()
{
    RunCarpenterShopSceneCore(core);
    return continuation;
}

SceneOwner CarpenterShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__18CarpenterShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(CarpenterShopScene)), &next, save));
}
