#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Rick_WorriesAboutLilliasHealth_LilliaAppreciatesChildrenAndResolvesToStayHealthy[] =
        "Was für ein Glück,\r\n"
        "solche tollen Kinder \r\n"
        "zu haben! {Press}\p"
        "Ich muss gesund bleiben\r\n"
        "für die beiden...!{Press}";
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
