#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupStuDialogue_StuPraisesEllisWeddingAppearance[] =
        "Elli ist so hübsch! {Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupStuDialogue_StuExpectsDoctorToBeSurprisedByEllisCooking[] =
        "Ich wette, er ist über-\r\n"
        "rascht, wenn er \r\n"
        "Ellis Essen isst!{Press}";
};

void EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupStuDialogue(void)
{
    if (HasMetNpc(CHARACTER_STU) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_STU);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_STU) == FALSE)
    {
        SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_STU_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_STU);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupStuDialogue_StuPraisesEllisWeddingAppearance);
        TalkClose();
        SetEntityFacing(ENTITY_STU, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_STU);
    }
    else
    {
        SetEntityFacing(ENTITY_STU, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_STU_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_STU);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupStuDialogue_StuExpectsDoctorToBeSurprisedByEllisCooking);
        TalkClose();
        SetEntityFacing(ENTITY_STU, FACING_LEFT);
        MarkNpcSpokenTo(CHARACTER_STU);
    }
}
