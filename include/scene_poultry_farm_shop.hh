#ifndef SCENE_POULTRY_FARM_SHOP_HH
#define SCENE_POULTRY_FARM_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

struct GameStateSaveImage;
#include "shop_common.hh"
#include "utility/fixed_str.hh"

struct Animal;

struct PoultryShopChickenSaleEntry {
    i32 chicken_index;
    u32 price;
};

// Native 12 x 2 4bpp label storage; the first word is not initialized/read.
struct PoultryShopNameTiles {
    u32 unk_00;
    u32 tiles[12 * 2 * 8];
};

#pragma interface "scene_poultry_farm_shop.hh"
struct PoultryFarmShopSceneCore;

struct PoultryFarmShopSceneCoreOwner {
    explicit PoultryFarmShopSceneCoreOwner(PoultryFarmShopSceneCore * input) : value(input) {}
    ~PoultryFarmShopSceneCoreOwner();
    PoultryFarmShopSceneCore * value;
};

#pragma interface "scene_poultry_farm_shop.hh"
struct PoultryFarmShopScene : AScene {
    PoultryFarmShopScene(SceneTransitionOwner next, GameStateSaveImage * image, u32 input);
    virtual ~PoultryFarmShopScene();
    virtual SceneTransitionOwner Run();
    PoultryFarmShopSceneCoreOwner core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    GameStateSaveImage * save;
};

struct PoultryFarmShopSceneCore : ShopScreenCore {
    PoultryFarmShopSceneCore(GameStateSaveImage * image, u32 input);
    virtual ~PoultryFarmShopSceneCore();
    u32 DrawCatalog();
    u32 DrawChickenSaleList();
    u32 GetChickenAffectionHearts(Animal const * chicken) const;
    void UpdateDescription();
    u32 GetChickenSalePrice(u32 chicken_index) const;
    i32 Run();

    i32 phase;
    u8 unk_6A8;
    // Native capacity is eight chickens; -1 marks an unused sale entry.
    PoultryShopChickenSaleEntry chickens[8];
    u32 chicken_menu_count;
    u32 chicken_menu_codes[8];
    PoultryShopNameTiles name_tiles[9];
    // Original append paths enforce these byte limits, including one NUL.
    FixedStr<127> description;
    FixedStr<99> purchase_description;
    i32 naming_chicken_index;
};

typedef char PoultryShopChickenSaleEntrySizeCheck[sizeof(PoultryShopChickenSaleEntry) == 8 ? 1 : -1];
typedef char PoultryShopNameTilesSizeCheck[sizeof(PoultryShopNameTiles) == 0x304 ? 1 : -1];
typedef char PoultryShopCorePhaseCheck[offsetof(PoultryFarmShopSceneCore, phase) == 0x6A4 ? 1 : -1];
typedef char PoultryShopCoreChickensCheck[offsetof(PoultryFarmShopSceneCore, chickens) == 0x6AC ? 1 : -1];
typedef char PoultryShopCoreMenuCheck[offsetof(PoultryFarmShopSceneCore, chicken_menu_codes) == 0x6F0 ? 1 : -1];
typedef char PoultryShopCoreTilesCheck[offsetof(PoultryFarmShopSceneCore, name_tiles) == 0x710 ? 1 : -1];
typedef char PoultryShopCoreDescriptionCheck[offsetof(PoultryFarmShopSceneCore, description) == 0x2234 ? 1 : -1];
typedef char PoultryShopCorePurchaseDescriptionCheck[offsetof(PoultryFarmShopSceneCore, purchase_description) == 0x22B4 ? 1 : -1];
typedef char PoultryShopCoreResultCheck[offsetof(PoultryFarmShopSceneCore, naming_chicken_index) == 0x2318 ? 1 : -1];
typedef char PoultryShopCoreSizeCheck[sizeof(PoultryFarmShopSceneCore) == 0x231C ? 1 : -1];

// Member order releases the continuation before this owned core.
#pragma interface "scene_poultry_farm_shop.hh"

#pragma interface "scene_poultry_farm_shop.hh"
typedef char PoultryFarmShopSceneSizeCheck[sizeof(PoultryFarmShopScene) == 20 ? 1 : -1];
typedef char PoultryFarmShopSceneSaveCheck[offsetof(PoultryFarmShopScene, save) == 16 ? 1 : -1];

EXTERN_C

// Direct reference to the real GCC 2.9 continuation-slot constructor ABI.
PoultryFarmShopScene * __20PoultryFarmShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUi(
    void * object, SceneTransition ** next, GameStateSaveImage * image, u32 input);

EXTERN_C_END

#pragma interface "scene_poultry_farm_shop.hh"


// The original shop directory consists of five contiguous 32-bit fields.
// Keep both text pointers: some entries intentionally point at one text twice.
struct PoultryShopCatalogEntry
{
    u32 code;
    char const * primary_text;
    u32 price;
    char const * secondary_text;
    u32 mode;
};

extern char const gText_PoultryShop_Empty[];
extern char const gText_PoultryShop_BuyChicken[];
extern char const gText_PoultryShop_SellChicken[];
extern PoultryShopCatalogEntry const gPoultryShopCatalog[];

extern char const gText_PoultryShop_PageBreak[];
extern char const gText_PoultryShop_StatusSick[];
extern char const gText_PoultryShop_StatusUnhappy[];
extern char const gText_PoultryShop_StatusHealthy[];
extern char const gText_PoultryShop_StatusSpacer[];
extern char const gText_PoultryShop_Age[];
extern char const gText_PoultryShop_Spring[];
extern char const gText_PoultryShop_Summer[];
extern char const gText_PoultryShop_Autumn[];
extern char const gText_PoultryShop_Winter[];
extern char const gText_PoultryShop_DailySellingPrice[];
extern char const gText_PoultryShop_Currency[];

extern char const gText_PoultryShop_InsufficientGold[];
extern char const gText_PoultryShop_FeedBinFull[];
extern char const gText_PoultryShop_BlankLinePair[];
extern char const gText_PoultryShop_InventoryFull[];
extern char const gText_PoultryShop_CoopFull[];
extern char const gText_PoultryShop_NameChickenPrompt[];
extern char const gText_PoultryShop_NoChickensToSell[];
extern char const gText_PoultryShop_NotInterested[];
extern char const gText_PoultryShop_PurchaseDeclined[];
extern char const gText_PoultryShop_Yes[];
extern char const gText_PoultryShop_No[];
extern char const gText_PoultryShop_FeedPurchaseComplete[];
extern char const gText_PoultryShop_PurchaseDeliveryPartial[];
extern char const gText_PoultryShop_MedicinePurchaseComplete[];
extern char const gText_PoultryShop_PurchaseComplete[];
extern char const gText_PoultryShop_ChickenPurchaseComplete[];
extern char const gText_PoultryShop_PurchaseMorePrompt[];
extern char const gText_PoultryShop_ChickenSold[];

#if defined(REGION_JP)
extern char const gText_PoultryShop_PricePrompt[];
#else
extern char const gText_PoultryShop_PricePromptPrefix[];
#if defined(REGION_DE)
extern char const gText_PoultryShop_PricePromptSuffix[];
#endif
#endif

#endif // SCENE_POULTRY_FARM_SHOP_HH
