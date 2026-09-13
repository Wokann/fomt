#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Popuri_BabyBirthdayGooGoo[] =
        "Goo-goo.{Press}";
};

void EventScript_FamilyEvent_Popuri_BabyBirthdayGooGoo(void)
{
    SetEntityFacing(ENTITY_CHILD, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_CHILD);
    SetTalkPortrait(TALK_PORTRAIT_BABY_NORMAL);
    TalkMessage(gText_FamilyEvent_Popuri_BabyBirthdayGooGoo);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_CHILD);
    SetEntityFacing(ENTITY_CHILD, FACING_DOWN);
}
