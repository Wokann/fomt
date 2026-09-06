#include "supermarket_text.hh"

#include "item.hh"

SupermarketCatalogEntry const gSupermarketCropSeedCatalog[] SUPERMARKET_CROP_CATALOG = {
    { TOOL_TURNIP_SEEDS, 120 },
    { TOOL_POTATO_SEEDS, 150 },
    { TOOL_CUCUMBER_SEEDS, 200 },
    { TOOL_STRAWBERRY_SEEDS, 150 },
    { TOOL_TOMATO_SEEDS, 200 },
    { TOOL_CORN_SEEDS, 300 },
    { TOOL_ONION_SEEDS, 150 },
    { TOOL_PUMPKIN_SEEDS, 500 },
    { TOOL_EGGPLANT_SEEDS, 120 },
    { TOOL_CARROT_SEEDS, 300 },
    { TOOL_SWEET_POTATO_SEEDS, 300 },
    { TOOL_SPINACH_SEEDS, 200 },
    { TOOL_GRASS_SEEDS, 500 },
};

SupermarketCatalogEntry const gSupermarketAdditionalSeedCatalog[] SUPERMARKET_ADDITIONAL_SEED_CATALOG = {
    { TOOL_SPINACH_SEEDS, 100 },
    { TOOL_GREEN_PEPPER_SEEDS, 100 },
    { TOOL_GRASS_SEEDS, 50 },
    { TOOL_MOON_DROP_SEEDS, 50 },
    { TOOL_PINK_CAT_SEEDS, 50 },
    { TOOL_MAGIC_SEEDS, 100 },
    { TOOL_TOY_FLOWER_SEEDS, 100 },
    { 0, 0 },
};
