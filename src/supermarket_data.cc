#include "supermarket_data.hh"

#include "item.hh"

SupermarketCatalogEntry const gSupermarketCropSeedCatalog[] = {
    { ITEM_TOOL_SEEDS_TURNIP, 120 },
    { ITEM_TOOL_SEEDS_POTATO, 150 },
    { ITEM_TOOL_SEEDS_CUCUMBER, 200 },
    { ITEM_TOOL_SEEDS_STRAWBERRY, 150 },
    { ITEM_TOOL_SEEDS_TOMATO, 200 },
    { ITEM_TOOL_SEEDS_CORN, 300 },
    { ITEM_TOOL_SEEDS_ONION, 150 },
    { ITEM_TOOL_SEEDS_PUMPKIN, 500 },
    { ITEM_TOOL_SEEDS_EGGPLANT, 120 },
    { ITEM_TOOL_SEEDS_CARROT, 300 },
    { ITEM_TOOL_SEEDS_SWEET_POTATO, 300 },
    { ITEM_TOOL_SEEDS_SPINACH, 200 },
    { ITEM_TOOL_SEEDS_GRASS, 500 },
};

#include FOMT_TEXT_INCLUDE(supermarket_data.cc)

SupermarketCatalogEntry const gSupermarketAdditionalSeedCatalog[] = {
    { ITEM_TOOL_SEEDS_SPINACH, 100 },
    { ITEM_TOOL_SEEDS_GREEN_PEPPER, 100 },
    { ITEM_TOOL_SEEDS_GRASS, 50 },
    { ITEM_TOOL_SEEDS_MOON_DROP, 50 },
    { ITEM_TOOL_SEEDS_PINK_CAT, 50 },
    { ITEM_TOOL_SEEDS_MAGIC, 100 },
    { ITEM_TOOL_SEEDS_TOY_FLOWER, 100 },
    { 0, 0 },
};

#include FOMT_TEXT_INCLUDE(supermarket_data_1.cc)
#include "data/text/common/supermarket_data_1.cc"
