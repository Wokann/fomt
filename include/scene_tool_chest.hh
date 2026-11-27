#ifndef SCENE_TOOL_CHEST_HH
#define SCENE_TOOL_CHEST_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "game_menu.hh"
#include "furniture.hh"
#include "game_state_types.hh"
#include "farmer_types.hh"
#include "farm.hh"
#include "farm_house.hh"
struct Rucksack;
#include "utility/fixed_str.hh"
#pragma interface "scene_tool_chest.hh"

struct ToolChestSceneCore;

struct ToolChestSceneCoreOwner {
    explicit ToolChestSceneCoreOwner(ToolChestSceneCore * input) : value(input) {}
    ~ToolChestSceneCoreOwner();
    ToolChestSceneCore * value;
};

#pragma interface "scene_tool_chest.hh"
struct ToolChestScene : AScene {
    ToolChestScene(SceneTransitionOwner next, GameStateSaveImage * image);
    virtual ~ToolChestScene();
    virtual SceneTransitionOwner Run();

    ToolChestSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct ToolChestSceneCore : GameSceneMenuSelectionCore {
    ToolChestSceneCore(GameStateSaveImage * image);
    virtual ~ToolChestSceneCore();
    void DrawRucksackTools(u32 count);
    void DrawToolChestPage(u32 page);
    void ShowNextPage();
    void ShowPreviousPage();
    void UpdateDescription(i32 selection);
    bool ExchangeHeldTool(i32 selection, u32 page);
    bool MoveTool(i32 source_selection, i32 destination_selection);
    void ShowCannotDiscard(i32 selection);
    void Run();

    FixedStr<99> item_description;
    ToolStack * held_tool;
    Rucksack * rucksack;
    ToolChest * tool_chest;
    u32 phase;
};

#pragma interface "scene_tool_chest.hh"

#pragma interface "scene_tool_chest.hh"


EXTERN_C

// Direct reference to the actual GCC 2.9 continuation-slot constructor ABI.
ToolChestScene * __14ToolChestSceneG20SceneTransitionOwnerP18GameStateSaveImage(
    void * object, SceneTransition ** next, GameStateSaveImage * image);

EXTERN_C_END

#pragma interface "scene_tool_chest.hh"


extern char const gText_ToolChest_EmptyDescription[];
extern char const gText_ToolChest_HeaderTools[];
extern char const gText_ToolChest_Title[];

#endif // SCENE_TOOL_CHEST_HH
