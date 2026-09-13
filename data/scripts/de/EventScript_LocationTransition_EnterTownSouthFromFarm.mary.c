#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterTownSouthFromFarm(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_SOUTH_SIDE_TOWN, X(812), Y(496));
        SetEntityPosition(ENTITY_PLAYER, X(812), Y(496), FACING_UP);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
