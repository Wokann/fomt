#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_CarterInvitesPlayerToWedding[] =
        "やぁ、{Player}\r\n"
        "くんじゃないか。{Press}\p"
        "今日は、カレンとリックの\r\n"
        "結婚式なんだ。{Press}\p"
        "２人の幸せをいわって、\r\n"
        "いっしょに朝までのまないか？{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_ChoiceAttendWedding[] =
        "のむ";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_ChoiceKeepWorking[] =
        "まだ仕事がのこっている";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_CarterBeginsWeddingCelebration[] =
        "じゃあ、のもう。{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_GuestsToastNewlyweds[] =
        "わかい２人にカンパイ！！{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_CarterInvitesPlayerAfterWork[] =
        "そうか、じゃあ手が空いたら\r\n"
        "来るといいよ。{Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice(void)
{
    int var_0, var_1;
    mary_nodisc(var_1 = 1);
    var_1 = 0;
    ChangeMap(MAP_CHURCH, X(184), Y(320));
    PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_WEDDING);
    SetEntityPosition(ENTITY_KAREN, X(200), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_KAREN, ANIMATION_KAREN_WEDDING_IDLE);
    SetEntityPosition(ENTITY_RICK, X(168), Y(152), FACING_DOWN);
    SetEntityAnim(ENTITY_RICK, ANIMATION_RICK_WEDDING_IDLE);
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
    SetEntityPosition(ENTITY_LILLIA, X(104), Y(155), FACING_RIGHT);
    SetEntityAnim(ENTITY_LILLIA, ANIMATION_LILLIA_IDLE);
    SetEntityPosition(ENTITY_JEFF, X(296), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_JEFF, ANIMATION_JEFF_IDLE);
    SetEntityPosition(ENTITY_SASHA, X(264), Y(155), FACING_LEFT);
    SetEntityAnim(ENTITY_SASHA, ANIMATION_SASHA_IDLE);
    if (GetEntityLocation(ENTITY_CLIFF) == MAP_CHURCH)
    {
        HideEntity(ENTITY_CLIFF);
    }
    if (GetEntityLocation(ENTITY_DOCTOR) == MAP_CHURCH)
    {
        HideEntity(ENTITY_DOCTOR);
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
    if (VarGet(VAR_RICK_KAREN_WEDDING_ATTENDANCE_DEFERRED) == FALSE)
    {
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        PanCameraTo(X(184), Y(160), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
        WaitForCameraMovement();
        SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_CarterInvitesPlayerToWedding);
        TalkClose();
        TalkOpen();
        var_0 = TalkChoice2(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_ChoiceAttendWedding, gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_ChoiceKeepWorking);
        switch (var_0)
        {
            case CHOICE_OPTION_1:
                AddNpcFriendship(CHARACTER_KAREN, 20);
                AddNpcFriendship(CHARACTER_CARTER, 20);
                AddNpcFriendship(CHARACTER_LILLIA, 20);
                AddNpcFriendship(CHARACTER_JEFF, 20);
                AddNpcFriendship(CHARACTER_SASHA, 20);
                SetNpcFriendship(CHARACTER_RICK, 200);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_CarterBeginsWeddingCelebration);
                TalkClose();
                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                TalkOpen();
                TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_GuestsToastNewlyweds);
                TalkClose();
                MarkNpcSpokenTo(CHARACTER_CARTER);
                VarSet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
                VarSet(VAR_RICK_KAREN_WEDDING_MISSED, FALSE);
                VarSet(VAR_RICK_AND_KAREN_RIVAL_WEDDING_ROUTING_STATE, FALSE);
                CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
                break;
            case CHOICE_OPTION_2:
                VarSet(VAR_RICK_KAREN_WEDDING_ATTENDANCE_DEFERRED, TRUE);
                TalkClose();
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_CARTER);
                TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceChoice_CarterInvitesPlayerAfterWork);
                TalkClose();
                SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
                PanCameraTo(X(184), Y(320), CAMERA_MOVE_SPEED_NOMINAL_1_PIXEL_PER_UPDATE);
                WaitForCameraMovement();
                EnableScriptedNpcControl();
                MarkNpcSpokenTo(CHARACTER_CARTER);
                SetEntityEventScript(ENTITY_CARTER, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice);
                SetEntityEventScript(ENTITY_RICK, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue);
                SetEntityEventScript(ENTITY_LILLIA, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue);
                SetEntityEventScript(ENTITY_JEFF, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupJeffDialogue);
                SetEntityEventScript(ENTITY_KAREN, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue);
                SetEntityEventScript(ENTITY_SASHA, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue);
                VarSet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
                break;
        }
    }
    else
    {
        EnableScriptedNpcControl();
        FadeInScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
        SetEntityEventScript(ENTITY_CARTER, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice);
        SetEntityEventScript(ENTITY_RICK, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue);
        SetEntityEventScript(ENTITY_LILLIA, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue);
        SetEntityEventScript(ENTITY_JEFF, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupJeffDialogue);
        SetEntityEventScript(ENTITY_KAREN, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue);
        SetEntityEventScript(ENTITY_SASHA, EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue);
        VarSet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
    }
}
