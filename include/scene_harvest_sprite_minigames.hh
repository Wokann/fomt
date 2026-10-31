#ifndef SCENE_HARVEST_SPRITE_MINIGAMES_HH
#define SCENE_HARVEST_SPRITE_MINIGAMES_HH

#include "game_scene.hh"
#pragma interface "scene_harvest_sprite_minigames.hh"

struct HarvestSpriteAnimalCareSetup {
    HarvestSpriteAnimalCareSetup() : sprite_variant(2), experience(18) {}
    u32 sprite_variant;
    u8 experience;
};
typedef char HarvestSpriteAnimalCareSetupSizeCheck[sizeof(HarvestSpriteAnimalCareSetup) == 8 ? 1 : -1];

// The UI methods below still have native implementations with these actual ABIs.
struct HarvestSpriteAnimalCareUiScene : AScene {
    HarvestSpriteAnimalCareUiScene(HarvestSpriteAnimalCareSetup const & setup);
    virtual ~HarvestSpriteAnimalCareUiScene();
    virtual SceneTransitionOwner Run();
    bool Succeeded();
    u32 GetUnkRecordValue();
    GameSceneUiComponentOwner core;
};

struct HarvestSpriteAnimalCareScene : AScene {
    HarvestSpriteAnimalCareScene(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
        : continuation(next), save(image), sprite_id(id) {}
    virtual ~HarvestSpriteAnimalCareScene();
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

struct HarvestSpriteAnimalCareTransition : SceneTransition {
    HarvestSpriteAnimalCareTransition(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
        : continuation(next), save(image), sprite_id(id) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};
typedef char HarvestSpriteAnimalCareUiSceneSizeCheck[sizeof(HarvestSpriteAnimalCareUiScene) == 8 ? 1 : -1];
typedef char HarvestSpriteAnimalCareSceneSizeCheck[sizeof(HarvestSpriteAnimalCareScene) == 16 ? 1 : -1];
typedef char HarvestSpriteAnimalCareSceneCharacterCheck[offsetof(HarvestSpriteAnimalCareScene, sprite_id) == 12 ? 1 : -1];
typedef char HarvestSpriteAnimalCareTransitionSizeCheck[sizeof(HarvestSpriteAnimalCareTransition) == 16 ? 1 : -1];

struct HarvestSpriteHarvestingSetup {
    HarvestSpriteHarvestingSetup() : sprite_variant(4), experience(18) {}
    u32 sprite_variant;
    u8 experience;
};
typedef char HarvestSpriteHarvestingSetupSizeCheck[sizeof(HarvestSpriteHarvestingSetup) == 8 ? 1 : -1];

// The UI methods below still have native implementations with these actual ABIs.
struct HarvestSpriteHarvestingUiScene : AScene {
    HarvestSpriteHarvestingUiScene(HarvestSpriteHarvestingSetup const & setup);
    virtual ~HarvestSpriteHarvestingUiScene();
    virtual SceneTransitionOwner Run();
    bool Succeeded();
    u32 GetUnkRecordValue();
    GameSceneUiComponentOwner core;
};

struct HarvestSpriteHarvestingScene : AScene {
    HarvestSpriteHarvestingScene(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
        : continuation(next), save(image), sprite_id(id) {}
    virtual ~HarvestSpriteHarvestingScene();
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

struct HarvestSpriteHarvestingTransition : SceneTransition {
    HarvestSpriteHarvestingTransition(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
        : continuation(next), save(image), sprite_id(id) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};
typedef char HarvestSpriteHarvestingUiSceneSizeCheck[sizeof(HarvestSpriteHarvestingUiScene) == 8 ? 1 : -1];
typedef char HarvestSpriteHarvestingSceneSizeCheck[sizeof(HarvestSpriteHarvestingScene) == 16 ? 1 : -1];
typedef char HarvestSpriteHarvestingSceneCharacterCheck[offsetof(HarvestSpriteHarvestingScene, sprite_id) == 12 ? 1 : -1];
typedef char HarvestSpriteHarvestingTransitionSizeCheck[sizeof(HarvestSpriteHarvestingTransition) == 16 ? 1 : -1];

struct HarvestSpriteWateringSetup {
    HarvestSpriteWateringSetup() : sprite_variant(3), experience(15) {}
    u32 sprite_variant;
    u8 experience;
};
typedef char HarvestSpriteWateringSetupSizeCheck[sizeof(HarvestSpriteWateringSetup) == 8 ? 1 : -1];

// The UI methods below still have native implementations with these actual ABIs.
struct HarvestSpriteWateringUiScene : AScene {
    HarvestSpriteWateringUiScene(HarvestSpriteWateringSetup const & setup);
    virtual ~HarvestSpriteWateringUiScene();
    virtual SceneTransitionOwner Run();
    bool Succeeded();
    u32 GetUnkRecordValue();
    GameSceneUiComponentOwner core;
};

struct HarvestSpriteWateringScene : AScene {
    HarvestSpriteWateringScene(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
        : continuation(next), save(image), sprite_id(id) {}
    virtual ~HarvestSpriteWateringScene();
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

struct HarvestSpriteWateringTransition : SceneTransition {
    HarvestSpriteWateringTransition(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
        : continuation(next), save(image), sprite_id(id) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};
typedef char HarvestSpriteWateringUiSceneSizeCheck[sizeof(HarvestSpriteWateringUiScene) == 8 ? 1 : -1];
typedef char HarvestSpriteWateringSceneSizeCheck[sizeof(HarvestSpriteWateringScene) == 16 ? 1 : -1];
typedef char HarvestSpriteWateringSceneCharacterCheck[offsetof(HarvestSpriteWateringScene, sprite_id) == 12 ? 1 : -1];
typedef char HarvestSpriteWateringTransitionSizeCheck[sizeof(HarvestSpriteWateringTransition) == 16 ? 1 : -1];

#endif // SCENE_HARVEST_SPRITE_MINIGAMES_HH
