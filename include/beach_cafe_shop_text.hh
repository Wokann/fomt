#ifndef BEACH_CAFE_SHOP_TEXT_HH
#define BEACH_CAFE_SHOP_TEXT_HH

#include "prelude.h"

// The cafe menu stores seven contiguous 32-bit fields for each item.  The
// first field is passed directly to FoodUi.  The final three values are still
// menu-owned data until their meaning is recovered, but the text pointer and
// override flag are known from the call sites.
struct BeachCafeShopMenuEntry
{
    u32 food_ui_id;
    u32 price;
    char const * description_override;
    u32 uses_description_override;
    u32 field_10;
    int field_14;
    u32 field_18;
};

#define BEACH_CAFE_SHOP_DESCRIPTIONS SECTION(".rodata.beach_cafe_shop_descriptions")
#define BEACH_CAFE_SHOP_CATALOG SECTION(".rodata.beach_cafe_shop_catalog")
#define BEACH_CAFE_SHOP_DIALOGUE SECTION(".rodata.beach_cafe_shop_dialogue")

extern BeachCafeShopMenuEntry const gBeachCafeShopMenu[];

extern char const gText_BeachCafeShop_WaterDescription[];
extern char const gText_BeachCafeShop_EmptyDescription[];
extern char const gText_BeachCafeShop_SpaghettiDescription[];
extern char const gText_BeachCafeShop_SnowConeDescription[];
extern char const gText_BeachCafeShop_InsufficientGold[];
extern char const gText_BeachCafeShop_NoOrder[];
extern char const gText_BeachCafeShop_OrderComplete[];
extern char const gCppRuntimeBadAlloc_BeachCafeShopTrailer[];

#endif // BEACH_CAFE_SHOP_TEXT_HH
