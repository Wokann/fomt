#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_MothersDeathAnniversary_Followup_DougReflectsOnLateWife[] =
        "Heute ist der einzige Tag,\r\n"
        "an dem ich mir erlaube, \r\n"
        "an sie zu denken...{Press}";
};

void EventScript_FamilyEvent_Ann_MothersDeathAnniversary_FollowupDougDialogue(void)
{
    if (VarGet(VAR_ANN_MOTHERS_DEATH_ANNIVERSARY_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_FamilyEvent_Ann_MothersDeathAnniversary_Followup_DougReflectsOnLateWife);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_DOUG);
        SetEntityFacing(ENTITY_DOUG, FACING_UP);
    }
}
