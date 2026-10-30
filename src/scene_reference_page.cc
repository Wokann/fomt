#include "prelude.h"
#pragma implementation "scene_reference_page.hh"
#include "scene_reference_page.hh"

void GameScene::ShowReferencePage(i32 page_id)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_REFERENCE_PAGE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ReferencePageTransition(continuation, current->save, page_id);
    current->script_state = 0x18;
}

void GameScene::OpenBookList()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_REFERENCE_PAGE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ReferencePageTransition(
        continuation, current->save, ReferencePageScene::BOOK_LIST);
    current->script_state = 0x18;
}

void GameScene::OpenLetterList()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_REFERENCE_PAGE);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ReferencePageTransition(
        continuation, current->save, ReferencePageScene::LETTER_LIST);
    current->script_state = 0x18;
}

ReferencePageScene::ReferencePageScene(SceneTransitionOwner next, GameStateSaveImage * image, i32 page)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructReferencePageSceneCore(
          ::operator new(0xA74), image, page))), continuation(next)
{
}

ReferencePageScene::~ReferencePageScene()
{
}

SceneTransitionOwner ReferencePageScene::Run()
{
    RunReferencePageSceneCore(reinterpret_cast<ReferencePageSceneCore *>(core.value));
    return continuation;
}

SceneOwner ReferencePageTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__18ReferencePageSceneG20SceneTransitionOwnerP18GameStateSaveImagei(
        ::operator new(sizeof(ReferencePageScene)), &next, save, page_id));
}
