#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_IAlwaysLoseAtTheseRaces[] =
        "わたし、いつも草競馬で\r\n"
        "負けちゃうのよね。\r\n"
        "やっぱり外見がかっこいいだけ\r\n"
        "じゃダメなのかしら。\r\n"
        "でも、だからって他に何を見て\r\n"
        "決めればいいか\r\n"
        "分からないのよね。\r\n"
        "ま、お祭りなんだから\r\n"
        "楽しければいいんだけど…\r\n"
        "でもやっぱりくやしいわよね。{Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_ImGoingToBetOnYou[] =
        "あら、{Player}さん！\r\n"
        "出るんでしょう！\r\n"
        "もちろんわたしは、\r\n"
        "あなたのチケットを買うわよ！\r\n"
        "がんばってね！\r\n"
        "毎回こうやって知り合いが\r\n"
        "出ていれば、どのチケットを\r\n"
        "買えばいいかも分かるのに。\r\n"
        "ああ、ううん。\r\n"
        "{Player}さんに\r\n"
        "期待しているから\r\n"
        "買うのよ、もちろん。{Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessageSlow(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_IAlwaysLoseAtTheseRaces);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessageSlow(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_ImGoingToBetOnYou);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
}
