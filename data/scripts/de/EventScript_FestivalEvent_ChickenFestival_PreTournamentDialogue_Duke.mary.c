#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Duke_HiTherePlayerItsAnElimination[] =
        "Hi, {Player}. \r\n"
        "Es ist ein Turnier mit \r\n"
        "Ausscheiden. {Press}";

    const char gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Duke_GoodLuck[] =
        "Viel Glück! {Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Duke(void)
{
    if (HasMetNpc(CHARACTER_DUKE) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DUKE);
    }
    SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Duke_HiTherePlayerItsAnElimination);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Duke_GoodLuck);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DUKE) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DUKE, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
}
