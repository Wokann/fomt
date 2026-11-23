#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1110_FestivalEvent_CookingFestival_PreJudgingDialogue_Thomas.mary.h"

void EventScript_1110_FestivalEvent_CookingFestival_PreJudgingDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Thomas);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_THOMAS);
}
