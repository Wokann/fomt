#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0789_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue.mary.h"

void EventScript_0789_NPCEvent_DougAndDuke_Argument_FollowupThomasDialogue(void)
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
