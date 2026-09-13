#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_May_ThereAreSoManyPrettyHorses[] =
        "There are so many \r\n"
        "pretty Horses. {Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_May_HorseIsGoingToRunToo[] =
        "{Horse} \r\n"
        "is going to run, too, \r\n"
        "right? {Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_May(void)
{
    if (HasMetNpc(CHARACTER_MAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MAY);
    }
    SetEntityFacing(ENTITY_MAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_May_ThereAreSoManyPrettyHorses);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_May_HorseIsGoingToRunToo);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MAY);
    SetEntityFacing(ENTITY_MAY, FACING_RIGHT);
}
