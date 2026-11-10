#ifndef SCENE_BLACKSMITH_UPGRADE_HH
#define SCENE_BLACKSMITH_UPGRADE_HH

#include "scene.hh"
#include "game_menu.hh"
#include "held_item.hh"
struct Rucksack;
#include "utility/fixed_str.hh"

#pragma interface "scene_blacksmith_upgrade.hh"

struct BlacksmithShopResultSceneCore;

struct BlacksmithShopResultSceneCoreOwner {
    explicit BlacksmithShopResultSceneCoreOwner(BlacksmithShopResultSceneCore * input) : value(input) {}
    ~BlacksmithShopResultSceneCoreOwner();
    BlacksmithShopResultSceneCore * value;
};

#pragma interface "scene_blacksmith_upgrade.hh"
struct BlacksmithShopResultScene : AScene {
    BlacksmithShopResultScene(SceneTransitionOwner next, GameStateSaveImage * image, u8 has_purchased);
    virtual ~BlacksmithShopResultScene();
    virtual SceneTransitionOwner Run();
    BlacksmithShopResultSceneCoreOwner core;
    SceneTransitionOwner continuation;
};

struct BlacksmithShopResultSceneCore : GameSceneMenuSelectionCore {
    BlacksmithShopResultSceneCore(SceneTransitionOwner next, GameStateSaveImage * image, u8 has_purchased);
    virtual ~BlacksmithShopResultSceneCore();
    void DrawTools(u32 count);
    void DrawItems(u32 count);
    void UpdateDescription(i32 selection);
    bool IsCursedTool(Tool tool) const;
    bool IsUpgradeOre(Article ore) const;
    // 1: same tier, 2: downgrade, 3: upgrade.
    u32 CompareUpgradeLevel(u32 tool_id, u32 ore_id) const;
    u32 GetUpgradeWorkDays(u32 tool_id, u32 ore_id) const;
    SceneTransitionOwner Run();

    FixedStr<99> item_description;
    ToolStack * held_tool;
    HeldItem * held_item;
    Rucksack * rucksack;
    u32 phase;
    GameSceneMenuSpriteDataOwner ore_sprite;
    SceneTransitionOwner continuation;
    u8 has_purchased;
    // The original append operations cap this RAM buffer at 159 bytes plus NUL.
    FixedStr<159> work_order_description;
};
typedef char BlacksmithUpgradeCoreSizeCheck[sizeof(BlacksmithShopResultSceneCore) == 0x1B8 ? 1 : -1];
typedef char BlacksmithUpgradeDescriptionCheck[offsetof(BlacksmithShopResultSceneCore, item_description) == 0x98 ? 1 : -1];
typedef char BlacksmithUpgradeHeldToolCheck[offsetof(BlacksmithShopResultSceneCore, held_tool) == 0xFC ? 1 : -1];
typedef char BlacksmithUpgradeHeldItemCheck[offsetof(BlacksmithShopResultSceneCore, held_item) == 0x100 ? 1 : -1];
typedef char BlacksmithUpgradeRucksackCheck[offsetof(BlacksmithShopResultSceneCore, rucksack) == 0x104 ? 1 : -1];
typedef char BlacksmithUpgradePhaseCheck[offsetof(BlacksmithShopResultSceneCore, phase) == 0x108 ? 1 : -1];
typedef char BlacksmithUpgradeOreSpriteCheck[offsetof(BlacksmithShopResultSceneCore, ore_sprite) == 0x10C ? 1 : -1];
typedef char BlacksmithUpgradeContinuationCheck[offsetof(BlacksmithShopResultSceneCore, continuation) == 0x110 ? 1 : -1];
typedef char BlacksmithUpgradePurchasedCheck[offsetof(BlacksmithShopResultSceneCore, has_purchased) == 0x114 ? 1 : -1];
typedef char BlacksmithUpgradeWorkOrderCheck[offsetof(BlacksmithShopResultSceneCore, work_order_description) == 0x118 ? 1 : -1];

#pragma interface "scene_blacksmith_upgrade.hh"

typedef char BlacksmithShopResultSceneSizeCheck[sizeof(BlacksmithShopResultScene) == 12 ? 1 : -1];
typedef char BlacksmithShopResultSceneCoreCheck[offsetof(BlacksmithShopResultScene, core) == 4 ? 1 : -1];
typedef char BlacksmithShopResultSceneContinuationCheck[offsetof(BlacksmithShopResultScene, continuation) == 8 ? 1 : -1];


extern char const gText_BlacksmithUpgrade_Tools[];
extern char const gText_BlacksmithUpgrade_Items[];
extern char const gText_BlacksmithUpgrade_SelectTool[];
extern char const gText_BlacksmithUpgrade_CursedTool[];
extern char const gText_BlacksmithUpgrade_SelectOre[];
extern char const gText_BlacksmithUpgrade_CannotUpgradeTool[];
extern char const gText_BlacksmithUpgrade_InvalidUpgradeOre[];
extern char const gText_BlacksmithUpgrade_CannotChangeMind[];
extern char const gText_BlacksmithUpgrade_InsufficientExperience[];
extern char const gText_BlacksmithUpgrade_AlreadyUpgradedWithOre[];
extern char const gText_BlacksmithUpgrade_DowngradeConfirmation[];
extern char const gText_BlacksmithUpgrade_EmptyDescription[];
extern char const gText_BlacksmithUpgrade_WorkOrderPrefix[];
extern char const gText_BlacksmithUpgrade_WorkOrderGoldSuffix[];
#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_BlacksmithUpgrade_WorkOrderDaysPrefix[];
#endif
extern char const gText_BlacksmithUpgrade_WorkOrderDaysSuffix[];
#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_BlacksmithUpgrade_WorkOrderQuestion[];
#endif
extern char const gText_BlacksmithUpgrade_InsufficientGoldPageBreak[];
extern char const gText_BlacksmithUpgrade_InsufficientGold[];
extern char const gText_BlacksmithUpgrade_ResultYes[];
extern char const gText_BlacksmithUpgrade_ResultNo[];

#endif // SCENE_BLACKSMITH_UPGRADE_HH
