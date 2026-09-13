#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnRickGrowingUp[] =
        "Why is it so surprising how \r\n"
        "fast kids grow up?!...{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaHopesRecoveryWillBringRodHome[] =
        "If only I would get better\r\n"
        "so that my darling could\r\n"
        "come home...{Press}\p"
        "If he were here with me \r\n"
        "everything would be OK...{Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue(void)
{
    if (HasMetNpc(CHARACTER_LILLIA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_LILLIA) == FALSE)
    {
        SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnRickGrowingUp);
        TalkClose();
        SetEntityFacing(ENTITY_LILLIA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
    else
    {
        SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaHopesRecoveryWillBringRodHome);
        TalkClose();
        SetEntityFacing(ENTITY_LILLIA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
}
