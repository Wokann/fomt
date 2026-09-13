#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_TelephoneDirectory_Blacksmith[] =
        "Schmied";

    const char gText_SystemMenu_TelephoneDirectory_Supermarket[] =
        "Supermarkt";

    const char gText_SystemMenu_TelephoneDirectory_Woodcutter[] =
        "Holzfäller";

    const char gText_SystemMenu_TelephoneDirectory_Clinic[] =
        "Klinik";

    const char gText_SystemMenu_TelephoneDirectory_AjaWinery[] =
        "Garten";

    const char gText_SystemMenu_TelephoneDirectory_Other[] =
        "Andere";

    const char gText_SystemMenu_TelephoneDirectory_Inn[] =
        "Gasthof";

    const char gText_SystemMenu_TelephoneDirectory_KaisSeasideLodge[] =
        "Strandhaus";

    const char gText_SystemMenu_TelephoneDirectory_PoultryFarm[] =
        "Geflügelfarm";

    const char gText_SystemMenu_TelephoneDirectory_YodelFarm[] =
        "Jodel-Farm";

    const char gText_SystemMenu_TelephoneDirectory_WonsShop[] =
        "Laden";
};

void EventScript_SystemMenu_TelephoneDirectory(void)
{
    int var_0, var_1, var_2;
    var_1 = FALSE;
    TalkOpen();
    do
    {
        switch (var_1)
        {
            case FALSE:
                var_0 = TalkChoice6(gText_SystemMenu_TelephoneDirectory_Blacksmith, gText_SystemMenu_TelephoneDirectory_Supermarket, gText_SystemMenu_TelephoneDirectory_Woodcutter, gText_SystemMenu_TelephoneDirectory_Clinic, gText_SystemMenu_TelephoneDirectory_AjaWinery, gText_SystemMenu_TelephoneDirectory_Other);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_SAIBARA_BLACKSMITH);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_2:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_SUPERMARKET);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_3:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_WOODCUTTER_HOUSE);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_4:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_MINERAL_TOWN_CLINIC);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_5:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_AJA_WINERY);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_6:
                        var_1 = TRUE;
                        var_2 = FALSE;
                        break;
                }
                break;
            case TRUE:
                var_0 = TalkChoice6(gText_SystemMenu_TelephoneDirectory_Inn, gText_SystemMenu_TelephoneDirectory_KaisSeasideLodge, gText_SystemMenu_TelephoneDirectory_PoultryFarm, gText_SystemMenu_TelephoneDirectory_YodelFarm, gText_SystemMenu_TelephoneDirectory_WonsShop, gText_SystemMenu_TelephoneDirectory_Other);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_DOUGS_INN);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_2:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_KAIS_SEASIDE_LODGE);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_3:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_POULTRY_FARM);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_4:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_YODEL_FARM);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_5:
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        ShowReferencePage(REFERENCE_PAGE_PHONE_WONS_SHOP);
                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_2 = TRUE;
                        break;
                    case CHOICE_OPTION_6:
                        var_1 = FALSE;
                        var_2 = FALSE;
                        break;
                }
                break;
        }
    }
    while (var_2 == FALSE);
}
