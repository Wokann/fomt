#ifndef SCENE_COOKING_HH
#define SCENE_COOKING_HH

#include "game_scene.hh"
#pragma interface "scene_cooking.hh"

struct CookingSceneCore;
struct CookingScene : AScene {
    CookingScene(SceneTransitionOwner next, GameStateSaveImage * image, u8 show_recipes);
    virtual ~CookingScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct CookingTransition : SceneTransition {
    CookingTransition(SceneTransitionOwner next, GameStateSaveImage * image, u8 show_recipes)
        : continuation(next), save(image), recipe_list(show_recipes) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u8 recipe_list;
};

typedef char CookingSceneSizeCheck[sizeof(CookingScene) == 12 ? 1 : -1];
typedef char CookingSceneCoreCheck[offsetof(CookingScene, core) == 4 ? 1 : -1];
typedef char CookingSceneContinuationCheck[offsetof(CookingScene, continuation) == 8 ? 1 : -1];
typedef char CookingTransitionSizeCheck[sizeof(CookingTransition) == 16 ? 1 : -1];

typedef char CookingTransitionSaveCheck[offsetof(CookingTransition, save) == 8 ? 1 : -1];
typedef char CookingTransitionModeCheck[offsetof(CookingTransition, recipe_list) == 12 ? 1 : -1];

EXTERN_C

// The native core retains its verified UI base prefix and opaque remaining layout.
CookingSceneCore * ConstructCookingSceneCore(void * object, GameStateSaveImage * image, u8 show_recipes);
SceneTransitionOwner RunCookingSceneCore(CookingSceneCore * core);

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
CookingScene * __12CookingSceneG20SceneTransitionOwnerP18GameStateSaveImageUc(
    void * object, SceneTransition ** next, GameStateSaveImage * image, u8 show_recipes);

EXTERN_C_END

#endif // SCENE_COOKING_HH
