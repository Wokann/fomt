#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_Elli_Followup_ElliIsDeterminedToHealEllen[] =
        "Ich bin entschlossen, Groß-\r\n"
        "mutters Beine zu heilen!{Press}";
};

void EventScript_NPCEvent_Elli_StudiesMedicineForEllensLegs_FollowupElliDialogue(void)
{
    if (VarGet(VAR_ELLI_STUDIES_MEDICINE_FOR_ELLENS_LEGS_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkNameplateCharacter(CHARACTER_ELLI);
        if (!(VarGet(VAR_KAREN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_POPURI_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_ANN_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_MARY_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED || VarGet(VAR_HARVEST_GODDESS_WEDDING_AND_NICKNAME_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_WEDDING_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED || VarGet(VAR_ELLI_DOCTOR_RIVAL_MARRIAGE_STATE) == MARRIAGE_STATE_MARRIED))
        {
            ShowTalkHeartIndicator(CHARACTER_ELLI);
        }
        SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
        TalkMessage(gText_NPCEvent_Elli_StudiesMedicineForEllensLegs_Elli_Followup_ElliIsDeterminedToHealEllen);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ELLI);
        SetEntityFacing(ENTITY_ELLI, FACING_RIGHT);
    }
}
