#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Rick_WorriesAboutLilliasHealth_PopuriWorriesAboutLilliasIllness[] =
        "お母さん、\r\n"
        "体弱いから心配だな…{Press}\p"
        "早く、\r\n"
        "元気になってくれないかな…{Press}";
};

void EventScript_NPCEvent_Rick_WorriesAboutLilliasHealth_FollowupPopuriDialogue(void)
{
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_POPURI_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ELLI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_POPURI_KAI_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_POPURI);
    }
    TalkMessage(gText_NPCEvent_Rick_WorriesAboutLilliasHealth_PopuriWorriesAboutLilliasIllness);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_UP);
    return;
}
