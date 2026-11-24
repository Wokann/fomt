mary_text_table
{
    const char gText_SystemMenu_RecipeBook_KitchenAcquisitionOption[] =
        "Get Kitchen";

    const char gText_SystemMenu_RecipeBook_MenuPage1[] =
        "Recipe Book 1";

    const char gText_SystemMenu_RecipeBook_Exit[] =
        "Exit";

#ifndef UNIFY_REGIONS
    const char gText_SystemMenu_RecipeBook_MenuPage1_2[] =
        "Recipe Book1";

    const char gText_SystemMenu_RecipeBook_MenuPage2_2[] =
        "Recipe Book2";

    const char gText_SystemMenu_RecipeBook_MenuPage3_2[] =
        "Recipe Book3";
#endif

    const char gText_SystemMenu_RecipeBook_MenuPage2[] =
#ifdef UNIFY_REGIONS
        "Recipe Book2";
#else
        "Recipe Book 2";
#endif

    const char gText_SystemMenu_RecipeBook_MenuPage3[] =
#ifdef UNIFY_REGIONS
        "Recipe Book3";
#else
        "Recipe Book 3";
#endif


    const char gText_SystemMenu_RecipeBook_MenuPage4[] =
        "Recipe Book 4";
};
