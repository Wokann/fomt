#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaSaysJeffHasCriedSinceWedding[] =
        "How long is Jeff going to\r\n"
        "keep crying like this?{Press}\p"
        "He's been this way since\r\n"
        "yesterday!{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaRecallsJeffCryingOverChildhoodMarriagePromise[] =
        "Jeff cried when Karen said \r\n"
        "she was going to marry Rick\r\n"
        "as a child, too!...{Press}\p"
        "You'd think he'd be used \r\n"
        "to the idea by now...{Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue(void)
{
    if (HasMetNpc(CHARACTER_SASHA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_SASHA) == FALSE)
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaSaysJeffHasCriedSinceWedding);
        TalkClose();
        SetEntityFacing(ENTITY_SASHA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
    else
    {
        SetEntityFacing(ENTITY_SASHA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_SASHA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_SASHA);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaRecallsJeffCryingOverChildhoodMarriagePromise);
        TalkClose();
        SetEntityFacing(ENTITY_SASHA, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_SASHA);
    }
}
