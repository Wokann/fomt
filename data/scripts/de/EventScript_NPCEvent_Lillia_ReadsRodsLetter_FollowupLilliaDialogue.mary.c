#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaRemainsHappyAfterLetter[] =
        "Hi-hi....\r\n"
        "Ich freue mich so!{Press}";
};

void EventScript_NPCEvent_Lillia_ReadsRodsLetter_FollowupLilliaDialogue(void)
{
    SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_LILLIA);
    SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_LilliaRemainsHappyAfterLetter);
    TalkClose();
    SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
    return;
}
