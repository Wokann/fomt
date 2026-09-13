#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupAnnDialogue_AnnFeelsEmbarrassedInWeddingDress[] =
        "I'm kind of embarrassed \r\n"
        "to be all dressed up \r\n"
        "like this!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupAnnDialogue_AnnHopesDougIsHappyForHer[] =
        "You're happy for me too,\r\n"
        "aren't you dad? {Press}";
};

void EventScript_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupAnnDialogue(void)
{
    if (HasMetNpc(CHARACTER_ANN) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_ANN) == FALSE)
    {
        SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANN_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_ANN);
        TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupAnnDialogue_AnnFeelsEmbarrassedInWeddingDress);
        TalkClose();
        SetEntityFacing(ENTITY_ANN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
    else
    {
        SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANN_WEDDING);
        SetTalkNameplateCharacter(CHARACTER_ANN);
        TalkMessage(gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupAnnDialogue_AnnHopesDougIsHappyForHer);
        TalkClose();
        SetEntityFacing(ENTITY_ANN, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
}
