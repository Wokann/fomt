#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupAnnDialogue_AnnFeelsEmbarrassedInWeddingDress[] =
        "Ich schäme mich\r\n"
        "etwas in dieser \r\n"
        "schicken Kleidung!{Press}";

    const char gText_RivalMarriageEvent_AnnAndCliff_05_Wedding_FollowupAnnDialogue_AnnHopesDougIsHappyForHer[] =
        "Du freust dich für\r\n"
        "mich, oder Papa?{Press}";
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
