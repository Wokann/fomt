#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_CarterAsksIfPlayerFinishedWork[] =
        "Are you done with work? {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_ChoiceFinishedWork[] =
        "Yes.";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_ChoiceWorkRemains[] =
        "Not yet.";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_CarterWelcomesPlayerToCelebration[] =
        "Let's celebrate! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_CarterToastsElliAndDoctor[] =
        "To the young couple!! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_CarterInvitesPlayerWhenFree[] =
        "Well, come join us if you \r\n"
        "have the time. {Press}";
};

void EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_CarterAsksIfPlayerFinishedWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_ChoiceFinishedWork, gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_ChoiceWorkRemains);
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
            TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_CarterWelcomesPlayerToCelebration);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_CarterToastsElliAndDoctor);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_CARTER);
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_DOCTOR);
            ClearEntityEventScript(ENTITY_ELLEN);
            ClearEntityEventScript(ENTITY_ELLI);
            ClearEntityEventScript(ENTITY_STU);
            ClearEntityEventScript(ENTITY_HARRIS);
            ClearEntityEventScript(ENTITY_CARTER);
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
            TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_AttendanceAfterWorkChoice_CarterInvitesPlayerWhenFree);
            TalkClose();
            SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
            MarkNpcSpokenTo(CHARACTER_CARTER);
            VarSet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
            break;
    }
}
