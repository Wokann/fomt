#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick_ThisYearsCompetitionWasGreatDont[] =
        "This year's competition was \r\n"
        "great, don't you think?{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick_PraisesSelectedChickenStrength[] =
        "Yeah, {Var1} \r\n"
        "was particularly strong. {Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick_SorryYouDidntWinAllThe[] =
        "Sorry you didn't win. \r\n"
        "All the other Chickens were\r\n"
        "very strong, though. {Press}";
};

void EventScript_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick(void)
{
    int var_0;
    var_0 = GetContestAnimalIndex(ANIMAL_KIND_CHICKEN);
    GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_CHICKEN, var_0);
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_CHICKEN_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick_ThisYearsCompetitionWasGreatDont);
    }
    else
    {
        if (VarGet(VAR_CHICKEN_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick_PraisesSelectedChickenStrength);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick_SorryYouDidntWinAllThe);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_RICK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_RICK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
}
