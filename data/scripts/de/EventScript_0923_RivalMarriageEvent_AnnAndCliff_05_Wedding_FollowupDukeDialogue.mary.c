#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0923_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDukeDialogue.mary.h"

void EventScript_0923_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDukeDialogue(void)
{
    if (HasMetNpc(CHARACTER_DUKE) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DUKE);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_DUKE) == FALSE)
    {
        SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDukeDialogue_DukeRegardsCliffAsHisOwnSon);
        TalkClose();
        SetEntityFacing(ENTITY_DUKE, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_DUKE);
    }
    else
    {
        SetEntityFacing(ENTITY_DUKE, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DUKE_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_DUKE);
        TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDukeDialogue_DukeApprovesAnnAndRespectsDoug);
        TalkClose();
        SetEntityFacing(ENTITY_DUKE, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_DUKE);
    }
}
