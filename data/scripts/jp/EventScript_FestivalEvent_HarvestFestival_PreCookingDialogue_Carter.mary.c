#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Carter[] =
        "いやぁ、なつかしいなぁ。\r\n"
        "わたしもむかし、こういう事を\r\n"
        "しましたよ。{Press}\p"
        "たくさんスープを作って、\r\n"
        "町の人にふるまうんです。{Press}";
};

void EventScript_FestivalEvent_HarvestFestival_PreCookingDialogue_Carter(void)
{
    if (HasMetNpc(CHARACTER_CARTER) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    TalkMessage(gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Carter);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_CARTER) == FALSE)
    {
        AddNpcFriendship(CHARACTER_CARTER, 5);
    }
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_CARTER);
}
