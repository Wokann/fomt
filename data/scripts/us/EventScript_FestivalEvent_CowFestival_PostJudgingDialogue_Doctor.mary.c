#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_IfACowEverStepsOn[] =
        "If a Cow ever steps on your\r\n"
        "foot, don't try to pull \r\n"
        "it out. That'll only make {Press}\r\n"
        "it worse. {Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_PraisesSelectedCowsMilk[] =
        "{Var1} looks \r\n"
        "like she gives great Milk. \r\n"
        "Can I drink some later? {Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_ExpectedSelectedCowToWin[] =
        "I thought {Var1} \r\n"
        "would win for sure. \r\n"
        "Try again next year. {Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor(void)
{
    int var_0;
    var_0 = GetContestAnimalIndex(ANIMAL_KIND_COW);
    GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_COW, var_0);
    if (HasMetNpc(CHARACTER_DOCTOR) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
    }
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_IfACowEverStepsOn);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_PraisesSelectedCowsMilk);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_DOCTOR);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_ExpectedSelectedCowToWin);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOCTOR) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOCTOR, 5);
    }
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
}
