#ifndef SCENE_REFRIGERATOR_HH
#define SCENE_REFRIGERATOR_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "game_menu.hh"
#include "furniture.hh"
#include "held_item.hh"
struct Rucksack;
#include "utility/fixed_str.hh"
#include "game_state_types.hh"
#include "farmer_types.hh"
#include "farm.hh"
#include "farm_house.hh"
#pragma interface "scene_refrigerator.hh"

struct RefrigeratorSceneCore;

struct RefrigeratorSceneCoreOwner {
    explicit RefrigeratorSceneCoreOwner(RefrigeratorSceneCore * input) : value(input) {}
    ~RefrigeratorSceneCoreOwner();
    RefrigeratorSceneCore * value;
};

#pragma interface "scene_refrigerator.hh"
struct RefrigeratorScene : AScene {
    RefrigeratorScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~RefrigeratorScene();
    virtual SceneTransitionOwner Run();

    RefrigeratorSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct RefrigeratorSceneCore : GameSceneMenuSelectionCore {
    RefrigeratorSceneCore(GameStateSaveImage * image);
    virtual ~RefrigeratorSceneCore();
    void DrawRucksackItems(u32 count);
    void DrawFridgePage(u32 page);
    void ShowNextPage();
    void ShowPreviousPage();
    void UpdateDescription(i32 selection);
    bool ExchangeHeldItem(i32 selection, u32 page);
    bool MoveItem(i32 source_selection, i32 destination_selection);
    void ConfirmWrappedItemMove(i32 source_selection, i32 destination_selection);
    void BeginDiscard(i32 selection);
    void DiscardItem(i32 selection);
    void Run();

    FixedStr<99> item_description;
    HeldItem * held_item;
    Rucksack * rucksack;
    Fridge * fridge;
    u32 phase;
};

#pragma interface "scene_refrigerator.hh"

#pragma interface "scene_refrigerator.hh"


EXTERN_C

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
RefrigeratorScene * __17RefrigeratorSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#pragma interface "scene_refrigerator.hh"


extern char const gText_Fridge_EmptyDescription[];
extern char const gText_Fridge_WrappedGiftWarning[];
extern char const gText_Fridge_Yes[];
extern char const gText_Fridge_No[];
extern char const gText_Fridge_Items[];
extern char const gText_Fridge_Title[];

#endif // SCENE_REFRIGERATOR_HH
