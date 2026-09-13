#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_ImSorryYouLostIBet[] =
        "Tut mir Leid, dass \r\n"
        "du verloren hast.\r\n"
        "Ich wette, du kannst {Press}\r\n"
        "nächstes Jahr gewinnen!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_CongratulationsOnWinning[] =
        "Herzlichen Glückwunsch!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Carter_TooBadIThoughtYoudWin[] =
        "Zu schade. Ich\r\n"
        "dachte, du gewinnst sicher.{Press}";
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
