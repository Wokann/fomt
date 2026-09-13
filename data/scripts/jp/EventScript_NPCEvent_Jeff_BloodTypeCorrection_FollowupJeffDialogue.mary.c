#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Jeff_BloodTypeCorrection_Jeff_Followup_JeffPlansToTellSashaAboutCorrection[] =
        "帰ったらサーシャに、\r\n"
        "このことを話さなくっちゃ。{Press}\p"
        "サーシャがいつも\r\n"
        "不思議がっていたんだ。{Press}\p"
        "「あんたの血液型で\r\n"
        "気の弱い性格はおかしい」\r\n"
        "ってね。{Press}\p"
        "サーシャの言う通り\r\n"
        "だったなぁ。{Press}";
};

void EventScript_NPCEvent_Jeff_BloodTypeCorrection_FollowupJeffDialogue(void)
{
    if (VarGet(VAR_JEFF_BLOOD_TYPE_CORRECTION_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_NPCEvent_Jeff_BloodTypeCorrection_Jeff_Followup_JeffPlansToTellSashaAboutCorrection);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_JEFF);
        SetEntityFacing(ENTITY_JEFF, FACING_DOWN);
    }
}
