#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_CarterInvitesPlayerToCelebrateWedding[] =
        "やぁ、{Player}\r\n"
        "くんじゃないか。{Press}\p"
        "今日は、ランとクリフの\r\n"
        "結婚式なんだ。{Press}\p"
        "２人の幸せをいわって、\r\n"
        "いっしょに朝までのまないか？{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_ChoiceCelebrateWedding[] =
        "のむ";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_ChoiceKeepWorking[] =
        "まだ仕事がのこっている";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_CarterWelcomesPlayerToCelebration[] =
        "じゃあ、のもう。{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_GuestsToastNewlyweds[] =
        "わかい２人にカンパイ！！{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_CarterInvitesPlayerToJoinWhenFree[] =
        "そうか、じゃあ手が空いたら\r\n"
        "来るといいよ。{Press}";
};

void EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice(void)
{
    int var_0;
    ChangeMap(MAP_CHURCH, X(184), Y(320));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_WEDDING);
    SetEntityPosition(ENTITY_ANN, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_ANN, ANIMATION_ANN_WEDDING_IDLE);
    SetEntityPosition(ENTITY_CLIFF, X(168), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_WEDDING_IDLE);
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
    SetEntityPosition(ENTITY_MANNA, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_MANNA, ANIMATION_MANNA_IDLE);
    SetEntityPosition(ENTITY_DUKE, X(72), Y(195), FACING_RIGHT);
    SetEntityAnim(ENTITY_DUKE, ANIMATION_DUKE_IDLE);
    SetEntityPosition(ENTITY_DOUG, X(264), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_DOUG, ANIMATION_DOUG_IDLE);
    if (GetEntityLocation(ENTITY_JEFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_JEFF);
    }
    if (GetEntityLocation(ENTITY_DOCTOR) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DOCTOR);
    }
    if (GetEntityLocation(ENTITY_POPURI) == MAP_CHURCH)
    {
        HideEntity(ENTITY_POPURI);
    }
    if (VarGet(VAR_ANN_CLIFF_WEDDING_ATTENDANCE_DEFERRED) == FALSE)
    {
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        PanCameraTo(X(184), Y(160), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
        WaitForCameraMovement();
        SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_CarterInvitesPlayerToCelebrateWedding);
        TalkClose();
        TalkOpen();
        var_0 = TalkChoice2(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_ChoiceCelebrateWedding, gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_ChoiceKeepWorking);
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                AddNpcFriendship(CHARACTER_CARTER, 20);
                AddNpcFriendship(CHARACTER_MANNA, 20);
                AddNpcFriendship(CHARACTER_DUKE, 20);
                AddNpcFriendship(CHARACTER_DOUG, 20);
                SetNpcFriendship(CHARACTER_ANN, 200);
                SetNpcFriendship(CHARACTER_CLIFF, 200);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_CarterWelcomesPlayerToCelebration);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_GuestsToastNewlyweds);
                TalkClose();
                MarkNpcSpokenTo(CHARACTER_CARTER);
                VarSet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                VarSet(VAR_ANN_CLIFF_WEDDING_MISSED, FALSE);
                VarSet(VAR_ANN_AND_CLIFF_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                break;
            case CHOICE_OPTION_2:
                VarSet(VAR_ANN_CLIFF_WEDDING_ATTENDANCE_DEFERRED, TRUE);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceChoice_CarterInvitesPlayerToJoinWhenFree);
                TalkClose();
                SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
                PanCameraTo(X(GetEntityX(ENTITY_PLAYER)), Y(GetEntityY(ENTITY_PLAYER)), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
                WaitForCameraMovement();
                EnableScriptedNpcControl();
                MarkNpcSpokenTo(CHARACTER_CARTER);
                SetEntityEventScript(ENTITY_CLIFF, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupCliffDialogue);
                SetEntityEventScript(ENTITY_DOUG, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue);
                SetEntityEventScript(ENTITY_ANN, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupAnnDialogue);
                SetEntityEventScript(ENTITY_DUKE, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDukeDialogue);
                SetEntityEventScript(ENTITY_MANNA, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue);
                SetEntityEventScript(ENTITY_CARTER, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice);
                VarSet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
                break;
        }
    }
    else
    {
        EnableScriptedNpcControl();
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        SetEntityEventScript(ENTITY_CLIFF, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupCliffDialogue);
        SetEntityEventScript(ENTITY_DOUG, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue);
        SetEntityEventScript(ENTITY_ANN, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupAnnDialogue);
        SetEntityEventScript(ENTITY_DUKE, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDukeDialogue);
        SetEntityEventScript(ENTITY_MANNA, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue);
        SetEntityEventScript(ENTITY_CARTER, EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice);
        VarSet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
    }
}
