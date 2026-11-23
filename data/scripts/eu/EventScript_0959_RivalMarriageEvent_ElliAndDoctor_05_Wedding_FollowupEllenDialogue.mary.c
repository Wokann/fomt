#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0959_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue.mary.h"

void EventScript_0959_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue(void)
{
    if (HasMetNpc(CHARACTER_ELLEN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_ELLEN) == FALSE)
    {
        SetEntityFacing(ENTITY_ELLEN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenPraisesElliAndUrgesHerToPrioritizeHerNewFamily);
        TalkClose();
        SetEntityFacing(ENTITY_ELLEN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
    else
    {
        SetEntityFacing(ENTITY_ELLEN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupEllenDialogue_EllenWantsToLiveToSeeStuMarry);
        TalkClose();
        SetEntityFacing(ENTITY_ELLEN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
}
