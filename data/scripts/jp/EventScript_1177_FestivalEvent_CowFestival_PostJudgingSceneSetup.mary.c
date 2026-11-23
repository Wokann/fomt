#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1177_FestivalEvent_CowFestival_PostJudgingSceneSetup.mary.h"

void EventScript_1177_FestivalEvent_CowFestival_PostJudgingSceneSetup(void)
{
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_ANIMAL_FESTIVAL);
    SetGameTime(18, 1);
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
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingSceneSetup_ThomasAnnouncesFestivalClosingAndCowReturn);
    TalkClose();
    SetEntityEventScript(ENTITY_RICK, EventScript_1178_FestivalEvent_CowFestival_PostJudgingDialogue_Rick);
    SetEntityEventScript(ENTITY_POPURI, EventScript_1179_FestivalEvent_CowFestival_PostJudgingDialogue_Popuri);
    SetEntityEventScript(ENTITY_BARLEY, EventScript_1188_FestivalEvent_CowFestival_PostJudgingDialogue_Barley);
    SetEntityEventScript(ENTITY_MAY, EventScript_1187_FestivalEvent_CowFestival_PostJudgingDialogue_May);
    SetEntityEventScript(ENTITY_BASIL, EventScript_1181_FestivalEvent_CowFestival_PostJudgingDialogue_Basil);
    SetEntityEventScript(ENTITY_MARY, EventScript_1182_FestivalEvent_CowFestival_PostJudgingDialogue_Mary);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_1183_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas);
    SetEntityEventScript(ENTITY_STU, EventScript_1185_FestivalEvent_CowFestival_PostJudgingDialogue_Stu);
    SetEntityEventScript(ENTITY_DOCTOR, EventScript_1180_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor);
    SetEntityEventScript(ENTITY_ELLI, EventScript_1184_FestivalEvent_CowFestival_PostJudgingDialogue_Elli);
    SetEntityEventScript(ENTITY_CARTER, EventScript_1186_FestivalEvent_CowFestival_PostJudgingDialogue_Carter);
}
