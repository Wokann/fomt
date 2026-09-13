#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Carter_ItMustFeelSoGreatTo[] =
        "Es muss toll sein \r\n"
        "zu galoppieren!{Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Carter_IHearYouAreRacingIll[] =
        "Rennst du auch mit?\r\n"
        "Ich bete für dich. {Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Carter(void)
{
    if (HasMetNpc(CHARACTER_CARTER) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Carter_ItMustFeelSoGreatTo);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_CARTER);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Carter_IHearYouAreRacingIll);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_CARTER) == FALSE)
    {
        AddNpcFriendship(CHARACTER_CARTER, 5);
    }
    MarkNpcSpokenTo(CHARACTER_CARTER);
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
}
