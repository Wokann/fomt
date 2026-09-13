#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Popuri_NoPlayerEntryComment[] =
        "みんな、かわいかったー。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Popuri_CongratulatesPlayerVictory[] =
        "おめでとー。やっぱり、\r\n"
        "優勝したね。ポプリ、\r\n"
        "そうじゃないかなぁって{Press}\r\n"
        "思ってたんだ。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Popuri_ConsolesPlayerOverSelectedCowLoss[] =
        "残念だったねー。でも、\r\n"
        "{Var1}も\r\n"
        "がんばってたよ。{Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Popuri(void)
{
    int var_0;
    var_0 = GetContestAnimalIndex(ANIMAL_KIND_COW);
    GetAnimalName(TEXT_VARIABLE_1, ANIMAL_KIND_COW, var_0);
    if (HasMetNpc(CHARACTER_POPURI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_POPURI);
    }
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_POPURI);
        }
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Popuri_NoPlayerEntryComment);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Popuri_CongratulatesPlayerVictory);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_POPURI);
            if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
            {
                ShowTalkHeartIndicator(CHARACTER_POPURI);
            }
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Popuri_ConsolesPlayerOverSelectedCowLoss);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_POPURI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_POPURI, 5);
    }
    MarkNpcSpokenTo(CHARACTER_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
}
