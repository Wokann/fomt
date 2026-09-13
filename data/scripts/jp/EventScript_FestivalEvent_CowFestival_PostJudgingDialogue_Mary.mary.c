#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Mary_CowsLoveBeingBrushedYouKnow[] =
        "ブラシがけしてやると、\r\n"
        "よろこんでた。\r\n"
        "楽しい１日だったわ。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Mary_CongratulationsOnWinning[] =
        "優勝おめでとう。さすがね。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Mary_DontBeHardOnYourselfAll[] =
        "気にすることないわよ。\r\n"
        "今日集まった牛は、\r\n"
        "スゴイ牛ばかりだったもの。{Press}\r\n"
        "よくやったと思うよ。{Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Mary(void)
{
    if (HasMetNpc(CHARACTER_MARY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_MARY);
    }
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Mary_CowsLoveBeingBrushedYouKnow);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Mary_CongratulationsOnWinning);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Mary_DontBeHardOnYourselfAll);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MARY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MARY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MARY);
    SetEntityFacing(ENTITY_MARY, FACING_LEFT);
}
