#ifndef SCENE_BLACKSMITH_SHOP_HH
#define SCENE_BLACKSMITH_SHOP_HH

#include "game_scene.hh"

#pragma interface "scene_blacksmith_shop.hh"

struct BlacksmithShopSceneCore;
struct BlacksmithShopScene : AScene {
    BlacksmithShopScene(SceneTransitionOwner next, GameStateSaveImage * image,
        u8 input, u32 unk_0C, u32 unk_10, u32 unk_14, u32 unk_18);
    virtual ~BlacksmithShopScene();
    virtual SceneTransitionOwner Run();
    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    GameStateSaveImage * save;
};

struct BlacksmithShopTransition : SceneTransition {
    // Default opening state; these words are not yet assigned a semantic domain.
    BlacksmithShopTransition(SceneTransitionOwner next, GameStateSaveImage * image)
        : continuation(next), save(image), unk_0C(0x51), unk_10(0x5F),
          unk_14(0), unk_18(0), unk_1C(0) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 unk_1C;
};
typedef char BlacksmithShopSceneSizeCheck[sizeof(BlacksmithShopScene) == 32 ? 1 : -1];
typedef char BlacksmithShopSceneSaveCheck[offsetof(BlacksmithShopScene, save) == 28 ? 1 : -1];
typedef char BlacksmithShopTransitionSizeCheck[sizeof(BlacksmithShopTransition) == 32 ? 1 : -1];
typedef char BlacksmithShopTransitionByteCheck[offsetof(BlacksmithShopTransition, unk_1C) == 28 ? 1 : -1];

// This is the verified native destruction-prefix view, not the full core hierarchy.
// The concrete core constructor, Run and destructor bodies remain native.
struct BlacksmithShopResultSceneCore : GameSceneUiComponent {
    u8 unk_008[0x108];
    SceneTransitionOwner continuation;
    u8 unk_114;
    u8 unk_115[0xA3];
};
typedef char BlacksmithShopResultSceneCoreSizeCheck[sizeof(BlacksmithShopResultSceneCore) == 0x1B8 ? 1 : -1];
typedef char BlacksmithShopResultSceneCorePayloadCheck[offsetof(BlacksmithShopResultSceneCore, unk_008) == 8 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreContinuationCheck[offsetof(BlacksmithShopResultSceneCore, continuation) == 0x110 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreByteCheck[offsetof(BlacksmithShopResultSceneCore, unk_114) == 0x114 ? 1 : -1];

struct BlacksmithShopResultScene : AScene {
    BlacksmithShopResultScene(SceneTransitionOwner next, GameStateSaveImage * image, u8 input);
    virtual ~BlacksmithShopResultScene();
    virtual SceneTransitionOwner Run();
    GameSceneUiComponentOwner core;
    SceneTransitionOwner continuation;
};

// This result transition is not the 32-byte shop-opening transition above.
// Its byte is passed unchanged to the native result-scene constructor.
struct BlacksmithShopResultTransition : SceneTransition {
    BlacksmithShopResultTransition(SceneTransitionOwner next, GameStateSaveImage * image, u8 input)
        : continuation(next), save(image), unk_0C(input) {}
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u8 unk_0C;
};
typedef char BlacksmithShopResultSceneSizeCheck[sizeof(BlacksmithShopResultScene) == 12 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreCheck[offsetof(BlacksmithShopResultScene, core) == 4 ? 1 : -1];
typedef char BlacksmithShopResultSceneContinuationCheck[offsetof(BlacksmithShopResultScene, continuation) == 8 ? 1 : -1];
typedef char BlacksmithShopResultTransitionSizeCheck[sizeof(BlacksmithShopResultTransition) == 16 ? 1 : -1];
typedef char BlacksmithShopResultTransitionContinuationCheck[offsetof(BlacksmithShopResultTransition, continuation) == 4 ? 1 : -1];
typedef char BlacksmithShopResultTransitionSaveCheck[offsetof(BlacksmithShopResultTransition, save) == 8 ? 1 : -1];
typedef char BlacksmithShopResultTransitionByteCheck[offsetof(BlacksmithShopResultTransition, unk_0C) == 12 ? 1 : -1];


EXTERN_C

// The native core has the verified zero-offset lifecycle prefix used by core.
// Its full 0x48E8-byte internal layout is intentionally still opaque.
BlacksmithShopSceneCore * ConstructBlacksmithShopSceneCore(void * object,
    GameStateSaveImage * save, u8 input, u32 unk_0C, u32 unk_10, u32 unk_14, u32 unk_18);
u32 RunBlacksmithShopSceneCore(BlacksmithShopSceneCore * core);

// Sole C++ constructor body, declared in its actual GCC 2.9 owner-slot ABI.
BlacksmithShopScene * __19BlacksmithShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUcUiUiUiUi(
    void * object, SceneTransition ** next, GameStateSaveImage * save,
    u8 input, u32 unk_0C, u32 unk_10, u32 unk_14, u32 unk_18);

BlacksmithShopResultSceneCore * ConstructBlacksmithShopResultCore(void * object,
    SceneTransitionOwner next, GameStateSaveImage * save, u8 input);
SceneTransitionOwner RunBlacksmithShopResultCore(BlacksmithShopResultSceneCore * core);

EXTERN_C_END

#endif // SCENE_BLACKSMITH_SHOP_HH
