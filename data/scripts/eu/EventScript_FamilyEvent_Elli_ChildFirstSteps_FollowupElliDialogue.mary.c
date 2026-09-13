#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Elli_ChildFirstSteps_FollowupElliDialogue_ElliCallsChildATreasure[] =
        "He's such a treasure!{Press}";
};

void EventScript_FamilyEvent_Elli_ChildFirstSteps_FollowupElliDialogue(void)
{
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_FamilyEvent_Elli_ChildFirstSteps_FollowupElliDialogue_ElliCallsChildATreasure);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ELLI);
    SetEntityFacing(ENTITY_ELLI, FACING_LEFT);
}
