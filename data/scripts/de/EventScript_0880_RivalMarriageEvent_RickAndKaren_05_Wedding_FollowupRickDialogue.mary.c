#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0880_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue.mary.h"

void EventScript_0880_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue(void)
{
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_RICK) == FALSE)
    {
        SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue_RickReflectsOnMarryingChildhoodFriend);
        TalkClose();
        SetEntityFacing(ENTITY_RICK, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    else
    {
        SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue_RickSaysHeAlwaysLovedBeingWithKaren);
        TalkClose();
        SetEntityFacing(ENTITY_RICK, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
}
