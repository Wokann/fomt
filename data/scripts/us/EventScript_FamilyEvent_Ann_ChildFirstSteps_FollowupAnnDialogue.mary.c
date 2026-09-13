#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Ann_ChildFirstSteps_FollowupAnnDialogue_AnnPlansFamilyMountainHike[] =
        "I can't wait to go on a \r\n"
        "family hike!{Press}";
};

void EventScript_FamilyEvent_Ann_ChildFirstSteps_FollowupAnnDialogue(void)
{
    SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ANN);
    SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ANN);
    TalkMessage(gText_FamilyEvent_Ann_ChildFirstSteps_FollowupAnnDialogue_AnnPlansFamilyMountainHike);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ANN);
    SetEntityFacing(ENTITY_ANN, FACING_LEFT);
}
