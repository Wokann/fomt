#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupRickDialogue_RickStillOpposesPopuriLeaving[] =
        "What happened to Mom?!\r\n"
        "I'm against it!{Press}";
};

void EventScript_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupRickDialogue(void)
{
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
    SetTalkNameplateCharacter(CHARACTER_RICK);
    TalkMessage(gText_RivalEvent_PopuriAndKai_04_OrangeHeart_LilliasApproval_FollowupRickDialogue_RickStillOpposesPopuriLeaving);
    TalkClose();
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_RICK);
}
