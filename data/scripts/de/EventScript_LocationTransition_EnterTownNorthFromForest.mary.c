#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterTownNorthFromForest(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_NORTH_SIDE_TOWN, X(104), Y(680));
        SetEntityPosition(ENTITY_PLAYER, X(104), Y(680), FACING_UP);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
