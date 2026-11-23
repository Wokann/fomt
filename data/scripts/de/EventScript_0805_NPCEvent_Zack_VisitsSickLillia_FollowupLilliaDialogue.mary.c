#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0805_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue.mary.h"

void EventScript_0805_NPCEvent_Zack_VisitsSickLillia_FollowupLilliaDialogue(void)
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
