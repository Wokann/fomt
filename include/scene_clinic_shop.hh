#ifndef SCENE_CLINIC_SHOP_HH
#define SCENE_CLINIC_SHOP_HH

#include "game_scene.hh"

#pragma interface "scene_clinic_shop.hh"

struct ClinicShopSceneCore;
struct ClinicShopScene : AScene {
    ClinicShopScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~ClinicShopScene();
    virtual SceneTransitionOwner Run();

    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

struct ClinicShopTransition : SceneTransition {
    ClinicShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image) {}
    virtual SceneOwner CreateScene();

    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
};

typedef char ClinicShopSceneSizeCheck[sizeof(ClinicShopScene) == 12 ? 1 : -1];
typedef char ClinicShopSceneCoreCheck[offsetof(ClinicShopScene, core) == 4 ? 1 : -1];
typedef char ClinicShopSceneContinuationCheck[offsetof(ClinicShopScene, continuation) == 8 ? 1 : -1];
typedef char ClinicShopTransitionSizeCheck[sizeof(ClinicShopTransition) == 12 ? 1 : -1];

EXTERN_C

// Only the zero-offset lifecycle prefix is typed; the full native core is opaque.
ClinicShopSceneCore * ConstructClinicShopSceneCore(void * object, GameStateSaveImage * save);
void RunClinicShopSceneCore(ClinicShopSceneCore * core);

// Sole C++ constructor body, declared in its actual GCC 2.9 owner-slot ABI.
ClinicShopScene * __15ClinicShopSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * save);

EXTERN_C_END

#endif // SCENE_CLINIC_SHOP_HH
