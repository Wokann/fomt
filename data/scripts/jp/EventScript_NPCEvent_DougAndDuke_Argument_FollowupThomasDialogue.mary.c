#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_FirstTalk_ThomasRelievedMealCanResume[] =
        "ケンカが終わってよかったよ。\r\n"
        "楽しく食事をしたいからね。{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_RepeatTalk_ThomasThanksPlayer[] =
        "{Player}くんのおかげで\r\n"
        "楽しい食事が出来そうだよ。{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_FirstTalk_ThomasWondersWhatCausedFight[] =
        "何が原因でケンカになったん\r\n"
        "だろうねぇ？{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_RepeatTalk_ThomasSaysFightRuinedMeal[] =
        "今日の食事は、重い空気のせい\r\n"
        "でなんだかおいしくないなぁ。{Press}";
};

void EventScript_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue(void)
{
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_THOMAS);
    if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_CHOICE) == DOUG_DUKE_ARGUMENT_STOP_FIGHT)
    {
        if (WasNpcSpokenToJustNow(CHARACTER_THOMAS) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_FirstTalk_ThomasRelievedMealCanResume);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_RepeatTalk_ThomasThanksPlayer);
        }
    }
    else
    {
        if (WasNpcSpokenToJustNow(CHARACTER_THOMAS) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_FirstTalk_ThomasWondersWhatCausedFight);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_AFRAID);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_RepeatTalk_ThomasSaysFightRuinedMeal);
        }
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
    return;
}
