#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Jeff_DogsAreSoCleverMaybeI[] =
        "Dogs are so clever!\r\n"
        "Maybe I should keep one \r\n"
        "as a guard dog...{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Jeff_YoureGoingToCompeteIllBe[] =
        "You're going to compete?\r\n"
        "I'll be rooting for you! {Press}";
};

void EventScript_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Jeff(void)
{
    if (HasMetNpc(CHARACTER_JEFF) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
    SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (VarGet(VAR_FRISBEE_TOURNAMENT_PLAYER_DOG_ENTRY_SELECTED) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Jeff_DogsAreSoCleverMaybeI);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Jeff_YoureGoingToCompeteIllBe);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_JEFF) == FALSE)
    {
        AddNpcFriendship(CHARACTER_JEFF, 5);
    }
    MarkNpcSpokenTo(CHARACTER_JEFF);
    SetEntityFacing(ENTITY_JEFF, FACING_RIGHT);
}
