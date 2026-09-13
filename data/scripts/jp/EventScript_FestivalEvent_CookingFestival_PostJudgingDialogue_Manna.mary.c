#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Manna[] =
        "わたしはね、おふくろの味を\r\n"
        "テーマにしているんですよ。\r\n"
        "いつも作りなれているもの\r\n"
        "だから、自信はあるんだけど\r\n"
        "ねぇ。{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PostJudgingDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Manna);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    SetEntityFacing(ENTITY_MANNA, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_MANNA);
}
