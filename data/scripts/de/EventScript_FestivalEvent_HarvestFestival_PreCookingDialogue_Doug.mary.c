#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Doug[] =
        "Hey!! Ihr alle! Stopft\r\n"
        "nicht alles auf einmal rein!{Press}\p"
        "Du da, geh zurück!\r\n"
        "...Was macht der Fisch \r\n"
        "hier...?!?{Press}";
};

void EventScript_FestivalEvent_HarvestFestival_PreCookingDialogue_Doug(void)
{
    if (HasMetNpc(CHARACTER_DOUG) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Doug);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_DOUG) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOUG, 5);
    }
    SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_DOUG);
}
