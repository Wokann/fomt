#include "prelude.h"
#include "name_entry.hh"
#pragma implementation "scene_poultry_farm_shop.hh"
#include "scene_poultry_farm_shop.hh"

void GameScene::OpenPoultryFarmShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_POULTRY_FARM_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new PoultryFarmShopTransition(continuation, current->save, 0);
    current->script_state = 0x18;
}

PoultryFarmShopScene::PoultryFarmShopScene(SceneTransitionOwner next, GameStateSaveImage * image, u32 input)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructPoultryFarmShopSceneCore(
          ::operator new(0x231C), image, input))), continuation(next), unk_0C(input), save(image)
{
}

PoultryFarmShopScene::~PoultryFarmShopScene()
{
}

SceneTransitionOwner PoultryFarmShopScene::Run()
{
    i32 result = RunPoultryFarmShopSceneCore(
        reinterpret_cast<PoultryFarmShopSceneCore *>(core.value));
    if (result != -1) {
        SceneTransitionOwner next(new PoultryFarmShopTransition(continuation, save, 1));
        return SceneTransitionOwner(new SavedNameEntryTransition(next, save, NAME_ENTRY_CHICKEN, result));
    }
    return continuation;
}

SceneOwner PoultryFarmShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__20PoultryFarmShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUi(
        ::operator new(sizeof(PoultryFarmShopScene)), &next, save, unk_0C));
}
