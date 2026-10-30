#include "prelude.h"
#pragma implementation "scene_cooking.hh"
#include "scene_cooking.hh"

void GameScene::OpenCookingMenu()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_COOKING_MENU);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new CookingTransition(continuation, current->save, false);
    current->script_state = 0x18;
}

void GameScene::OpenRecipeList()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_RECIPE_LIST);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new CookingTransition(continuation, current->save, true);
    current->script_state = 0x18;
}

void GameScene::PrepareCookingMenuTransition()
{
    state->game_object.value->PrepareCookingMenuTransition();
}

void GameScene::RestoreAfterCookingMenu()
{
    state->game_object.value->RestoreAfterCookingMenu();
}

void GameScene::PrepareRecipeMenuTransition()
{
    state->game_object.value->PrepareRecipeMenuTransition();
}

void GameScene::RestoreAfterRecipeMenu()
{
    state->game_object.value->RestoreAfterRecipeMenu();
}

CookingScene::CookingScene(SceneTransitionOwner next, GameStateSaveImage * image, u8 show_recipes)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructCookingSceneCore(
          ::operator new(0x33E0), image, show_recipes))), continuation(next)
{
}

CookingScene::~CookingScene()
{
}

SceneTransitionOwner CookingScene::Run()
{
    RunCookingSceneCore(reinterpret_cast<CookingSceneCore *>(core.value));
    return continuation;
}

SceneOwner CookingTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__12CookingSceneG20SceneTransitionOwnerP18GameStateSaveImageUc(
        ::operator new(sizeof(CookingScene)), &next, save, recipe_list));
}
