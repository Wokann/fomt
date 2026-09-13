#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_FollowupElliDialogue_ElliWondersWhatDoctorMeant[] =
        "I wonder what he meant by\r\n"
        "that...? {Press}";
};

void EventScript_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_FollowupElliDialogue(void)
{
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_BLUSHING);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
    {
        ShowTalkHeartIndicator(CHARACTER_ELLI);
    }
    TalkMessage(gText_RivalEvent_ElliAndDoctor_03_GreenHeart_DoctorFallsIll_FollowupElliDialogue_ElliWondersWhatDoctorMeant);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_ELLI);
}
