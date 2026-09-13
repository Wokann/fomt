#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupCliffDialogue_CliffSaysHeIsMarryingAnn[] =
        "Hab ich schon erzählt, \r\n"
        "Ann und ich heiraten?{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupCliffDialogue_CliffSaysHeWillStayInTownWithHisFamily[] =
        "Ich bleibe für \r\n"
        "immer hier. \r\n"
        "Ich bin hier glücklich.{Press}";
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
