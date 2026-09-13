#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_AnniversaryChildReaction[] =
        "だあ？{Press}";
};

void EventScript_FamilyEvent_Ann_AnniversaryChildReaction(void)
{
    if (VarGet(VAR_ANN_CHILDBIRTH_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED)
    {
        if (VarGet(VAR_CHILD_AGE_DAYS) >= CHILD_AGE_DAYS_FAMILY_SCENE_AND_INJURY_EVENT_START)
        {
            SetEntityFacing(ENTITY_CHILD, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
            TalkOpen();
            SetTalkNameplateCharacter(CHARACTER_CHILD);
            SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
            TalkMessage(gText_FamilyEvent_Ann_AnniversaryChildReaction);
            TalkClose();
            MarkNpcSpokenTo(CHARACTER_CHILD);
            SetEntityFacing(ENTITY_CHILD, FACING_DOWN);
        }
        else
        {
            return;
        }
    }
}
