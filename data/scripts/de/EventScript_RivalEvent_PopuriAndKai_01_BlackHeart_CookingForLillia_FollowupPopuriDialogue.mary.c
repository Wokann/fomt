#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_FollowupPopuriDialogue_PopuriInvitesPlayerToJoinThem[] =
        "Mach einfach mit, wenn \r\n"
        "du Zeit hast. {Press}";
};

void EventScript_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_FollowupPopuriDialogue(void)
{
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_POPURI);
    }
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_FollowupPopuriDialogue_PopuriInvitesPlayerToJoinThem);
    TalkClose();
    SetEntityFacing(ENTITY_POPURI, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_POPURI);
}
