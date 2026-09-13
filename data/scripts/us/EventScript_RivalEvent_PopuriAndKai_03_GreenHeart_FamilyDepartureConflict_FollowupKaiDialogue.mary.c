#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_FollowupKaiDialogue_KaiWondersWhetherPopuriIsSeriousAboutLeaving[] =
        "I wonder if Popuri's \r\n"
        "serious?{Press}";
};

void EventScript_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_FollowupKaiDialogue(void)
{
    SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_03_GreenHeart_FamilyDepartureConflict_FollowupKaiDialogue_KaiWondersWhetherPopuriIsSeriousAboutLeaving);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_UP);
    MarkNpcSpokenTo(CHARACTER_KAI);
}
