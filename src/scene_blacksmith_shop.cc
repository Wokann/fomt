#include "prelude.h"
#pragma implementation "scene_blacksmith_shop.hh"
#include "scene_blacksmith_shop.hh"

void GameScene::OpenBlacksmithShop()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_BLACKSMITH_SHOP);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new BlacksmithShopTransition(continuation, current->save);
    current->script_state = 0x18;
}

BlacksmithShopScene::BlacksmithShopScene(SceneTransitionOwner next,
    GameStateSaveImage * image, u8 input, u32 unk_0C, u32 unk_10, u32 unk_14, u32 unk_18)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructBlacksmithShopSceneCore(
          ::operator new(0x48E8), image, input, unk_0C, unk_10, unk_14, unk_18))),
      continuation(next), unk_0C(unk_0C), unk_10(unk_10),
      unk_14(unk_14), unk_18(unk_18), save(image)
{
}

BlacksmithShopScene::~BlacksmithShopScene()
{
}

SceneTransitionOwner BlacksmithShopScene::Run()
{
    u32 result = RunBlacksmithShopSceneCore(reinterpret_cast<BlacksmithShopSceneCore *>(core.value));
    if (result == 0)
        return continuation;
    if (result == 1)
        return SceneTransitionOwner(new BlacksmithShopResultTransition(continuation, save, 0));
    return SceneTransitionOwner(new BlacksmithShopResultTransition(continuation, save, 1));
}

BlacksmithShopResultScene::BlacksmithShopResultScene(SceneTransitionOwner next,
    GameStateSaveImage * image, u8 input)
    : core(ConstructBlacksmithShopResultCore(::operator new(sizeof(BlacksmithShopResultSceneCore)), next, image, input)),
      continuation(next)
{
}

BlacksmithShopResultScene::~BlacksmithShopResultScene()
{
}

SceneTransitionOwner BlacksmithShopResultScene::Run()
{
    return RunBlacksmithShopResultCore(static_cast<BlacksmithShopResultSceneCore *>(core.value));
}

SceneOwner BlacksmithShopTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__19BlacksmithShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUcUiUiUiUi(
        ::operator new(sizeof(BlacksmithShopScene)), &next, save,
        unk_1C, unk_0C, unk_10, unk_14, unk_18));
}

SceneOwner BlacksmithShopResultTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(new BlacksmithShopResultScene(SceneTransitionOwner(next), save, unk_0C));
}
