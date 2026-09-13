#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_Dialogue_May[] =
        "メイも大きくなったら、\r\n"
        "音楽祭でおうたをうたいたい\r\n"
        "なぁ。{Press}";
};

void EventScript_FestivalEvent_MusicFestival_Dialogue_May(void)
{
    if (HasMetNpc(CHARACTER_MAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MAY);
    }
    SetEntityFacing(ENTITY_MAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MAY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MAY);
    TalkMessage(gText_FestivalEvent_MusicFestival_Dialogue_May);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MAY, 5);
    }
    SetEntityFacing(ENTITY_MAY, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_MAY);
}
