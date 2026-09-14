#include "cooking_recipe_inventory_page_data.hh"

extern "C" {

#include FOMT_TEXT_INCLUDE(cooking_recipe_inventory_page_data.cc)

// The recipe screen walks the eight utensil flags in order and passes the
// corresponding value to its native display helper.
u16 const gCookingRecipeInventoryUtensilValues[] = {
    0x0109,
    0x00CC,
    0x015A,
    0x0040,
    0x01D8,
    0x0139,
    0x0147,
    0x0190,
};

}
