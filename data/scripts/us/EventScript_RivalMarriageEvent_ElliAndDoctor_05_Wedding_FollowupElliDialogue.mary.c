#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliIsHappyHerFeelingsForDoctorAreMutual[] =
        "I've always been in love \r\n"
        "with the Doctor...But, I\r\n"
        "didn't know how he{Press}\r\n"
        "feels about me...! {Press}\p"
        "I’m so happy now...{Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliPlansToStudyAndCureEllensLegs[] =
        "I'm going to concentrate on\r\n"
        "my studies with him. {Press}\p"
        "Maybe I can even cure \r\n"
        "grandmda's legs! {Press}";
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
