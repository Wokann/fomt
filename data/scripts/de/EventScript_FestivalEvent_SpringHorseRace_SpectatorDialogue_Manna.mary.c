#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_IAlwaysLoseAtTheseRaces[] =
        "Ich verliere immer \r\n"
        "bei diesen Rennen!  Ich\r\n"
        "setze nie auf die Gewinner.{Press}\p"
        "Aber egal, es ist ja nur \r\n"
        "zum Spaß!{Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_ImGoingToBetOnYou[] =
        "Ich wette auf dich, \r\n"
        "{Player}! \r\n"
        "Ich zähle darauf, dass{Press}\r\n"
        "du mir Glück bringst. {Press}\p"
        "Ich weiß nie, auf wen \r\n"
        "ich setzen soll, also setze\r\n"
        "ich nur auf Leute, {Press}\r\n"
        "die ich kenne.{Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_IAlwaysLoseAtTheseRaces);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MANNA);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_ImGoingToBetOnYou);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
}
