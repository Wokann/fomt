#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue_KaiApologizesForPrivateWeddingAndInvitesCelebration[] =
        "今日、よばなくてごめんな。\r\n"
        "あんまり大げさにしてもさ…{Press}\p"
        "でも、サンキュ。\r\n"
        "今日はのもうぜ。{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue_KaiRepeatPostWeddingConversationAboutPopuriAndRick[] =
        "リックのヤツ…いや、\r\n"
        "お兄さんもみとめてくれたし、{Press}\p"
        "オレにはバラ色の人生が待って\r\n"
        "いるってわけ。{Press}";
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
