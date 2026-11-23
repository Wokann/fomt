#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1108_FestivalEvent_CookingFestival_PreJudgingDialogue_Doug.mary.h"

void EventScript_1108_FestivalEvent_CookingFestival_PreJudgingDialogue_Doug(void)
{
    if (HasMetNpc(CHARACTER_DOUG) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Doug);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOUG) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOUG, 5);
    }
    SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_DOUG);
}
