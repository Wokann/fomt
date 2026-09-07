#ifndef COOKING_RECIPE_INVENTORY_HH
#define COOKING_RECIPE_INVENTORY_HH

#include "prelude.h"

EXTERN_C

struct CookingRecipeInventoryMaskEntry
{
    u16 required_mask;
    u16 selected_value;
};

enum
{
    COOKING_RECIPE_INVENTORY_UTENSIL_VALUE_COUNT = 8,
    COOKING_RECIPE_INVENTORY_MASK_ENTRY_COUNT = 9,
};

extern u16 const
    gCookingRecipeInventoryUtensilValues[COOKING_RECIPE_INVENTORY_UTENSIL_VALUE_COUNT];
extern CookingRecipeInventoryMaskEntry const
    gCookingRecipeInventoryMaskEntries[COOKING_RECIPE_INVENTORY_MASK_ENTRY_COUNT];

EXTERN_C_END

#endif // COOKING_RECIPE_INVENTORY_HH
