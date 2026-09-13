#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RickWantsRodToReturnHome[] =
        "Letters are nice...\r\n"
        "But I want him to come\r\n"
        "home now!...{Press}";
};

void EventScript_NPCEvent_Lillia_ReadsRodsLetter_FollowupRickDialogue(void)
{
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_RICK);
    SetTalkPortrait(TALK_PORTRAIT_RICK_SURPRISED);
    TalkMessage(gText_NPCEvent_Lillia_ReadsRodsLetter_RickWantsRodToReturnHome);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_DOWN);
    return;
}
