#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Lillia[] =
        "What should I make \r\n"
        "this year...?{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Lillia(void)
{
    if (HasMetNpc(CHARACTER_LILLIA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
    SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Lillia);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_LILLIA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_LILLIA, 5);
    }
    SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_LILLIA);
}
