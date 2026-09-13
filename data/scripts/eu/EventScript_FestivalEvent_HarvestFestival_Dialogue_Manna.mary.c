#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Manna_PlayerDoYouHaveAnyWater[] =
        "{Player}, \r\n"
        "do you have any water?{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Manna_ItWasAnnaWhoPutIn[] =
        "It was Anna who put in \r\n"
        "those herbs. They make the \r\n"
        "fish much more fragrant.\r\n"
        "Too fragrant, maybe...{Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_MANNA_AFRAID);
        TalkMessageSlow(gText_FestivalEvent_HarvestFestival_Dialogue_Manna_PlayerDoYouHaveAnyWater);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
        TalkMessageSlow(gText_FestivalEvent_HarvestFestival_Dialogue_Manna_ItWasAnnaWhoPutIn);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
}
