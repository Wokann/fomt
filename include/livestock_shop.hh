#ifndef LIVESTOCK_SHOP_HH
#define LIVESTOCK_SHOP_HH

#include "prelude.h"

// Each original catalog entry is five 32-bit fields.  Native callers establish
// the two text fields and price; the first and last fields have not yet been
// given reliable semantic names.
struct LivestockShopCatalogEntry
{
    u32 unk_00;
    char const * primary_text;
    u32 price;
    char const * secondary_text;
    u32 unk_10;
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

#if defined(REGION_WESTERN)
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
#else
extern char const gText_LivestockShop_PricePromptPrefix[];
extern char const gText_LivestockShop_PricePromptSuffix[];
#endif

#endif // LIVESTOCK_SHOP_HH
