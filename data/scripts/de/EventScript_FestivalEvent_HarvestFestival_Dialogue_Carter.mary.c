#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Carter_ThisKindOfThingIsWhat[] =
        "Das ist, was das Festival\r\n"
        "so witzig macht!\r\n"
        "Ha ha ha...!!{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Carter_ItsFunWhenYouEatWith[] =
        "Es macht Spaß, wenn du\r\n"
        "so mit allen Freunden isst!{Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Carter(void)
{
    if (HasMetNpc(CHARACTER_CARTER) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
    SetEntityFacing(ENTITY_CARTER, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_CARTER) == FALSE)
    {
        AddNpcFriendship(CHARACTER_CARTER, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CARTER);
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_CARTER_HAPPY);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Carter_ThisKindOfThingIsWhat);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_CARTER_NORMAL);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Carter_ItsFunWhenYouEatWith);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_CARTER);
    }
    SetEntityFacing(ENTITY_CARTER, FACING_DOWN);
}
