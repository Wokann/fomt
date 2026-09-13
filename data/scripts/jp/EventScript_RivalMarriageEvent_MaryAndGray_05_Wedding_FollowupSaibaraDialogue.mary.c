#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupSaibaraDialogue_SaibaraSaysMenOnceNeededIndependenceBeforeMarriage[] =
        "わしの時代は、男が１人立ちも\r\n"
        "していないのに結婚するなど\r\n"
        "考えられなかったが…{Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupSaibaraDialogue_SaibaraTrustsMaryToSupportGray[] =
        "マリーはしっかりして、\r\n"
        "やさしい子だ。{Press}\p"
        "マリーのような子がいっしょ\r\n"
        "なら、グレイのような者でも\r\n"
        "何とかなるかもしれんな。{Press}";
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
