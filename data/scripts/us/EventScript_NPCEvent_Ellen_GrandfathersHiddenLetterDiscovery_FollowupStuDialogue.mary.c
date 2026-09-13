#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupStuDialogue_StuMissesGrandfather[] =
        "I miss Grandpa...{Press}";
};

void EventScript_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupStuDialogue(void)
{
    if (VarGet(VAR_ELLEN_GRANDFATHERS_HIDDEN_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_STU_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_STU);
        TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupStuDialogue_StuMissesGrandfather);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_STU);
        SetEntityFacing(ENTITY_STU, FACING_LEFT);
    }
}
