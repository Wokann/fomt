#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0938_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupBasilDialogue.mary.h"

void EventScript_0938_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupBasilDialogue(void)
{
    if (HasMetNpc(CHARACTER_BASIL) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BASIL);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_BASIL) == FALSE)
    {
        SetEntityFacing(ENTITY_BASIL, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BASIL_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BASIL);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupBasilDialogue_BasilRealizesMaryHasReachedMarriageAge);
        TalkClose();
        SetEntityFacing(ENTITY_BASIL, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_BASIL);
    }
    else
    {
        SetEntityFacing(ENTITY_BASIL, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BASIL_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_BASIL);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupBasilDialogue_BasilAcceptsMarysMarriageAsNaturalLifeExperience);
        TalkClose();
        SetEntityFacing(ENTITY_BASIL, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_BASIL);
    }
}
