#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Anna_CommentsAfterAcceptedPlayerContribution[] =
        "Warum ich wohl so \r\n"
        "müde bin...{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Anna_CommentsWithoutAcceptedPlayerContribution[] =
        "Das war köstlich!\r\n"
        "Ich sehe, es sind keine \r\n"
        "Zutaten übrig. {Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Anna(void)
{
    if (HasMetNpc(CHARACTER_ANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_ANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ANNA, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_ANNA_AFRAID);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Anna_CommentsAfterAcceptedPlayerContribution);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Anna_CommentsWithoutAcceptedPlayerContribution);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    SetEntityFacing(ENTITY_ANNA, FACING_DOWN);
}
