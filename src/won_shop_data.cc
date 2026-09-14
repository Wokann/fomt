#include "won_shop_data.hh"

#include "item.hh"

WonShopCatalogEntry const gWonShopCatalog[] = {
    { ITEM_ARTICLE_BALL, 100 },
    { ITEM_ARTICLE_FRISBEE, 5000 },
    { ITEM_ARTICLE_JEWEL_OF_TRUTH, 50000 },
    { ITEM_TOOL_SEEDS_CABBAGE, 500 },
    { ITEM_TOOL_SEEDS_PINEAPPLE, 1000 },
    { ITEM_TOOL_SEEDS_GREEN_PEPPER, 150 },
    { ITEM_TOOL_SEEDS_MOON_DROP, 500 },
    { ITEM_TOOL_SEEDS_PINK_CAT, 300 },
    { ITEM_TOOL_SEEDS_MAGIC, 600 },
    { ITEM_TOOL_SEEDS_TOY_FLOWER, 400 },
};

#include FOMT_TEXT_INCLUDE(won_shop_data.cc)
