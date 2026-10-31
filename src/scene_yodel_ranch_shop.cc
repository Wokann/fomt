#include "prelude.h"
#include "name_entry.hh"
#pragma implementation "scene_yodel_ranch_shop.hh"
#include "game_scene.hh"
#include "scene_yodel_ranch_shop.hh"

void GameScene::OpenYodelRanchShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_YODEL_RANCH_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new YodelRanchShopTransition(continuation, current->save, 0);
    current->script_state = 0x18;
}

SceneTransitionOwner YodelRanchShopScene::Run()
{
    i32 result = RunYodelRanchShopCore(core);
    if (result != -1) {
        u32 selection = GetYodelRanchShopAnimalChoice(core);
        MaryNameEntryKind kind = selection != 0 ? NAME_ENTRY_SHEEP : NAME_ENTRY_COW;
        SceneTransitionOwner next(new YodelRanchShopTransition(continuation, save,
            selection != 0 ? 2 : 1));
        return SceneTransitionOwner(new SavedNameEntryTransition(next, save, kind, result));
    }
    return continuation;
}

SceneOwner YodelRanchShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__19YodelRanchShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUi(
        ::operator new(sizeof(YodelRanchShopScene)), &next, save, unk_0C));
}
