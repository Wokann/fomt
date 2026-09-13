#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Barley_IWaitForThisDayThe[] =
        "I wait for this day \r\n"
        "the whole year! {Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Barley_SoYoureCompetingJustRelaxAnd[] =
        "So you're competing? \r\n"
        "Just relax and you'll \r\n"
        "do fine. {Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Barley(void)
{
    if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BARLEY);
    }
    SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Barley_IWaitForThisDayThe);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Barley_SoYoureCompetingJustRelaxAnd);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_BARLEY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_BARLEY);
    SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
}
