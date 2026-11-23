#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0905_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue.mary.h"

void EventScript_0905_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue(void)
{
    if (HasMetNpc(CHARACTER_KAI) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAI);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_KAI) == FALSE)
    {
        SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue_KaiApologizesForPrivateWeddingAndInvitesCelebration);
        TalkClose();
        SetEntityFacing(ENTITY_KAI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_KAI);
    }
    else
    {
        SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAI_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_KAI);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue_KaiRepeatPostWeddingConversationAboutPopuriAndRick);
        TalkClose();
        SetEntityFacing(ENTITY_KAI, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_KAI);
    }
}
