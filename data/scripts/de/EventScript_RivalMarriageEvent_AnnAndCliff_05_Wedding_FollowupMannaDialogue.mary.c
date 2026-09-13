#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaSaysCliffSettlingDownMeansHeCannotMarryAja[] =
        "Scheint, als würde Cliff \r\n"
        "sich für sie niederlassen.\r\n"
        "Das heißt natürlich, dass\r\n"
        "er Aja nicht heiraten kann.{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaRegardsCliffAndAnnAsHerChildren[] =
        "Cliff ist schon wie ein\r\n"
        "Sohn für mich, das heißt,\r\n"
        "Ann so etwas wie  \r\n"
        "unsere Tochter! {Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaStillHopesAjaReturnsHome[] =
        "Trotzdem... Ich hoffe, \r\n"
        "Aja kommt bald heim.\r\n"
        "Ich dachte, sie würde\r\n"
        "Heimweh kriegen \r\n"
        "und bald kommen.{Press}";
};

void EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_MANNA) == FALSE)
    {
        SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessageSlow(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaSaysCliffSettlingDownMeansHeCannotMarryAja);
        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessageSlow(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaRegardsCliffAndAnnAsHerChildren);
        TalkClose();
        SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    else
    {
        SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessageSlow(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaStillHopesAjaReturnsHome);
        TalkClose();
        SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
}
