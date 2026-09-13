#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_ChildPostFirstStepsInteraction_Response[] =
        "だぁ。{Press}";
};

void EventScript_FamilyEvent_HarvestGoddess_ChildPostFirstStepsInteraction(void)
{
    SetEntityFacing(ENTITY_CHILD, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildPostFirstStepsInteraction_Response);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_CHILD);
    SetEntityFacing(ENTITY_CHILD, FACING_DOWN);
}
