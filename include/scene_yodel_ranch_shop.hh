#ifndef SCENE_YODEL_RANCH_SHOP_HH
#define SCENE_YODEL_RANCH_SHOP_HH

#include "scene.hh"
#include "fomt_constants.hh"

#include "shop_common.hh"
#include "utility/fixed_str.hh"
#include "ui_text_commands.hh"
#include "font_draw.hh"

struct GameStateSaveImage;

struct YodelRanchAnimalSaleEntry {
    i32 animal_index;
    u32 price;
};

// Native 12 by 2 tile label, preceded by one untouched word.
struct YodelRanchNameTiles {
    YodelRanchNameTiles() {}
    u32 TileBytes() const { return sizeof(tiles); }
    u32 const * TileData() const { return tiles; }
    void Clear()
    {
        UnkUiSelectionDimensions size(12, 2);
        Clear2DGfxBuffer(reinterpret_cast<u32 const &>(size), tiles, 0);
    }
    void Draw(char const * text)
    {
        UnkUiSelectionDimensions size(12, 2);
        DrawStringTo2DGfxBufferExt(reinterpret_cast<u32 const &>(size), tiles,
            0, 0, reinterpret_cast<u8 const *>(text), 0, 1);
    }
    u32 unk_00;
    u32 tiles[12 * 2 * 8];
};

struct YodelRanchAnimalDescription {
    bool ready;
    FixedStr<127> text;
};

struct YodelRanchShopSceneCore;

struct YodelRanchShopSceneCoreOwner {
    explicit YodelRanchShopSceneCoreOwner(YodelRanchShopSceneCore * input) : value(input) {}
    ~YodelRanchShopSceneCoreOwner();
    YodelRanchShopSceneCore * value;
};

#pragma interface "scene_yodel_ranch_shop.hh"
struct YodelRanchShopScene : AScene {
    YodelRanchShopScene(SceneTransitionOwner next, GameStateSaveImage * image, u32 input);
    virtual ~YodelRanchShopScene();
    virtual SceneTransitionOwner Run();
    YodelRanchShopSceneCoreOwner core;
    SceneTransitionOwner continuation;
    u32 unk_0C;
    GameStateSaveImage * save;
};

struct YodelRanchShopSceneCore : ShopScreenCore {
    YodelRanchShopSceneCore(GameStateSaveImage * image, u32 input);
    virtual ~YodelRanchShopSceneCore();
    u32 DrawCatalog();
    u32 DrawAnimalSaleList(u32 animal_icon);
    u32 GetAffectionHearts(u32 affection) const;
    u32 GetAnimalChoice() const;
    void UpdateDescription(u32 selection);
    u32 GetAnimalSalePrice(u32 index, u32 animal_kind) const;
    u32 CountPregnantAnimals() const;
    i32 Run();

    i32 phase;
    bool has_purchased;
    // Sixteen native barn slots; -1 marks an unused sale entry.
    YodelRanchAnimalSaleEntry animals[16];
    ShopScreenList<u32, 16> animal_menu;
    YodelRanchNameTiles name_tiles[17];
    FixedStr<127> description;
    FixedStr<99> purchase_description;
    YodelRanchAnimalDescription animal_descriptions[16];
    u32 naming_animal_kind;
    i32 naming_animal_index;
};


inline YodelRanchShopSceneCoreOwner::~YodelRanchShopSceneCoreOwner() { delete value; }

EXTERN_C

// Actual GCC 2.9 constructor ABI: the continuation is transferred through
// its single pointer slot.
YodelRanchShopScene * __19YodelRanchShopSceneG20SceneTransitionOwnerP18GameStateSaveImageUi(
    void * storage, SceneTransition ** next, GameStateSaveImage * image, u32 input);

EXTERN_C_END

// Mode selects Article, animal purchase, Tool, animal sale, or a sale-list
// description. The code belongs to that mode, not one global item-ID domain.
struct LivestockShopCatalogEntry
{
    u32 code;
    char const * primary_text;
    u32 price;
    char const * secondary_text;
    i32 mode;
};

extern char const gText_LivestockShop_Empty[];
#if defined(REGION_DE)
extern char const gText_LivestockShop_BuyCowPrimary[];
#endif
extern char const gText_LivestockShop_BuyCow[];
extern char const gText_LivestockShop_BuySheep[];
extern char const gText_LivestockShop_SellCow[];
extern char const gText_LivestockShop_SellSheep[];
extern LivestockShopCatalogEntry const gLivestockShopCatalog[];

extern u8 const gUnk_08751B4C[];
extern u16 const gUnk_08751BCC[];
extern u8 const gUnk_0875320C[];
extern u16 const gUnk_0875328C[];
extern u8 const gUnk_0875254C[];
extern u16 const gUnk_087525CC[];

extern char const gText_LivestockShop_PageBreak[];
extern char const gText_LivestockShop_StatusSick[];
extern char const gText_LivestockShop_StatusUnhappy[];
extern char const gText_LivestockShop_StatusHealthy[];
extern char const gText_LivestockShop_StatusSpacer[];
extern char const gText_LivestockShop_Age[];
extern char const gText_LivestockShop_Spring[];
extern char const gText_LivestockShop_Summer[];
extern char const gText_LivestockShop_Autumn[];
extern char const gText_LivestockShop_Winter[];
extern char const gText_LivestockShop_DailySellingPrice[];
extern char const gText_LivestockShop_Currency[];
extern char const gText_LivestockShop_SecondaryDailySellingPrice[];

#if defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_LivestockShop_SecondaryStatusSick[];
extern char const gText_LivestockShop_SecondaryAge[];
#endif

extern char const gText_LivestockShop_InsufficientGold[];
extern char const gText_LivestockShop_FeedBinFull[];
extern char const gText_LivestockShop_BlankLinePair[];
extern char const gText_LivestockShop_InventoryFull[];
extern char const gText_LivestockShop_BarnFull[];
extern char const gText_LivestockShop_NameAnimalPrompt[];
extern char const gText_LivestockShop_NoCowsToSell[];
extern char const gText_LivestockShop_NoSheepToSell[];
extern char const gText_LivestockShop_ComeAgain[];
extern char const gText_LivestockShop_PurchaseConfirmation[];
extern char const gText_LivestockShop_Yes[];
extern char const gText_LivestockShop_No[];
extern char const gText_LivestockShop_FeedPurchaseComplete[];
extern char const gText_LivestockShop_PurchaseDeliveryPartial[];
extern char const gText_LivestockShop_PurchaseDeliveryAll[];
extern char const gText_LivestockShop_PurchaseComplete[];
extern char const gText_LivestockShop_AnimalPurchaseComplete[];
extern char const gText_LivestockShop_PurchaseMorePrompt[];
extern char const gText_LivestockShop_PurchaseDeclinedPrefix[];
#if defined(REGION_DE)
extern char const gText_LivestockShop_AnimalDeliveryLineBreak[];
#endif
extern char const gText_LivestockShop_AnimalDelivery[];

#if defined(REGION_JP)
extern char const gText_LivestockShop_PricePrompt[];
#elif defined(REGION_US) || defined(REGION_EU) || defined(REGION_DE)
extern char const gText_LivestockShop_PricePromptPrefix[];
extern char const gText_LivestockShop_PricePromptSuffix[];
#endif

#endif // SCENE_YODEL_RANCH_SHOP_HH
