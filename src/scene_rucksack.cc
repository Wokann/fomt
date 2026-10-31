#include "prelude.h"
#pragma implementation "scene_rucksack.hh"
#include "game_scene.hh"
#include "scene_rucksack.hh"
#pragma implementation

void * operator new(unsigned long);
void operator delete(void *);

void GameScene::OpenRucksackMenu()
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_RUCKSACK_MENU);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new RucksackMenuTransition(next, current->save);
    current->script_state = 0x18;
}

RucksackMenuCore::RucksackMenuCore(GameStateSaveImage * image)
    : GameSceneMenuSelectionCore(image)
{
    unk_98 = 0;
    held_tool = &save->farmer.unk_5C;
    held_item = &save->farmer.held_item;
    rucksack = &save->farmer.rucksack;
    unk_108 = 0;
}

RucksackMenuCore::~RucksackMenuCore() {}

RucksackMenuScene::RucksackMenuScene(SceneTransitionOwner next, GameStateSaveImage * image)
    : core(new RucksackMenuCore(image)), continuation(next) {}

RucksackMenuScene::~RucksackMenuScene() {}

SceneTransitionOwner RucksackMenuScene::Run()
{
    core.value->Run();
    return continuation;
}
