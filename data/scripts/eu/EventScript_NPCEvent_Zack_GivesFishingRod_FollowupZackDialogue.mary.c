#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Zack_GivesFishingRod_FollowupZackDialogue_ZackEncouragesPlayerToCatchFish[] =
        "You'll be able to catch lots\r\n"
        "of fish with that!{Press}";
};

void EventScript_NPCEvent_Zack_GivesFishingRod_FollowupZackDialogue(void)
{
    if (HasMetNpc(CHARACTER_ZACK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
    if (VarGet(VAR_ZACK_GIVES_FISHING_ROD_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_NPCEvent_Zack_GivesFishingRod_FollowupZackDialogue_ZackEncouragesPlayerToCatchFish);
        TalkClose();
        SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
}
