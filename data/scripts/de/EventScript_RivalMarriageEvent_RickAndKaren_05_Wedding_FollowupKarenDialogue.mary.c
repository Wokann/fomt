#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue_KarenFirstPostWeddingConversationAboutRick[] =
        "Du kannst Rick einfach\r\n"
        "nicht allein lassen?{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue_KarenExplainsRickRelaxesWithHer[] =
        "Er ist der einzige Mann\r\n"
        "im Haus, mit Popuri und \r\n"
        "seiner Großmutter. Denke,{Press}\r\n"
        "er hat es manchmal \r\n"
        "nicht leicht.{Press}\p"
        "Er entspannt sich mehr,\r\n"
        "bei mir, denke ich. {Press}";
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
