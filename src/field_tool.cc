#include "field_tool.hh"

#include "fomt_constants.hh"
#include "item.hh"

#include <stdlib.h>

SeedCropId GetCropForSeed(int tool_id)
{
    switch (tool_id) {
    case ITEM_TOOL_SEEDS_TURNIP: return SEED_CROP_TURNIP;
    case ITEM_TOOL_SEEDS_POTATO: return SEED_CROP_POTATO;
    case ITEM_TOOL_SEEDS_CUCUMBER: return SEED_CROP_CUCUMBER;
    case ITEM_TOOL_SEEDS_STRAWBERRY: return SEED_CROP_STRAWBERRY;
    case ITEM_TOOL_SEEDS_CABBAGE: return SEED_CROP_CABBAGE;
    case ITEM_TOOL_SEEDS_TOMATO: return SEED_CROP_TOMATO;
    case ITEM_TOOL_SEEDS_CORN: return SEED_CROP_CORN;
    case ITEM_TOOL_SEEDS_ONION: return SEED_CROP_ONION;
    case ITEM_TOOL_SEEDS_PUMPKIN: return SEED_CROP_PUMPKIN;
    case ITEM_TOOL_SEEDS_PINEAPPLE: return SEED_CROP_PINEAPPLE;
    case ITEM_TOOL_SEEDS_EGGPLANT: return SEED_CROP_EGGPLANT;
    case ITEM_TOOL_SEEDS_CARROT: return SEED_CROP_CARROT;
    case ITEM_TOOL_SEEDS_SWEET_POTATO: return SEED_CROP_SWEET_POTATO;
    case ITEM_TOOL_SEEDS_SPINACH: return SEED_CROP_SPINACH;
    case ITEM_TOOL_SEEDS_GREEN_PEPPER: return SEED_CROP_GREEN_PEPPER;
    case ITEM_TOOL_SEEDS_GRASS: return SEED_CROP_GRASS;
    case ITEM_TOOL_SEEDS_MOON_DROP: return SEED_CROP_MOON_DROP;
    case ITEM_TOOL_SEEDS_PINK_CAT: return SEED_CROP_PINK_CAT;
    case ITEM_TOOL_SEEDS_MAGIC:
    {
        // Preserve the original random arithmetic and byte-sized choice.
        u8 choice = rand() % 1000 / 10;
        if (choice <= 4)
            return SEED_CROP_MAGIC_RED;
        return SEED_CROP_MAGIC_BLUE;
    }
    case ITEM_TOOL_SEEDS_TOY_FLOWER: return SEED_CROP_TOY_FLOWER;
    default: return SEED_CROP_WEEDS;
    }
}

u32 AccumulateMaxWateringCanTier(u32 max_tier, Tool const & tool)
{
    u32 tier;
    switch (tool.GetId()) {
    case ITEM_TOOL_WATERING_CAN_IRON: tier = 0; break;
    case ITEM_TOOL_WATERING_CAN_COPPER: tier = 1; break;
    case ITEM_TOOL_WATERING_CAN_SILVER: tier = 2; break;
    case ITEM_TOOL_WATERING_CAN_GOLD: tier = 3; break;
    case ITEM_TOOL_WATERING_CAN_MYSTRILE: tier = 4; break;
    case ITEM_TOOL_WATERING_CAN_CURSED:
    case ITEM_TOOL_WATERING_CAN_BLESSED: tier = 5; break;
    case ITEM_TOOL_WATERING_CAN_MYTHIC: tier = 6; break;
    default: return max_tier;
    }
    if (tier > max_tier)
        max_tier = tier;
    return max_tier;
}
