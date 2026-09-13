#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliIsHappyHerFeelingsForDoctorAreMutual[] =
        "Ich liebe den Doktor \r\n"
        "schon immer...  Aber ich\r\n"
        "wusste nie, wie er{Press}\r\n"
        "empfindet...! {Press}\p"
        "Ich freue mich so.{Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliPlansToStudyAndCureEllensLegs[] =
        "Ich konzentriere mich \r\n"
        "auf mein Studium mit ihm. {Press}\p"
        "Vielleicht kann ich sogar \r\n"
        "Großmutters Beine heilen!{Press}";
};

void EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue(void)
{
    if (HasMetNpc(CHARACTER_ELLI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_ELLI) == FALSE)
    {
        SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliIsHappyHerFeelingsForDoctorAreMutual);
        TalkClose();
        SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    else
    {
        SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliPlansToStudyAndCureEllensLegs);
        TalkClose();
        SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
}
