#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1238_FestivalEvent_HarvestFestival_PreCookingDialogue_Manna.mary.h"

void EventScript_1238_FestivalEvent_HarvestFestival_PreCookingDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Manna);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_MANNA);
}
