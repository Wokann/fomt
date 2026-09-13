#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Gotz_YouMustBelieveInYourself[] =
        "Du musst an dich\r\n"
        "glauben. {Press}";

    const char gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Gotz_ImBettingOnYouSoDont[] =
        "Ich setze auf dich, also\r\n"
        "lass mich nicht hängen!{Press}";
};

void EventScript_FestivalEvent_FallHorseRace_SpectatorDialogue_Gotz(void)
{
    if (HasMetNpc(CHARACTER_GOTZ) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GOTZ);
    }
    SetEntityFacing(ENTITY_GOTZ, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_GOTZ);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Gotz_YouMustBelieveInYourself);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_GOTZ);
        TalkMessage(gText_FestivalEvent_FallHorseRace_SpectatorDialogue_Gotz_ImBettingOnYouSoDont);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GOTZ) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GOTZ, 5);
    }
    MarkNpcSpokenTo(CHARACTER_GOTZ);
    SetEntityFacing(ENTITY_GOTZ, FACING_DOWN);
}
