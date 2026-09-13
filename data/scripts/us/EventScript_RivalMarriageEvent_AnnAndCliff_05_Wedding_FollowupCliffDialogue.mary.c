#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupCliffDialogue_CliffSaysHeIsMarryingAnn[] =
        "Have I told you Ann and I\r\n"
        "are getting married?{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupCliffDialogue_CliffSaysHeWillStayInTownWithHisFamily[] =
        "I'm going to stay here \r\n"
        "forever, now. \r\n"
        "I'm happy here. {Press}";
};

void EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupCliffDialogue(void)
{
    if (HasMetNpc(CHARACTER_CLIFF) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CLIFF);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_CLIFF) == FALSE)
    {
        SetEntityFacing(ENTITY_CLIFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CLIFF_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_CLIFF);
        TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupCliffDialogue_CliffSaysHeIsMarryingAnn);
        TalkClose();
        SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_CLIFF);
    }
    else
    {
        SetEntityFacing(ENTITY_CLIFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CLIFF_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_CLIFF);
        TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupCliffDialogue_CliffSaysHeWillStayInTownWithHisFamily);
        TalkClose();
        SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_CLIFF);
    }
}
