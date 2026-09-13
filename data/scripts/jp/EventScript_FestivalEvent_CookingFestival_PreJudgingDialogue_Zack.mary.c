#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Zack[] =
        "よう、{Player}。\r\n"
        "おまえも出場するのか？{Press}\p"
        "だったら、うまい料理を\r\n"
        "出さなきゃダメだぜ。グルメ\r\n"
        "マンが審査をするんだからな。{Press}\p"
        "普通の料理を出しても\r\n"
        "優勝できねぇぜ！{Press}";
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
