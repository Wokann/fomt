#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_FollowupEllenDialogue_EllenWantsToSeeFlowerBeforeSheDies[] =
        "I just want to look \r\n"
        "at it once before I die...{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_FollowupEllenDialogue_EllenAcceptsHerWishMayNotComeTrue[] =
        "I know I may never\r\n"
        "get my wish, but...{Press}";
};

void EventScript_NPCEvent_Ellen_WhiteFlowerLegend_FollowupEllenDialogue(void)
{
    if (VarGet(VAR_ELLEN_WHITE_FLOWER_LEGEND_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_FollowupEllenDialogue_EllenWantsToSeeFlowerBeforeSheDies);
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
        TalkMessage(gText_NPCEvent_Ellen_WhiteFlowerLegend_FollowupEllenDialogue_EllenAcceptsHerWishMayNotComeTrue);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
}
