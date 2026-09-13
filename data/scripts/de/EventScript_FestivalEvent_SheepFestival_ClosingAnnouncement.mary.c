#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_ClosingAnnouncement[] =
        "Das Schaffestival ist \r\n"
        "vorbei. Wir bringen\r\n"
        "die Schafe für euch heim,{Press}\r\n"
        "also geht bitte nach Hause.{Press}";
};

void EventScript_FestivalEvent_SheepFestival_ClosingAnnouncement(void)
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
    SetEntityPosition(ENTITY_KAREN, X(90), Y(319), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_IDLE);
    SetEntityPosition(ENTITY_THOMAS, X(76), Y(345), FACING_RIGHT);
    SetEntityAnim(ENTITY_THOMAS, ANIMATION_THOMAS_IDLE);
    SetEntityPosition(ENTITY_MAY, X(256), Y(115), FACING_LEFT);
    SetEntityAnim(ENTITY_MAY, ANIMATION_MAY_IDLE);
    SetEntityPosition(ENTITY_ANNA, X(220), Y(133), FACING_UP);
    SetEntityAnim(ENTITY_ANNA, ANIMATION_ANNA_IDLE);
    SetEntityPosition(ENTITY_HARRIS, X(196), Y(92), FACING_DOWN);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(380), Y(316), FACING_LEFT);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_GRAY, X(352), Y(334), FACING_UP);
    SetEntityAnim(ENTITY_GRAY, ANIMATION_GRAY_IDLE);
    SetEntityPosition(ENTITY_GOTZ, X(354), Y(289), FACING_DOWN);
    SetEntityAnim(ENTITY_GOTZ, ANIMATION_GOTZ_IDLE);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1, X(99), Y(335), FACING_RIGHT);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1, ENTITY_AUX_RENDER_LIVESTOCK);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1, ANIMATION_SHEEP_IDLE);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2, X(350), Y(306), FACING_RIGHT);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2, ENTITY_AUX_RENDER_LIVESTOCK);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2, ANIMATION_SHEEP_IDLE);
    SetEntityPosition(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3, X(222), Y(109), FACING_LEFT);
    SetEntityAuxRenderProfile(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3, ENTITY_AUX_RENDER_LIVESTOCK);
    SetEntityAnim(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3, ANIMATION_SHEEP_IDLE);
    FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    TalkOpen();
    TalkMessage(gText_FestivalEvent_SheepFestival_ClosingAnnouncement);
    TalkClose();
    SetEntityEventScript(ENTITY_RICK, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick);
    SetEntityEventScript(ENTITY_KAREN, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Karen);
    SetEntityEventScript(ENTITY_BARLEY, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley);
    SetEntityEventScript(ENTITY_MAY, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_May);
    SetEntityEventScript(ENTITY_HARRIS, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Harris);
    SetEntityEventScript(ENTITY_ANNA, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Anna);
    SetEntityEventScript(ENTITY_THOMAS, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Thomas);
    SetEntityEventScript(ENTITY_GOTZ, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Gotz);
    SetEntityEventScript(ENTITY_GRAY, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Gray);
    SetEntityEventScript(ENTITY_JEFF, EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Jeff);
    SetEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_1, EventScript_FestivalEvent_SheepFestival_JudgingFanfare);
    SetEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_2, EventScript_FestivalEvent_SheepFestival_JudgingFanfare);
    SetEntityEventScript(ENTITY_SCRIPT_VISUAL_EFFECT_SLOT_3, EventScript_FestivalEvent_SheepFestival_JudgingFanfare);
}
