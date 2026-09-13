#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Barley_ThereAreLotsOfGoodCows[] =
        "今年も、いい牛が\r\n"
        "たくさん来たの。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Barley_YouGottaTakeGoodCareOf[] =
        "これからも動物たちを\r\n"
        "大事にするとええ。{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Barley_BarleyConsolesPlayer[] =
        "惜しかったの。{Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Barley(void)
{
    if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BARLEY);
    }
    SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Barley_ThereAreLotsOfGoodCows);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Barley_YouGottaTakeGoodCareOf);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Barley_BarleyConsolesPlayer);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_BARLEY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_BARLEY);
    SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
}
