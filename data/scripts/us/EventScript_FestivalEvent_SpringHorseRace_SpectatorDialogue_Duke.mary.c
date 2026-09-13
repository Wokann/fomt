#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Duke_HaveYouPlacedABetYet[] =
        "Have you placed a bet yet?\r\n"
        "You do it with the Mayor. {Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Duke_ImGoingToBetOnYou[] =
        "I'm going to bet on you, \r\n"
        "so do a good job! {Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Duke(void)
{
    if (HasMetNpc(CHARACTER_DUKE) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DUKE);
    }
    SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Duke_HaveYouPlacedABetYet);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Duke_ImGoingToBetOnYou);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DUKE) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DUKE, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DUKE);
    SetEntityFacing(ENTITY_DUKE, FACING_LEFT);
}
