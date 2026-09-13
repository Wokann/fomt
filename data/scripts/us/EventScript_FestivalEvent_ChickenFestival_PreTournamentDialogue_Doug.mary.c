#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Doug_ILookForwardToThisEvery[] =
        "I look forward to this \r\n"
        "every year. {Press}";

    const char gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Doug_IfYoureGoingToEnterYou[] =
        "If you're going to enter, \r\n"
        "you may as well win. {Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PreTournamentDialogue_Doug(void)
{
    if (HasMetNpc(CHARACTER_DOUG) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Doug_ILookForwardToThisEvery);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PreTournamentDialogue_Doug_IfYoureGoingToEnterYou);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOUG) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOUG, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DOUG);
    SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
}
