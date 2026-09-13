#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue_RickReflectsOnMarryingChildhoodFriend[] =
        "なんだか変な感じだよ。\r\n"
        "カレンとは、物心ついた時から\r\n"
        "ずっといっしょだったから。{Press}";

    const char gText_RivalMarriageEvent_RickAndKaren_05_Wedding_FollowupRickDialogue_RickSaysHeAlwaysLovedBeingWithKaren[] =
        "でも、カレンといるのが１番楽\r\n"
        "だよ。こうなる事もずっと考え\r\n"
        "ていたかも。{Press}";
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
