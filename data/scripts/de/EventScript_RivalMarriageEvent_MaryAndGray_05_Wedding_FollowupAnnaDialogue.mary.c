#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupAnnaDialogue_AnnaHadThoughtMaryUninterestedInRomance[] =
        "Und ich dachte, Mary hätte\r\n"
        "kein Interesse an Jungen!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupAnnaDialogue_AnnaIsRelievedMaryFoundRomanticInterest[] =
        "Ich freue mich.\r\n"
        "Es ist schließlich \r\n"
        "richtig so! {Press}";
};

void EventScript_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupAnnaDialogue(void)
{
    if (HasMetNpc(CHARACTER_ANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_ANNA) == FALSE)
    {
        SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ANNA);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupAnnaDialogue_AnnaHadThoughtMaryUninterestedInRomance);
        TalkClose();
        SetEntityFacing(ENTITY_ANNA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    else
    {
        SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ANNA);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupAnnaDialogue_AnnaIsRelievedMaryFoundRomanticInterest);
        TalkClose();
        SetEntityFacing(ENTITY_ANNA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
}
