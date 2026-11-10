#ifndef SCENE_BLACKSMITH_SHOP_HH
#define SCENE_BLACKSMITH_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#include "shop_common.hh"
#include "fomt_constants.hh"

#pragma interface "scene_blacksmith_shop.hh"

// Each native label has a 24 by 2 tile buffer, plus one untouched word.
struct BlacksmithShopLabelTiles {
    u32 unk_00;
    u32 tiles[24 * 2 * 8];
};

struct BlacksmithShopSceneCore;

struct BlacksmithShopSceneCoreOwner {
    explicit BlacksmithShopSceneCoreOwner(BlacksmithShopSceneCore * input) : value(input) {}
    ~BlacksmithShopSceneCoreOwner();
    BlacksmithShopSceneCore * value;
};
#pragma interface "scene_blacksmith_shop.hh"
struct BlacksmithShopScene : AScene {
    BlacksmithShopScene(SceneTransitionOwner next, GameStateSaveImage * image,
        u8 input, u32 tool_id, u32 ore_id, u32 order_price, u32 work_days);
    virtual ~BlacksmithShopScene();
    virtual SceneTransitionOwner Run();
    BlacksmithShopSceneCoreOwner core;
    SceneTransitionOwner continuation;
    u32 tool_id;
    u32 ore_id;
    u32 order_price;
    u32 work_days;
    GameStateSaveImage * save;
};

// This transition preserves the shop purchase flag while selecting a tool and ore.
struct BlacksmithShopResultTransition : SceneTransition {
    BlacksmithShopResultTransition(SceneTransitionOwner next, GameStateSaveImage * image, u8 has_purchased)
        : continuation(next), save(image), has_purchased(has_purchased) {}
    virtual ~BlacksmithShopResultTransition();
    virtual SceneOwner CreateScene();
    SceneTransitionOwner continuation;
    GameStateSaveImage * save;
    u8 has_purchased;
};

struct BlacksmithShopSceneCore : ShopScreenCore {
    BlacksmithShopSceneCore(GameStateSaveImage * image, u8 input,
        u32 tool_id, u32 ore_id, u32 order_price, u32 work_days);
    virtual ~BlacksmithShopSceneCore();
    void AppendResourceRow(u32 resource_id, i32 x, i16 y, u8 const * archive);
    void DrawToolIcon(u32 tool_id, u32 tile_x, u32 tile_y);
    void DrawCatalog();
    void PrepareCraftOrder(u32 ore_id, u32 price);
    void UpdateDescription(u32 selection);
    bool IsToolUnowned(u32 tool_id) const;
    u32 Run();

    i32 phase;
    bool has_purchased;
    BlacksmithShopLabelTiles label_tiles[11];
    u32 tool_id;
    u32 ore_id;
    u32 order_price;
    u32 work_days;
};

typedef char BlacksmithLabelTilesSizeCheck[sizeof(BlacksmithShopLabelTiles) == 0x604 ? 1 : -1];
typedef char BlacksmithCorePhaseCheck[offsetof(BlacksmithShopSceneCore, phase) == 0x6A4 ? 1 : -1];
typedef char BlacksmithCorePurchasedCheck[offsetof(BlacksmithShopSceneCore, has_purchased) == 0x6A8 ? 1 : -1];
typedef char BlacksmithCoreTilesCheck[offsetof(BlacksmithShopSceneCore, label_tiles) == 0x6AC ? 1 : -1];
typedef char BlacksmithCoreToolCheck[offsetof(BlacksmithShopSceneCore, tool_id) == 0x48D8 ? 1 : -1];
typedef char BlacksmithCoreOreCheck[offsetof(BlacksmithShopSceneCore, ore_id) == 0x48DC ? 1 : -1];
typedef char BlacksmithCorePriceCheck[offsetof(BlacksmithShopSceneCore, order_price) == 0x48E0 ? 1 : -1];
typedef char BlacksmithCoreDaysCheck[offsetof(BlacksmithShopSceneCore, work_days) == 0x48E4 ? 1 : -1];
typedef char BlacksmithCoreSizeCheck[sizeof(BlacksmithShopSceneCore) == 0x48E8 ? 1 : -1];

#pragma interface "scene_blacksmith_shop.hh"
typedef char BlacksmithShopSceneSizeCheck[sizeof(BlacksmithShopScene) == 32 ? 1 : -1];
typedef char BlacksmithShopSceneSaveCheck[offsetof(BlacksmithShopScene, save) == 28 ? 1 : -1];
typedef char BlacksmithShopResultTransitionSizeCheck[sizeof(BlacksmithShopResultTransition) == 16 ? 1 : -1];
typedef char BlacksmithShopResultTransitionContinuationCheck[offsetof(BlacksmithShopResultTransition, continuation) == 4 ? 1 : -1];
typedef char BlacksmithShopResultTransitionSaveCheck[offsetof(BlacksmithShopResultTransition, save) == 8 ? 1 : -1];
typedef char BlacksmithShopResultTransitionByteCheck[offsetof(BlacksmithShopResultTransition, has_purchased) == 12 ? 1 : -1];

EXTERN_C

// Sole C++ constructor body, declared in its actual GCC 2.9 owner-slot ABI.
BlacksmithShopScene * __19BlacksmithShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUcUiUiUiUi(
    void * object, SceneTransition ** next, GameStateSaveImage * save,
    u8 input, u32 tool_id, u32 ore_id, u32 order_price, u32 work_days);

EXTERN_C_END

#pragma interface "scene_blacksmith_shop.hh"


extern char const gText_Blacksmith_ToolUpgradeMenuLabel[];
extern char const gText_Blacksmith_ToolUpgradeTitle[];
extern char const gText_Blacksmith_Empty[];
extern char const gText_Blacksmith_MakeMayonnaiseMaker[];
extern char const gText_Blacksmith_CostAdamantite[];
extern char const gText_Blacksmith_MakeCheeseMaker[];
extern char const gText_Blacksmith_MakeYarnMaker[];
extern char const gText_Blacksmith_MakeNecklace[];
extern char const gText_Blacksmith_CostOrichalc[];
extern char const gText_Blacksmith_MakeEarrings[];
extern char const gText_Blacksmith_MakeBracelet[];
extern char const gText_Blacksmith_MakeBroach[];

// The original directory is eleven contiguous 20-byte entries. Selection
// identifiers are interpreted by entry_kind: only kind 1 is passed to ToolUi;
// the maker codes 4–6 are intentionally retained as their original values.
struct BlacksmithCatalogEntry
{
    u32 selection_id;
    char const * menu_text;
    u32 price;
    u32 entry_kind;
    char const * detail_text;
};

extern char const gText_Blacksmith_InsufficientGoldAdamantite[];
extern char const gText_Blacksmith_InsufficientGoldOrichalc[];
extern char const gText_Blacksmith_MakerFiveDays[];
extern char const gText_Blacksmith_MakerOneDay[];
extern char const gText_Blacksmith_InsufficientOreAdamantite[];
extern char const gText_Blacksmith_InsufficientOreOrichalc[];
extern char const gText_Blacksmith_SelectToolAndOre[];
extern char const gText_Blacksmith_InsufficientGold[];
extern char const gText_Blacksmith_EquipmentFull[];
extern char const gText_Blacksmith_NeedAnythingElse[];
extern char const gText_Blacksmith_NothingElse[];
extern char const gText_Blacksmith_PurchaseComplete[];
extern char const gText_Blacksmith_Delivery[];
extern char const gText_Blacksmith_PurchaseMore[];
extern char const gText_Blacksmith_MakeIt[];
extern char const gText_Blacksmith_DontMakeIt[];
extern char const gText_Blacksmith_StartWork[];
extern char const gText_Blacksmith_CannotChangeMind[];
extern char const gText_Blacksmith_NoToolToUpgrade[];
extern char const gText_Blacksmith_NoOreToUpgrade[];

extern BlacksmithCatalogEntry const gBlacksmithCatalog[];

#endif // SCENE_BLACKSMITH_SHOP_HH
