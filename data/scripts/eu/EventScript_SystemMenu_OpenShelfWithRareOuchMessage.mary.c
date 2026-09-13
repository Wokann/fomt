#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_SystemMenu_OpenShelfWithRareOuchMessage[] =
        "Ouch!...{Press}";
};

void EventScript_SystemMenu_OpenShelfWithRareOuchMessage(void)
{
    int var_0;
    PrepareClockMenuTransition();
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    OpenShelf();
    PrepareClockMenuTransition();
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    RestoreAfterClockMenu();
    var_0 = RandomIntInclusive(0, 65535);
    if (var_0 == 0)
    {
        TalkOpen();
        TalkMessage(gText_SystemMenu_OpenShelfWithRareOuchMessage);
    }
}
