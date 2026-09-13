#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExplainsGotzPatrolsAfterFamilyDeaths[] =
        "Seit er seine Frau und\r\n"
        "Tochter in den Bergen\r\n"
        "verloren hat, übernimmt{Press}\r\n"
        "Gotz die Streife in \r\n"
        "seiner Freizeit. {Press}";

    const char gText_NPCEvent_GotzAndHarris_PatrolDiscussion_FollowupHarrisDialogue_HarrisExpressesGratitudeToGotz[] =
        "Ich bin ihm dafür  \r\n"
        "sehr dankbar. {Press}";
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
