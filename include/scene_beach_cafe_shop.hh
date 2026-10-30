#ifndef SCENE_BEACH_CAFE_SHOP_HH
#define SCENE_BEACH_CAFE_SHOP_HH

#include "game_scene.hh"

#pragma interface "scene_beach_cafe_shop.hh"

struct BeachCafeShopSceneCore;
struct BeachCafeShopScene : AScene {
    BeachCafeShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~BeachCafeShopScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct BeachCafeShopTransition : SceneTransition {
    BeachCafeShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char BeachCafeShopSceneSizeCheck[sizeof(BeachCafeShopScene) == 12 ? 1 : -1];
typedef char BeachCafeShopSceneCoreCheck[offsetof(BeachCafeShopScene, core) == 4 ? 1 : -1];
typedef char BeachCafeShopSceneContinuationCheck[offsetof(BeachCafeShopScene, continuation) == 8 ? 1 : -1];
typedef char BeachCafeShopTransitionSizeCheck[sizeof(BeachCafeShopTransition) == 12 ? 1 : -1];

EXTERN_C

// The existing zero-offset destruction prefix is typed; the native core is opaque.
BeachCafeShopSceneCore * ConstructBeachCafeShopSceneCore(void * object, GameStateSaveImage * image);
void RunBeachCafeShopSceneCore(BeachCafeShopSceneCore * core);

// The real constructor's GCC 2.9 continuation-slot ABI, without a wrapper body.
BeachCafeShopScene * __18BeachCafeShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#endif // SCENE_BEACH_CAFE_SHOP_HH
