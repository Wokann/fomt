#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExplainsGotzPatrolsAfterFamilyDeaths[] =
        "Ever since he lost his wife \r\n"
        "and daughter in the \r\n"
        "mountains, Gotz has taken {Press}\r\n"
        "it upon himself to patrol \r\n"
        "them in his spare time. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExpressesGratitudeToGotz[] =
        "I'm really grateful to \r\n"
        "him for it. {Press}";
};

void EventScript_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue(void)
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
