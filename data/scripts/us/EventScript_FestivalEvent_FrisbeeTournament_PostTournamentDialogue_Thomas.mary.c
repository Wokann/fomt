#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas_BetterLuckNextTimeDogWas[] =
        "Better luck next time. \r\n"
        "{Dog} was fun \r\n"
        "to watch, though!{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas_CongratulationsPlayerIThoughtYoudWin[] =
        "Congratulations, \r\n"
        "{Player}. \r\n"
        "I thought you'd win {Press}\r\n"
        "all the time!{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PostTournamentDialogue_Thomas_ThatWasFunThisIsMy[] =
        "That was fun. \r\n"
        "This is my favorite of all\r\n"
        "the Festivals! {Press}";
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
