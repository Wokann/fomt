#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0924_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue.mary.h"

void EventScript_0924_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupMannaDialogue(void)
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
