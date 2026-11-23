#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0791_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue.mary.h"

void EventScript_0791_NPCEvent_DougAndDuke_Argument_FollowupHarrisDialogue(void)
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
