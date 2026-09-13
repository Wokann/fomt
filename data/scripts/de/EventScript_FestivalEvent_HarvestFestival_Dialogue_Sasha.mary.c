#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Sasha_IBetItsKarensFaultAgain[] =
        "Ich wette, es ist wieder \r\n"
        "Karens Schuld! Sie \r\n"
        "hat vielleicht Bonbons {Press}\r\n"
        "reingetan oder so...{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Sasha_ThankGoodnessNoOnePutIn[] =
        "Zum Glück hat diesmal\r\n"
        "niemand etwas Komisches\r\n"
        "hineingetan!{Press}";
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
