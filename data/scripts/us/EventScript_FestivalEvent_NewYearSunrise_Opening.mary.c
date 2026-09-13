#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_NewYearSunrise_Opening(void)
{
    VarSet(VAR_NEW_YEAR_SUNRISE_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    ChangeMap(MAP_MOTHERS_HILL_SUMMIT, X(236), Y(398));
    PlayBGM(AUDIO_START_WEAK, AUDIO_AMBIENCE_NIGHT);
    SetEntityPosition(ENTITY_PLAYER, X(236), Y(464), FACING_UP);
    if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE)
    {
        SetEntityPosition(ENTITY_CLIFF, X(161), Y(402), FACING_UP);
        SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    }
    SetEntityPosition(ENTITY_DOUG, X(273), Y(268), FACING_UP);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(298), Y(388), FACING_UP);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_BASIL, X(258), Y(410), FACING_UP);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    SetEntityPosition(ENTITY_MARY, X(282), Y(428), FACING_UP);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_SAIBARA, X(191), Y(303), FACING_UP);
    SetEntityAnim(ENTITY_SAIBARA, ANIMATION_SAIBARA_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(281), Y(319), FACING_UP);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    EnableScriptedNpcControl();
    SetEntityEventScript(ENTITY_CLIFF, EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Cliff);
    SetEntityEventScript(ENTITY_DOUG, EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Doug);
    SetEntityEventScript(ENTITY_BASIL, EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Basil);
    SetEntityEventScript(ENTITY_MARY, EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Mary);
    SetEntityEventScript(ENTITY_ANNA, EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Anna);
    SetEntityEventScript(ENTITY_GRAY, EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Gray);
    SetEntityEventScript(ENTITY_SAIBARA, EventScript_FestivalEvent_NewYearSunrise_FestivalDialogue_Saibara);
}
