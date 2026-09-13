#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Manna[] =
        "あらあら、あなたもおそばを\r\n"
        "食べにきたの？\r\n"
        "おそばっておいしいわよねぇ。\r\n"
        "こう、つるつるつるって\r\n"
        "食べられる所がいいわよね。\r\n"
        "天ぷらなんかのせたら、\r\n"
        "もっとおいしいわよね。\r\n"
        "あー、\r\n"
        "はやく始まらないかしら？\r\n"
        "お腹が減ってきたわ。{Press}";
};

void EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Manna);
    ClearTalkPortrait();
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
}
