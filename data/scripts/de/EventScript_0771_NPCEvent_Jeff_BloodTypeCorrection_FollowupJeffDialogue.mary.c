#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0771_NPCEvent_Jeff_BloodTypeCorrection_FollowupJeffDialogue.mary.h"

void EventScript_0771_NPCEvent_Jeff_BloodTypeCorrection_FollowupJeffDialogue(void)
{
    if (VarGet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_Jeff_Followup_JeffPlansToTellSashaAboutCorrection);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_JEFF);
        SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    }
}
