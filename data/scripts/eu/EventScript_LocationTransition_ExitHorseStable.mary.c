#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_ExitHorseStable(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_DOWN)
    {
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_FARM, X(752), Y(122));
        SetEntityPosition(ENTITY_PLAYER, X(752), Y(122), FACING_DOWN);
        if (IsPlayerRidingHorse() == TRUE)
        {
            SetEntityPosition(ENTITY_FARM_HORSE, X(752), Y(122), FACING_DOWN);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
