#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0622_FamilyEvent_Mary_BabyBirthdayGooGoo.mary.h"

void EventScript_0622_FamilyEvent_Mary_BabyBirthdayGooGoo(void)
{
    SetEntityFacing(ENTITY_CHILD, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
    TalkMessage(gText_FamilyEvent_Mary_BabyBirthdayGooGoo);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_CHILD);
    SetEntityFacing(ENTITY_CHILD, FACING_DOWN);
}
