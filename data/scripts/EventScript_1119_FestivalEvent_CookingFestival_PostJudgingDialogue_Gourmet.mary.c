#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1119_FestivalEvent_CookingFestival_PostJudgingDialogue_Gourmet.mary.h"

void EventScript_1119_FestivalEvent_CookingFestival_PostJudgingDialogue_Gourmet(void)
{
    if (HasMetNpc(CHARACTER_GOURMET) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GOURMET);
    }
    SetEntityFacing(ENTITY_GOURMET, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOURMET_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GOURMET);
    TalkMessage(gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Gourmet);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GOURMET) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GOURMET, 5);
    }
    SetEntityFacing(ENTITY_GOURMET, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_GOURMET);
}
