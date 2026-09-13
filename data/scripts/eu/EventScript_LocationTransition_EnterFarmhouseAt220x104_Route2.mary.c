#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterFarmhouseAt220x104_Route2(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FARMHOUSE, X(120), Y(208));
        SetEntityPosition(ENTITY_PLAYER, X(220), Y(104), FACING_UP);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
