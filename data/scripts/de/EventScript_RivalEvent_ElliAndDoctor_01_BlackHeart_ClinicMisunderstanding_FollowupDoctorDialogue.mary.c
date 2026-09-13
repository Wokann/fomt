#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_FollowupDoctorDialogue_DoctorWorriesElliSeemsWorse[] =
        "Ob es Elli gut geht?\r\n"
        "Sieht immer schlechter aus.{Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_FollowupDoctorDialogue(void)
{
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_AFRAID);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_01_BlackHeart_ClinicMisunderstanding_FollowupDoctorDialogue_DoctorWorriesElliSeemsWorse);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
}
