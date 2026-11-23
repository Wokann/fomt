#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0958_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue.mary.h"

void EventScript_0958_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue(void)
{
    if (HasMetNpc(CHARACTER_DOCTOR) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_DOCTOR) == FALSE)
    {
        SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue_DoctorInvitesPlayerToCelebrateMarriage);
        TalkClose();
        SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
    }
    else
    {
        SetEntityFacing(ENTITY_DOCTOR, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOCTOR_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_DOCTOR);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue_DoctorSaysClinicWillNotChange);
        TalkClose();
        SetEntityFacing(ENTITY_DOCTOR, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_DOCTOR);
    }
}
