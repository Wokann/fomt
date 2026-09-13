#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_Doctor_Followup_DoctorBelievesElliWillSucceed[] =
        "I'm sure she can do it.{Press}";
};

void EventScript_NPCEvent_Elli_StudiesMedicineForEllensLegs_FollowupDoctorDialogue(void)
{
    if (VarGet(VAR_ELLI_STUDIES_MEDICINE_FOR_ELLENS_LEGS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_Doctor_Followup_DoctorBelievesElliWillSucceed);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
        SetEntityFacing(ENTITY_DOCTOR, FACING_LEFT);
    }
}
