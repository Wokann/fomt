#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Basil_PublishingAward_BasilCreditsHisFamily[] =
        "Das verdanke ich alles \r\n"
        "meiner Familie. {Press}";
};

void EventScript_NPCEvent_Basil_PublishingAward_FollowupBasilDialogue(void)
{
    SetEntityFacing(ENTITY_BASIL, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_BASIL);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_BasilCreditsHisFamily);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_BASIL);
    SetEntityFacing(ENTITY_BASIL, FACING_DOWN);
    return;
}
