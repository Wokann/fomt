#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue_DougFeelsLonelyAfterAnnMarries[] =
        "I kept pressuring Ann to get\r\n"
        "married...{Press}\p"
        "But now that she did, \r\n"
        "I'm kind of sad! {Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue_DougIsGladAnnWillRemainNearby[] =
        "Still, it's not like she's \r\n"
        "going far away or anything! {Press}\p"
        "I'm glad to have her stay \r\n"
        "around. {Press}";
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
