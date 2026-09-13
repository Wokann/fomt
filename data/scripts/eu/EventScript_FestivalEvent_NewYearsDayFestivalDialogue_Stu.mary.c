#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsDayFestivalDialogue_Stu[] =
        "I like how gooey they are! {Press}";
};

void EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Stu(void)
{
    if (HasMetNpc(CHARACTER_STU) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_STU);
    }
    SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_STU);
    TalkMessage(gText_FestivalEvent_NewYearsDayFestivalDialogue_Stu);
    ClearTalkPortrait();
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_STU) == FALSE)
    {
        AddNpcFriendship(CHARACTER_STU, 5);
    }
    MarkNpcSpokenTo(CHARACTER_STU);
    SetEntityFacing(ENTITY_STU, FACING_RIGHT);
}
