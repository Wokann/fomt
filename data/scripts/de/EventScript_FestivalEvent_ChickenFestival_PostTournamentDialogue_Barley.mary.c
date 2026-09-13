#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley_HmmmThatWasAGreatMatch[] =
        "Hmmm, das war ein\r\n"
        "toller Wettkampf...{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley_GoodJobItWasFunTo[] =
        "Gut gemacht.\r\n"
        "Das Zusehen hat \r\n"
        "Spaß gemacht.{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Barley_IsYourChickenOK[] =
        "Ist dein Huhn ok?{Press}";
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
