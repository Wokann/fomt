#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Thomas_CommentsAfterAcceptedPlayerContribution[] =
        "Da jeder mitgeholfen hat,\r\n"
        "schmeckt es so gut...{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Thomas_CommentsWithoutAcceptedPlayerContribution[] =
        "Hattest du Spaß?\r\n"
        "Manchmal macht es Spaß,\r\n"
        "mit allen zu essen, oder?{Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Thomas_CommentsAfterAcceptedPlayerContribution);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Thomas_CommentsWithoutAcceptedPlayerContribution);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
}
