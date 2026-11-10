#ifndef COOKING_RECIPE_INVENTORY_HH
#define COOKING_RECIPE_INVENTORY_HH

#include "cooking_recipe_types.hh"

#include <algorithm>

inline CookingRecipeRecord::CookingRecipeRecord()
    : recipe_id(0), utensil_mask(0), learned(false)
{
    std::fill_n(ingredients, int(ARRAY_COUNT(ingredients)), u16(0));
}

#endif // COOKING_RECIPE_INVENTORY_HH
