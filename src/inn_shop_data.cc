#include "inn_shop_text.hh"

#if defined(REGION_JP)
#define FOMT_TEXT_INN_SHOP_DESCRIPTIONS
#include FOMT_TEXT_INCLUDE(inn_shop.cc)
#undef FOMT_TEXT_INN_SHOP_DESCRIPTIONS
#else
#define FOMT_TEXT_INN_SHOP_DESCRIPTIONS
#include FOMT_TEXT_INCLUDE(inn_shop.cc)
#undef FOMT_TEXT_INN_SHOP_DESCRIPTIONS
#endif

InnShopMenuEntry const gInnShopMenu[] = {
    { 0x1CD, 0, gText_InnShop_WaterDescription, 1, 1, 0, 1 },
    { 0x191, 500, gText_InnShop_BoxLunchDescription, 1, 100, -20, 0 },
    { 0x4C, 300, gText_InnShop_Empty, 0, 20, -30, 0 },
    { 0x73, 300, gText_InnShop_Empty, 0, 50, -3, 0 },
    { 0x71, 250, gText_InnShop_Empty, 0, 40, -3, 0 },
    { 0x8B, 200, gText_InnShop_Empty, 0, 20, -3, 0 },
    { 0x4B, 500, gText_InnShop_Empty, 0, 1, -40, 0 },
    { 0x64, 300, gText_InnShop_Empty, 0, 3, -30, 0 },
    { 0x122, 200, gText_InnShop_MilkDescription, 1, 3, -20, 1 },
};

#if defined(REGION_JP)
#define FOMT_TEXT_INN_SHOP_DIALOGUE
#include FOMT_TEXT_INCLUDE(inn_shop.cc)
#undef FOMT_TEXT_INN_SHOP_DIALOGUE
#else
#define FOMT_TEXT_INN_SHOP_DIALOGUE
#include FOMT_TEXT_INCLUDE(inn_shop.cc)
#undef FOMT_TEXT_INN_SHOP_DIALOGUE
#endif
