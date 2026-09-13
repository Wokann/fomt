#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HarvestFestival_Dialogue_Elli_CommentsAfterAcceptedPlayerContribution[] =
        "みんなどうしたのかしら？\r\n"
        "おいしかったと思うけど？{Press}";

    const char gText_FestivalEvent_HarvestFestival_Dialogue_Elli_CommentsWithoutAcceptedPlayerContribution[] =
        "お魚のダシがきいてたわね。{Press}";
};

void EventScript_FestivalEvent_HarvestFestival_Dialogue_Elli(void)
{
    if (HasMetNpc(CHARACTER_ELLI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (WasNpcSpokenToToday(CHARACTER_ELLI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ELLI, 5);
    }
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    if (VarGet(VAR_HARVEST_FESTIVAL_CONTRIBUTED_INGREDIENT_ACCEPTED) == TRUE)
    {
        SetTalkPortrait(TALK_PORTRAIT_ELLI_ANGRY);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Elli_CommentsAfterAcceptedPlayerContribution);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ELLI_HAPPY);
        TalkMessage(gText_FestivalEvent_HarvestFestival_Dialogue_Elli_CommentsWithoutAcceptedPlayerContribution);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ELLI);
    }
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
}
