#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_ChickenFestival_OpeningScene(void)
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
    SetEntityPosition(ENTITY_RICK, X(170), Y(233), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_BARLEY, X(140), Y(271), FACING_RIGHT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_SAIBARA, X(193), Y(155), FACING_DOWN);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(289), Y(224), FACING_LEFT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(88), Y(86), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_POPURI, X(196), Y(296), FACING_UP);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(275), Y(162), FACING_LEFT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    if (GetEntityLocation(ENTITY_FARM_DOG) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_FARM_DOG, X(416), Y(133), FACING_DOWN);
    }
    if (GetEntityLocation(ENTITY_BASKET) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_BASKET, X(416 + 16), Y(133), FACING_DOWN);
    }
    if (GetEntityLocation(ENTITY_BALL) == MAP_ROSE_SQUARE)
    {
        SetEntityPosition(ENTITY_BALL, X(416 + 32), Y(133), FACING_DOWN);
    }
    EnableScriptedNpcControl();
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    VarSet(VAR_CHICKEN_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
    SetEntityEventScript(ENTITY_RICK, EventScript_FestivalEvent_ChickenFestival_Opening);
    SetEntityEventScript(ENTITY_BARLEY, EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Barley);
    SetEntityEventScript(ENTITY_SAIBARA, EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Saibara);
    SetEntityEventScript(ENTITY_DUKE, EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Duke);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Thomas);
    SetEntityEventScript(ENTITY_POPURI, EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Popuri);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Doug);
}
