#include "prelude.h"
#pragma implementation "scene_gamecube_link.hh"
#include "scene_gamecube_link.hh"

void GameScene::RunGameCubeLink()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_GAMECUBE_LINK);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new GameCubeLinkTransition(continuation, current->save);
    current->script_state = 0x18;
}

GameCubeLinkUiScene::GameCubeLinkUiScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructGameCubeLinkUiCore(
          ::operator new(0x3F0), image))), continuation(next)
{
}

GameCubeLinkUiScene::~GameCubeLinkUiScene()
{
}

MaryGameCubeLinkResult GameCubeLinkUiScene::GetResult()
{
    return reinterpret_cast<GameCubeLinkUiCore *>(core.value)->result;
}

SceneTransitionOwner GameCubeLinkUiScene::Run()
{
    RunGameCubeLinkUiCore(reinterpret_cast<GameCubeLinkUiCore *>(core.value));
    return continuation;
}

SceneOwner GameCubeLinkTransition::CreateScene()
{
    return SceneOwner(new GameCubeLinkScene(continuation, save));
}

SceneTransitionOwner GameCubeLinkScene::Run()
{
    GameCubeLinkUiScene ui(SceneTransitionOwner(nullptr), save);
    ui.Run();
    static_cast<ReturnToGameScene *>(continuation.get())->SetGameCubeLinkResult(ui.GetResult());
    return SceneTransitionOwner(continuation.release());
}
