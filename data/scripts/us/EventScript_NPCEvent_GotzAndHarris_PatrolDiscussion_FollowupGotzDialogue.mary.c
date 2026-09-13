#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupGotzDialogue_GotzWarnsPlayerToBeCarefulOnMountain[] =
        "You have to be careful\r\n"
        "on the mountain. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupGotzDialogue_GotzFallsSilentRememberingFamily[] =
        "...............\r\n"
        "{Press}";
};

void EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupGotzDialogue(void)
{
    SetEntityFacing(ENTITY_GOTZ, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    if (WasNpcSpokenToJustNow(CHARACTER_GOTZ) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
        TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupGotzDialogue_GotzWarnsPlayerToBeCarefulOnMountain);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_GOTZ_AFRAID);
        TalkMessage(gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupGotzDialogue_GotzFallsSilentRememberingFamily);
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_GOTZ);
    SetEntityFacing(ENTITY_GOTZ, FACING_LEFT);
    return;
}
