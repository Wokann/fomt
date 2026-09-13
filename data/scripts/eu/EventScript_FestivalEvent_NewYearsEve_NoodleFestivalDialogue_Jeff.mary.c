#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Jeff[] =
        "Buckwheat Noodles are really\r\n"
        "good for you, you know. {Press}\p"
        "That's why I'm going to \r\n"
        "eat a lot!{Press}";
};

void EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Jeff(void)
{
    if (HasMetNpc(CHARACTER_JEFF) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
    SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    TalkMessage(gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Jeff);
    ClearTalkPortrait();
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_JEFF) == FALSE)
    {
        AddNpcFriendship(CHARACTER_JEFF, 5);
    }
    MarkNpcSpokenTo(CHARACTER_JEFF);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
}
