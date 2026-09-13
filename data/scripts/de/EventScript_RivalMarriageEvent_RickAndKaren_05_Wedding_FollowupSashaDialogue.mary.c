#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaSaysJeffHasCriedSinceWedding[] =
        "Wie lange wird Jeff noch\r\n"
        "so rumheulen?{Press}\p"
        "Er ist schon seit\r\n"
        "gestern so!{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupSashaDialogue_SashaRecallsJeffCryingOverChildhoodMarriagePromise[] =
        "Jeff hat auch geweint, als\r\n"
        "Karen als Kind sagte, sie\r\n"
        "würde mal Rick heiraten...{Press}\p"
        "Man sollte denken, er \r\n"
        "hätte sich daran gewöhnt.{Press}";
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
