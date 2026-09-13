#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Thomas[] =
        "Did you come for New Year \r\n"
        "Noodles, {Player}? {Press}\p"
        "Do you like Buckwheat \r\n"
        "Noodles? {Press}";
};

void EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    TalkMessage(gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Thomas);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
}
