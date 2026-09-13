#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_ItsAlwaysGoodToSeeAll[] =
        "やぁ、キミもいろんな牛を\r\n"
        "見られてよかったろう。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_PraisesPlayersWinningCow[] =
        "優勝おめでとう！\r\n"
        "いやぁ、わたしも\r\n"
        "町の人間として鼻が高いよ。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_IThoughtYouShouldHaveWon[] =
        "やあ、{Player}くん。\r\n"
        "惜しかったね。めげずに\r\n"
        "来年も参加してくれ。{Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_ItsAlwaysGoodToSeeAll);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_PraisesPlayersWinningCow);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_IThoughtYouShouldHaveWon);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
}
