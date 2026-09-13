#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue_DougFeelsLonelyAfterAnnMarries[] =
        "Ich habe Ann gedrängt\r\n"
        "zu heiraten...{Press}\p"
        "Aber jetzt, wo es soweit\r\n"
        "ist, bin ich traurig! {Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupDougDialogue_DougIsGladAnnWillRemainNearby[] =
        "Sie geht ja nicht weit \r\n"
        "weg oder so! {Press}\p"
        "Ich bin froh, dass \r\n"
        "sie in der Nähe bleibt. {Press}";
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
