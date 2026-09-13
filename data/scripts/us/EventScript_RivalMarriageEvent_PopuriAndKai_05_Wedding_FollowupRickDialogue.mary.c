#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupRickDialogue_RickAdmitsUncertaintyAboutMarriage[] =
        "As her older brother, I'm not\r\n"
        "sure what to think of this.{Press}";

    const char gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupRickDialogue_RickAcceptsMarriageIfPopuriIsHappy[] =
        "But...just as long as \r\n"
        "Popuri is happy, I guess...{Press}";
};

void EventScript_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupRickDialogue(void)
{
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_RICK) == FALSE)
    {
        SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupRickDialogue_RickAdmitsUncertaintyAboutMarriage);
        TalkClose();
        SetEntityFacing(ENTITY_RICK, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    else
    {
        SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_RivalMarriageEvent_PopuriAndKai_05_Wedding_FollowupRickDialogue_RickAcceptsMarriageIfPopuriIsHappy);
        TalkClose();
        SetEntityFacing(ENTITY_RICK, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
}
