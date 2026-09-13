#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Jeff_DogsAreSoCleverMaybeI[] =
        "Hunde sind so schlau!\r\n"
        "Vielleicht sollte ich mir\r\n"
        "einen Wachhund halten...{Press}";

    const char gText_FestivalEvent_FrisbeeTournament_PreTournamentDialogue_Jeff_YoureGoingToCompeteIllBe[] =
        "Machst du auch mit?\r\n"
        "Ich drücke dir die Daumen!{Press}";
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
