#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue_DoctorInvitesPlayerToCelebrateMarriage[] =
        "よかったら、\r\n"
        "いっしょにのもう。{Press}\p"
        "ボクとエリィの事、\r\n"
        "いわってくれ。{Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupDoctorDialogue_DoctorSaysClinicWillNotChange[] =
        "病院は今までどおりだよ。\r\n"
        "何も変わらない。{Press}";
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
