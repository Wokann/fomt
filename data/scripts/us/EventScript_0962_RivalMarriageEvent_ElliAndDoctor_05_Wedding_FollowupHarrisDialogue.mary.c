#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0962_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue.mary.h"

void EventScript_0962_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue(void)
{
    if (HasMetNpc(CHARACTER_HARRIS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_HARRIS) == FALSE)
    {
        SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisSaysHeAndDoctorAreSameAgeAndChildhoodFriends);
        TalkClose();
        SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
    else
    {
        SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisRecallsTheirSharedDreamToHelpMineralTown);
        TalkClose();
        SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
}
