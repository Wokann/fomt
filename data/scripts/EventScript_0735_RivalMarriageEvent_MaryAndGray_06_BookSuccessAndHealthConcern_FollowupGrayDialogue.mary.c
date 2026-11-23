#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0735_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupGrayDialogue.mary.h"

void EventScript_0735_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupGrayDialogue(void)
{
    SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    SetTalkPortrait(TALK_PORTRAIT_GRAY_BLUSHING);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupGrayDialogue_GrayHidesEmbarrassment);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_LEFT);
    return;
}
