#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue_LilliaWondersWhyZackLookedSad[] =
        "Zack seemed kind of sad\r\n"
        "to be leaving...\r\n"
        "I wonder why? {Press}";

    const char gText_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue_LilliaWondersWhyZackIsNervousAroundHer[] =
        "Zack always seems kind of \r\n"
        "nervous around me. \r\n"
        "I wonder why...{Press}";
};

void EventScript_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue(void)
{
    SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
    if (WasNpcSpokenToJustNow(CHARACTER_LILLIA) == FALSE)
    {
        TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue_LilliaWondersWhyZackLookedSad);
    }
    else
    {
        TalkMessage(gText_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue_LilliaWondersWhyZackIsNervousAroundHer);
    }
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
    return;
}
