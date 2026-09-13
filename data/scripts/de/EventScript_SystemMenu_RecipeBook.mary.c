#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_RecipeBook_ChoiceGetKitchen[] =
        "Küche kriegen";

    const char gText_SystemMenu_RecipeBook_ChoiceRecipeBook1[] =
        "Rezeptbuch 1";

    const char gText_SystemMenu_RecipeBook_Exit[] =
        "Schließen";

    const char gText_SystemMenu_RecipeBook_ChoiceKitchen[] =
        "Küche";

    const char gText_SystemMenu_RecipeBook_ChoiceRecipeBook2[] =
        "Rezeptbuch 2";

    const char gText_SystemMenu_RecipeBook_ChoiceRecipeBook3[] =
        "Rezeptbuch 3";

    const char gText_SystemMenu_RecipeBook_ChoiceRecipeBook4[] =
        "Rezeptbuch 4";
};

void EventScript_SystemMenu_RecipeBook(void)
{
    int var_0;
    if (VarGet(VAR_YEAR) == 1)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ShowReferencePage(REFERENCE_PAGE_ACQUIRING_A_KITCHEN);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
    else
    {
        if (VarGet(VAR_YEAR) <= 3)
        {
            TalkOpen();
            var_0 = TalkChoice3(gText_SystemMenu_RecipeBook_ChoiceGetKitchen, gText_SystemMenu_RecipeBook_ChoiceRecipeBook1, gText_SystemMenu_RecipeBook_Exit);
            switch (var_0)
            {
                case CHOICE_OPTION_1:
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    ShowReferencePage(REFERENCE_PAGE_ACQUIRING_A_KITCHEN);
                    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    break;
                case CHOICE_OPTION_2:
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    ShowReferencePage(REFERENCE_PAGE_COOKBOOK_1);
                    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    break;
                case CHOICE_OPTION_3:
                    TalkClose();
                    return;
                mary_dead_jump:
            }
        }
        else
        {
            if (VarGet(VAR_YEAR) <= 5)
            {
                TalkOpen();
                var_0 = TalkChoice4(gText_SystemMenu_RecipeBook_ChoiceKitchen, gText_SystemMenu_RecipeBook_ChoiceRecipeBook1, gText_SystemMenu_RecipeBook_ChoiceRecipeBook2, gText_SystemMenu_RecipeBook_Exit);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_ACQUIRING_A_KITCHEN);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        break;
                    case CHOICE_OPTION_2:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_COOKBOOK_1);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        break;
                    case CHOICE_OPTION_3:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_COOKBOOK_2);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        break;
                    case CHOICE_OPTION_4:
                        TalkClose();
                        return;
                    mary_dead_jump:
                }
            }
            else
            {
                if (VarGet(VAR_YEAR) <= 10)
                {
                    TalkOpen();
                    var_0 = TalkChoice5(gText_SystemMenu_RecipeBook_ChoiceKitchen, gText_SystemMenu_RecipeBook_ChoiceRecipeBook1, gText_SystemMenu_RecipeBook_ChoiceRecipeBook2, gText_SystemMenu_RecipeBook_ChoiceRecipeBook3, gText_SystemMenu_RecipeBook_Exit);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ShowReferencePage(REFERENCE_PAGE_ACQUIRING_A_KITCHEN);
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            break;
                        case CHOICE_OPTION_2:
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ShowReferencePage(REFERENCE_PAGE_COOKBOOK_1);
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            break;
                        case CHOICE_OPTION_3:
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ShowReferencePage(REFERENCE_PAGE_COOKBOOK_2);
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            break;
                        case CHOICE_OPTION_4:
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ShowReferencePage(REFERENCE_PAGE_COOKBOOK_3);
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            break;
                        case CHOICE_OPTION_5:
                            TalkClose();
                            return;
                        mary_dead_jump:
                    }
                }
                else
                {
                    TalkOpen();
                    var_0 = TalkChoice6(gText_SystemMenu_RecipeBook_ChoiceKitchen, gText_SystemMenu_RecipeBook_ChoiceRecipeBook1, gText_SystemMenu_RecipeBook_ChoiceRecipeBook2, gText_SystemMenu_RecipeBook_ChoiceRecipeBook3, gText_SystemMenu_RecipeBook_ChoiceRecipeBook4, gText_SystemMenu_RecipeBook_Exit);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ShowReferencePage(REFERENCE_PAGE_ACQUIRING_A_KITCHEN);
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            break;
                        case CHOICE_OPTION_2:
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ShowReferencePage(REFERENCE_PAGE_COOKBOOK_1);
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            break;
                        case CHOICE_OPTION_3:
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ShowReferencePage(REFERENCE_PAGE_COOKBOOK_2);
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            break;
                        case CHOICE_OPTION_4:
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ShowReferencePage(REFERENCE_PAGE_COOKBOOK_3);
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            break;
                        case CHOICE_OPTION_5:
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            ShowReferencePage(REFERENCE_PAGE_COOKBOOK_4);
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            break;
                        case CHOICE_OPTION_6:
                            TalkClose();
                            return;
                        mary_dead_jump:
                    }
                }
            }
        }
    }
}
