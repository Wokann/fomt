#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1121_FestivalEvent_CookingFestival_PostJudgingDialogue_Sasha.mary.h"

void EventScript_1121_FestivalEvent_CookingFestival_PostJudgingDialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Sasha);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    SetEntityFacing(ENTITY_SASHA, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_SASHA);
}
