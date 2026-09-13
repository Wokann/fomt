#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue_KarenFirstPostWeddingConversationAboutRick[] =
        "リックって、\r\n"
        "ほうっておけないタイプなの\r\n"
        "よね。{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue_KarenExplainsRickRelaxesWithHer[] =
        "今は、家に男は自分しかいない\r\n"
        "でしょ？だから、意気ごみすぎ\r\n"
        "てたみたい。{Press}\p"
        "おばさんやポプリといっしょに\r\n"
        "いる時よりも２人でいた方が気\r\n"
        "をぬいている感じ。{Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue(void)
{
    if (HasMetNpc(CHARACTER_KAREN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_KAREN) == FALSE)
    {
        SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue_KarenFirstPostWeddingConversationAboutRick);
        TalkClose();
        SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
    else
    {
        SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue_KarenExplainsRickRelaxesWithHer);
        TalkClose();
        SetEntityFacing(ENTITY_KAREN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_KAREN);
    }
}
