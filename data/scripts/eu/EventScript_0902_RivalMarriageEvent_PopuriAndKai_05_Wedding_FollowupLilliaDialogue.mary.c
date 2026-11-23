#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0902_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue.mary.h"

void EventScript_0902_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue(void)
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
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaReflectsOnPopurisWedding);
        TalkClose();
        SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
    else
    {
        SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_LILLIA);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupLilliaDialogue_LilliaWishesRodWereHomeForWedding);
        TalkClose();
        SetEntityFacing(ENTITY_LILLIA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_LILLIA);
    }
}
