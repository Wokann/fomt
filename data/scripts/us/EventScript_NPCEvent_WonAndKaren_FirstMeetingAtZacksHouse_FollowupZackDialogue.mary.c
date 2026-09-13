#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_Zack_Followup_ZackLamentsMissingFreeOffer[] =
        "Too bad...{Press}";
};

void EventScript_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_FollowupZackDialogue(void)
{
    if (VarGet(VAR_WON_AND_KAREN_FIRST_MEETING_AT_ZACKS_HOUSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ZACK_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_Zack_Followup_ZackLamentsMissingFreeOffer);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ZACK);
        SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
    }
}
