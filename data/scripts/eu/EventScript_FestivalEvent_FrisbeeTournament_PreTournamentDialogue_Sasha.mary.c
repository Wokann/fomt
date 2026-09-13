#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha_ICantBelieveDogsCanLearn[] =
        "I can't believe Dogs can \r\n"
        "learn so many tricks \r\n"
        "if they practice. {Press}\r\n"
        "I want a Dog now, too!{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha_GoodLuckPlayer[] =
        "Good luck, {Player}!{Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha_ICantBelieveDogsCanLearn);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Sasha_GoodLuckPlayer);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_SASHA);
    SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
}
