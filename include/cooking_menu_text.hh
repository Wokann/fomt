#ifndef COOKING_MENU_TEXT_HH
#define COOKING_MENU_TEXT_HH

#include "prelude.h"

#define COOKING_RESULT_TEXT SECTION(".rodata.cooking_result_text")
#define COOKING_RESULT_SUCCESS_TEXT SECTION(".rodata.cooking_result_success_text")
#define COOKING_RECIPE_ACTIONS_EXTRA_TEXT SECTION(".rodata.cooking_recipe_actions_extra_text")

extern char const gText_Cooking_SeasoningSet[];
extern char const gText_Cooking_CompleteUtensilSelection[];
extern char const gText_Cooking_WrappedGiftDescription[];
extern char const gText_Cooking_FollowRecipe[];
extern char const gText_Cooking_ImproviseRecipe[];
extern char const gText_Cooking_MakeAnotherRecipe[];
extern char const gText_Cooking_NotEnoughIngredients[];
extern char const gText_Cooking_UseTheseIngredients[];
extern char const gText_Cooking_RestartIngredients[];
extern char const gText_Cooking_RestartUtensils[];
extern char const gText_Cooking_Recipe_MakeThis[];
extern char const gText_Cooking_Recipe_ViewCurrent[];
extern char const gText_Cooking_Recipe_Rewrite[];
extern char const gText_Cooking_Recipe_ViewNew[];
extern char const gText_Cooking_Recipe_ListTitle[];
extern char const gText_Cooking_Recipe_Utensils[];
extern char const gText_Cooking_Recipe_Ingredients[];
extern char const gText_Cooking_Recipe_UseIngredients[];
extern char const gText_Cooking_Recipe_IngredientsRequired[];
extern char const gText_Cooking_Recipe_Empty[];
extern char const gText_Cooking_Recipe_PageBreak[];
extern char const gText_Cooking_Recipe_StorageHeader[];
extern char const gText_Cooking_Recipe_SelectionNames[13][11];
extern char const gText_Cooking_ResultFailure[];
extern char const gText_Cooking_ResultSuccessNewRecipe[];
extern char const gText_Cooking_ResultSuccess[];
extern char const gText_Cooking_ResultComparison[];

#if defined(REGION_JP)
extern char const gText_Cooking_Recipe_LeavePreviousAsIs[];
extern char const gText_Cooking_Recipe_LeaveNewAsIs[];
#else
extern char const gText_Cooking_ImproviseAnyway[];
extern char const gText_Cooking_Recipe_LeaveAsIs[];
#endif

#endif // COOKING_MENU_TEXT_HH
