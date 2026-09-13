#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Rick_WorriesAboutLilliasHealth_LilliaAppreciatesChildrenAndResolvesToStayHealthy[] =
        "I can't believe how luck I \r\n"
        "am to have such fine \r\n"
        "children! {Press}\p"
        "I'll have to stay healthy \r\n"
        "for them...!{Press}";
};

void EventScript_NPCEvent_Rick_WorriesAboutLilliasHealth_FollowupLilliaDialogue(void)
{
    SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    TalkMessage(gText_NPCEvent_Rick_WorriesAboutLilliasHealth_LilliaAppreciatesChildrenAndResolvesToStayHealthy);
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    return;
}
