#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0802_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue.mary.h"

void EventScript_0802_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue(void)
{
    SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    if (WasNpcSpokenToJustNow(CHARACTER_HARRIS) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
        TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExplainsGotzPatrolsAfterFamilyDeaths);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
        TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExpressesGratitudeToGotz);
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
    return;
}
