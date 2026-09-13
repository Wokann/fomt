#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_FirstTalk_ThomasRelievedMealCanResume[] =
        "I'm just glad they're done \r\n"
        "fighting. Now I can \r\n"
        "enjoy my meal!{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_StoppedFight_RepeatTalk_ThomasThanksPlayer[] =
        "Thanks for helping settle \r\n"
        "things, {Player}. {Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_FirstTalk_ThomasWondersWhatCausedFight[] =
        "I wonder what they were \r\n"
        "fighting about to begin \r\n"
        "with...?{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue_NotIntervened_RepeatTalk_ThomasSaysFightRuinedMeal[] =
        "Now my food doesn't taste\r\n"
        "good any more...\r\n"
        "What a waste!{Press}";
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
