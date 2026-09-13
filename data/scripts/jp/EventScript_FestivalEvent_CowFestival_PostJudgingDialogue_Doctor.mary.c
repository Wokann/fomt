#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_IfACowEverStepsOn[] =
        "牛に足をふまれた時は、\r\n"
        "ムリにひきぬいちゃダメだよ。\r\n"
        "ほねがおれるからね。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_PraisesSelectedCowsMilk[] =
        "{Var1}の牛乳は、\r\n"
        "栄養がありそうだね。\r\n"
        "今度、飲ませてくれるかい？{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Doctor_ExpectedSelectedCowToWin[] =
        "残念だったね。{Var1}の\r\n"
        "毛なみもいいし、\r\n"
        "来年は優勝できるよ。{Press}";
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
