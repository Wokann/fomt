#ifndef INN_SHOP_TEXT_HH
#define INN_SHOP_TEXT_HH

#include "prelude.h"

// The inn menu stores seven contiguous 32-bit fields for each dish.  The
// first field is passed directly to FoodUi.  The final three values are still
// menu-owned data until their meaning is recovered, but the text pointer and
// override flag are known from the call sites.
struct InnShopMenuEntry
{
    u32 food_ui_id;
    u32 price;
    char const * description_override;
    u32 uses_description_override;
    u32 field_10;
    int field_14;
    u32 field_18;
};

#define INN_SHOP_DESCRIPTIONS SECTION(".rodata.inn_shop_descriptions")
#define INN_SHOP_CATALOG SECTION(".rodata.inn_shop_catalog")
#define INN_SHOP_DIALOGUE SECTION(".rodata.inn_shop_dialogue")

extern InnShopMenuEntry const gInnShopMenu[];

extern char const gText_InnShop_WaterDescription[];
extern char const gText_InnShop_BoxLunchDescription[];
extern char const gText_InnShop_Empty[];
extern char const gText_InnShop_MilkDescription[];
extern char const gText_InnShop_InsufficientGold[];
extern char const gText_InnShop_NoOrder[];
extern char const gText_InnShop_OrderComplete[];

#endif // INN_SHOP_TEXT_HH
