#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Lillia_ReadsRodsLetter_RickWantsRodToReturnHome[] =
        "手紙じゃなく、\r\n"
        "はやく帰ってきてほしいよ。{Press}";
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
