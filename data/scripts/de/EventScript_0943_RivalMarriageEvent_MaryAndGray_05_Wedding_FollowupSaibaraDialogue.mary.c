#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0943_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupSaibaraDialogue.mary.h"

void EventScript_0943_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupSaibaraDialogue(void)
{
    if (HasMetNpc(CHARACTER_SAIBARA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SAIBARA);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_SAIBARA) == FALSE)
    {
        SetEntityFacing(ENTITY_SAIBARA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SAIBARA);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupSaibaraDialogue_SaibaraSaysMenOnceNeededIndependenceBeforeMarriage);
        TalkClose();
        SetEntityFacing(ENTITY_SAIBARA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_SAIBARA);
    }
    else
    {
        SetEntityFacing(ENTITY_SAIBARA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SAIBARA);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupSaibaraDialogue_SaibaraTrustsMaryToSupportGray);
        TalkClose();
        SetEntityFacing(ENTITY_SAIBARA, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_SAIBARA);
    }
}
