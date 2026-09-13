#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Jeff_BloodTypeCorrection_Doctor_Followup_DoctorIsDisturbedByMedicalError[] =
        "Diese Art Fehler ist \r\n"
        "sehr beunruhigend...{Press}";
};

void EventScript_NPCEvent_Jeff_BloodTypeCorrection_FollowupDoctorDialogue(void)
{
    if (VarGet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_SURPRISED);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_Doctor_Followup_DoctorIsDisturbedByMedicalError);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
        SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    }
}
