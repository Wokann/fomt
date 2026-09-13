#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Manna_FlattersJeff_JeffAdmiresMannasFlattery[] =
        "マナさんも口がうまいなぁ。\r\n"
        "{Press}";
};

void EventScript_NPCEvent_Manna_FlattersJeff_FollowupJeffDialogue(void)
{
    SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_JEFF);
    SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
    TalkMessage(gText_NPCEvent_Manna_FlattersJeff_JeffAdmiresMannasFlattery);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_JEFF);
    SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    return;
}
