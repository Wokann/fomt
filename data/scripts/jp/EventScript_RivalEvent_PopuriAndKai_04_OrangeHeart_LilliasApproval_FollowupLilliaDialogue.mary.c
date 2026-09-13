#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupLilliaDialogue_LilliaAnticipatesPreparationsAndMissesRod[] =
        "さあ、いそがしくなるわね～。\r\n"
        "うちの人も、早く\r\n"
        "帰ってくればいいのに～。{Press}";
};

void EventScript_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupLilliaDialogue(void)
{
    SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupLilliaDialogue_LilliaAnticipatesPreparationsAndMissesRod);
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_LILLIA);
}
