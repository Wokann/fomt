#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue_KaiApologizesForPrivateWeddingAndInvitesCelebration[] =
        "Entschuldige, dass wir dich \r\n"
        "heute nicht {Press}\r\n"
        "eingeladen haben.\r\n"
        "Wir wollten eine kleine{Press}\p"
        "Hochzeit feiern. \r\n"
        "Trotzdem danke.\r\n"
        "Feiern wir heute nacht! {Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupKaiDialogue_KaiRepeatPostWeddingConversationAboutPopuriAndRick[] =
        "Rick... ah...\r\n"
        "mein zukünftiger Schwager{Press}\p"
        "hat der Hochzeit zugestimmt.\r\n"
        "Wir werden glücklich.{Press}";
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
