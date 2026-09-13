#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Elli_StuCausesTroubleNoMatterWhere[] =
        "Stu causes trouble \r\n"
        "no matter where I bring \r\n"
        "him!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Elli_CongratulationsItsBecauseYouTreatYour[] =
        "Congratulations. It's \r\n"
        "because you treat your \r\n"
        "animals so well! {Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Elli_IfYouGiveYourAnimalsMore[] =
        "If you give your animals \r\n"
        "more affection, you could \r\n"
        "win next year. {Press}";
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
