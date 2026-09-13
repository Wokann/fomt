#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearSunrise_FestivalOpening_Doug[] =
        "そろそろ時間だな…{Press}";

    const char gText_FestivalEvent_NewYearSunrise_FestivalWish_Doug[] =
        "この町にとって、\r\n"
        "今年が、いい年で\r\n"
        "ありますように…{Press}";
};

void EventScript_FestivalEvent_NewYearSunrise_FestivalOpening_Doug(void)
{
    ChangeMap(MAP_MOTHERS_HILL_SUMMIT, X(236), Y(265));
    SetEntityPosition(ENTITY_PLAYER, X(249), Y(285), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    if (VarGet(VAR_TOLD_CLIFF_ABOUT_GRAPE_HARVEST_JOB) == TRUE)
    {
        SetEntityPosition(ENTITY_CLIFF, X(161), Y(402), FACING_UP);
        SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
    }
    SetEntityPosition(ENTITY_DOUG, X(273), Y(285), FACING_UP);
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
    WaitFrames(60);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FestivalEvent_NewYearSunrise_FestivalOpening_Doug);
    TalkClose();
    WaitFrames(60);
    PanCameraTo(X(236), Y(170), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
    WaitForCameraMovement();
    VarSet(VAR_NEW_YEAR_SUNRISE_SCENE_WRITE_MARKER, TRUE);
    WaitFrames(60 * 3);
    CreateNewYearSunriseEffect();
    PlayNewYearSunriseEffect();
    WaitFrames(60 * 2);
    FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_NORMAL);
    DestroyNewYearSunriseEffect();
    TalkOpen();
    TalkMessage(gText_FestivalEvent_NewYearSunrise_FestivalWish_Doug);
    TalkClose();
    DisableScriptedNpcControl();
    ClearEntityEventScript(ENTITY_CLIFF);
    ClearEntityEventScript(ENTITY_DOUG);
    ClearEntityEventScript(ENTITY_BASIL);
    ClearEntityEventScript(ENTITY_MARY);
    ClearEntityEventScript(ENTITY_ANNA);
    ClearEntityEventScript(ENTITY_GRAY);
    ClearEntityEventScript(ENTITY_SAIBARA);
    VarSet(VAR_NEW_YEAR_SUNRISE_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
