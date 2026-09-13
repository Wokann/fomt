#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_IAlwaysLoseAtTheseRaces[] =
        "I always lose at \r\n"
        "these races! I can never \r\n"
        "pick the winners, it seems.{Press}\p"
        "Oh well, it's just for \r\n"
        "fun, so who cares!{Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_ImGoingToBetOnYou[] =
        "I'm going to bet on you, \r\n"
        "{Player}! \r\n"
        "I'm counting on you to {Press}\r\n"
        "bring me good luck. {Press}\p"
        "I never know who to bet \r\n"
        "on, so I just bet on people\r\n"
        "know. {Press}";
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
        TalkMessageSlow(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Manna_IAlwaysLoseAtTheseRaces);
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
