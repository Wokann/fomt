#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Manna_PlayerDoYouHaveAnyWater[] =
        "{Player}さん、\r\n"
        "お水持ってない？{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Manna_ItWasAnnaWhoPutIn[] =
        "あの香草を入れたのは、アンナ\r\n"
        "さんね。魚のくさみがとれて、\r\n"
        "ちょうどいい感じだったわ。\r\n"
        "でも、ちょっと香りがきつすぎ\r\n"
        "たかも。{Press}";
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
