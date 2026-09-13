#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Harris_AllTheSheepHereSeemSo[] =
        "All the Sheep here \r\n"
        "seem so happy.{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Harris_WinningIsSuchAGreatAccomplishment[] =
        "Winning is such a great\r\n"
        "accomplishment!{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Harris_AllTheSheepThisYearHave[] =
        "All the Sheep this year \r\n"
        "have such beautiful coats!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Harris(void)
{
    if (HasMetNpc(CHARACTER_HARRIS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
    SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Harris_AllTheSheepHereSeemSo);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_HARRIS);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Harris_WinningIsSuchAGreatAccomplishment);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_HARRIS);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Harris_AllTheSheepThisYearHave);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_HARRIS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_HARRIS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_DOWN);
}
