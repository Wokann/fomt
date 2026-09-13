#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_NoPlayerEntryComment[] =
        "牛にのろうとして、\r\n"
        "エリィお姉ちゃんに\r\n"
        "おこられたよ。{Press}\p"
        "コミュニケーションを\r\n"
        "とろうとしただけなのに。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_CongratulatesPlayerVictory[] =
        "お兄ちゃん、優勝おめでとう！\r\n"
        "今度、優勝した牛にのせてよ。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_RespondsToPlayerLoss[] =
        "お兄ちゃんの牛、\r\n"
        "負けちゃったんだね。\r\n"
        "来年は絶対勝ってね。{Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Stu(void)
{
    if (HasMetNpc(CHARACTER_STU) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_STU);
    }
    SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_STU);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_NoPlayerEntryComment);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_CongratulatesPlayerVictory);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_STU);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Stu_RespondsToPlayerLoss);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_STU) == FALSE)
    {
        AddNpcFriendship(CHARACTER_STU, 5);
    }
    MarkNpcSpokenTo(CHARACTER_STU);
    SetEntityFacing(ENTITY_STU, FACING_UP);
}
