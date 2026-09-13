#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Doug_ThatsStrangeITastedItA[] =
        "That's strange...\r\n"
        "I tasted it a while ago, \r\n"
        "but...{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Doug_MmmAnythingIMakeIsBound[] =
        "Mmm...Anything I make is \r\n"
        "bound to turn out well! {Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Doug(void)
{
    if (HasMetNpc(CHARACTER_DOUG) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_DOUG) == FALSE)
    {
        AddNpcFriendship(CHARACTER_DOUG, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Doug_ThatsStrangeITastedItA);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Doug_MmmAnythingIMakeIsBound);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
}
