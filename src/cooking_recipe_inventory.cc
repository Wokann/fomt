#include "cooking_recipe_inventory.hh"
#include "fomt_constants.hh"

CookingRecipeInventory::CookingRecipeInventory()
    : failed_dish(false), failed_drink(false), failed_pot_dish(false),
      failed_dessert(false), failed_bread(false), failed_noodles(false)
{
    u16 previous_id = 0;
    u16 count = 0;
    CookingRecipeDefinition const * definition = gCookingRecipeDefinitions;
    for (; definition->recipe_id != 0; ++definition) {
        if (definition->recipe_id != previous_id) {
            records[count].recipe_id = definition->recipe_id;
            ++count;
            previous_id = definition->recipe_id;
        }
    }
    record_count = count;
}

void CookingRecipeInventory::CopyRecipe(CookingRecipeRecord * output, u32 index) const
{
    CookingRecipeRecord const & source = records[index];
    output->recipe_id = source.recipe_id;
    output->utensil_mask = source.utensil_mask;
    output->learned = source.learned;
    for (int ingredient = 0; ingredient < 8; ++ingredient)
        output->ingredients[ingredient] = source.ingredients[ingredient];
}

void CookingRecipeInventory::LearnRecipe(CookingRecipeRecord const * recipe)
{
    CookingRecipeRecord * stored = records;
    for (int index = 0; index < record_count; ++stored, ++index) {
        if (stored->recipe_id == recipe->recipe_id) {
            stored->learned = true;
            stored->utensil_mask = recipe->utensil_mask;
            for (int ingredient = 0; ingredient < 8; ++ingredient)
                stored->ingredients[ingredient] = recipe->ingredients[ingredient];
            break;
        }
    }
}

u32 CookingRecipeInventory::CountLearnedRecipes() const
{
    u32 count = 0;
    for (int index = 0; index < record_count; ++index) {
        if (records[index].learned)
            ++count;
    }
    return count;
}

bool CookingRecipeInventory::RecordFailedDish(u16 result_id)
{
    bool result = false;
    switch (result_id) {
    case ITEM_FOOD_FAILED_DISH + 1:
        if (!failed_dish) {
            failed_dish = true;
            result = true;
        }
        break;
    case ITEM_FOOD_FAILED_DRINK + 1:
        if (!failed_drink) {
            failed_drink = true;
            result = true;
        }
        break;
    case ITEM_FOOD_FAILED_POT_DISH + 1:
        if (!failed_pot_dish) {
            failed_pot_dish = true;
            result = true;
        }
        break;
    case ITEM_FOOD_FAILED_DESSERT + 1:
        if (!failed_dessert) {
            failed_dessert = true;
            result = true;
        }
        break;
    case ITEM_FOOD_FAILED_BREAD + 1:
        if (!failed_bread) {
            failed_bread = true;
            result = true;
        }
        break;
    case ITEM_FOOD_FAILED_NOODLES + 1:
        if (!failed_noodles) {
            failed_noodles = true;
            result = true;
        }
        break;
    }
    return result;
}

u32 CookingRecipeInventory::CountLearnedFoodRecipes() const
{
    u32 count = 0;
    for (int index = 0; index < record_count; ++index) {
        if (records[index].recipe_id <= ITEM_FOOD_NONE && records[index].learned)
            ++count;
    }
    return count;
}

CookingRecipeEvaluation CookingRecipeInventory::GetLearnedFoodRecipe(u32 ordinal) const
{
    CookingRecipeEvaluation result;
    u32 found = 0;
    for (int index = 0; index < record_count; ++index) {
        if (records[index].recipe_id <= ITEM_FOOD_NONE && records[index].learned) {
            if (found == ordinal) {
                result = EvaluateCookingRecipe(records[index]);
                break;
            }
            ++found;
        }
    }
    return result;
}
