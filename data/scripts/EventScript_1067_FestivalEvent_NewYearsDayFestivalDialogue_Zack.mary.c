#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1067_FestivalEvent_NewYearsDayFestivalDialogue_Zack.mary.h"

void EventScript_1067_FestivalEvent_NewYearsDayFestivalDialogue_Zack(void)
{
    if (HasMetNpc(CHARACTER_ZACK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
    SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_FestivalEvent_NewYearsDayFestivalDialogue_Zack);
    ClearTalkPortrait();
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ZACK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ZACK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_LEFT);
}
