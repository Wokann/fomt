#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_FallHorseRace_Opening(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
    SetEntityPosition(ENTITY_THOMAS, X(85), Y(91), FACING_DOWN);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_BARLEY, X(104), Y(166), FACING_RIGHT);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_SAIBARA, X(88), Y(171), FACING_RIGHT);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    SetEntityPosition(ENTITY_ZACK, X(159), Y(84), FACING_DOWN);
    SetEntityAnim(ENTITY_ZACK, ANIMATION_ZACK_IDLE);
    SetEntityPosition(ENTITY_GOTZ, X(113), Y(73), FACING_DOWN);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(78), Y(372), FACING_DOWN);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityPosition(ENTITY_MARY, X(97), Y(386), FACING_DOWN);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(329), Y(172), FACING_LEFT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(296), Y(372), FACING_UP);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(353), Y(350), FACING_LEFT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(382), Y(87), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_LILLIA, X(332), Y(329), FACING_LEFT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_RICK, X(366), Y(372), FACING_LEFT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_HARRIS, X(327), Y(74), FACING_DOWN);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(319), Y(138), FACING_LEFT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
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
    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Thomas);
    SetEntityEventScript(ENTITY_BARLEY, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Barley);
    SetEntityEventScript(ENTITY_SAIBARA, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Saibara);
    SetEntityEventScript(ENTITY_ZACK, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Zack);
    SetEntityEventScript(ENTITY_GOTZ, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Gotz);
    SetEntityEventScript(ENTITY_GRAY, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Gray);
    SetEntityEventScript(ENTITY_MARY, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Mary);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Doug);
    SetEntityEventScript(ENTITY_ELLI, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Elli);
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Doctor);
    SetEntityEventScript(ENTITY_CARTER, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Carter);
    SetEntityEventScript(ENTITY_LILLIA, EventScript_FestivalEvent_HorseRacePreRaceDialogue_Lillia);
    SetEntityEventScript(ENTITY_RICK, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Rick);
    SetEntityEventScript(ENTITY_HARRIS, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Harris);
    SetEntityEventScript(ENTITY_DUKE, EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Duke);
}
