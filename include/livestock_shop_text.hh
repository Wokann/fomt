#ifndef LIVESTOCK_SHOP_TEXT_HH
#define LIVESTOCK_SHOP_TEXT_HH

#include "prelude.h"

// Each original catalog entry is five 32-bit fields.  The first and last
// fields are still caller-owned mode values; the two middle pointers are
// deliberately retained as distinct fields even when they target one string.
struct LivestockShopCatalogEntry
{
    u32 code;
    char const * primary_text;
    u32 price;
    char const * secondary_text;
    u32 mode;
};

#define LIVESTOCK_SHOP_MENU SECTION(".rodata.livestock_shop_menu")
#define LIVESTOCK_SHOP_CATALOG SECTION(".rodata.livestock_shop_catalog")
#define LIVESTOCK_SHOP_STATUS_PREFIX SECTION(".rodata.livestock_shop_status_prefix")
#define LIVESTOCK_SHOP_STATUS SECTION(".rodata.livestock_shop_status")
#define LIVESTOCK_SHOP_DIALOGUE SECTION(".rodata.livestock_shop_dialogue")

extern char const gText_LivestockShop_Empty[];
extern char const gText_LivestockShop_BuyCow[];
extern char const gText_LivestockShop_BuySheep[];
extern char const gText_LivestockShop_SellCow[];
extern char const gText_LivestockShop_SellSheep[];
extern LivestockShopCatalogEntry const gLivestockShopCatalog[];

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

#if defined(REGION_US)
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
extern char const gText_LivestockShop_AnimalDelivery[];

#if defined(REGION_JP)
extern char const gText_LivestockShop_PricePrompt[];
#else
extern char const gText_LivestockShop_PricePromptPrefix[];
extern char const gText_LivestockShop_PricePromptSuffix[];
#endif

#endif // LIVESTOCK_SHOP_TEXT_HH
