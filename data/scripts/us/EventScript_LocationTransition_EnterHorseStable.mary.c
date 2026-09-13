#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterHorseStable(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_HORSE_STABLE, X(120), Y(208));
        SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
        if (IsPlayerRidingHorse() == TRUE)
        {
            SetEntityPosition(ENTITY_FARM_HORSE, X(120), Y(208), FACING_UP);
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
