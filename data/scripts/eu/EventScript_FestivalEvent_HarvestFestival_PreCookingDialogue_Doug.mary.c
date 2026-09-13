#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Doug[] =
        "Hey!! Everyone don't stuff \r\n"
        "in everything at once!{Press}\p"
        "You there, get back!\r\n"
        "...What's this fish doing \r\n"
        "here...?!?{Press}";
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
