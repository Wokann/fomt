#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Jeff_BloodTypeCorrection_Jeff_Followup_JeffPlansToTellSashaAboutCorrection[] =
        "I have to tell Sasha about\r\n"
        "this when I get home! {Press}\p"
        "She always did say that\r\n"
        "my personality was too kind\r\n"
        "for that blood type!{Press}";
};

void EventScript_NPCEvent_Jeff_BloodTypeCorrection_FollowupJeffDialogue(void)
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
