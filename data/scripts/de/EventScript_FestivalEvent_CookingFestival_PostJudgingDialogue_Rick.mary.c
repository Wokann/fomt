#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Rick[] =
        "Ich hoffe, Mama ist ok.\r\n"
        "Ich wollte sie überreden,\r\n"
        "nicht zu kommen. {Press}";
};

void EventScript_FestivalEvent_CookingFestival_PostJudgingDialogue_Rick(void)
{
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Rick);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_RICK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_RICK, 5);
    }
    SetEntityFacing(ENTITY_RICK, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_RICK);
}
