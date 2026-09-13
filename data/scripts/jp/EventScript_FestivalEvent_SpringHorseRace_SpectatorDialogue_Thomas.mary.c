#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas_ThisIsWhereYouPlaceBets[] =
        "ここではチケットを買ったり、\r\n"
        "コインを景品に変えたり\r\n"
        "することが出来るんだよ。{Press}\p"
        "それとレースを始めたければ、\r\n"
        "わたしに声をかけてくれ。{Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas_YouCanBetEvenIfYou[] =
        "レースに出る人もチケットが\r\n"
        "買えるんだよ。やっぱり、\r\n"
        "みんな自分のを買っていくね。{Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas_ThisIsWhereYouPlaceBets);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Thomas_YouCanBetEvenIfYou);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
}
