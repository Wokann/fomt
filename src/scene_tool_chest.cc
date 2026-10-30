#include "prelude.h"
#pragma implementation "scene_tool_chest.hh"
#include "scene_tool_chest.hh"

void GameScene::OpenToolChest()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_TOOL_CHEST);
    SceneTransitionOwner continuation(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new ToolChestTransition(continuation, current->save);
    current->script_state = 0x18;
}

ToolChestScene::ToolChestScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(reinterpret_cast<GameSceneUiComponent *>(ConstructToolChestSceneCore(
          ::operator new(0x10C), image))), continuation(next)
{
}

ToolChestScene::~ToolChestScene()
{
}

SceneTransitionOwner ToolChestScene::Run()
{
    RunToolChestSceneCore(reinterpret_cast<ToolChestSceneCore *>(core.value));
    return continuation;
}

SceneOwner ToolChestTransition::CreateScene()
{
    SceneTransition * next = continuation.release();
    return SceneOwner(__14ToolChestSceneG20SceneTransitionOwnerP18GameStateSaveImage(
        ::operator new(sizeof(ToolChestScene)), &next, save));
}
