#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaSaysCliffSettlingDownMeansHeCannotMarryAja[] =
        "Seems like Cliff is going to\r\n"
        "settle down here for good. \r\n"
        "Of course, that means he \r\n"
        "can't marry Aja...{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaRegardsCliffAndAnnAsHerChildren[] =
        "Still, Cliff is like my own \r\n"
        "son already, so that means \r\n"
        "Ann will become like our \r\n"
        "daughter! {Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue_MannaStillHopesAjaReturnsHome[] =
        "Still...I hope Aja comes \r\n"
        "back home soon...\r\n"
        "I thought she'd get home-\r\n"
        "sick and come back sooner.{Press}";
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
