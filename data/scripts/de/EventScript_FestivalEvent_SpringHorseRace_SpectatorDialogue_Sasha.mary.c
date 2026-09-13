#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Sasha_WhatGreatWeatherForAHorse[] =
        "Tolles Wetter für \r\n"
        "ein Pferderennen!{Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Sasha_GoodLuck[] =
        "Viel Glück! {Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Sasha_WhatGreatWeatherForAHorse);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Sasha_GoodLuck);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_SASHA);
    SetEntityFacing(ENTITY_SASHA, FACING_LEFT);
}
