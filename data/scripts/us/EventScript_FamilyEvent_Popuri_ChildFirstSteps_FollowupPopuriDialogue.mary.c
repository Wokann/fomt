#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_ChildFirstSteps_FollowupPopuriDialogue_PopuriPlansFamilyPicnic[] =
        "I can't wait to go \r\n"
        "for a family picnic!{Press}";
};

void EventScript_FamilyEvent_Popuri_ChildFirstSteps_FollowupPopuriDialogue(void)
{
    SetEntityFacing(ENTITY_POPURI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_POPURI);
    SetTalkPortrait(TALK_PORTRAIT_POPURI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_POPURI);
    TalkMessage(gText_FamilyEvent_Popuri_ChildFirstSteps_FollowupPopuriDialogue_PopuriPlansFamilyPicnic);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_POPURI);
    SetEntityFacing(ENTITY_POPURI, FACING_LEFT);
}
