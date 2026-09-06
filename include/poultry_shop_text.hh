#ifndef POULTRY_SHOP_TEXT_HH
#define POULTRY_SHOP_TEXT_HH

#include "prelude.h"

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

#define POULTRY_SHOP_MENU SECTION(".rodata.poultry_shop_menu")
#define POULTRY_SHOP_CATALOG SECTION(".rodata.poultry_shop_catalog")
#define POULTRY_SHOP_STATUS_PREFIX SECTION(".rodata.poultry_shop_status_prefix")
#define POULTRY_SHOP_STATUS SECTION(".rodata.poultry_shop_status")
#define POULTRY_SHOP_DIALOGUE SECTION(".rodata.poultry_shop_dialogue")

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
#endif

#endif // POULTRY_SHOP_TEXT_HH
