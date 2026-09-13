#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_FireworksFestival_Opening(void)
{
    ChangeMap(MAP_MINERAL_BEACH, X(24), Y(280));
    PlayBGM(AUDIO_START_WEAK, AUDIO_AMBIENCE_BEACH);
    SetEntityPosition(ENTITY_PLAYER, X(24), Y(280), FACING_RIGHT);
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    SetEntityPosition(ENTITY_RICK, X(241), Y(124), FACING_RIGHT);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(234), Y(186), FACING_RIGHT);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(258), Y(330), FACING_RIGHT);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE)
    {
        SetEntityPosition(ENTITY_CLIFF, X(166), Y(361), FACING_RIGHT);
        SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    }
    SetEntityPosition(ENTITY_KAI, X(58), Y(228), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAI, ANIMATION_KAI_IDLE);
    SetEntityPosition(ENTITY_KAREN, X(231), Y(146), FACING_RIGHT);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(192), Y(398), FACING_RIGHT);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_ANN, X(198), Y(345), FACING_RIGHT);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_IDLE);
    SetEntityPosition(ENTITY_POPURI, X(58), Y(188), FACING_RIGHT);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_MARY, X(250), Y(226), FACING_RIGHT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_ELLI, EventScript_FestivalEvent_FireworksFestival_Invitation_Elli);
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_FestivalEvent_FireworksFestival_Dialogue_Doctor);
    SetEntityEventScript(ENTITY_GRAY, EventScript_FestivalEvent_FireworksFestival_Dialogue_Gray);
    SetEntityEventScript(ENTITY_ANN, EventScript_FestivalEvent_FireworksFestival_Invitation_Ann);
    SetEntityEventScript(ENTITY_CLIFF, EventScript_FestivalEvent_FireworksFestival_Dialogue_Cliff);
    SetEntityEventScript(ENTITY_KAREN, EventScript_FestivalEvent_FireworksFestival_Invitation_Karen);
    SetEntityEventScript(ENTITY_KAI, EventScript_FestivalEvent_FireworksFestival_Dialogue_Kai);
    SetEntityEventScript(ENTITY_MARY, EventScript_FestivalEvent_FireworksFestival_Invitation_Mary);
    SetEntityEventScript(ENTITY_RICK, EventScript_FestivalEvent_FireworksFestival_Dialogue_Rick);
    SetEntityEventScript(ENTITY_POPURI, EventScript_FestivalEvent_FireworksFestival_Invitation_Popuri);
    VarSet(VAR_FIREWORKS_FESTIVAL_ACTIVE, FESTIVAL_PHASE_INITIAL);
}
