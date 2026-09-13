#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Manna[] =
        "あら、あなたも出場するの？\r\n"
        "どんな料理をつくるのかしら？\r\n"
        "わたし、男の人が料理を作る\r\n"
        "姿ってステキだと思うのよ。\r\n"
        "ウチのだんななんて、何にも\r\n"
        "出来ないし…もし、出場するん\r\n"
        "だったらがんばってね。{Press}";
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
