#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_IfACowEverStepsOn[] =
        "Wenn dir eine Kuh auf\r\n"
        "den Fuß tritt, versuch \r\n"
        "nicht wegzuziehen. Das{Press}\r\n"
        "macht es nur schlimmer. {Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_PraisesSelectedCowsMilk[] =
        "{Var1} sieht aus,\r\n"
        "als gäbe sie tolle Milch.\r\n"
        "Kann ich später {Press}\r\n"
        "welche haben?{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_ExpectedSelectedCowToWin[] =
        "War klar, dass {Var1} \r\n"
        "gewinnen würde. \r\n"
        "Versuch es nächstes {Press}\r\n"
        "Jahr wieder. {Press}";
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
