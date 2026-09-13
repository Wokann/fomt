#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_Won_Followup_WonRemindsPlayerWaresAreNotFree[] =
        "Weißt du, nicht alles ist\r\n"
        "umsonst! Zeit zu bezahlen!{Press}";
};

void EventScript_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_FollowupWonDialogue(void)
{
    if (VarGet(VAR_WON_AND_KAREN_FIRST_MEETING_AT_ZACKS_HOUSE_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_WON, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_WON);
        TalkMessage(gText_NPCEvent_WonAndKaren_FirstMeetingAtZacksHouse_Won_Followup_WonRemindsPlayerWaresAreNotFree);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_WON);
        SetEntityFacing(ENTITY_WON, FACING_LEFT);
    }
}
