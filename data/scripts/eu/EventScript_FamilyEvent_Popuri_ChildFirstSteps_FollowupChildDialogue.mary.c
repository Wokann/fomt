#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_ChildFirstSteps_FollowupChildDialogue_ChildCallsPlayerDaDa[] =
        "Da-da.{Press}";
};

void EventScript_FamilyEvent_Popuri_ChildFirstSteps_FollowupChildDialogue(void)
{
    SetEntityFacing(ENTITY_CHILD, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_HAPPY);
    TalkMessage(gText_FamilyEvent_Popuri_ChildFirstSteps_FollowupChildDialogue_ChildCallsPlayerDaDa);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_CHILD);
    SetEntityFacing(ENTITY_CHILD, FACING_RIGHT);
}
