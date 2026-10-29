#include "prelude.h"
#pragma implementation "scene_supermarket.hh"
#include "game_scene.hh"
#include "scene_supermarket.hh"

void GameScene::OpenSupermarketShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_SUPERMARKET_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new SupermarketTransition(continuation, current->save);
    current->script_state = 0x18;
}

void GameScene::OpenSupermarketPurchase(MarySupermarketItemId item)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_SUPERMARKET_PURCHASE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new SupermarketPurchaseTransition(continuation, current->save, item);
    current->script_state = 0x18;
}

SceneTransitionOwner SupermarketScene::Run()
{
    RunSupermarketSceneCore(core);
    return continuation;
}

SceneTransitionOwner SupermarketPurchaseScene::Run()
{
    RunSupermarketPurchaseSceneCore(core);
    return continuation;
}

SceneOwner SupermarketPurchaseTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(ConstructSupermarketPurchaseScene(::operator new(sizeof(SupermarketPurchaseScene)),
        &next, save, item_id));
}

SceneOwner SupermarketTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(ConstructSupermarketScene(::operator new(sizeof(SupermarketScene)), &next, save));
}
