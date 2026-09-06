#include "livestock_shop_text.hh"

#include "item.hh"

// This table stays in a common source file so its pointer fields keep real
// relocations to the selected JP or US text object rather than compiler-made
// copies of a same-translation-unit string literal.
LivestockShopCatalogEntry const gLivestockShopCatalog[] LIVESTOCK_SHOP_CATALOG = {
    { ARTICLE_ANIMAL_FODDER, gText_LivestockShop_Empty, 20, gText_LivestockShop_Empty, 0 },
    { 1, gText_LivestockShop_BuyCow, 5000, gText_LivestockShop_BuyCow, 1 },
    { 2, gText_LivestockShop_BuySheep, 4000, gText_LivestockShop_BuySheep, 1 },
    { TOOL_COW_MIRACLE_POTION, gText_LivestockShop_Empty, 3000, gText_LivestockShop_Empty, 2 },
    { TOOL_SHEEP_MIRACLE_POTION, gText_LivestockShop_Empty, 3000, gText_LivestockShop_Empty, 2 },
    { TOOL_ANIMAL_MEDICINE, gText_LivestockShop_Empty, 1000, gText_LivestockShop_Empty, 2 },
    { TOOL_BELL, gText_LivestockShop_Empty, 500, gText_LivestockShop_Empty, 2 },
    { 7, gText_LivestockShop_SellCow, 0, gText_LivestockShop_SellCow, 3 },
    { 8, gText_LivestockShop_SellSheep, 0, gText_LivestockShop_SellSheep, 3 },
    { 9, gText_LivestockShop_Empty, 0, gText_LivestockShop_Empty, 4 },
    { 10, gText_LivestockShop_Empty, 0, gText_LivestockShop_Empty, 4 },
};
