#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0917_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_FollowupDukeDialogue.mary.h"

void EventScript_0917_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_FollowupDukeDialogue(void)
{
    SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DUKE);
    TalkMessage(gText_RivalEvent_AnnAndCliff_04_OrangeHeart_WineryProposalAdvice_FollowupDukeDialogue_DukeWondersWhatCliffWillDecide);
    TalkClose();
    SetEntityFacing(ENTITY_DUKE, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_DUKE);
}
