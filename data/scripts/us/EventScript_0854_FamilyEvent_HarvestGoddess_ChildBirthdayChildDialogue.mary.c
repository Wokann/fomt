#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0854_FamilyEvent_HarvestGoddess_ChildBirthdayChildDialogue.mary.h"

void EventScript_0854_FamilyEvent_HarvestGoddess_ChildBirthdayChildDialogue(void)
{
    SetEntityFacing(ENTITY_CHILD, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
    TalkMessage(gText_FamilyEvent_HarvestGoddess_ChildBirthdayChildDialogue_ChildResponse);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_CHILD);
    SetEntityFacing(ENTITY_CHILD, FACING_DOWN);
}
