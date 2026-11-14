#ifndef SCENE_GIFT_WRAPPING_HH
#define SCENE_GIFT_WRAPPING_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "game_menu.hh"
#include "held_item.hh"
struct Rucksack;
#include "utility/fixed_str.hh"
#pragma interface "scene_gift_wrapping.hh"

struct GiftWrappingSceneCore;

struct GiftWrappingSceneCoreOwner {
    explicit GiftWrappingSceneCoreOwner(GiftWrappingSceneCore * input) : value(input) {}
    ~GiftWrappingSceneCoreOwner();
    GiftWrappingSceneCore * value;
};

#pragma interface "scene_gift_wrapping.hh"
struct GiftWrappingScene : AScene {
    GiftWrappingScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~GiftWrappingScene();
    virtual SceneTransitionOwner Run();

    GiftWrappingSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct GiftWrappingSceneCore : GameSceneMenuSelectionCore {
    GiftWrappingSceneCore(GameStateSaveImage * image);
    virtual ~GiftWrappingSceneCore();
    void DrawTools(u32 count);
    void DrawItems(u32 count);
    void UpdateDescription(i32 selection);
    void BeginWrap(i32 selection);
    void WrapItem(i32 selection);
    void Run();

    FixedStr<99> item_description;
    ToolStack * held_tool;
    HeldItem * held_item;
    Rucksack * rucksack;
    i32 phase;
};
typedef char GiftWrappingCoreDescriptionCheck[offsetof(GiftWrappingSceneCore, item_description) == 0x98 ? 1 : -1];
typedef char GiftWrappingCoreHeldToolCheck[offsetof(GiftWrappingSceneCore, held_tool) == 0xFC ? 1 : -1];
typedef char GiftWrappingCoreHeldItemCheck[offsetof(GiftWrappingSceneCore, held_item) == 0x100 ? 1 : -1];
typedef char GiftWrappingCoreRucksackCheck[offsetof(GiftWrappingSceneCore, rucksack) == 0x104 ? 1 : -1];
typedef char GiftWrappingCorePhaseCheck[offsetof(GiftWrappingSceneCore, phase) == 0x108 ? 1 : -1];
typedef char GiftWrappingCoreSizeCheck[sizeof(GiftWrappingSceneCore) == 0x10C ? 1 : -1];

#pragma interface "scene_gift_wrapping.hh"

#pragma interface "scene_gift_wrapping.hh"

typedef char GiftWrappingSceneSizeCheck[sizeof(GiftWrappingScene) == 12 ? 1 : -1];
typedef char GiftWrappingSceneCoreCheck[offsetof(GiftWrappingScene, core) == 4 ? 1 : -1];
typedef char GiftWrappingSceneContinuationCheck[offsetof(GiftWrappingScene, continuation) == 8 ? 1 : -1];

EXTERN_C

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
GiftWrappingScene * __17GiftWrappingSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#pragma interface "scene_gift_wrapping.hh"


extern char const gText_GiftWrap_EmptyDescription[];
extern char const gText_GiftWrap_CannotWrap[];
extern char const gText_GiftWrap_Confirm[];
extern char const gText_GiftWrap_Yes[];
extern char const gText_GiftWrap_No[];
extern char const gText_GiftWrap_DogWarning[];
extern char const gText_GiftWrap_Tools[];
extern char const gText_GiftWrap_Items[];
extern char const gText_GiftWrap_Recommendation[];
extern char const gText_GiftWrap_Complete[];
extern char const gText_GiftWrap_SelectItem[];

#endif // SCENE_GIFT_WRAPPING_HH
