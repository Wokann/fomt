#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0734_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupMaryDialogue.mary.h"

void EventScript_0734_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupMaryDialogue(void)
{
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupMaryDialogue_MaryReflectsOnGraysConcern);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_MARY);
    SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
    return;
}
