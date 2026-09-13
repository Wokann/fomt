#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Mary_ThereAreSomeThingsYouShould[] =
        "There are some things you \r\n"
        "should just never put in \r\n"
        "the pot! {Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Mary_WeShouldBeThankfulForThe[] =
        "We should be thankful for \r\n"
        "the bounty of nature, which\r\n"
        "sustains us. {Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Mary(void)
{
    if (HasMetNpc(CHARACTER_MARY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_MARY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MARY, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MARY);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_MARY_GRAY_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_MARY);
    }
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_MARY_AFRAID);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Mary_ThereAreSomeThingsYouShould);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Mary_WeShouldBeThankfulForThe);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_MARY);
    }
    SetEntityFacing(ENTITY_MARY, FACING_UP);
}
