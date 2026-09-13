#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Gotz[] =
        "日ごろは自分の作ったまずい\r\n"
        "料理を食べているから、今日は\r\n"
        "うれしいぜ。{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PostJudgingDialogue_Gotz(void)
{
    if (HasMetNpc(CHARACTER_GOTZ) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GOTZ);
    }
    SetEntityFacing(ENTITY_GOTZ, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Gotz);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GOTZ) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GOTZ, 5);
    }
    SetEntityFacing(ENTITY_GOTZ, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_GOTZ);
}
