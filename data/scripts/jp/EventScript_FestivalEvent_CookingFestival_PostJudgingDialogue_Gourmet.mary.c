#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Gourmet[] =
        "皆さんの料理にかける意気込み\r\n"
        "がヒシヒシと伝わってきます\r\n"
        "ね。{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PostJudgingDialogue_Gourmet(void)
{
    if (HasMetNpc(CHARACTER_GOURMET) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GOURMET);
    }
    SetEntityFacing(ENTITY_GOURMET, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOURMET_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GOURMET);
    TalkMessage(gText_FestivalEvent_CookingFestival_PostJudgingDialogue_Gourmet);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GOURMET) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GOURMET, 5);
    }
    SetEntityFacing(ENTITY_GOURMET, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_GOURMET);
}
