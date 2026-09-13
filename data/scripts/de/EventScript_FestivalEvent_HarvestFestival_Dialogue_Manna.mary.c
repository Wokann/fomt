#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Manna_PlayerDoYouHaveAnyWater[] =
        "{Player}, \r\n"
        "hast du etwas Wasser?{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Manna_ItWasAnnaWhoPutIn[] =
        "Anna hat diese \r\n"
        "Kräuter hineingetan. Sie \r\n"
        "heben den Fischgeschmack.\r\n"
        "Vielleicht zu sehr...{Press}";
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
