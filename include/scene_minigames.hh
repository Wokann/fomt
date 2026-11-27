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


struct HarvestSpriteAnimalCareScene : AScene {
    inline HarvestSpriteAnimalCareScene(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id);
    virtual ~HarvestSpriteAnimalCareScene();
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

#pragma interface "scene_minigames_lifetimes.cc"

struct HarvestSpriteHarvestingScene : AScene {
    inline HarvestSpriteHarvestingScene(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id);
    virtual ~HarvestSpriteHarvestingScene();
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

#pragma interface "scene_minigames_lifetimes.cc"

struct HarvestSpriteWateringScene : AScene {
    inline HarvestSpriteWateringScene(SceneTransitionOwner next, GameStateSaveImage * image, MaryCharacterId id);
    virtual ~HarvestSpriteWateringScene();
    virtual SceneTransitionOwner Run();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MaryCharacterId sprite_id;
};

#pragma interface "scene_minigames_lifetimes.cc"

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
