#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_Argument_FollowupAnnDialogue_StoppedFight_AnnExasperatedByForgottenCause[] =
        "Huh, can you believe this?{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupAnnDialogue_NotIntervened_AnnContinuesPleadingWithDoug[] =
        "Dad!...\r\n"
        "Stop arguing already!!{Press}";
};

void EventScript_NPCEvent_DougAndDuke_Argument_FollowupAnnDialogue(void)
{
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_POPURI);
    }
    if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_CHOICE) == DOUG_DUKE_ARGUMENT_STOP_FIGHT)
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
        TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupAnnDialogue_StoppedFight_AnnExasperatedByForgottenCause);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_ANN_ANGRY);
        TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupAnnDialogue_NotIntervened_AnnContinuesPleadingWithDoug);
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ANN);
    SetEntityFacing(ENTITY_ANN, FACING_DOWN);
    return;
}
