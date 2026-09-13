#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Gotz[] =
        "Es macht mehr Spaß,\r\n"
        "mit anderen zu essen, \r\n"
        "wenn man allein lebt. {Press}";
};

void EventScript_FestivalEvent_HarvestFestival_PreCookingDialogue_Gotz(void)
{
    if (HasMetNpc(CHARACTER_GOTZ) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GOTZ);
    }
    SetEntityFacing(ENTITY_GOTZ, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GOTZ_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GOTZ);
    TalkMessage(gText_FestivalEvent_HarvestFestival_PreCookingDialogue_Gotz);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GOTZ) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GOTZ, 5);
    }
    SetEntityFacing(ENTITY_GOTZ, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_GOTZ);
}
