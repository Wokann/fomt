#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterInvitesPlayerToWeddingCelebration[] =
        "Hi there, {Player}.\r\n"
        "Today is Elli and the \r\n"
        "Doctor's wedding day!! {Press}\p"
        "Come celebrate with us! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_ChoiceAttendWedding[] =
        "OK!";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_ChoiceKeepWorking[] =
        "I've got work to do.";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterWelcomesPlayerToCelebration[] =
        "Let's celebrate, then! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterToastsElliAndDoctor[] =
        "To the young couple! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterInvitesPlayerToComeLater[] =
        "Well, come by if you get \r\n"
        "a chance. {Press}";
};

void EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice(void)
{
    int var_0;
    ChangeMap(MAP_CHURCH, X(184), Y(320));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_WEDDING);
    SetEntityPosition(ENTITY_ELLI, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLI, ANIMATION_ELLI_WEDDING_IDLE);
    SetEntityPosition(ENTITY_DOCTOR, X(168), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_DOCTOR, ANIMATION_DOCTOR_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CARTER, X(144), Y(152), FACING_RIGHT);
    SetEntityAnim(ENTITY_CARTER, ANIMATION_CARTER_IDLE);
    SetEntityPosition(ENTITY_PLAYER, X(184), Y(320), FACING_UP);
    if (IsPlayerHoldingNothing())
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_EMPTY_HANDED);
    }
    else
    {
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_IDLE_HOLDING_ITEM);
    }
    SetEntityPosition(ENTITY_ELLEN, X(264), Y(120), FACING_DOWN);
    SetEntityAnim(ENTITY_ELLEN, ANIMATION_ELLEN_IDLE);
    SetEntityPosition(ENTITY_STU, X(264), Y(195), FACING_LEFT);
    SetEntityAnim(ENTITY_STU, ANIMATION_STU_IDLE);
    SetEntityPosition(ENTITY_HARRIS, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_HARRIS, ANIMATION_HARRIS_IDLE);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CLIFF);
    }
    if (GetEntityLocation(ENTITY_JEFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_JEFF);
    }
    if (GetEntityLocation(ENTITY_DUKE) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DUKE);
    }
    if (GetEntityLocation(ENTITY_MANNA) == MAP_CHURCH)
    {
        HideEntity(ENTITY_MANNA);
    }
    if (GetEntityLocation(ENTITY_POPURI) == MAP_CHURCH)
    {
        HideEntity(ENTITY_POPURI);
    }
    if (VarGet(VAR_ELLI_DOCTOR_WEDDING_ATTENDANCE_DEFERRED) == FALSE)
    {
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        PanCameraTo(X(184), Y(160), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
        WaitForCameraMovement();
        SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterInvitesPlayerToWeddingCelebration);
        TalkClose();
        TalkOpen();
        var_0 = TalkChoice2(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_ChoiceAttendWedding, gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_ChoiceKeepWorking);
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                AddNpcFriendship(CHARACTER_CARTER, 20);
                AddNpcFriendship(CHARACTER_ELLEN, 20);
                AddNpcFriendship(CHARACTER_STU, 20);
                AddNpcFriendship(CHARACTER_HARRIS, 20);
                SetNpcFriendship(CHARACTER_ELLI, 200);
                SetNpcFriendship(CHARACTER_DOCTOR, 200);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterWelcomesPlayerToCelebration);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterToastsElliAndDoctor);
                TalkClose();
                MarkNpcSpokenTo(CHARACTER_CARTER);
                VarSet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                VarSet(VAR_ELLI_DOCTOR_WEDDING_MISSED, FALSE);
                VarSet(VAR_ELLI_AND_DOCTOR_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                break;
            case CHOICE_OPTION_2:
                VarSet(VAR_ELLI_DOCTOR_WEDDING_ATTENDANCE_DEFERRED, TRUE);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceChoice_CarterInvitesPlayerToComeLater);
                TalkClose();
                SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
                PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
                WaitForCameraMovement();
                EnableScriptedNpcControl();
                MarkNpcSpokenTo(CHARACTER_CARTER);
                SetEntityEventScript(ENTITY_DOCTOR, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue);
                SetEntityEventScript(ENTITY_ELLEN, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue);
                SetEntityEventScript(ENTITY_ELLI, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue);
                SetEntityEventScript(ENTITY_STU, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupStuDialogue);
                SetEntityEventScript(ENTITY_HARRIS, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue);
                SetEntityEventScript(ENTITY_CARTER, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice);
                VarSet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
                break;
        }
    }
    else
    {
        EnableScriptedNpcControl();
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        SetEntityEventScript(ENTITY_DOCTOR, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue);
        SetEntityEventScript(ENTITY_ELLEN, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue);
        SetEntityEventScript(ENTITY_ELLI, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue);
        SetEntityEventScript(ENTITY_STU, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupStuDialogue);
        SetEntityEventScript(ENTITY_HARRIS, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue);
        SetEntityEventScript(ENTITY_CARTER, EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice);
        VarSet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
    }
}
