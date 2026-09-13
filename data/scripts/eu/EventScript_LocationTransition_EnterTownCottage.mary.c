#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_LocationTransition_EnterTownCottage(void)
{
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        PlaySong(AUDIO_START, AUDIO_SFX_OPEN_DOOR);
        FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        ChangeMap(MAP_TOWN_COTTAGE, X(120), Y(208));
        SetEntityPosition(ENTITY_PLAYER, X(120), Y(208), FACING_UP);
        if (IsFireplaceLitAtLocation(MAP_TOWN_COTTAGE))
        {
            switch (VarGet(VAR_SEASON))
            {
                case SEASON_SPRING:
                    ChangePlayerStaminaAndFatigue(0, 1);
                    break;
                case SEASON_SUMMER:
                    ChangePlayerStaminaAndFatigue(0, 2);
                    break;
                case SEASON_FALL:
                    ChangePlayerStaminaAndFatigue(0, 1);
                    break;
                case SEASON_WINTER:
                    ChangePlayerStaminaAndFatigue(0, mary_negated_int(-1));
                    break;
            }
        }
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
}
