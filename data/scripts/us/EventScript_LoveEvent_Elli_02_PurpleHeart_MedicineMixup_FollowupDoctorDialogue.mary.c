#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupDoctorDialogue[] =
        "Elli is working very hard.{Press}";
};

void EventScript_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupDoctorDialogue(void)
{
    if (VarGet(VAR_ELLI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupDoctorDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
}
