#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliIsHappyHerFeelingsForDoctorAreMutual[] =
        "わたし、ずっとドクターに\r\n"
        "あこがれてたの♡{Press}\p"
        "でも、ドクターってちょっと\r\n"
        "何を考えてるか分からない\r\n"
        "人でしょ？{Press}\p"
        "あきらめようかな、\r\n"
        "と思ってたのよね。{Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupElliDialogue_ElliPlansToStudyAndCureEllensLegs[] =
        "わたし、これを機会に\r\n"
        "今よりがんばって勉強するわ。{Press}\p"
        "おばあちゃんの足も、\r\n"
        "きっとなおしてみせるの。{Press}";
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
