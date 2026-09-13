#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisSaysHeAndDoctorAreSameAgeAndChildhoodFriends[] =
        "これでもボクとドクター\r\n"
        "は同い年なんだ。{Press}\p"
        "小さいころ、\r\n"
        "２人でユメをかたり\r\n"
        "あったっけ。{Press}";

    const char gText_RivalMarriageEvent_ElliAndDoctor_05_Wedding_FollowupHarrisDialogue_HarrisRecallsTheirSharedDreamToHelpMineralTown[] =
        "２人ともこの町が好きで、\r\n"
        "まぁ、何か役に立てたらなぁ、\r\n"
        "なんて言ってたんだよ。{Press}";
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
