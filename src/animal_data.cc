#include "animal_data.hh"
#include "fomt_constants.hh"

#include FOMT_TEXT_INCLUDE(animal_data.cc)

FarmHouseDrawTilePosition const gFarmHouseUpgradeDrawPositions[] ALIGN(1) = {
    { 15, 4 },
    { 30, 4 },
    { 38, 4 },
};

FarmHouseEntityPosition const gFarmHouseOriginalRelocationPositions[] = {
    { 209, 121 },
    { 65, 157 },
    { 176, 64 },
    { 120, 208 },
    { 212, 136 },
};

FarmHouseEntityPosition const gFarmHouseFirstExtensionRelocationPositions[] = {
    { 56, 151 },
    { 135, 106 },
    { 298, 125 },
    { 296, 64 },
    { 240, 208 },
    { 332, 136 },
};

FarmHouseEntityPosition const gFarmHouseSecondExtensionRelocationPositions[] = {
    { 405, 131 },
    { 207, 109 },
    { 37, 100 },
    { 360, 64 },
    { 304, 208 },
    { 444, 136 },
};

// World time update collects entity pointers using these u32 slot indices.
// Its two native loops currently consume exactly 10 and 36 entries; extending
// either list also requires updating the corresponding reader.
u32 const gUnk_080F0748[] = {
    ENTITY_ZACK,
    ENTITY_STAID,
    ENTITY_NAPPY,
    ENTITY_BOLD,
    ENTITY_CHEF,
    ENTITY_AQUA,
    ENTITY_HOGGY,
    ENTITY_TIMID,
    ENTITY_FARM_DOG,
    ENTITY_FRISBEE,
};

u32 const gUnk_080F0770[] = {
    ENTITY_PLAYER,
    ENTITY_ZACK,
    ENTITY_STAID,
    ENTITY_NAPPY,
    ENTITY_BOLD,
    ENTITY_CHEF,
    ENTITY_AQUA,
    ENTITY_HOGGY,
    ENTITY_TIMID,
    ENTITY_FARM_DOG,
    ENTITY_FARM_HORSE,
    ENTITY_FRISBEE,
    ENTITY_ANIMAL_CHICKEN_SLOT_1,
    ENTITY_ANIMAL_CHICKEN_SLOT_2,
    ENTITY_ANIMAL_CHICKEN_SLOT_3,
    ENTITY_ANIMAL_CHICKEN_SLOT_4,
    ENTITY_ANIMAL_CHICKEN_SLOT_5,
    ENTITY_ANIMAL_CHICKEN_SLOT_6,
    ENTITY_ANIMAL_CHICKEN_SLOT_7,
    ENTITY_ANIMAL_CHICKEN_SLOT_8,
    ENTITY_BARN_ANIMAL_SLOT_1,
    ENTITY_BARN_ANIMAL_SLOT_2,
    ENTITY_BARN_ANIMAL_SLOT_3,
    ENTITY_BARN_ANIMAL_SLOT_4,
    ENTITY_BARN_ANIMAL_SLOT_5,
    ENTITY_BARN_ANIMAL_SLOT_6,
    ENTITY_BARN_ANIMAL_SLOT_7,
    ENTITY_BARN_ANIMAL_SLOT_8,
    ENTITY_BARN_ANIMAL_SLOT_9,
    ENTITY_BARN_ANIMAL_SLOT_10,
    ENTITY_BARN_ANIMAL_SLOT_11,
    ENTITY_BARN_ANIMAL_SLOT_12,
    ENTITY_BARN_ANIMAL_SLOT_13,
    ENTITY_BARN_ANIMAL_SLOT_14,
    ENTITY_BARN_ANIMAL_SLOT_15,
    ENTITY_BARN_ANIMAL_SLOT_16,
};

// Independent tool-effect lookups, indexed by the current charge level (0..6).
// The native player charge updater stops at the selected maximum minus one.
u8 const gUnk_080F0800[] ALIGN(1) = {
    0x01, 0x02, 0x03, 0x04, 0x05, 0x08, 0x09,
};

u8 const gUnk_080F0807[] ALIGN(1) = {
    0x01, 0x02, 0x03, 0x04, 0x08, 0x08, 0x08,
};
