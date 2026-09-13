#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas_BetterLuckNextTimeDogWas[] =
        "いやぁ、残念だったねぇ。\r\n"
        "でも、{Dog}も\r\n"
        "よくがんばったと思うよ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas_CongratulationsPlayerIThoughtYoudWin[] =
        "{Player}くん、\r\n"
        "おめでとう！{Press}\p"
        "わたしはキミが優勝すると\r\n"
        "思っていたよ。{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas_ThatWasFunThisIsMy[] =
        "いやぁ、楽しかったねぇ。\r\n"
        "いつみても、\r\n"
        "この祭りはいいね。{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == TRUE)
    {
        if (VarGet(VAR_FRISBEE_TOURNAMENT_RESULT) == FESTIVAL_CONTEST_RESULT_NOT_WON)
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas_BetterLuckNextTimeDogWas);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas_CongratulationsPlayerIThoughtYoudWin);
        }
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas_ThatWasFunThisIsMy);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
}
