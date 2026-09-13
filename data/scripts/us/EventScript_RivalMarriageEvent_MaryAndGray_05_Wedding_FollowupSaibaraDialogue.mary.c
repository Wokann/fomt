#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupSaibaraDialogue_SaibaraSaysMenOnceNeededIndependenceBeforeMarriage[] =
        "In my day, it was \r\n"
        "unthinkable for a boy to get\r\n"
        "married before he could {Press}\r\n"
        "support a family on his own!{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupSaibaraDialogue_SaibaraTrustsMaryToSupportGray[] =
        "Mary's a good girl. \r\n"
        "I won't have to worry about \r\n"
        "Gray if she's with him! {Press}";
};

void EventScript_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupSaibaraDialogue(void)
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
