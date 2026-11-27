#ifndef COOKING_RECIPE_TYPES_HH
#define COOKING_RECIPE_TYPES_HH

#include "cooking_recipe.hh"

// Saved at GameStateSaveImage +0x2214. The low twelve bits select utensils;
// bit twelve records that this recipe has been learned. The remaining three
// bits are unknown and must survive construction, copying and updates.
struct CookingRecipeRecord
{
    CookingRecipeRecord();

    u16 recipe_id; // One-based food/article result ID, not a MaryItemFoodId.
    u16 ingredients[8];
    u32 utensil_mask : 12;
    bool learned : 1;
    u32 unk_13_5 : 3;
};

// The original constructor keeps one record per consecutive run of equal
// definition IDs. It assumes the list fits 128 records; it does not globally
// deduplicate IDs or perform a capacity check. Padding at +0xA07 is untouched.
struct CookingRecipeInventory
{
    CookingRecipeInventory();
    void CopyRecipe(CookingRecipeRecord * output, u32 index) const;
    void LearnRecipe(CookingRecipeRecord const * recipe);
    u32 CountLearnedRecipes() const;
    // Result IDs are ITEM_FOOD_* + 1. A true return marks a first occurrence;
    // the separate caller decides whether to increment Lou's recipe counter.
    bool RecordFailedDish(u16 result_id);
    // One-based food results end at ITEM_FOOD_NONE; article results follow.
    u32 CountLearnedFoodRecipes() const;
    CookingRecipeEvaluation GetLearnedFoodRecipe(u32 ordinal) const;

    CookingRecipeRecord records[128];
    bool failed_dish;
    bool failed_drink;
    bool failed_pot_dish;
    bool failed_dessert;
    bool failed_bread;
    bool failed_noodles;
    u8 record_count;
};


#endif // COOKING_RECIPE_TYPES_HH
