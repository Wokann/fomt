#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupLilliaDialogue_LilliaAnticipatesPreparationsAndMissesRod[] =
        "Things are going to get \r\n"
        "busy around here! \r\n"
        "I only wish my darling{Press}\r\n"
        "would come back...{Press}";
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
