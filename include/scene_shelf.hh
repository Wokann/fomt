#ifndef SCENE_SHELF_HH
#define SCENE_SHELF_HH

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
#pragma interface "scene_shelf.hh"

struct ShelfSceneCore;

struct ShelfSceneCoreOwner {
    explicit ShelfSceneCoreOwner(ShelfSceneCore * input) : value(input) {}
    ~ShelfSceneCoreOwner();
    ShelfSceneCore * value;
};

#pragma interface "scene_shelf.hh"
struct ShelfScene : AScene {
    ShelfScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~ShelfScene();
    virtual SceneTransitionOwner Run();

    ShelfSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct ShelfSceneCore : GameSceneMenuSelectionCore {
    ShelfSceneCore(GameStateSaveImage * image);
    virtual ~ShelfSceneCore();
    void DrawRucksackItems(u32 count);
    void DrawShelfPage(u32 page);
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
    Shelf * shelf;
    u32 phase;
};

#pragma interface "scene_shelf.hh"

#pragma interface "scene_shelf.hh"


EXTERN_C

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
ShelfScene * __10ShelfSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#pragma interface "scene_shelf.hh"


extern char const gText_Shelf_EmptyDescription[];
extern char const gText_Shelf_WrappedGiftWarning[];
extern char const gText_Shelf_Yes[];
extern char const gText_Shelf_No[];
extern char const gText_Shelf_Items[];
extern char const gText_Shelf_Title[];

#endif // SCENE_SHELF_HH
