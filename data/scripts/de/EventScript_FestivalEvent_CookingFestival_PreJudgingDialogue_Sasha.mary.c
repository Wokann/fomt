#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Sasha[] =
        "Was wohl das Thema  \r\n"
        "dieses Jahres ist?{Press}\p"
        "Was es auch ist, ich \r\n"
        "wünschte, Karen würde\r\n"
        "nicht mitmachen.{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Sasha);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    SetEntityFacing(ENTITY_SASHA, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_SASHA);
}
