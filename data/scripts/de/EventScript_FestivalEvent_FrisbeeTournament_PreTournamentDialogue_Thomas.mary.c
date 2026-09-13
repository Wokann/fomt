#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas_NoPlayerEntryComment[] =
        "Ich liebe dieses \r\n"
        "Festival. Es macht\r\n"
        "so viel Spaß, den Hunden{Press}\r\n"
        "beim Fangen zuzusehen! {Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas_EncouragesPlayerEntry[] =
        "Good luck! {Press}Machst du auch mit?\r\n"
        "Viel Glück! {Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas_NoPlayerEntryComment);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Thomas_EncouragesPlayerEntry);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
}
