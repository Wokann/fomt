#ifndef SCENE_RUCKSACK_HH
#define SCENE_RUCKSACK_HH

#include "scene.hh"
#include "fomt_constants.hh"
#include "game_menu.hh"
#include "utility/fixed_str.hh"
#pragma interface "scene_rucksack.hh"

struct Rucksack;
struct HeldItem;
struct ToolStack;
struct RucksackMenuCore;

struct RucksackMenuCoreOwner {
    RucksackMenuCore * value;
    explicit RucksackMenuCoreOwner(RucksackMenuCore * input) : value(input) {}
    ~RucksackMenuCoreOwner();
};

#pragma interface "scene_rucksack.hh"
struct RucksackMenuScene : AScene {
    RucksackMenuScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~RucksackMenuScene();
    virtual SceneTransitionOwner Run();
    RucksackMenuCoreOwner core;
    SceneTransitionOwner continuation;
};

// Direct native constructor ABI for the transitional scene factory.
extern "C" RucksackMenuScene * ConstructRucksackMenuScene(void * storage,
    SceneTransition ** continuation, GameStateSaveImage * save)
    asm("__17RucksackMenuSceneG20SceneTransitionOwnerP18GameStateSaveImage");

// This is the player's held tool, held item and rucksack menu. Its remaining
// menu/update logic is still native; no keyboard buffer belongs to this core.
struct RucksackMenuCore : GameSceneMenuSelectionCore {
    RucksackMenuCore(GameStateSaveImage * image);
    virtual ~RucksackMenuCore();
    bool ExchangeHeldSlot(i32 selection);
    bool MoveSlot(i32 source_selection, i32 destination_selection);
    void BeginDiscard(i32 selection);
    void DiscardItem(i32 selection);
    void DrawTools(u32 count);
    void DrawItems(u32 count);
    void UpdateDescription(i32 selection);
    void Run();

    FixedStr<99> item_description;
    ToolStack * held_tool;
    HeldItem * held_item;
    Rucksack * rucksack;
    u32 phase;
};

#pragma interface "scene_rucksack.hh"


extern char const gText_HomeStorage_ConfirmationYes[];
extern char const gText_HomeStorage_ConfirmationNo[];
extern char const gText_HomeStorage_EmptyDescription[];
extern char const gText_HomeStorage_CategoryTools[];
extern char const gText_HomeStorage_CategoryItems[];

#endif
