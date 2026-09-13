#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Doug_IAlwaysGetExcitedAboutThe[] =
        "Ich bin jedes Jahr wieder\r\n"
        "aufgeregt bei den \r\n"
        "Pferderennen!{Press}";

    const char gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Doug_IfYoureGoingToCompeteYou[] =
        "Wenn du mitmachst, \r\n"
        "kannst du auch\r\n"
        "gewinnen! {Press}";
};

void EventScript_FestivalEvent_SpringHorseRace_SpectatorDialogue_Doug(void)
{
    if (HasMetNpc(CHARACTER_DOUG) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_FESTIVAL_HORSE_RACE_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Doug_IAlwaysGetExcitedAboutThe);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_FestivalEvent_SpringHorseRace_SpectatorDialogue_Doug_IfYoureGoingToCompeteYou);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOUG) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOUG, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DOUG);
    SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
}
