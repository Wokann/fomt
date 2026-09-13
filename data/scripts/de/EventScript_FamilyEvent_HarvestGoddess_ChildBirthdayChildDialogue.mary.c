#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_HarvestGoddess_ChildBirthdayChildDialogue_ChildResponse[] =
        "Ga-Ga. {Press}";
};

void EventScript_FamilyEvent_HarvestGoddess_ChildBirthdayChildDialogue(void)
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
