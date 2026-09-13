#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Carter_ThisKindOfThingIsWhat[] =
        "This kind of thing is what \r\n"
        "makes this Festival so fun!\r\n"
        "Ha ha ha...!!{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Carter_ItsFunWhenYouEatWith[] =
        "It's fun when you eat with\r\n"
        "all your friends like this!{Press}";
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
