#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Doug_ThatsStrangeITastedItA[] =
        "おかしいなぁ、\r\n"
        "オレ、とちゅうで味見したん\r\n"
        "だぜ。{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Doug_MmmAnythingIMakeIsBound[] =
        "やっぱりオレが作った物は\r\n"
        "何でもうまいなぁ。{Press}";
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
