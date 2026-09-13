#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_Kitchen_MenuCook[] =
        "Cook";

    const char gText_SystemMenu_Kitchen_MenuViewRecipes[] =
        "View recipies";

    const char gText_SystemMenu_Kitchen_Exit[] =
        "Exit";

    const char gText_SystemMenu_Kitchen_YouHaventMadeAnything[] =
        "You haven't made anything.{Press}";

    const char gText_SystemMenu_Kitchen_HoldingItemPreventsCooking[] =
        "Cook here.\r\n"
        "You can't cook while \r\n"
        "holding something.{Press}";
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
