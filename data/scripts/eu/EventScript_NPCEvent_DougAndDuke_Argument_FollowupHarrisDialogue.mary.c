#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_StoppedFight_FirstTalk_HarrisRelievedFightEnded[] =
        "I was getting worried \r\n"
        "there!...{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_StoppedFight_RepeatTalk_HarrisThanksPlayerForHelp[] =
        "When those two start \r\n"
        "fighting, even I can't stop\r\n"
        "them by myself. {Press}\p"
        "Thanks, {Player}. {Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_NotIntervened_FirstTalk_HarrisDecidesToIntervene[] =
        "I should put a stop to this. {Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_NotIntervened_RepeatTalk_HarrisAdmitsHeCannotStopBothAlone[] =
        "But, I can't stop both of \r\n"
        "them all by myself...{Press}";
};

void EventScript_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue(void)
{
    SetEntityFacing(ENTITY_HARRIS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_HARRIS);
    if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_CHOICE) == DOUG_DUKE_ARGUMENT_STOP_FIGHT)
    {
        if (WasNpcSpokenToJustNow(CHARACTER_HARRIS) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_HAPPY);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_StoppedFight_FirstTalk_HarrisRelievedFightEnded);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_NORMAL);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_StoppedFight_RepeatTalk_HarrisThanksPlayerForHelp);
        }
    }
    else
    {
        if (WasNpcSpokenToJustNow(CHARACTER_HARRIS) == FALSE)
        {
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_ANGRY);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_NotIntervened_FirstTalk_HarrisDecidesToIntervene);
        }
        else
        {
            SetTalkPortrait(TALK_PORTRAIT_HARRIS_AFRAID);
            TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue_NotIntervened_RepeatTalk_HarrisAdmitsHeCannotStopBothAlone);
        }
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_HARRIS);
    SetEntityFacing(ENTITY_HARRIS, FACING_RIGHT);
    return;
}
