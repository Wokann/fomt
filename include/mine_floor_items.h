#ifndef MINE_FLOOR_ITEMS_H
#define MINE_FLOOR_ITEMS_H

#include "prelude.h"
#include "mine_weight_rows.h"

// The byte offset of each weight is its column in the parallel code array.
typedef struct PACKED {
    u8 down_ladder;
    u8 money;
    u8 sickle_cursed;
    u8 hoe_cursed;
    u8 axe_cursed;
    u8 hammer_cursed;
    u8 watering_can_cursed;
    u8 fishing_rod_cursed;
    u8 black_grass;
    u8 power_berry;
} LakeMineBuriedWeightRow;

typedef struct PACKED {
    u8 kappa_jewel;
    u8 junk_ore;
    u8 pink_diamond;
    u8 alexandrite;
    u8 moon_stone;
    u8 sand_rose;
    u8 diamond;
    u8 emerald;
    u8 ruby;
    u8 topaz;
    u8 peridot;
    u8 fluorite;
    u8 agate;
    u8 amethyst;
} LakeMineRockWeightRow;

typedef struct PACKED {
    u8 down_ladder;
    u8 money;
    u8 black_grass;
    u8 power_berry;
    u8 lithograph;
} SpringMineBuriedWeightRow;

typedef struct PACKED {
    u8 teleport_stone;
    u8 harvest_goddess_jewel;
    u8 junk_ore;
    u8 copper;
    u8 silver;
    u8 gold;
    u8 mystrile;
    u8 orichalc;
    u8 adamantite;
    u8 mythic_stone;
} SpringMineRockWeightRow;

// C initializes named rows and fields. The mine loops read the same bytes in column order.
typedef union PACKED {
    LakeMineBuriedWeightRow rows[LAKE_BURIED_ROW_B255 + 1];
    u8 bytes[LAKE_BURIED_ROW_B255 + 1][sizeof(LakeMineBuriedWeightRow)];
} LakeMineBuriedWeightTable;

typedef union PACKED {
    LakeMineRockWeightRow rows[LAKE_ROCK_ROW_B255 + 1];
    u8 bytes[LAKE_ROCK_ROW_B255 + 1][sizeof(LakeMineRockWeightRow)];
} LakeMineRockWeightTable;

typedef union PACKED {
    SpringMineBuriedWeightRow rows[SPRING_BURIED_ROW_B255 + 1];
    u8 bytes[SPRING_BURIED_ROW_B255 + 1][sizeof(SpringMineBuriedWeightRow)];
} SpringMineBuriedWeightTable;

typedef union PACKED {
    SpringMineRockWeightRow rows[SPRING_ROCK_ROW_B255 + 1];
    u8 bytes[SPRING_ROCK_ROW_B255 + 1][sizeof(SpringMineRockWeightRow)];
} SpringMineRockWeightTable;

EXTERN_C

extern u32 const gLakeMineBuriedItemCodes[];
extern LakeMineBuriedWeightTable const gLakeMineBuriedItemWeights;
extern u32 const gLakeMineRockItemCodes[];
extern LakeMineRockWeightTable const gLakeMineRockItemWeights;
extern u32 const gSpringMineBuriedItemCodes[];
extern SpringMineBuriedWeightTable const gSpringMineBuriedItemWeights;
extern u32 const gSpringMineRockItemCodes[];
extern SpringMineRockWeightTable const gSpringMineRockItemWeights;

EXTERN_C_END

#endif // MINE_FLOOR_ITEMS_H
