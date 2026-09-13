#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Sasha_IBetItsKarensFaultAgain[] =
        "I bet it's Karen's fault \r\n"
        "again! She probably put in \r\n"
        "candy or something...{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Sasha_ThankGoodnessNoOnePutIn[] =
        "Thank goodness no one\r\n"
        "put in something strange\r\n"
        "this time!{Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Sasha(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_SASHA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SASHA, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_SASHA);
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_SASHA_AFRAID);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Sasha_IBetItsKarensFaultAgain);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Sasha_ThankGoodnessNoOnePutIn);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    SetEntityFacing(ENTITY_SASHA, FACING_LEFT);
}
