#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupDoctorDialogue[] =
        "I understand how Stu\r\n"
        "feels, though. {Press}\p"
        "All children want lots of \r\n"
        "attention, so they bother \r\n"
        "people they like. {Press}";
};

void EventScript_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupDoctorDialogue(void)
{
    if (VarGet(VAR_ELLI_BLACK_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_LoveEvent_Elli_01_BlackHeart_MeetElliAndStu_FollowupDoctorDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
}
