#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_ImSorryYouLostIBet[] =
        "I'm sorry you lost.\r\n"
        "I bet you could win next\r\n"
        "year, though!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_CongratulationsOnWinning[] =
        "Congratulations on winning!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_TooBadIThoughtYoudWin[] =
        "Too bad. I thought\r\n"
        "you'd win for sure. {Press}";
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
