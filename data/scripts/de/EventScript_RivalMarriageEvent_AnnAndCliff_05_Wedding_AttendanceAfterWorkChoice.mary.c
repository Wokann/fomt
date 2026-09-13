#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_CarterAsksWhetherPlayerFinishedWork[] =
        "Bist du fertig mit \r\n"
        "deiner Arbeit?{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_ChoiceFinishedWork[] =
        "Ja.";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_ChoiceStillWorking[] =
        "Noch nicht.";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_CarterWelcomesPlayerToCelebration[] =
        "Dann feiern wir! {Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_GuestsToastNewlyweds[] =
        "Auf das junge Paar!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_CarterInvitesPlayerToJoinWhenFree[] =
        "Komm, wenn du kannst. {Press}";
};

void EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice(void)
{
    int var_0;
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_CarterAsksWhetherPlayerFinishedWork);
    TalkClose();
    TalkOpen();
    var_0 = TalkChoice2(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_ChoiceFinishedWork, gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_ChoiceStillWorking);
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
            TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_CarterWelcomesPlayerToCelebration);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            TalkOpen();
            TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_GuestsToastNewlyweds);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_CARTER);
            DisableScriptedNpcControl();
            ClearEntityEventScript(ENTITY_CLIFF);
            ClearEntityEventScript(ENTITY_DOUG);
            ClearEntityEventScript(ENTITY_ANN);
            ClearEntityEventScript(ENTITY_DUKE);
            ClearEntityEventScript(ENTITY_MANNA);
            ClearEntityEventScript(ENTITY_CARTER);
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
            TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_AttendanceAfterWorkChoice_CarterInvitesPlayerToJoinWhenFree);
            TalkClose();
            SetEntityFacing(ENTITY_CARTER, FACING_RIGHT);
            MarkNpcSpokenTo(CHARACTER_CARTER);
            VarSet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE, MARRIAGE_STATE_WEDDING_IN_PROGRESS);
            break;
    }
}
