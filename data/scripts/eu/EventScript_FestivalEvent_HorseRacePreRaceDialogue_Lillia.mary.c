#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HorseRacePreRaceDialogue_Lillia_ItsAPerfectDayForHorse[] =
        "It's a perfect day \r\n"
        "for Horse racing!{Press}";

    const char gText_FestivalEvent_HorseRacePreRaceDialogue_Lillia_AreYouRacingIHopeYou[] =
        "Are you racing? \r\n"
        "I hope you win! {Press}";
};

void EventScript_FestivalEvent_HorseRacePreRaceDialogue_Lillia(void)
{
    if (HasMetNpc(CHARACTER_LILLIA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
    SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        TalkMessage(gText_FestivalEvent_HorseRacePreRaceDialogue_Lillia_ItsAPerfectDayForHorse);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        TalkMessage(gText_FestivalEvent_HorseRacePreRaceDialogue_Lillia_AreYouRacingIHopeYou);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_LILLIA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_LILLIA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_LILLIA);
    SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
}
