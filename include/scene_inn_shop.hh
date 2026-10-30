#ifndef SCENE_INN_SHOP_HH
#define SCENE_INN_SHOP_HH

#include "game_scene.hh"

#pragma interface "scene_inn_shop.hh"

struct InnShopSceneCore;
struct InnShopScene : AScene {
    InnShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~InnShopScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct InnShopTransition : SceneTransition {
    InnShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char InnShopSceneSizeCheck[sizeof(InnShopScene) == 12 ? 1 : -1];
typedef char InnShopSceneCoreCheck[offsetof(InnShopScene, core) == 4 ? 1 : -1];
typedef char InnShopSceneContinuationCheck[offsetof(InnShopScene, continuation) == 8 ? 1 : -1];
typedef char InnShopTransitionSizeCheck[sizeof(InnShopTransition) == 12 ? 1 : -1];

EXTERN_C

// The existing zero-offset destruction prefix is typed; the native core is opaque.
InnShopSceneCore * ConstructInnShopSceneCore(void * object, GameStateSaveImage * image);
void RunInnShopSceneCore(InnShopSceneCore * core);

// The real constructor's GCC 2.9 continuation-slot ABI, without a wrapper body.
InnShopScene * __12InnShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#endif // SCENE_INN_SHOP_HH
