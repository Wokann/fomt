#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Anna[] =
        "Die Reste kann ich heute\r\n"
        "zum Abendbrot essen,\r\n"
        "dann brauch ich {Press}\r\n"
        "nichts zu machen!{Press}";
};

void EventScript_FestivalEvent_HarvestFestival_PreCookingDialogue_Anna(void)
{
    if (HasMetNpc(CHARACTER_ANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Anna);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ANNA, 5);
    }
    SetEntityFacing(ENTITY_ANNA, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_ANNA);
}
