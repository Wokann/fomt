#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_DougAndDuke_Argument_FollowupDougDialogue_StoppedFight_DougEmbarrassedHeForgotCause[] =
        "I can't believe I forgot\r\n"
        "what we were arguing over!\r\n"
        "I must be getting old...{Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupDougDialogue_StoppedFight_DougApologizesToPlayer[] =
        "Sorry, {Player}. {Press}";

    const char gText_NPCEvent_DougAndDuke_Argument_FollowupDougDialogue_NotIntervened_DougBlamesDuke[] =
        "Hmmph! It was all his fault!{Press}";
};

void EventScript_NPCEvent_DougAndDuke_Argument_FollowupDougDialogue(void)
{
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    if (VarGet(VAR_DOUG_AND_DUKE_ARGUMENT_CHOICE) == DOUG_DUKE_ARGUMENT_STOP_FIGHT)
    {
        SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
        TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupDougDialogue_StoppedFight_DougEmbarrassedHeForgotCause);
        SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
        TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupDougDialogue_StoppedFight_DougApologizesToPlayer);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_DOUG_ANGRY);
        TalkMessage(gText_NPCEvent_DougAndDuke_Argument_FollowupDougDialogue_NotIntervened_DougBlamesDuke);
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_DOUG);
    SetEntityFacing(ENTITY_DOUG, FACING_RIGHT);
    return;
}
