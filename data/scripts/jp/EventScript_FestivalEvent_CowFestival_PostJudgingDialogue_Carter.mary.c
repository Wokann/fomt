#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_ImSorryYouLostIBet[] =
        "わたしのユメは、\r\n"
        "牛にもたれて寝る事なんだ。\r\n"
        "こう、麦わらぼうしを{Press}\r\n"
        "顔にかけてね。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_CongratulationsOnWinning[] =
        "優勝したんだね。\r\n"
        "おめでとう！{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_TooBadIThoughtYoudWin[] =
        "残念だったねぇ。わたしは\r\n"
        "優勝できると\r\n"
        "みてたんだけどなぁ。{Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Carter(void)
{
    if (HasMetNpc(CHARACTER_CARTER) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_ImSorryYouLostIBet);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_CongratulationsOnWinning);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_CARTER);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_TooBadIThoughtYoudWin);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_CARTER) == FALSE)
    {
        AddNpcFriendship(CHARACTER_CARTER, 5);
    }
    MarkNpcSpokenTo(CHARACTER_CARTER);
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
}
