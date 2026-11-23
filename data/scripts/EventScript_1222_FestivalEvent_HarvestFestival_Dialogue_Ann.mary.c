#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_1222_FestivalEvent_HarvestFestival_Dialogue_Ann.mary.h"

void EventScript_1222_FestivalEvent_HarvestFestival_Dialogue_Ann(void)
{
    if (HasMetNpc(CHARACTER_ANN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_ANN) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ANN, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ANN_CLIFF_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ANN);
    }
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_AFRAID);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Ann_MyStomachIsntFullYetI);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_SURPRISED);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Ann_OhhhIAteTooMuchAgain);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
}
