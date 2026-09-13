#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_NoPlayerEntryComment[] =
        "I look forward to Beach Day\r\n"
        "all the more since they \r\n"
        "began the Frisbee {Press}\r\n"
        "Tournament. I know all \r\n"
        "the Dogs because I see them\r\n"
        "when I’m working. {Press}\p"
        "So, I'm glad whoever wins!{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_EncouragesPlayerEntry[] =
        "Good luck to all people \r\n"
        "and canines! {Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack(void)
{
    if (HasMetNpc(CHARACTER_ZACK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
    SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_NoPlayerEntryComment);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ZACK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ZACK);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Zack_EncouragesPlayerEntry);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ZACK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ZACK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ZACK);
    SetEntityFacing(ENTITY_ZACK, FACING_DOWN);
}
