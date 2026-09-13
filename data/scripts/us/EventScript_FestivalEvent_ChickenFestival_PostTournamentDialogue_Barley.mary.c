#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley_HmmmThatWasAGreatMatch[] =
        "Hmmm, that was a great\r\n"
        "match...{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley_GoodJobItWasFunTo[] =
        "Good job.\r\n"
        "It was fun to watch.{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley_IsYourChickenOK[] =
        "Is your chicken OK?{Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley(void)
{
    if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BARLEY);
    }
    SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley_HmmmThatWasAGreatMatch);
    }
    else
    {
        if (VarGet(VAR_CHICKEN_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley_GoodJobItWasFunTo);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley_IsYourChickenOK);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_BARLEY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_BARLEY);
    SetEntityFacing(ENTITY_BARLEY, FACING_RIGHT);
}
