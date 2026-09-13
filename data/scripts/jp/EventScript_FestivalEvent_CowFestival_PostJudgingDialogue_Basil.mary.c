#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Basil_HaHaHaThatCowLicked[] =
        "ははははは、\r\n"
        "顔中なめられちゃったよ。\r\n"
        "まいったなー。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Basil_ItsImpressiveToWinAmongSuch[] =
        "この牛の中で優勝するなんて\r\n"
        "大したものだね。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Basil_DontGetTooUpsetItsThe[] =
        "参加することが重要なんだし、\r\n"
        "そう落ち込まなくてもいいよ。{Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Basil(void)
{
    if (HasMetNpc(CHARACTER_BASIL) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BASIL);
    }
    SetEntityFacing(ENTITY_BASIL, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_BASIL);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Basil_HaHaHaThatCowLicked);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BASIL);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Basil_ItsImpressiveToWinAmongSuch);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BASIL);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Basil_DontGetTooUpsetItsThe);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_BASIL) == FALSE)
    {
        AddNpcFriendship(CHARACTER_BASIL, 5);
    }
    MarkNpcSpokenTo(CHARACTER_BASIL);
    SetEntityFacing(ENTITY_BASIL, FACING_UP);
}
