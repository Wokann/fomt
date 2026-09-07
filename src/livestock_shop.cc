#include "livestock_shop.hh"

/*
 * The source order is the ROM order: menu text, catalog, status text, then
 * dialogue text.  Regional prose lives in data/text; these includes deliberately
 * make one physical source object so the catalog stays between its text groups.
 */
#define FOMT_LIVESTOCK_SHOP_TEXT_MENU
#if defined(REGION_JP)
#include "data/text/jp/livestock_shop.cc"
#else
#include "data/text/us/livestock_shop.cc"
#endif
#undef FOMT_LIVESTOCK_SHOP_TEXT_MENU

LivestockShopCatalogEntry const gLivestockShopCatalog[] = {
    { 0x5B, gText_LivestockShop_Empty, 20, gText_LivestockShop_Empty, 0 },
    { 0x01, gText_LivestockShop_BuyCow, 5000, gText_LivestockShop_BuyCow, 1 },
    { 0x02, gText_LivestockShop_BuySheep, 4000, gText_LivestockShop_BuySheep, 1 },
    { 0x30, gText_LivestockShop_Empty, 3000, gText_LivestockShop_Empty, 2 },
    { 0x31, gText_LivestockShop_Empty, 3000, gText_LivestockShop_Empty, 2 },
    { 0x4A, gText_LivestockShop_Empty, 1000, gText_LivestockShop_Empty, 2 },
    { 0x49, gText_LivestockShop_Empty, 500, gText_LivestockShop_Empty, 2 },
    { 0x07, gText_LivestockShop_SellCow, 0, gText_LivestockShop_SellCow, 3 },
    { 0x08, gText_LivestockShop_SellSheep, 0, gText_LivestockShop_SellSheep, 3 },
    { 0x09, gText_LivestockShop_Empty, 0, gText_LivestockShop_Empty, 4 },
    { 0x0A, gText_LivestockShop_Empty, 0, gText_LivestockShop_Empty, 4 },
};

#define FOMT_LIVESTOCK_SHOP_TEXT_STATUS
#if defined(REGION_JP)
#include "data/text/jp/livestock_shop.cc"
#else
#include "data/text/us/livestock_shop.cc"
#endif
#undef FOMT_LIVESTOCK_SHOP_TEXT_STATUS

#define FOMT_LIVESTOCK_SHOP_TEXT_DIALOGUE
#if defined(REGION_JP)
#include "data/text/jp/livestock_shop.cc"
#else
#include "data/text/us/livestock_shop.cc"
#endif
#undef FOMT_LIVESTOCK_SHOP_TEXT_DIALOGUE
