#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick_ThisYearsCompetitionWasGreatDont[] =
        "Der Wettkampf dieses \r\n"
        "Jahres war toll, oder?{Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick_PraisesSelectedChickenStrength[] =
        "Ja, {Var1} \r\n"
        "war besonders stark. {Press}";

    const char gText_FestivalEvent_ChickenFestival_PostTournamentDialogue_Rick_SorryYouDidntWinAllThe[] =
        "Tut mir Leid, dass \r\n"
        "du nicht gewonnen hast. \r\n"
        "All die anderen Hühner{Press}\r\n"
        "waren sehr stark. {Press}";
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
