#ifndef SPECIAL_MERCHANT_SHOP_TEXT_HH
#define SPECIAL_MERCHANT_SHOP_TEXT_HH

#include "prelude.h"

struct SpecialMerchantShopCatalogEntry
{
    u32 item_id;
    u32 price;
};

// The original entry at index 10 is handled as a Record Player rather than
// as an ArticleUi item.  Its first word is a catalog sentinel, not a tool ID.
enum
{
    SPECIAL_MERCHANT_RECORD_PLAYER_SENTINEL = 10,
};

#define SPECIAL_MERCHANT_SHOP_CATALOG SECTION(".rodata.special_merchant_shop_catalog")
#define SPECIAL_MERCHANT_SHOP_TEXT SECTION(".rodata.special_merchant_shop_text")

extern SpecialMerchantShopCatalogEntry const gSpecialMerchantShopCatalog[];

extern char const gText_SpecialMerchantShop_RecordPlayerDescription[];
extern char const gText_SpecialMerchantShop_InsufficientGold[];
extern char const gText_SpecialMerchantShop_InventoryFull[];
extern char const gText_SpecialMerchantShop_BlankLinePair[];
extern char const gText_SpecialMerchantShop_PurchaseComplete[];
extern char const gText_SpecialMerchantShop_RecordPlayerDelivery[];
extern char const gText_SpecialMerchantShop_PurchaseCompleteShort[];
extern char const gText_SpecialMerchantShop_ArticleDelivery[];
extern char const gText_SpecialMerchantShop_PurchaseMorePrompt[];

#endif // SPECIAL_MERCHANT_SHOP_TEXT_HH
