#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Doctor_PlayerCollapseRecovery_DoctorExplainsPlayerCollapsedFromFatigue[] =
        "I see you're awake now.\r\n"
        "You worked too hard and \r\n"
        "collapsed. {Press}";

    const char gText_NPCEvent_Doctor_PlayerCollapseRecovery_DoctorAdvisesPacingWorkAndOrdersRest[] =
        "You'll have to learn to pace\r\n"
        "yourself better from now on.\r\n"
        "Rest here for today. {Press}";
};

void EventScript_NPCEvent_Doctor_PlayerCollapseRecovery(void)
{
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ExitHotSpringBathingState();
    VarSet(VAR_PLAYER_COLLAPSE_RECOVERY_EVENT_STATE, EVENT_LIFECYCLE_IN_PROGRESS);
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_MINERAL_TOWN);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_MINERAL_CLINIC_1F)
    {
        ChangeMap(MAP_MINERAL_CLINIC_1F, X(241), Y(306));
        SetEntityPosition(ENTITY_PLAYER, X(320 + 112), Y(232), FACING_DOWN);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_CLINIC_BED_SHADOW);
        SetEntityPosition(ENTITY_DOCTOR, X(219), Y(226), FACING_DOWN);
        SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
        SetEntityPosition(ENTITY_CLIFF, X(219), Y(245), FACING_DOWN);
        SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_IDLE);
        SetEntityPosition(ENTITY_ELLI, X(100), Y(257), FACING_RIGHT);
        SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        WaitFrames(30);
        PlaySong(AUDIO_START, AUDIO_SFX_DOCTOR_EXAMINATION);
        SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_GESTURE);
        WaitFrames(30);
        FadeOutScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        FadeInScreen(SCREEN_FADE_STYLE_WHITE, SCREEN_FADE_SPEED_FAST);
        SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_COLLAPSE_FORWARD);
        WaitFrames(60);
        SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
        WaitFrames(30);
        SetEntityFacing(ENTITY_DOCTOR, FACING_UP);
        SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WALK);
        MoveEntityYTo(ENTITY_DOCTOR, Y(143), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_DOCTOR);
        SetEntityFacing(ENTITY_DOCTOR, FACING_RIGHT);
        SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WALK);
        MoveEntityXTo(ENTITY_DOCTOR, X(287), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_DOCTOR);
        SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
        SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WALK);
        MoveEntityYTo(ENTITY_DOCTOR, Y(263), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_DOCTOR);
        SetEntityFacing(ENTITY_DOCTOR, FACING_RIGHT);
        SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WALK);
        MoveEntityXTo(ENTITY_DOCTOR, X(311), ENTITY_MOVE_SPEED_1_PIXEL_PER_FRAME);
        WaitForEntityMovement(ENTITY_DOCTOR);
        SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
        WaitFrames(60);
    }
    else
    {
        ChangeMap(MAP_MINERAL_CLINIC_1F, X(241), Y(306));
        SetEntityPosition(ENTITY_PLAYER, X(320 + 112), Y(232), FACING_DOWN);
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_CLINIC_BED_SHADOW);
        SetEntityPosition(ENTITY_DOCTOR, X(311), Y(263), FACING_RIGHT);
        SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_IDLE);
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    }
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Doctor_PlayerCollapseRecovery_DoctorExplainsPlayerCollapsedFromFatigue);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_MINERAL_CLINIC_1F)
    {
        TalkClose();
        SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WALK);
        MoveEntityXTo(ENTITY_ELLI, X(199), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
        WaitForEntityMovement(ENTITY_ELLI);
        SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_IDLE);
        WaitFrames(30);
        SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_GESTURE);
        WaitFrames(30);
        MoveEntityXTo(ENTITY_ELLI, X(152), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
        MoveEntityXTo(ENTITY_CLIFF, X(169), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
        WaitForEntityMovement(ENTITY_ELLI);
        WaitForEntityMovement(ENTITY_CLIFF);
        SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
        MoveEntityYTo(ENTITY_ELLI, Y(240), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
        MoveEntityXTo(ENTITY_CLIFF, X(152), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
        WaitFrames(30);
        MoveEntityYTo(ENTITY_ELLI, Y(66), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
        MoveEntityYTo(ENTITY_CLIFF, Y(79), ENTITY_MOVE_SPEED_2_PIXELS_PER_FRAME);
        WaitForEntityMovement(ENTITY_ELLI);
        WaitForEntityMovement(ENTITY_CLIFF);
        TalkOpen();
    }
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_NPCEvent_Doctor_PlayerCollapseRecovery_DoctorAdvisesPacingWorkAndOrdersRest);
    TalkClose();
    WaitFrames(30);
    FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
    ChangePlayerStaminaAndFatigue(200, mary_negated_int(-100));
    RelocateEntityToMap(ENTITY_PLAYER, MAP_FARMHOUSE, X(0), Y(0));
    if (VarGet(VAR_HOUR) < 6)
    {
        VarSet(VAR_PLAYER_COLLAPSE_RECOVERY_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    }
    else
    {
        VarSet(VAR_PLAYER_COLLAPSE_RECOVERY_EVENT_STATE, EVENT_LIFECYCLE_NOT_STARTED);
    }
    CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
}
