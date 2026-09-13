#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_FollowupEllenDialogue_EllenWantsToSeeFlowerBeforeSheDies[] =
        "Ich möchte sie nur einmal\r\n"
        "ansehen, bevor ich sterbe...{Press}";

    const char gText_NPCEvent_Ellen_WhiteFlowerLegend_FollowupEllenDialogue_EllenAcceptsHerWishMayNotComeTrue[] =
        "Vielleicht wird mir dieser\r\n"
        "Wunsch nie erfüllt, aber...{Press}";
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
