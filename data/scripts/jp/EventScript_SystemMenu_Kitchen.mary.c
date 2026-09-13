#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_Kitchen_MenuCook[] =
        "お料理を作る";

    const char gText_SystemMenu_Kitchen_MenuViewRecipes[] =
        "レシピを見る";

    const char gText_SystemMenu_Kitchen_Exit[] =
        "やめる";

    const char gText_SystemMenu_Kitchen_YouHaventMadeAnything[] =
        "何も作ったことがない。{Press}";

    const char gText_SystemMenu_Kitchen_HoldingItemPreventsCooking[] =
        "ここでお料理を作る。\r\n"
        "手に物を持ってたら作れない。{Press}";
};

void EventScript_SystemMenu_Kitchen(void)
{
    int var_0;
    TalkOpen();
    if (IsPlayerHoldingNothing() == TRUE)
    {
        var_0 = TalkChoice3(gText_SystemMenu_Kitchen_MenuCook, gText_SystemMenu_Kitchen_MenuViewRecipes, gText_SystemMenu_Kitchen_Exit);
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                OpenCookingMenu();
                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                break;
            case CHOICE_OPTION_2:
                if (GetKnownRecipeCount())
                {
                    TalkClose();
                    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                    OpenRecipeList();
                    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                }
                else
                {
                    TalkMessage(gText_SystemMenu_Kitchen_YouHaventMadeAnything);
                }
                break;
            case CHOICE_OPTION_3:
                break;
        }
    }
    else
    {
        TalkMessage(gText_SystemMenu_Kitchen_HoldingItemPreventsCooking);
    }
    TalkClose();
}
