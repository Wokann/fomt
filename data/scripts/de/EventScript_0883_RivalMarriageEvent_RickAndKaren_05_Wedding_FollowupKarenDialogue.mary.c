#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0883_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue.mary.h"

void EventScript_0883_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupKarenDialogue(void)
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
