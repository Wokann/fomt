#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue_DoctorInvitesPlayerToCelebrateMarriage[] =
        "Treffen wir uns \r\n"
        "mal. Wir  \r\n"
        "können feiern. {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue_DoctorSaysClinicWillNotChange[] =
        "Hier in der Klinik \r\n"
        "ändert sich nichts. {Press}";
};

void EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue(void)
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
