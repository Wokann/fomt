#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsDayFestivalDialogue_Thomas[] =
        "やぁやぁ、{Player}くん。\r\n"
        "キミもおもちを食べにきたの\r\n"
        "かい？{Press}\p"
        "わたしも、おもちには目が\r\n"
        "なくってねぇ。今日はたくさん\r\n"
        "食べようと思うんだ。{Press}";
};

void EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FestivalEvent_NewYearsDayFestivalDialogue_Thomas);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
}
