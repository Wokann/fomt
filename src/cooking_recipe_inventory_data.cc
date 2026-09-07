#include "cooking_recipe_inventory.hh"

EXTERN_C

// func_080977A0 compares a recipe inventory bitfield to required_mask and
// writes selected_value for the first matching row.
CookingRecipeInventoryMaskEntry const gCookingRecipeInventoryMaskEntries[] = {
    { 0x0008, 0x009C },
    { 0x0020, 0x00A0 },
    { 0x0040, 0x009E },
    { 0x0004, 0x009D },
    { 0x0002, 0x009F },
    { 0x0001, 0x009B },
    { 0x0010, 0x009E },
    { 0x0F80, 0x009B },
    { 0x0000, 0x009B },
};

EXTERN_C_END
