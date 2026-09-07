#include "cooking_recipe_inventory.hh"

EXTERN_C

// The recipe screen walks the eight utensil flags in order and passes the
// corresponding value to its native display helper.
u16 const gCookingRecipeInventoryUtensilValues[]
    SECTION(".rodata.cooking_recipe_inventory_utensil_values") = {
        0x0109,
        0x00CC,
        0x015A,
        0x0040,
        0x01D8,
        0x0139,
        0x0147,
        0x0190,
    };

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
