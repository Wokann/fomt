#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0954_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_FollowupDoctorDialogue.mary.h"

void EventScript_0954_RivalEvent_ElliAndDoctor_04_OrangeHeart_MineralBeachConfession_FollowupDoctorDialogue(void)
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
