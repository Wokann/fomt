#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue_RickReflectsOnMarryingChildhoodFriend[] =
        "This does feel kind of \r\n"
        "strange. After all, I've\r\n"
        "known Karen for ever. {Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue_RickSaysHeAlwaysLovedBeingWithKaren[] =
        "But, I like being with her\r\n"
        "more than anybody. I guess\r\n"
        "I always knew this would {Press}\r\n"
        "happen. {Press}";
};

void EventScript_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue(void)
{
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_RICK) == FALSE)
    {
        SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue_RickReflectsOnMarryingChildhoodFriend);
        TalkClose();
        SetEntityFacing(ENTITY_RICK, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    else
    {
        SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue_RickSaysHeAlwaysLovedBeingWithKaren);
        TalkClose();
        SetEntityFacing(ENTITY_RICK, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
}
