#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Sasha_IBetItsKarensFaultAgain[] =
        "あー、またカレンだわ…\r\n"
        "きっと。今度はキャンディー\r\n"
        "かしら、マシュマロかしら。{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Sasha_ThankGoodnessNoOnePutIn[] =
        "はぁ、よかった。\r\n"
        "今回は変なものが入って\r\n"
        "なかったわね。{Press}";
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
