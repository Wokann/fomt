#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_CarterAsksIfPlayerFinishedWork[] =
        "Bist du fertig mit \r\n"
        "deiner Arbeit? {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_ChoiceFinishedWork[] =
        "Ja.";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_ChoiceStillWorking[] =
        "Noch nicht.";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_CarterBeginsWeddingCelebration[] =
        "Lass uns feiern! {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_GuestsToastYoungCouple[] =
        "Auf das junge Paar!! {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_CarterInvitesPlayerToJoinLater[] =
        "Mach einfach mit, wenn \r\n"
        "du Zeit hast. {Press}";
};

void EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_CarterAsksIfPlayerFinishedWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_ChoiceFinishedWork, gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_ChoiceStillWorking);
    switch (var_0)
    {
        case CHOICE_OPTION_1:
            AddNpcFriendship(CHARACTER_CARTER, 20);
            AddNpcFriendship(CHARACTER_LILLIA, 20);
            AddNpcFriendship(CHARACTER_RICK, 20);
            AddNpcFriendship(CHARACTER_KAREN, 20);
            SetNpcFriendship(CHARACTER_POPURI, 200);
            SetNpcFriendship(CHARACTER_KAI, 200);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_CarterBeginsWeddingCelebration);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_GuestsToastYoungCouple);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_CARTER);
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_RICK);
            ClearEntityEventScript(ENTITY_POPURI);
            ClearEntityEventScript(ENTITY_LILLIA);
            ClearEntityEventScript(ENTITY_KAREN);
            ClearEntityEventScript(ENTITY_CARTER);
            ClearEntityEventScript(ENTITY_KAI);
            VarSet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_MARRIED);
            VarSet(VAR_POPURI_KAI_WEDDING_MISSED, FALSE);
            VarSet(VAR_POPURI_AND_KAI_RIVAL_WEDDING_ROUTING_STATE, FALSE);
            CallScript(EventScript_SystemEvent_PreserveLocationAndAdvanceToNextDay);
            break;
        case CHOICE_OPTION_2:
            VarSet(VAR_POPURI_KAI_WEDDING_ATTENDANCE_DEFERRED, TRUE);
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_AttendanceAfterWorkChoice_CarterInvitesPlayerToJoinLater);
            TalkClose();
            SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
            MarkNpcSpokenTo(CHARACTER_CARTER);
            VarSet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
            break;
    }
}
