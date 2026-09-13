#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Sasha[] =
        "Ich kam gerade mit Jeff. \r\n"
        "Ich liebe Neujahrsnudeln\r\n"
        "allerdings auch. {Press}";
};

void EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Sasha);
    ClearTalkPortrait();
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_SASHA);
    SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
}
