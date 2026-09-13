#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue_KarenFirstPostWeddingConversationAboutRick[] =
        "You just can't leave \r\n"
        "Rick alone, ya know?{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue_KarenExplainsRickRelaxesWithHer[] =
        "He's the only man in the\r\n"
        "house, with Popuri and his \r\n"
        "grandmother. I think that's{Press}\r\n"
        "hard on him sometimes.{Press}\p"
        "He relaxes more when he's\r\n"
        "with me, I think. {Press}";
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
