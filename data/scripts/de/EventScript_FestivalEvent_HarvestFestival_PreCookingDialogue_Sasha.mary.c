#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Sasha[] =
        "Wir müssen auf Karen \r\n"
        "aufpassen. {Press}\p"
        "Letztes Jahr hat sie\r\n"
        "Schokolade reingetan! {Press}";
};

void EventScript_FestivalEvent_HarvestFestival_PreCookingDialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SASHA_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    TalkMessage(gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Sasha);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    SetEntityFacing(ENTITY_SASHA, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_SASHA);
}
