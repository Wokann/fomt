#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_BeachDay_Closing[] =
        "Beach Day is now over. \r\n"
        "We'll return your Dogs to\r\n"
        "your homes, so you can go{Press}\r\n"
        "back home without them. \r\n"
        "Come again next year!{Press}";
};

void EventScript_FestivalEvent_BeachDay_Closing(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    SetGameTime(18, 1);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_THOMAS, X(245), Y(178), FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(128), Y(301), FACING_RIGHT);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(128), Y(260), FACING_RIGHT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_KAI, X(211), Y(318), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityPosition(ENTITY_POPURI, X(231), Y(349), FACING_RIGHT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_ZACK, X(205), Y(131), FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_BeachDay_Closing);
    TalkClose();
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas);
    SetEntityEventScript(ENTITY_JEFF, EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Jeff);
    SetEntityEventScript(ENTITY_SASHA, EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Sasha);
    SetEntityEventScript(ENTITY_KAI, EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Kai);
    SetEntityEventScript(ENTITY_POPURI, EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Popuri);
    SetEntityEventScript(ENTITY_ZACK, EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Zack);
}
