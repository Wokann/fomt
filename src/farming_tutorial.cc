#include "prelude.h"
#pragma implementation "farming_tutorial.hh"
#include "farming_tutorial.hh"
void * operator new(unsigned long);

FarmingTutorialTransition::FarmingTutorialTransition(SceneTransitionOwner next, MaryFarmingTutorialKind value)
    : continuation(next), kind(value) {}

SceneOwner FarmingTutorialTransition::CreateScene()
{
    return SceneOwner(new FarmingTutorialScene(continuation, kind));
}

void FarmingTutorialScene::Push(i32 value)
{
    stack.Push(value);
}

void GameScene::OpenFarmingTutorial(MaryFarmingTutorialKind kind)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_FARMING_TUTORIAL);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new FarmingTutorialTransition(next, kind);
    current->script_state = 0x18;
}
