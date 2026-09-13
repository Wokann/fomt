#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue_KaiApologizesForPrivateWeddingAndInvitesCelebration[] =
        "Sorry for not inviting you\r\n"
        "today. I didn't want to \r\n"
        "make the wedding such a big{Press}\p"
        "deal. Thanks, though.\r\n"
        "Let's celebrate, tonight! {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue_KaiRepeatPostWeddingConversationAboutPopuriAndRick[] =
        "Rick... ah...\r\n"
        "my future brother-in-law has{Press}\p"
        "approved of me and Popuri.\r\n"
        "We'll be happy.{Press}";
};

void EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue(void)
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
