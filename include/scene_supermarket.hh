#ifndef SCENE_SUPERMARKET_HH
#define SCENE_SUPERMARKET_HH

#include "scene.hh"
#include "fomt_constants.hh"

#pragma interface "scene_supermarket.hh"

struct GameStateSaveImage;
struct SupermarketSceneCore;
struct SupermarketPurchaseSceneCore;

// The native UI cores are opaque. Each scene owns its core and continuation;
// each transition consumes a continuation and borrows the save image.
struct SupermarketScene : AScene {
    virtual ~SupermarketScene();
    virtual SceneTransitionOwner Run();

    SupermarketSceneCore * core;
    SceneTransitionOwner continuation;
};

struct SupermarketPurchaseScene : AScene {
    virtual ~SupermarketPurchaseScene();
    virtual SceneTransitionOwner Run();

    SupermarketPurchaseSceneCore * core;
    SceneTransitionOwner continuation;
};

struct SupermarketPurchaseTransition : SceneTransition {
    SupermarketPurchaseTransition(SceneTransitionOwner next, GameStateSaveImage * image,
        MarySupermarketItemId item)
        : continuation(next), save(image), item_id(item) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    MarySupermarketItemId item_id;
};

struct SupermarketTransition : SceneTransition {
    SupermarketTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char SupermarketSceneSizeCheck[sizeof(SupermarketScene) == 12 ? 1 : -1];
typedef char SupermarketSceneCoreCheck[offsetof(SupermarketScene, core) == 4 ? 1 : -1];
typedef char SupermarketSceneContinuationCheck[offsetof(SupermarketScene, continuation) == 8 ? 1 : -1];
typedef char SupermarketPurchaseSceneSizeCheck[sizeof(SupermarketPurchaseScene) == 12 ? 1 : -1];
typedef char SupermarketPurchaseSceneCoreCheck[offsetof(SupermarketPurchaseScene, core) == 4 ? 1 : -1];
typedef char SupermarketPurchaseSceneContinuationCheck[offsetof(SupermarketPurchaseScene, continuation) == 8 ? 1 : -1];
typedef char SupermarketPurchaseTransitionSizeCheck[sizeof(SupermarketPurchaseTransition) == 16 ? 1 : -1];
typedef char SupermarketPurchaseTransitionItemCheck[offsetof(SupermarketPurchaseTransition, item_id) == 12 ? 1 : -1];
typedef char SupermarketTransitionSizeCheck[sizeof(SupermarketTransition) == 12 ? 1 : -1];

EXTERN_C

// Native modal loops and constructors. Construction consumes *continuation.
void RunSupermarketSceneCore(SupermarketSceneCore * core);
void RunSupermarketPurchaseSceneCore(SupermarketPurchaseSceneCore * core);
SupermarketScene * ConstructSupermarketScene(void * object, SceneTransition ** continuation,
    GameStateSaveImage * save);
SupermarketPurchaseScene * ConstructSupermarketPurchaseScene(void * object,
    SceneTransition ** continuation, GameStateSaveImage * save, MarySupermarketItemId item_id);

EXTERN_C_END

#endif // SCENE_SUPERMARKET_HH
