#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_FrisbeeTournament_Opening(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
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
    if (GetEntityLocation(ENTITY_BASKET) == MAP_MINERAL_BEACH)
    {
        SetEntityPosition(ENTITY_BASKET, X(119), Y(405), FACING_DOWN);
    }
    if (GetEntityLocation(ENTITY_BALL) == MAP_MINERAL_BEACH)
    {
        SetEntityPosition(ENTITY_BALL, X(119 + 16), Y(405), FACING_DOWN);
    }
    EnableScriptedNpcControl();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_BEACH_DAY_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas);
    SetEntityEventScript(ENTITY_JEFF, EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Jeff);
    SetEntityEventScript(ENTITY_SASHA, EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha);
    SetEntityEventScript(ENTITY_KAI, EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai);
    SetEntityEventScript(ENTITY_POPURI, EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Popuri);
    SetEntityEventScript(ENTITY_ZACK, EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack);
}
