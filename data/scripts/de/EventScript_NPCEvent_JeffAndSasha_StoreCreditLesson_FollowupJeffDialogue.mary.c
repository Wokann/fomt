#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_JeffAndSasha_StoreCreditLesson_Jeff_Followup_JeffFeelsMoreConfident[] =
        "Ich komm jetzt klar!!\r\n"
        "...Denke ich...{Press}";
};

void EventScript_NPCEvent_JeffAndSasha_StoreCreditLesson_FollowupJeffDialogue(void)
{
    if (VarGet(VAR_JEFF_AND_SASHA_STORE_CREDIT_LESSON_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_NPCEvent_JeffAndSasha_StoreCreditLesson_Jeff_Followup_JeffFeelsMoreConfident);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_JEFF);
        SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
    }
}
