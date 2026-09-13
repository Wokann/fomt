#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisSaysHeAndDoctorAreSameAgeAndChildhoodFriends[] =
        "We may not look like it, but\r\n"
        "the Doctor and I are \r\n"
        "the same age. {Press}\p"
        "We used to play together...{Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisRecallsTheirSharedDreamToHelpMineralTown[] =
        "We used to say how we wanted\r\n"
        "to help the people of this \r\n"
        "town somehow. {Press}";
};

void EventScript_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue(void)
{
    if (HasMetNpc(CHARACTER_HARRIS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
    if (WasNpcSpokenToJustNow(CHARACTER_HARRIS) == FALSE)
    {
        SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisSaysHeAndDoctorAreSameAgeAndChildhoodFriends);
        TalkClose();
        SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
    else
    {
        SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_HARRIS);
        TalkMessage(gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisRecallsTheirSharedDreamToHelpMineralTown);
        TalkClose();
        SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_HARRIS);
    }
}
