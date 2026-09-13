#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_CarterAsksWhetherFarmWorkIsFinished[] =
        "仕事は終わったかい？{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_ChoiceFinishedWork[] =
        "おわった";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_ChoiceContinueWorking[] =
        "のこっている";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_CarterBeginsWeddingCelebration[] =
        "じゃあ、のもう。{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_GuestsToastNewlyweds[] =
        "わかい２人にカンパイ！！{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_CarterInvitesPlayerWhenReady[] =
        "そうか、じゃあ手が空いたら\r\n"
        "来るといいよ。{Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_CarterAsksWhetherFarmWorkIsFinished);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_ChoiceFinishedWork, gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_ChoiceContinueWorking);
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
            TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_CarterBeginsWeddingCelebration);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_GuestsToastNewlyweds);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_CARTER);
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_CARTER);
            ClearEntityEventScript(ENTITY_RICK);
            ClearEntityEventScript(ENTITY_LILLIA);
            ClearEntityEventScript(ENTITY_JEFF);
            ClearEntityEventScript(ENTITY_KAREN);
            ClearEntityEventScript(ENTITY_SASHA);
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
            TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_AttendanceAfterWorkChoice_CarterInvitesPlayerWhenReady);
            TalkClose();
            SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
            MarkNpcSpokenTo(CHARACTER_CARTER);
            VarSet(VAR_RICK_KAREN_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
            break;
    }
}
