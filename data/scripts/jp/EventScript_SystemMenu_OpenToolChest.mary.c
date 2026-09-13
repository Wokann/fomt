#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_SystemMenu_OpenToolChest(void)
{
    PrepareCookingMenuTransition();
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    OpenToolChest();
    PrepareCookingMenuTransition();
    FadeInScreenWithoutSceneHook(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    RestoreAfterCookingMenu();
}
