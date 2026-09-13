#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsDayFestivalDialogue_Manna[] =
        "こんばんは、\r\n"
        "{Player}さん。あなたも、\r\n"
        "おもち好きなの？\r\n"
        "わたしもねぇ、\r\n"
        "おもち好きなのよ。\r\n"
        "食べすぎると太っちゃうから、\r\n"
        "普段はひかえてるんだけどね。\r\n"
        "今日ぐらい、思いっきり食べて\r\n"
        "もいいわよねぇ。{Press}";
};

void EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_FestivalEvent_NewYearsDayFestivalDialogue_Manna);
    ClearTalkPortrait();
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_LEFT);
}
