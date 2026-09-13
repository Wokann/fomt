#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_FollowupCliffDialogue_CliffThinksAboutAnn[] =
        "Ann...{Press}";
};

void EventScript_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_FollowupCliffDialogue(void)
{
    SetEntityFacing(ENTITY_CLIFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_FollowupCliffDialogue_CliffThinksAboutAnn);
    TalkClose();
    SetEntityFacing(ENTITY_CLIFF, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_CLIFF);
}
