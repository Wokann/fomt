#ifndef ITEM_HH
#define ITEM_HH

#include "prelude.h"

enum
{
    /* 0x00 */ TOOL_IRON_SICKLE,
    /* 0x01 */ TOOL_COPPER_SICKLE,
    /* 0x02 */ TOOL_SILVER_SICKLE,
    /* 0x03 */ TOOL_GOLD_SICKLE,
    /* 0x04 */ TOOL_MYSTRILE_SICKLE,
    /* 0x05 */ TOOL_CURSED_SICKLE,
    /* 0x06 */ TOOL_BLESSED_SICKLE,
    /* 0x07 */ TOOL_MYTHIC_SICKLE,
    /* 0x08 */ TOOL_IRON_HOE,
    /* 0x09 */ TOOL_COPPER_HOE,
    /* 0x0A */ TOOL_SILVER_HOE,
    /* 0x0B */ TOOL_GOLD_HOE,
    /* 0x0C */ TOOL_MYSTRILE_HOE,
    /* 0x0D */ TOOL_CURSED_HOE,
    /* 0x0E */ TOOL_BLESSED_HOE,
    /* 0x0F */ TOOL_MYTHIC_HOE,
    /* 0x10 */ TOOL_IRON_AXE,
    /* 0x11 */ TOOL_COPPER_AXE,
    /* 0x12 */ TOOL_SILVER_AXE,
    /* 0x13 */ TOOL_GOLD_AXE,
    /* 0x14 */ TOOL_MYSTRILE_AXE,
    /* 0x15 */ TOOL_CURSED_AXE,
    /* 0x16 */ TOOL_BLESSED_AXE,
    /* 0x17 */ TOOL_MYTHIC_AXE,
    /* 0x18 */ TOOL_IRON_HAMMER,
    /* 0x19 */ TOOL_COPPER_HAMMER,
    /* 0x1A */ TOOL_SILVER_HAMMER,
    /* 0x1B */ TOOL_GOLD_HAMMER,
    /* 0x1C */ TOOL_MYSTRILE_HAMMER,
    /* 0x1D */ TOOL_CURSED_HAMMER,
    /* 0x1E */ TOOL_BLESSED_HAMMER,
    /* 0x1F */ TOOL_MYTHIC_HAMMER,
    /* 0x20 */ TOOL_WATERING_CAN,
    /* 0x21 */ TOOL_COPPER_WATERING_CAN,
    /* 0x22 */ TOOL_SILVER_WATERING_CAN,
    /* 0x23 */ TOOL_GOLD_WATERING_CAN,
    /* 0x24 */ TOOL_MYSTRILE_WATERING_CAN,
    /* 0x25 */ TOOL_CURSED_WATERING_CAN,
    /* 0x26 */ TOOL_BLESSED_WATERING_CAN,
    /* 0x27 */ TOOL_MYTHIC_WATERING_CAN,
    /* 0x28 */ TOOL_FISHING_ROD,
    /* 0x29 */ TOOL_COPPER_FISHING_ROD,
    /* 0x2A */ TOOL_SILVER_FISHING_ROD,
    /* 0x2B */ TOOL_GOLD_FISHING_ROD,
    /* 0x2C */ TOOL_MYSTRILE_FISHING_ROD,
    /* 0x2D */ TOOL_CURSED_FISHING_ROD,
    /* 0x2E */ TOOL_BLESSED_FISHING_ROD,
    /* 0x2F */ TOOL_MYTHIC_FISHING_ROD,
    /* 0x30 */ TOOL_COW_MIRACLE_POTION,
    /* 0x31 */ TOOL_SHEEP_MIRACLE_POTION,
    /* 0x32 */ TOOL_TURNIP_SEEDS,
    /* 0x33 */ TOOL_POTATO_SEEDS,
    /* 0x34 */ TOOL_CUCUMBER_SEEDS,
    /* 0x35 */ TOOL_STRAWBERRY_SEEDS,
    /* 0x36 */ TOOL_CABBAGE_SEEDS,
    /* 0x37 */ TOOL_TOMATO_SEEDS,
    /* 0x38 */ TOOL_CORN_SEEDS,
    /* 0x39 */ TOOL_ONION_SEEDS,
    /* 0x3A */ TOOL_PUMPKIN_SEEDS,
    /* 0x3B */ TOOL_PINEAPPLE_SEEDS,
    /* 0x3C */ TOOL_EGGPLANT_SEEDS,
    /* 0x3D */ TOOL_CARROT_SEEDS,
    /* 0x3E */ TOOL_SWEET_POTATO_SEEDS,
    /* 0x3F */ TOOL_SPINACH_SEEDS,
    /* 0x40 */ TOOL_GREEN_PEPPER_SEEDS,
    /* 0x41 */ TOOL_GRASS_SEEDS,
    /* 0x42 */ TOOL_MOON_DROP_SEEDS,
    /* 0x43 */ TOOL_PINK_CAT_SEEDS,
    /* 0x44 */ TOOL_MAGIC_SEEDS,
    /* 0x45 */ TOOL_TOY_FLOWER_SEEDS,
    /* 0x46 */ TOOL_BRUSH,
    /* 0x47 */ TOOL_MILKER,
    /* 0x48 */ TOOL_CLIPPER,
    /* 0x49 */ TOOL_BELL,
    /* 0x4A */ TOOL_ANIMAL_MEDICINE,
    /* 0x4B */ TOOL_BLUE_FEATHER,
    /* 0x4C */ TOOL_PEDOMETER,
    /* 0x4D */ TOOL_TELEPORT_STONE,
    /* 0x4E */ TOOL_GEM_OF_THE_GODDESS,
    /* 0x4F */ TOOL_GEM_OF_THE_KAPPA,
    /* 0x50 */ TOOL_GEM_OF_TRUTH,

    TOOL_NONE,
    NUM_TOOLS = TOOL_NONE,
};

enum
{
    /* 0x00 */ FOOD_TURNIP,
    /* 0x01 */ FOOD_POTATO,
    /* 0x02 */ FOOD_CUCUMBER,
    /* 0x03 */ FOOD_STRAWBERRY,
    /* 0x04 */ FOOD_CABBAGE,
    /* 0x05 */ FOOD_TOMATO,
    /* 0x06 */ FOOD_CORN,
    /* 0x07 */ FOOD_ONION,
    /* 0x08 */ FOOD_PUMPKIN,
    /* 0x09 */ FOOD_PINEAPPLE,
    /* 0x0A */ FOOD_EGGPLANT,
    /* 0x0B */ FOOD_CARROT,
    /* 0x0C */ FOOD_SWEET_POTATO,
    /* 0x0D */ FOOD_SPINACH,
    /* 0x0E */ FOOD_GREEN_PEPPER,
    /* 0x0F */ FOOD_REGULAR_QUALITY_EGG,
    /* 0x10 */ FOOD_GOOD_QUALITY_EGG,
    /* 0x11 */ FOOD_HIGH_QUALITY_EGG,
    /* 0x12 */ FOOD_GOLDEN_EGG,
    /* 0x13 */ FOOD_P_EGG,
    /* 0x14 */ FOOD_X_EGG,
    /* 0x15 */ FOOD_SPABOILED_EGG,
    /* 0x16 */ FOOD_MAYONNAISE_S,
    /* 0x17 */ FOOD_MAYONNAISE_M,
    /* 0x18 */ FOOD_MAYONNAISE_L,
    /* 0x19 */ FOOD_MAYONNAISE_G,
    /* 0x1A */ FOOD_MAYONNAISE_P,
    /* 0x1B */ FOOD_MAYONNAISE_X,
    /* 0x1C */ FOOD_MILK_S,
    /* 0x1D */ FOOD_MILK_M,
    /* 0x1E */ FOOD_MILK_L,
    /* 0x1F */ FOOD_MILK_G,
    /* 0x20 */ FOOD_MILK_P,
    /* 0x21 */ FOOD_MILK_X,
    /* 0x22 */ FOOD_CHEESE_S,
    /* 0x23 */ FOOD_CHEESE_M,
    /* 0x24 */ FOOD_CHEESE_L,
    /* 0x25 */ FOOD_CHEESE_G,
    /* 0x26 */ FOOD_CHEESE_P,
    /* 0x27 */ FOOD_CHEESE_X,
    /* 0x28 */ FOOD_APPLE,
    /* 0x29 */ FOOD_HONEY,
    /* 0x2A */ FOOD_BAMBOO_SHOOT,
    /* 0x2B */ FOOD_WILD_GRAPES,
    /* 0x2C */ FOOD_MUSHROOM,
    /* 0x2D */ FOOD_POISONOUS_MUSHROOM,
    /* 0x2E */ FOOD_TRUFFLE,
    /* 0x2F */ FOOD_BLUE_GRASS,
    /* 0x30 */ FOOD_GREEN_GRASS,
    /* 0x31 */ FOOD_RED_GRASS,
    /* 0x32 */ FOOD_YELLOW_GRASS,
    /* 0x33 */ FOOD_ORANGE_GRASS,
    /* 0x34 */ FOOD_PURPLE_GRASS,
    /* 0x35 */ FOOD_INDIGO_GRASS,
    /* 0x36 */ FOOD_BLACK_GRASS,
    /* 0x37 */ FOOD_WHITE_GRASS,
    /* 0x38 */ FOOD_QUEEN_OF_THE_NIGHT,
    /* 0x39 */ FOOD_BODIGIZER,
    /* 0x3A */ FOOD_BODIGIZER_XL,
    /* 0x3B */ FOOD_TURBOJOLT,
    /* 0x3C */ FOOD_TURBOJOLT_XL,
    /* 0x3D */ FOOD_WINE,
    /* 0x3E */ FOOD_GRAPE_JUICE,
    /* 0x3F */ FOOD_RICE_BALL,
    /* 0x40 */ FOOD_BREAD,
    /* 0x41 */ FOOD_OIL,
    /* 0x42 */ FOOD_FLOWER,
    /* 0x43 */ FOOD_CURRY_POWDER,
    /* 0x44 */ FOOD_MUFFIN_MIX,
    /* 0x45 */ FOOD_CHOCOLATE,
    /* 0x46 */ FOOD_RELAX_TEA_LEAVES,
    /* 0x47 */ FOOD_SUGDW_APPLE,
    /* 0x48 */ FOOD_HMSGB_APPLE,
    /* 0x49 */ FOOD_AEPFE_APPLE,
    /* 0x4A */ FOOD_BUCKWHEAT_FLOUR,
    /* 0x4B */ FOOD_WILD_GRAPE_JUICE,
    /* 0x4C */ FOOD_SALAD,
    /* 0x4D */ FOOD_CURRY_RICE,
    /* 0x4E */ FOOD_STEW,
    /* 0x4F */ FOOD_MISO_SOUP,
    /* 0x50 */ FOOD_STIR_FRY,
    /* 0x51 */ FOOD_FRIED_RICE,
    /* 0x52 */ FOOD_SAVORY_PANCAKE,
    /* 0x53 */ FOOD_SANDWICH,
    /* 0x54 */ FOOD_FRUIT_JUICE,
    /* 0x55 */ FOOD_VEGETABLE_JUICE,
    /* 0x56 */ FOOD_MIXED_JUICE,
    /* 0x57 */ FOOD_FRUIT_LATTE,
    /* 0x58 */ FOOD_VEGETABLE_LATTE,
    /* 0x59 */ FOOD_MIXED_LATTE,
    /* 0x5A */ FOOD_STRAWBERRY_MILK,
    /* 0x5B */ FOOD_STRAWBERRY_JAM,
    /* 0x5C */ FOOD_TOMATO_JUICE,
    /* 0x5D */ FOOD_PICKLED_TURNIP,
    /* 0x5E */ FOOD_FRENCH_FRIES,
    /* 0x5F */ FOOD_PICKLES,
    /* 0x60 */ FOOD_KETCHUP,
    /* 0x61 */ FOOD_POPCORN,
    /* 0x62 */ FOOD_CORN_FLAKES,
    /* 0x63 */ FOOD_BAKED_CORN,
    /* 0x64 */ FOOD_PINEAPPLE_JUICE,
    /* 0x65 */ FOOD_PUMPKIN_PUDDING,
    /* 0x66 */ FOOD_PUMPKIN_STEW,
    /* 0x67 */ FOOD_HAPPY_EGGPLANT,
    /* 0x68 */ FOOD_SWEET_POTATOES,
    /* 0x69 */ FOOD_BAKED_SWEET_POTATO,
    /* 0x6A */ FOOD_GREENS,
    /* 0x6B */ FOOD_SCRAMBLED_EGGS,
    /* 0x6C */ FOOD_OMELET,
    /* 0x6D */ FOOD_OMELET_RICE,
    /* 0x6E */ FOOD_BOILED_EGG,
    /* 0x6F */ FOOD_HOT_MILK,
    /* 0x70 */ FOOD_BUTTER,
    /* 0x71 */ FOOD_CHEESE_CAKE,
    /* 0x72 */ FOOD_CHEESE_FONDUE,
    /* 0x73 */ FOOD_APPLE_PIE,
    /* 0x74 */ FOOD_APPLE_JAM,
    /* 0x75 */ FOOD_APPLE_SOUFFL,
    /* 0x76 */ FOOD_MUSHROOM_RICE,
    /* 0x77 */ FOOD_BAMBOO_RICE,
    /* 0x78 */ FOOD_TRUFFLE_RICE,
    /* 0x79 */ FOOD_SUSHI,
    /* 0x7A */ FOOD_JAM_BUN,
    /* 0x7B */ FOOD_DINNER_ROLE,
    /* 0x7C */ FOOD_RAISIN_BREAD,
    /* 0x7D */ FOOD_GRAPE_JAM,
    /* 0x7E */ FOOD_CURRY_BREAD,
    /* 0x7F */ FOOD_SASHIMI,
    /* 0x80 */ FOOD_GRILLED_FISH,
    /* 0x81 */ FOOD_CHIRASHI_SUSHI,
    /* 0x82 */ FOOD_PIZZA,
    /* 0x83 */ FOOD_NOODLES,
    /* 0x84 */ FOOD_CURRY_NOODLES,
    /* 0x85 */ FOOD_TEMPURA_NOODLES,
    /* 0x86 */ FOOD_FRIED_NOODLES,
    /* 0x87 */ FOOD_BUCKWHEAT_NOODLES,
    /* 0x88 */ FOOD_NOODLES_W_TEMPURA,
    /* 0x89 */ FOOD_FRIED_NOODLES_2,
    /* 0x8A */ FOOD_BUCKWHEAT_CHIPS,
    /* 0x8B */ FOOD_COOKIES,
    /* 0x8C */ FOOD_CHOCOLATE_COOKIES,
    /* 0x8D */ FOOD_TEMPURA,
    /* 0x8E */ FOOD_ICE_CREAM,
    /* 0x8F */ FOOD_CAKE,
    /* 0x90 */ FOOD_CHOCOLATE_CAKE,
    /* 0x91 */ FOOD_RELAXATION_TEA,
    /* 0x92 */ FOOD_TOAST,
    /* 0x93 */ FOOD_FRENCH_TOAST,
    /* 0x94 */ FOOD_PUDDING,
    /* 0x95 */ FOOD_MOUNTAIN_STEW,
    /* 0x96 */ FOOD_MOON_DUMPLINGS,
    /* 0x97 */ FOOD_RICE_CAKE,
    /* 0x98 */ FOOD_ROASTED_RICE_CAKE,
    /* 0x99 */ FOOD_ELLI_LEAVES,
    /* 0x9A */ FOOD_FAILED_DISH,
    /* 0x9B */ FOOD_FAILED_DRINK,
    /* 0x9C */ FOOD_FAILED_POT_DISH,
    /* 0x9D */ FOOD_FAILED_DESSERT,
    /* 0x9E */ FOOD_FAILED_BREAD,
    /* 0x9F */ FOOD_FAILED_NOODLES,
    /* 0xA0 */ FOOD_SMALL_FISH,
    /* 0xA1 */ FOOD_MEDIUM_FISH,
    /* 0xA2 */ FOOD_LARGE_FISH,
    /* 0xA3 */ FOOD_TOASTED_RICE_BALL,
    /* 0xA4 */ FOOD_TEMPURA_RICE,
    /* 0xA5 */ FOOD_EGG_OVER_RICE,
    /* 0xA6 */ FOOD_RICE_GRUEL,
    /* 0xA7 */ FOOD_PANCAKES,
    /* 0xA8 */ FOOD_FISH_STICKS,
    /* 0xA9 */ FOOD_CANDIED_POTATO,
    /* 0xAA */ FOOD_POTATO_PANCAKES,

    FOOD_NONE,
    NUM_FOODS = FOOD_NONE,
};

enum
{
    /* 0x00 */ ARTICLE_MOON_DROP_GRASS,
    /* 0x01 */ ARTICLE_PINK_CAT_GRASS,
    /* 0x02 */ ARTICLE_BLUE_MAGIC_GRASS,
    /* 0x03 */ ARTICLE_RED_MAGIC_GRASS,
    /* 0x04 */ ARTICLE_TOY_FLOWER,
    /* 0x05 */ ARTICLE_WOOL_S,
    /* 0x06 */ ARTICLE_WOOL_M,
    /* 0x07 */ ARTICLE_WOOL_L,
    /* 0x08 */ ARTICLE_WOOL_G,
    /* 0x09 */ ARTICLE_WOOL_P,
    /* 0x0A */ ARTICLE_WOOL_X,
    /* 0x0B */ ARTICLE_YARN_S,
    /* 0x0C */ ARTICLE_YARN_M,
    /* 0x0D */ ARTICLE_YARN_L,
    /* 0x0E */ ARTICLE_YARN_G,
    /* 0x0F */ ARTICLE_YARN_P,
    /* 0x10 */ ARTICLE_YARN_X,
    /* 0x11 */ ARTICLE_JUNK_ORE,
    /* 0x12 */ ARTICLE_COPPER,
    /* 0x13 */ ARTICLE_SILVER,
    /* 0x14 */ ARTICLE_GOLD,
    /* 0x15 */ ARTICLE_MYSTRILE,
    /* 0x16 */ ARTICLE_ORICHALC,
    /* 0x17 */ ARTICLE_ADAMANTITE,
    /* 0x18 */ ARTICLE_MOON_STONE,
    /* 0x19 */ ARTICLE_SAND_ROSE,
    /* 0x1A */ ARTICLE_PINK_DIAMOND,
    /* 0x1B */ ARTICLE_ALEXANDRITE,
    /* 0x1C */ ARTICLE_MYTHIC_STONE,
    /* 0x1D */ ARTICLE_DIAMOND,
    /* 0x1E */ ARTICLE_EMERALD,
    /* 0x1F */ ARTICLE_RUBY,
    /* 0x20 */ ARTICLE_TOPAZ,
    /* 0x21 */ ARTICLE_PERIDOT,
    /* 0x22 */ ARTICLE_FLUORITE,
    /* 0x23 */ ARTICLE_AGATE,
    /* 0x24 */ ARTICLE_AMETHYST,
    /* 0x25 */ ARTICLE_HARVEST_GODDESS_JEWEL,
    /* 0x26 */ ARTICLE_KAPPA_JEWEL,
    /* 0x27 */ ARTICLE_JEWEL_OF_TRUTH,
    /* 0x28 */ ARTICLE_THE_SPRING_SUN,
    /* 0x29 */ ARTICLE_THE_SUMMER_SUN,
    /* 0x2A */ ARTICLE_THE_AUTUMN_SUN,
    /* 0x2B */ ARTICLE_THE_WINTER_SUN,
    /* 0x2C */ ARTICLE_BRACELET,
    /* 0x2D */ ARTICLE_NECKLACE,
    /* 0x2E */ ARTICLE_EARRINGS,
    /* 0x2F */ ARTICLE_BROACH,
    /* 0x30 */ ARTICLE_WEEDS,
    /* 0x31 */ ARTICLE_STONES,
    /* 0x32 */ ARTICLE_BRANCHES,
    /* 0x33 */ ARTICLE_LITHOGRAPH,
    /* 0x34 */ ARTICLE_MESSAGE_IN_A_BOTTLE,
    /* 0x35 */ ARTICLE_BALL,
    /* 0x36 */ ARTICLE_PIRATE_TREASURE,
    /* 0x37 */ ARTICLE_FOSSIL_OF_FISH,
    /* 0x38 */ ARTICLE_EMPTY_CAN,
    /* 0x39 */ ARTICLE_BOOTS,
    /* 0x3A */ ARTICLE_FISH_BONES,
    /* 0x3B */ ARTICLE_KARENS_WINE,
    /* 0x3C */ ARTICLE_POPURIS_MUD_BALL,
    /* 0x3D */ ARTICLE_ANNS_MUSIC_BOX,
    /* 0x3E */ ARTICLE_MARYS_GREAT_BOOK,
    /* 0x3F */ ARTICLE_ELLIS_PRESSED_FLOWER,
    /* 0x40 */ ARTICLE_ALBUM_1,
    /* 0x41 */ ARTICLE_ALBUM_2,
    /* 0x42 */ ARTICLE_ALBUM_3,
    /* 0x43 */ ARTICLE_ALBUM_4,
    /* 0x44 */ ARTICLE_ALBUM_5,
    /* 0x45 */ ARTICLE_ALBUM_6,
    /* 0x46 */ ARTICLE_ALBUM_7,
    /* 0x47 */ ARTICLE_ALBUM_8,
    /* 0x48 */ ARTICLE_ALBUM_9,
    /* 0x49 */ ARTICLE_ALBUM_10,
    /* 0x4A */ ARTICLE_ALBUM_11,
    /* 0x4B */ ARTICLE_ALBUM_12,
    /* 0x4C */ ARTICLE_ALBUM_13,
    /* 0x4D */ ARTICLE_ALBUM_14,
    /* 0x4E */ ARTICLE_ALBUM_15,
    /* 0x4F */ ARTICLE_BANDAID,
    /* 0x50 */ ARTICLE_BOOK,
    /* 0x51 */ ARTICLE_PERFUME,
    /* 0x52 */ ARTICLE_PHOTO,
    /* 0x53 */ ARTICLE_PLANT_ENCYCLOPEDIA,
    /* 0x54 */ ARTICLE_INVITATION,
    /* 0x55 */ ARTICLE_DRESS,
    /* 0x56 */ ARTICLE_FACIAL_PACK,
    /* 0x57 */ ARTICLE_SKIN_LOTION,
    /* 0x58 */ ARTICLE_SUNBLOCK,
    /* 0x59 */ ARTICLE_LUMBER,
    /* 0x5A */ ARTICLE_GOLDEN_LUMBER,
    /* 0x5B */ ARTICLE_ANIMAL_FODDER,
    /* 0x5C */ ARTICLE_CHICKEN_FEED,
    /* 0x5D */ ARTICLE_LOTTERY,
    /* 0x5E */ ARTICLE_FRISBEE,

    ARTICLE_NONE,
    NUM_ARTICLES = ARTICLE_NONE,
};

enum
{
    /* 0x00 */ PRODUCT_TURNIP,
    /* 0x01 */ PRODUCT_POTATO,
    /* 0x02 */ PRODUCT_CUCUMBER,
    /* 0x03 */ PRODUCT_CABBAGE,
    /* 0x04 */ PRODUCT_STRAWBERRY,
    /* 0x05 */ PRODUCT_TOMATO,
    /* 0x06 */ PRODUCT_CORN,
    /* 0x07 */ PRODUCT_ONION,
    /* 0x08 */ PRODUCT_PINEAPPLE,
    /* 0x09 */ PRODUCT_PUMPKIN,
    /* 0x0A */ PRODUCT_EGGPLANT,
    /* 0x0B */ PRODUCT_CARROT,
    /* 0x0C */ PRODUCT_SWEET_POTATO,
    /* 0x0D */ PRODUCT_GREEN_PEPPER,
    /* 0x0E */ PRODUCT_SPINACH,
    /* 0x0F */ PRODUCT_REGULAR_QUALITY_EGG,
    /* 0x10 */ PRODUCT_GOOD_QUALITY_EGG,
    /* 0x11 */ PRODUCT_HIGH_QUALITY_EGG,
    /* 0x12 */ PRODUCT_GOLDEN_EGG,
    /* 0x13 */ PRODUCT_P_EGG,
    /* 0x14 */ PRODUCT_X_EGG,
    /* 0x15 */ PRODUCT_SPABOILED_EGG,
    /* 0x16 */ PRODUCT_MAYONNAISE_S,
    /* 0x17 */ PRODUCT_MAYONNAISE_M,
    /* 0x18 */ PRODUCT_MAYONNAISE_L,
    /* 0x19 */ PRODUCT_MAYONNAISE_G,
    /* 0x1A */ PRODUCT_MAYONNAISE_P,
    /* 0x1B */ PRODUCT_MAYONNAISE_X,
    /* 0x1C */ PRODUCT_MILK_S,
    /* 0x1D */ PRODUCT_MILK_M,
    /* 0x1E */ PRODUCT_MILK_L,
    /* 0x1F */ PRODUCT_MILK_G,
    /* 0x20 */ PRODUCT_MILK_P,
    /* 0x21 */ PRODUCT_MILK_X,
    /* 0x22 */ PRODUCT_CHEESE_S,
    /* 0x23 */ PRODUCT_CHEESE_M,
    /* 0x24 */ PRODUCT_CHEESE_L,
    /* 0x25 */ PRODUCT_CHEESE_G,
    /* 0x26 */ PRODUCT_CHEESE_P,
    /* 0x27 */ PRODUCT_CHEESE_X,
    /* 0x28 */ PRODUCT_APPLE,
    /* 0x29 */ PRODUCT_SUGDW_APPLE,
    /* 0x2A */ PRODUCT_HMSGB_APPLE,
    /* 0x2B */ PRODUCT_AEPFE_APPLE,
    /* 0x2C */ PRODUCT_HONEY,
    /* 0x2D */ PRODUCT_BAMBOO_SHOOT,
    /* 0x2E */ PRODUCT_WILD_GRAPES,
    /* 0x2F */ PRODUCT_MUSHROOM,
    /* 0x30 */ PRODUCT_POISONOUS_MUSHROOM,
    /* 0x31 */ PRODUCT_TRUFFLE,
    /* 0x32 */ PRODUCT_BLUE_GRASS,
    /* 0x33 */ PRODUCT_GREEN_GRASS,
    /* 0x34 */ PRODUCT_RED_GRASS,
    /* 0x35 */ PRODUCT_YELLOW_GRASS,
    /* 0x36 */ PRODUCT_ORANGE_GRASS,
    /* 0x37 */ PRODUCT_PURPLE_GRASS,
    /* 0x38 */ PRODUCT_INDIGO_GRASS,
    /* 0x39 */ PRODUCT_BLACK_GRASS,
    /* 0x3A */ PRODUCT_WHITE_GRASS,
    /* 0x3B */ PRODUCT_CHOCOLATE,
    /* 0x3C */ PRODUCT_RELAX_TEA_LEAVES,
    /* 0x3D */ PRODUCT_SMALL_FISH,
    /* 0x3E */ PRODUCT_MEDIUM_FISH,
    /* 0x3F */ PRODUCT_LARGE_FISH,
    /* 0x40 */ PRODUCT_PIRATE_TREASURE,
    /* 0x41 */ PRODUCT_FOSSIL_OF_FISH,
    /* 0x42 */ PRODUCT_RED_MAGIC_GRASS,
    /* 0x43 */ PRODUCT_WOOL_S,
    /* 0x44 */ PRODUCT_WOOL_M,
    /* 0x45 */ PRODUCT_WOOL_L,
    /* 0x46 */ PRODUCT_WOOL_G,
    /* 0x47 */ PRODUCT_WOOL_P,
    /* 0x48 */ PRODUCT_WOOL_X,
    /* 0x49 */ PRODUCT_YARN_S,
    /* 0x4A */ PRODUCT_YARN_M,
    /* 0x4B */ PRODUCT_YARN_L,
    /* 0x4C */ PRODUCT_YARN_G,
    /* 0x4D */ PRODUCT_YARN_P,
    /* 0x4E */ PRODUCT_YARN_X,
    /* 0x4F */ PRODUCT_BRACELET,
    /* 0x50 */ PRODUCT_NECKLACE,
    /* 0x51 */ PRODUCT_EARRINGS,
    /* 0x52 */ PRODUCT_BROACH,
    /* 0x53 */ PRODUCT_JUNK_ORE,
    /* 0x54 */ PRODUCT_COPPER,
    /* 0x55 */ PRODUCT_SILVER,
    /* 0x56 */ PRODUCT_GOLD,
    /* 0x57 */ PRODUCT_MYSTRILE,
    /* 0x58 */ PRODUCT_ORICHALC,
    /* 0x59 */ PRODUCT_ADAMANTITE,
    /* 0x5A */ PRODUCT_MYTHIC_STONE,
    /* 0x5B */ PRODUCT_PINK_DIAMOND,
    /* 0x5C */ PRODUCT_ALEXANDRITE,
    /* 0x5D */ PRODUCT_MOON_STONE,
    /* 0x5E */ PRODUCT_SAND_ROSE,
    /* 0x5F */ PRODUCT_DIAMOND,
    /* 0x60 */ PRODUCT_EMERALD,
    /* 0x61 */ PRODUCT_RUBY,
    /* 0x62 */ PRODUCT_TOPAZ,
    /* 0x63 */ PRODUCT_PERIDOT,
    /* 0x64 */ PRODUCT_FLUORITE,
    /* 0x65 */ PRODUCT_AGATE,
    /* 0x66 */ PRODUCT_AMETHYST,

    PRODUCT_NONE,
    NUM_PRODUCTS = PRODUCT_NONE,
};

struct PACKED Tool
{
    Tool(u32 id);

    int GetId() const;
    char const * GetName() const;
    u16 GetIconId() const;
    char const * GetDesc() const;

    /* +00 */ u8 id;
};

struct PACKED ToolStack : public Tool
{
    enum
    {
        MAX_AMOUNT = 99
    };

    ToolStack();
    ToolStack(Tool kind, u32 amount);

    Tool GetTool() const;
    bool IsEmpty() const;
    u32 GetAmount() const;
    void AddAmount(u32 amount);
    void SubtractAmount(u32 amount);

    /* +01 */ u8 amount;
};

struct PACKED Food
{
    Food(u32 id);

    int GetId() const;
    char const * GetName() const;
    u16 GetIconId() const;
    int GetStaminaGain() const;
    int GetFatigueGain() const;
    int GetStaminaBonus() const;
    int GetFatigueBonus() const;
    bool IsDrink() const;
    char const * GetDesc() const;
    void AddBonuses(i8 stamina_amount, i8 fatigue_amount);

    /* +00 */ u8 id;
    /* +01 */ i8 stamina_bonus;
    /* +02 */ i8 fatigue_bonus;
};

struct FoodStack : public Food
{
    enum
    {
        MAX_AMOUNT = 99
    };

    FoodStack();
    FoodStack(Food food, u32 a_amount);

    Food GetFood() const;
    bool IsEmpty() const;
    u32 GetAmount() const;
    void AddAmount(u32 amount);
    void SubtractAmount(u32 amount);

    /* +03 */ u8 amount;
};

struct PACKED Article
{
    Article(u32 id);

    int GetId() const;
    char const * GetName() const;
    u16 GetIconId() const;
    bool CanBeDiscarded() const;
    char const * GetDesc() const;

    /* +00 */ u8 id;
};

struct PACKED ArticleStack : public Article
{
    enum
    {
        MAX_AMOUNT = 99
    };

    ArticleStack();
    ArticleStack(Article article, u32 a_amount);

    Article GetArticle() const;
    bool IsEmpty() const;
    u32 GetAmount() const;
    void AddAmount(u32 amount);
    void SubtractAmount(u32 amount);

    /* +01 */ u8 amount;
};

struct PACKED Product
{
    Product();
    Product(u32 id);
    Product(Food food);
    Product(Article article);

    int GetId() const;
    u32 GetPrice() const;
    char const * GetName() const;
    u16 GetIconId() const;

    /* +00 */ u8 id;
};

struct PACKED ALIGN(2) ItemVariant
{
    enum Kind
    {
        KIND_TOOL,
        KIND_FOOD,
        KIND_ARTICLE,
    };

    Tool AsTool() const;
    Food AsFood() const;
    Article AsArticle() const;

    /* +00 */ u32 kind : 2;
    /* +00 */ u32 id : 14;
};

#endif // ITEM_HH
