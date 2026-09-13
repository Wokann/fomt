#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_FollowupDoctorDialogue_DoctorRemainsLostInThought[] =
        "……………………………………{Press}";
};

void EventScript_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_FollowupDoctorDialogue(void)
{
    if (VarGet(VAR_DOCTOR_REFLECTS_ON_PARENTS_AND_MEDICAL_CALLING_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        if (HasMetNpc(CHARACTER_DOCTOR) == FALSE)
        {
            MarkNpcSpokenTo(CHARACTER_DOCTOR);
        }
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_NPCEvent_Doctor_ReflectsOnParentsAndMedicalCalling_FollowupDoctorDialogue_DoctorRemainsLostInThought);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
        SetEntityFacing(ENTITY_DOCTOR, FACING_UP);
    }
}
