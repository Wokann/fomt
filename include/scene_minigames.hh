#ifndef SCENE_MINIGAMES_HH
#define SCENE_MINIGAMES_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#pragma interface "scene_minigames_lifetimes.cc"

// This scene runs the entered chicken through the contest and resumes the
// original world scene. The contest Run body remains native assembly.
struct ChickenFestivalContestScene : AScene {
    inline ChickenFestivalContestScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual SceneTransitionOwner Run();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

#pragma interface "scene_minigames_lifetimes.cc"

typedef char ChickenFestivalContestSceneSizeCheck[sizeof(ChickenFestivalContestScene) == 12 ? 1 : -1];
typedef char ChickenFestivalContestSceneContinuationCheck[offsetof(ChickenFestivalContestScene, continuation) == 4 ? 1 : -1];
typedef char ChickenFestivalContestSceneSaveCheck[offsetof(ChickenFestivalContestScene, save) == 8 ? 1 : -1];

struct HarvestSpriteAnimalCareScene : AScene {
    inline HarvestSpriteAnimalCareScene(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id);
    virtual ~HarvestSpriteAnimalCareScene();
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

#pragma interface "scene_minigames_lifetimes.cc"
typedef char HarvestSpriteAnimalCareSceneSizeCheck[sizeof(HarvestSpriteAnimalCareScene) == 16 ? 1 : -1];
typedef char HarvestSpriteAnimalCareSceneCharacterCheck[offsetof(HarvestSpriteAnimalCareScene, sprite_id) == 12 ? 1 : -1];

struct HarvestSpriteHarvestingScene : AScene {
    inline HarvestSpriteHarvestingScene(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id);
    virtual ~HarvestSpriteHarvestingScene();
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

#pragma interface "scene_minigames_lifetimes.cc"
typedef char HarvestSpriteHarvestingSceneSizeCheck[sizeof(HarvestSpriteHarvestingScene) == 16 ? 1 : -1];
typedef char HarvestSpriteHarvestingSceneCharacterCheck[offsetof(HarvestSpriteHarvestingScene, sprite_id) == 12 ? 1 : -1];

struct HarvestSpriteWateringScene : AScene {
    inline HarvestSpriteWateringScene(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id);
    virtual ~HarvestSpriteWateringScene();
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

#pragma interface "scene_minigames_lifetimes.cc"
typedef char HarvestSpriteWateringSceneSizeCheck[sizeof(HarvestSpriteWateringScene) == 16 ? 1 : -1];
typedef char HarvestSpriteWateringSceneCharacterCheck[offsetof(HarvestSpriteWateringScene, sprite_id) == 12 ? 1 : -1];

#pragma interface "scene_minigames.cc"

// These inline entries belong to the earlier scene implementation.

inline ChickenFestivalContestScene::ChickenFestivalContestScene(
    SceneTransitionOwner next, GameStateSaveImage * image)
    : continuation(next), save(image) {}

inline HarvestSpriteAnimalCareScene::HarvestSpriteAnimalCareScene(
    SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
    : continuation(next), save(image), sprite_id(id) {}

inline HarvestSpriteAnimalCareScene::~HarvestSpriteAnimalCareScene() {}

inline HarvestSpriteHarvestingScene::HarvestSpriteHarvestingScene(
    SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
    : continuation(next), save(image), sprite_id(id) {}

inline HarvestSpriteHarvestingScene::~HarvestSpriteHarvestingScene() {}

inline HarvestSpriteWateringScene::HarvestSpriteWateringScene(
    SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id)
    : continuation(next), save(image), sprite_id(id) {}

inline HarvestSpriteWateringScene::~HarvestSpriteWateringScene() {}


#endif // SCENE_MINIGAMES_HH
