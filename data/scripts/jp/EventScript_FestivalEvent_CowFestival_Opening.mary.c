#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

void EventScript_FestivalEvent_CowFestival_Opening(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_ANIMAL_FESTIVAL);
    if (IsPlayerHoldingNothing() == TRUE)
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_BARLEY, X(85), Y(91), FACING_DOWN);
    SetEntityAnim(ENTITY_BARLEY, ANIMATION_BARLEY_IDLE);
    SetEntityPosition(ENTITY_RICK, X(130), Y(310), FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_IDLE);
    SetEntityPosition(ENTITY_POPURI, X(90), Y(319), FACING_DOWN);
    SetEntityAnim(ENTITY_POPURI, ANIMATION_POPURI_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(76), Y(345), FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_MAY, X(256), Y(115), FACING_LEFT);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityPosition(ENTITY_STU, X(220), Y(133), FACING_UP);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(196), Y(92), FACING_DOWN);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
    SetEntityPosition(ENTITY_ELLI, X(235), Y(87), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
    SetEntityPosition(ENTITY_MARY, X(380), Y(316), FACING_LEFT);
    SetEntityAnim(ENTITY_MARY, ANIMATION_MARY_IDLE);
    SetEntityPosition(ENTITY_BASIL, X(352), Y(334), FACING_UP);
    SetEntityAnim(ENTITY_BASIL, ANIMATION_BASIL_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(354), Y(289), FACING_DOWN);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1, X(99), Y(335), FACING_RIGHT);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1, ENTITY_AUX_RENDER_LIVESTOCK);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1, ANIMATION_COW_IDLE);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2, X(350), Y(306), FACING_RIGHT);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2, ENTITY_AUX_RENDER_LIVESTOCK);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2, ANIMATION_COW_IDLE);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3, X(222), Y(109), FACING_LEFT);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3, ENTITY_AUX_RENDER_LIVESTOCK);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3, ANIMATION_COW_IDLE);
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
    VarSet(VAR_COW_FESTIVAL_SESSION_STATE, FESTIVAL_PHASE_INITIAL);
    SetEntityEventScript(ENTITY_RICK, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Rick);
    SetEntityEventScript(ENTITY_POPURI, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Popuri);
    SetEntityEventScript(ENTITY_BARLEY, EventScript_FestivalEvent_CowFestival_StartJudgingChoice_Barley);
    SetEntityEventScript(ENTITY_MAY, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_May);
    SetEntityEventScript(ENTITY_BASIL, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Basil);
    SetEntityEventScript(ENTITY_MARY, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Mary);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Thomas);
    SetEntityEventScript(ENTITY_STU, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Stu);
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Doctor);
    SetEntityEventScript(ENTITY_ELLI, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Elli);
    SetEntityEventScript(ENTITY_CARTER, EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Carter);
    SetEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1, EventScript_FestivalEvent_CowFestival_JudgingFanfare);
    SetEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2, EventScript_FestivalEvent_CowFestival_JudgingFanfare);
    SetEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3, EventScript_FestivalEvent_CowFestival_JudgingFanfare);
}
