#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupGrayDialogue_GrayAnnouncesWeddingToMary[] =
        "Today Mary and I are \r\n"
        "tying the knot! {Press}\p"
        "You already know, huh? \r\n"
        "You're invited! {Press}";

    const char gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupGrayDialogue_GrayInvitesPlayerToAttendIfFree[] =
        "If you have the time, come \r\n"
        "and watch! {Press}";
};

void EventScript_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupGrayDialogue(void)
{
    if (HasMetNpc(CHARACTER_GRAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GRAY);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_GRAY) == FALSE)
    {
        SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GRAY_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_GRAY);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupGrayDialogue_GrayAnnouncesWeddingToMary);
        TalkClose();
        SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_GRAY);
    }
    else
    {
        SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GRAY_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_GRAY);
        TalkMessage(gText_RivalMarriageEvent_MaryAndGray_05_Wedding_FollowupGrayDialogue_GrayInvitesPlayerToAttendIfFree);
        TalkClose();
        SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_GRAY);
    }
}
