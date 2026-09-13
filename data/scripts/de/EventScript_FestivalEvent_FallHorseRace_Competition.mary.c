#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_FallHorseRace_Competition(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    SetGameTime(18, 1);
    SetEntityPosition(ENTITY_THOMAS, X(85), Y(91), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT) == FESTIVAL_HORSE_RACE_RESULT_WON)
    {
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
    else
    {
        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_FallHorseRace_MedalExchangeAfterClosing);
}
