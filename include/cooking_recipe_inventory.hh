#ifndef COOKING_RECIPE_INVENTORY_HH
#define COOKING_RECIPE_INVENTORY_HH

#include "prelude.h"

EXTERN_C

struct CookingRecipeInventoryMaskEntry
{
    u16 required_mask;
    u16 selected_value;
};

// func_0809A58C walks these four-byte, zero-key-terminated records through
// the +0x0C and +0x10 pointers of a recipe definition.  The meanings of the
// signed adjustment bytes are not established yet.
struct CookingRecipeUnknownValueOffsetEntry
{
    u16 value;
    i8 unk_02;
    i8 unk_03;
};

// This table is terminated by a completely zero record.  The native recipe
// path reads the scalar fields and the three pointed lists directly; keep
// unproven field roles explicit rather than assigning speculative names.
struct CookingRecipeDefinition
{
    u16 recipe_id;
    u16 unk_02;
    i16 unk_04;
    u16 unk_06;
    u16 const * values_08;
    CookingRecipeUnknownValueOffsetEntry const * entries_0c;
    CookingRecipeUnknownValueOffsetEntry const * entries_10;
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
extern CookingRecipeDefinition const gCookingRecipeDefinitions[];

EXTERN_C_END

#endif // COOKING_RECIPE_INVENTORY_HH
