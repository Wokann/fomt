#ifndef SCENE_WINERY_SHOP_HH
#define SCENE_WINERY_SHOP_HH

#include "game_scene.hh"

#pragma interface "scene_winery_shop.hh"

struct WineryShopSceneCore;
struct WineryShopScene : AScene {
    WineryShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~WineryShopScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct WineryShopTransition : SceneTransition {
    WineryShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char WineryShopSceneSizeCheck[sizeof(WineryShopScene) == 12 ? 1 : -1];
typedef char WineryShopSceneCoreCheck[offsetof(WineryShopScene, core) == 4 ? 1 : -1];
typedef char WineryShopSceneContinuationCheck[offsetof(WineryShopScene, continuation) == 8 ? 1 : -1];
typedef char WineryShopTransitionSizeCheck[sizeof(WineryShopTransition) == 12 ? 1 : -1];

EXTERN_C

// The existing zero-offset destruction prefix is typed; the native core is opaque.
WineryShopSceneCore * ConstructWineryShopSceneCore(void * object, GameStateSaveImage * image);
void RunWineryShopSceneCore(WineryShopSceneCore * core);

// The real constructor's GCC 2.9 continuation-slot ABI, without a wrapper body.
WineryShopScene * __15WineryShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#endif // SCENE_WINERY_SHOP_HH
