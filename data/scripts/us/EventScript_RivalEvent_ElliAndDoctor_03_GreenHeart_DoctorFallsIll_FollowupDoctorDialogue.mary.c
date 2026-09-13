#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_FollowupDoctorDialogue_DoctorAdmitsHeHasACold[] =
        "Hmm... I guess I got\r\n"
        "a touch of the flu.{Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_FollowupDoctorDialogue(void)
{
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_FollowupDoctorDialogue_DoctorAdmitsHeHasACold);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
}
