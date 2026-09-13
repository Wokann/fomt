#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_MusicFestival_Dialogue_Sasha[] =
        "Ich mag es, dass wir alle\r\n"
        "zusammen musizieren. {Press}";
};

void EventScript_FestivalEvent_MusicFestival_Dialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_FestivalEvent_MusicFestival_Dialogue_Sasha);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    SetEntityFacing(ENTITY_SASHA, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_SASHA);
}
