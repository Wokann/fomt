#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_FollowupDoctorDialogue_DoctorGreetsPlayerNervously[] =
        "や…やあ。{Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_FollowupDoctorDialogue(void)
{
    SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOCTOR_SURPRISED);
    SetTalkNameplateCharacter(CHARACTER_DOCTOR);
    TalkMessage(gText_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_FollowupDoctorDialogue_DoctorGreetsPlayerNervously);
    TalkClose();
    SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_DOCTOR);
}
