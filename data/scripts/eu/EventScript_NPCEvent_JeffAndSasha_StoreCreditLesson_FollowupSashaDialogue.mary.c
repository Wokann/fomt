#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_Sasha_Followup_SashaHopesLessonCuresJeffsCreditHabit[] =
        "I hope this makes her \r\n"
        "better...{Press}";
};

void EventScript_NPCEvent_JeffAndSasha_StoreCreditLesson_FollowupSashaDialogue(void)
{
    if (VarGet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_Sasha_Followup_SashaHopesLessonCuresJeffsCreditHabit);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_SASHA);
        SetEntityFacing(ENTITY_SASHA, FACING_RIGHT);
    }
}
