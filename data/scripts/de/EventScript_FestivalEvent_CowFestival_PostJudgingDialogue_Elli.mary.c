#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Elli_StuCausesTroubleNoMatterWhere[] =
        "Stu macht immer \r\n"
        "Ärger, egal, wo ich\r\n"
        "ihn hinbringe!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Elli_CongratulationsItsBecauseYouTreatYour[] =
        "Herzlichen Glückwunsch! \r\n"
        "Das kommt, weil du \r\n"
        "deine Tiere so gut pflegst!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Elli_IfYouGiveYourAnimalsMore[] =
        "Wenn du deinen Tieren \r\n"
        "mehr Zuneigung gibst, \r\n"
        "gewinnen sie vielleicht{Press}\r\n"
        "nächstes Jahr. {Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Elli(void)
{
    if (HasMetNpc(CHARACTER_ELLI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Elli_StuCausesTroubleNoMatterWhere);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Elli_CongratulationsItsBecauseYouTreatYour);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Elli_IfYouGiveYourAnimalsMore);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ELLI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ELLI, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ELLI);
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
}
