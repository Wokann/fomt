#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Zack[] =
        "Are you going to compete \r\n"
        "this year, {Player}?{Press}\p"
        "Your dish better be\r\n"
        "extra delicious, because\r\n"
        "the Gourmet is going to be{Press}\r\n"
        "judging. He's tough!{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Zack(void)
{
    if (HasMetNpc(CHARACTER_ZACK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
    SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Zack);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ZACK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ZACK, 5);
    }
    SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_ZACK);
}
