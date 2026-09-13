#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Doug_ThatsStrangeITastedItA[] =
        "Eigenartig...\r\n"
        "Ich habe es vor einer \r\n"
        "Weile probiert, aber...{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Doug_MmmAnythingIMakeIsBound[] =
        "Mmm... Alles was ich \r\n"
        "mache, gelingt so gut! {Press}";
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
