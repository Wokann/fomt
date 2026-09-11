#include "won_shop_text.hh"

#include "item.hh"

WonShopCatalogEntry const gWonShopCatalog[] = {
    { ARTICLE_BALL, 100 },
    { ARTICLE_FRISBEE, 5000 },
    { ARTICLE_JEWEL_OF_TRUTH, 50000 },
    { TOOL_CABBAGE_SEEDS, 500 },
    { TOOL_PINEAPPLE_SEEDS, 1000 },
    { TOOL_GREEN_PEPPER_SEEDS, 150 },
    { TOOL_MOON_DROP_SEEDS, 500 },
    { TOOL_PINK_CAT_SEEDS, 300 },
    { TOOL_MAGIC_SEEDS, 600 },
    { TOOL_TOY_FLOWER_SEEDS, 400 },
};

#if defined(REGION_JP)
#include FOMT_TEXT_INCLUDE(won_shop.cc)
#else
#include FOMT_TEXT_INCLUDE(won_shop.cc)
#endif
