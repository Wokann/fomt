#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_SpringHorseRace_Opening(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    SetEntityPosition(ENTITY_RICK, X(356), Y(366), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    if (VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) != EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) != MARRIAGE_STATE_MARRIED)
    {
        SetEntityPosition(ENTITY_POPURI, X(340), Y(315), FACING_UP);
        SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    }
    SetEntityPosition(ENTITY_BARLEY, X(104), Y(166), FACING_RIGHT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_MAY, X(88), Y(171), FACING_RIGHT);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityPosition(ENTITY_SAIBARA, X(115), Y(295), FACING_UP);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(336), Y(138), FACING_LEFT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityPosition(ENTITY_MANNA, X(62), Y(371), FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(85), Y(91), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_HARRIS, X(326), Y(89), FACING_DOWN);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(79), Y(368), FACING_DOWN);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(98), Y(386), FACING_LEFT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(362), Y(341), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(343), Y(156), FACING_LEFT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_ANN, X(290), Y(361), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_ZACK, X(162), Y(91), FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
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
    VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
    SetEntityEventScript(ENTITY_RICK, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Rick);
    SetEntityEventScript(ENTITY_POPURI, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Popuri);
    SetEntityEventScript(ENTITY_BARLEY, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Barley);
    SetEntityEventScript(ENTITY_MAY, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_May);
    SetEntityEventScript(ENTITY_SAIBARA, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Saibara);
    SetEntityEventScript(ENTITY_DUKE, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Duke);
    SetEntityEventScript(ENTITY_MANNA, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas);
    SetEntityEventScript(ENTITY_HARRIS, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Harris);
    SetEntityEventScript(ENTITY_JEFF, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Jeff);
    SetEntityEventScript(ENTITY_SASHA, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Sasha);
    SetEntityEventScript(ENTITY_KAREN, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Karen);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Doug);
    SetEntityEventScript(ENTITY_ANN, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Ann);
    SetEntityEventScript(ENTITY_ZACK, EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Zack);
}
