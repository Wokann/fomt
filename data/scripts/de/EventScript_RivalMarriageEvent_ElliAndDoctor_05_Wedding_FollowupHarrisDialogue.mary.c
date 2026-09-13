#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisSaysHeAndDoctorAreSameAgeAndChildhoodFriends[] =
        "Wir sehen vielleicht nicht\r\n"
        "so aus, aber der Doktor \r\n"
        "und ich sind gleich alt. {Press}\p"
        "Wir haben zusammen \r\n"
        "gespielt...{Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisRecallsTheirSharedDreamToHelpMineralTown[] =
        "Wir haben immer davon\r\n"
        "gesprochen, wie wir den \r\n"
        "Menschen der Stadt eines {Press}\r\n"
        "Tages helfen wollten. {Press}";
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
