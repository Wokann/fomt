#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsDayFestivalDialogue_Manna[] =
        "Du bist also auch hier, \r\n"
        "{Player}?{Press}\r\n"
        "Sonst esse ich keine \r\n"
        "Reiskuchen, weil sie \r\n"
        "dick machen.  Nur {Press}\r\n"
        "einmal im Jahr  \r\n"
        "erlaube ich mir das. Hi-hii!{Press}";
};

void EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessage(gText_FestivalEvent_NewYearsDayFestivalDialogue_Manna);
    ClearTalkPortrait();
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_LEFT);
}
