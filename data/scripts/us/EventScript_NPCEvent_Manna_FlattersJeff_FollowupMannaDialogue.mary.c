#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_FlattersJeff_MannaRevealsJeffWasEasyToManipulate[] =
        "Jeff is so easy to fool!...{Press}";
};

void EventScript_NPCEvent_Manna_FlattersJeff_FollowupMannaDialogue(void)
{
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_MannaRevealsJeffWasEasyToManipulate);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
    return;
}
