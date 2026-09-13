#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnRickGrowingUp[] =
        "なんだか気がぬけちゃった～。\r\n"
        "子どもが大きくなるのって、\r\n"
        "思ったよりはやいのねぇ～。{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupLilliaDialogue_LilliaHopesRecoveryWillBringRodHome[] =
        "わたしもはやく元気になって、\r\n"
        "パパが帰ってこれるようにしな\r\n"
        "いと～。{Press}\p"
        "パパがそばにいる事が、わたし\r\n"
        "にとって１番うれしいことなん\r\n"
        "だもの～。{Press}";
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
