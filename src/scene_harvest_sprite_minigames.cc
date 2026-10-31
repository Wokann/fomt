#include "prelude.h"
#pragma implementation "scene_harvest_sprite_minigames.hh"
#include "scene_harvest_sprite_minigames.hh"

void GameScene::RunHarvestSpriteAnimalCareMinigame(MaryCharacterId sprite_id)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HARVEST_SPRITE_ANIMALCARE_MINIGAME);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HarvestSpriteAnimalCareTransition(next, current->save, sprite_id);
    current->script_state = 0x18;
}

void GameScene::RunHarvestSpriteHarvestingMinigame(MaryCharacterId sprite_id)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HARVEST_SPRITE_HARVESTING_MINIGAME);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HarvestSpriteHarvestingTransition(next, current->save, sprite_id);
    current->script_state = 0x18;
}

void GameScene::RunHarvestSpriteWateringMinigame(MaryCharacterId sprite_id)
{
    GameSceneState * current = state;
    GameSceneResumeRequest request(GameSceneResumeRequest::AFTER_HARVEST_SPRITE_WATERING_MINIGAME);
    SceneTransitionOwner next(new ReturnToGameScene(current->GetSave(), request));
    current->pending_transition = new HarvestSpriteWateringTransition(next, current->save, sprite_id);
    current->script_state = 0x18;
}

SceneTransitionOwner HarvestSpriteAnimalCareScene::Run()
{
    HarvestSpriteAnimalCareSetup setup;
    switch (sprite_id)
    {
    case CHARACTER_STAID: setup.sprite_variant = 0; break;
    case CHARACTER_NAPPY: setup.sprite_variant = 2; break;
    case CHARACTER_BOLD: setup.sprite_variant = 3; break;
    case CHARACTER_CHEF: setup.sprite_variant = 4; break;
    case CHARACTER_AQUA: setup.sprite_variant = 5; break;
    case CHARACTER_HOGGY: setup.sprite_variant = 6; break;
    case CHARACTER_TIMID: setup.sprite_variant = 1; break;
    }
    HarvestSprite * sprite = save->npcs.GetHarvestSpriteByCharacterId(sprite_id);
    setup.experience = sprite->GetMinigameExp(HarvestSprite::TASK_ANIMALS);
    HarvestSpriteAnimalCareUiScene ui(setup);
    ui.Run();
    bool succeeded = ui.Succeeded();
    sprite->SetPlayedMinigame(HarvestSprite::TASK_ANIMALS, succeeded);
    static_cast<ReturnToGameScene *>(continuation.get())->SetHarvestSpriteMinigameResult(succeeded);
    save->UpdateUnknown18(ui.GetUnkRecordValue());
    return SceneTransitionOwner(continuation.release());
}

HarvestSpriteAnimalCareScene::~HarvestSpriteAnimalCareScene()
{
}

SceneOwner HarvestSpriteAnimalCareTransition::CreateScene()
{
    return SceneOwner(new HarvestSpriteAnimalCareScene(continuation, save, sprite_id));
}

SceneTransitionOwner HarvestSpriteHarvestingScene::Run()
{
    HarvestSpriteHarvestingSetup setup;
    switch (sprite_id)
    {
    case CHARACTER_STAID: setup.sprite_variant = 0; break;
    case CHARACTER_NAPPY: setup.sprite_variant = 2; break;
    case CHARACTER_BOLD: setup.sprite_variant = 3; break;
    case CHARACTER_CHEF: setup.sprite_variant = 4; break;
    case CHARACTER_AQUA: setup.sprite_variant = 5; break;
    case CHARACTER_HOGGY: setup.sprite_variant = 6; break;
    case CHARACTER_TIMID: setup.sprite_variant = 1; break;
    }
    HarvestSprite * sprite = save->npcs.GetHarvestSpriteByCharacterId(sprite_id);
    setup.experience = sprite->GetMinigameExp(HarvestSprite::TASK_HARVEST);
    HarvestSpriteHarvestingUiScene ui(setup);
    ui.Run();
    bool succeeded = ui.Succeeded();
    sprite->SetPlayedMinigame(HarvestSprite::TASK_HARVEST, succeeded);
    static_cast<ReturnToGameScene *>(continuation.get())->SetHarvestSpriteMinigameResult(succeeded);
    save->UpdateUnknown13(ui.GetUnkRecordValue());
    return SceneTransitionOwner(continuation.release());
}

HarvestSpriteHarvestingScene::~HarvestSpriteHarvestingScene()
{
}

SceneOwner HarvestSpriteHarvestingTransition::CreateScene()
{
    return SceneOwner(new HarvestSpriteHarvestingScene(continuation, save, sprite_id));
}

SceneTransitionOwner HarvestSpriteWateringScene::Run()
{
    HarvestSpriteWateringSetup setup;
    switch (sprite_id)
    {
    case CHARACTER_STAID: setup.sprite_variant = 0; break;
    case CHARACTER_NAPPY: setup.sprite_variant = 2; break;
    case CHARACTER_BOLD: setup.sprite_variant = 3; break;
    case CHARACTER_CHEF: setup.sprite_variant = 4; break;
    case CHARACTER_AQUA: setup.sprite_variant = 5; break;
    case CHARACTER_HOGGY: setup.sprite_variant = 6; break;
    case CHARACTER_TIMID: setup.sprite_variant = 1; break;
    }
    HarvestSprite * sprite = save->npcs.GetHarvestSpriteByCharacterId(sprite_id);
    setup.experience = sprite->GetMinigameExp(HarvestSprite::TASK_WATER);
    HarvestSpriteWateringUiScene ui(setup);
    ui.Run();
    bool succeeded = ui.Succeeded();
    sprite->SetPlayedMinigame(HarvestSprite::TASK_WATER, succeeded);
    static_cast<ReturnToGameScene *>(continuation.get())->SetHarvestSpriteMinigameResult(succeeded);
    save->UpdateUnknown25(ui.GetUnkRecordValue());
    return SceneTransitionOwner(continuation.release());
}

HarvestSpriteWateringScene::~HarvestSpriteWateringScene()
{
}

SceneOwner HarvestSpriteWateringTransition::CreateScene()
{
    return SceneOwner(new HarvestSpriteWateringScene(continuation, save, sprite_id));
}
