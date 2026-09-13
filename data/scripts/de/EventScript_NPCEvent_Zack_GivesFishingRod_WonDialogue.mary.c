#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Zack_GivesFishingRod_WonDialogue_WonComplimentsFishingRod[] =
        "Du hast eine tolle \r\n"
        "Angel bekommen. {Press}";
};

void EventScript_NPCEvent_Zack_GivesFishingRod_WonDialogue(void)
{
    if (HasMetNpc(CHARACTER_WON) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_WON);
    }
    if (VarGet(VAR_ZACK_GIVES_FISHING_ROD_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_WON, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_WON_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_WON);
        TalkMessage(gText_NPCEvent_Zack_GivesFishingRod_WonDialogue_WonComplimentsFishingRod);
        TalkClose();
        SetEntityFacing(ENTITY_WON, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_WON);
    }
}
