#ifndef FIELD_TOOL_HH
#define FIELD_TOOL_HH

#include "prelude.h"

struct Tool;

// Crop ids produced by the sowing routine. The original fallback is weeds.
enum SeedCropId {
    SEED_CROP_TURNIP = 0,
    SEED_CROP_POTATO = 1,
    SEED_CROP_CUCUMBER = 2,
    SEED_CROP_STRAWBERRY = 3,
    SEED_CROP_CABBAGE = 4,
    SEED_CROP_TOMATO = 5,
    SEED_CROP_CORN = 6,
    SEED_CROP_ONION = 7,
    SEED_CROP_PUMPKIN = 8,
    SEED_CROP_PINEAPPLE = 9,
    SEED_CROP_EGGPLANT = 10,
    SEED_CROP_CARROT = 11,
    SEED_CROP_SWEET_POTATO = 12,
    SEED_CROP_SPINACH = 13,
    SEED_CROP_GREEN_PEPPER = 14,
    SEED_CROP_MOON_DROP = 15,
    SEED_CROP_PINK_CAT = 16,
    SEED_CROP_MAGIC_BLUE = 17,
    SEED_CROP_MAGIC_RED = 18,
    SEED_CROP_TOY_FLOWER = 19,
    SEED_CROP_GRASS = 20,
    SEED_CROP_WEEDS = 21,
};

EXTERN_C
SeedCropId GetCropForSeed(int tool_id);
u32 AccumulateMaxWateringCanTier(u32 max_tier, Tool const & tool);
EXTERN_C_END

#endif // FIELD_TOOL_HH
