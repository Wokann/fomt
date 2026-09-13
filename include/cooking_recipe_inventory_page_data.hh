#ifndef COOKING_RECIPE_INVENTORY_PAGE_DATA_HH
#define COOKING_RECIPE_INVENTORY_PAGE_DATA_HH

#include "prelude.h"

EXTERN_C

enum
{
    COOKING_RECIPE_INVENTORY_UTENSIL_VALUE_COUNT = 8,
};

extern char const gText_Cooking_Recipe_PageBreak[];
extern u16 const
    gCookingRecipeInventoryUtensilValues[COOKING_RECIPE_INVENTORY_UTENSIL_VALUE_COUNT];

EXTERN_C_END

#endif // COOKING_RECIPE_INVENTORY_PAGE_DATA_HH
