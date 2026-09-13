#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Carter[] =
        "わたしは、この祭りが大好き\r\n"
        "でしてね。みなさんのウデを\r\n"
        "見る事も出来ますしね。{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Carter(void)
{
    if (HasMetNpc(CHARACTER_CARTER) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Carter);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_CARTER) == FALSE)
    {
        AddNpcFriendship(CHARACTER_CARTER, 5);
    }
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_CARTER);
}
