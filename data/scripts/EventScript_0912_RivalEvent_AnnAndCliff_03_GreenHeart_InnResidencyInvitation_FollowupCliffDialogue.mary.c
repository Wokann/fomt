#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0912_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_FollowupCliffDialogue.mary.h"

void EventScript_0912_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_FollowupCliffDialogue(void)
{
    SetEntityFacing(ENTITY_CLIFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_RivalEvent_AnnAndCliff_03_GreenHeart_InnResidencyInvitation_FollowupCliffDialogue_CliffExplainsHeNowLivesInAnInnGuestRoom);
    TalkClose();
    SetEntityFacing(ENTITY_CLIFF, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_CLIFF);
}
