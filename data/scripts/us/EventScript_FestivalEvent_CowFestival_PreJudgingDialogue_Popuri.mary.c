#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Popuri_NoPlayerEntryComment[] =
        "I didn't use to like Milk,\r\n"
        "but now I love it. {Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Popuri_EncouragesPlayerEntry[] =
        "I hope you win, \r\n"
        "{Player}. {Press}";
};

void EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Popuri(void)
{
    if (HasMetNpc(CHARACTER_POPURI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_POPURI);
    }
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_POPURI);
        }
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Popuri_NoPlayerEntryComment);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_POPURI);
        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_POPURI);
        }
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Popuri_EncouragesPlayerEntry);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_POPURI) == FALSE)
    {
        AddNpcFriendship(CHARACTER_POPURI, 5);
    }
    MarkNpcSpokenTo(CHARACTER_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_DOWN);
}
