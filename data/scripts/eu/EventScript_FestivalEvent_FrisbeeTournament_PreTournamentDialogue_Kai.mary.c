#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai_IWasWonderingWhatAllThe[] =
        "I was wondering what all the\r\n"
        "fuss was about!\r\n"
        "I forgot today was the {Press}\r\n"
        "Frisbee Tournament. {Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai_YoureCompetingTooIllBeWatching[] =
        "You're competing too? \r\n"
        "I'll be watching you and \r\n"
        "{Dog}. {Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai(void)
{
    if (HasMetNpc(CHARACTER_KAI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAI);
    }
    SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai_IWasWonderingWhatAllThe);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Kai_YoureCompetingTooIllBeWatching);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_KAI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_KAI, 5);
    }
    MarkNpcSpokenTo(CHARACTER_KAI);
    SetEntityFacing(ENTITY_KAI, FACING_RIGHT);
}
