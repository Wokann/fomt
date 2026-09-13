#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue_DougFeelsLonelyAfterAnnMarries[] =
        "結婚しろ、しろって\r\n"
        "ずっと言っていたんだが…{Press}\p"
        "いざ本当にしてしまうと、\r\n"
        "さみしいもんだな。{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue_DougIsGladAnnWillRemainNearby[] =
        "結婚したっていっても、\r\n"
        "どっかに行っちまうわけじゃ\r\n"
        "ないから、{Press}\r\n"
        "かまわねぇんだけどな。{Press}";
};

void EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue(void)
{
    if (HasMetNpc(CHARACTER_DOUG) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_DOUG) == FALSE)
    {
        SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue_DougFeelsLonelyAfterAnnMarries);
        TalkClose();
        SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    else
    {
        SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue_DougIsGladAnnWillRemainNearby);
        TalkClose();
        SetEntityFacing(ENTITY_DOUG, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
}
