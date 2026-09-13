#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Manna[] =
        "You're going to enter \r\n"
        "this year, {Player}? \r\n"
        "That's great! I love seeing{Press}\r\n"
        "men cook, you know. \r\n"
        "My husband can't cook\r\n"
        "at all...\r\n"
        "I'll be rooting for you! {Press}";
};

void EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Manna);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    SetEntityFacing(ENTITY_MANNA, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_MANNA);
}
