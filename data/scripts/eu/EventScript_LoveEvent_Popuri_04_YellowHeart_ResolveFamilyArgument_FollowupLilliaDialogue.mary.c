#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupLillia_ArgumentResolved[] =
        "Thanks for stopping the\r\n"
        "fight, {Player}. {Press}";

    const char gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupLillia_SupportRickConcern[] =
        "I just hope they don't\r\n"
        "start again...{Press}";
};

void EventScript_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupLilliaDialogue(void)
{
    if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_CHOICE) == POPURI_YELLOW_HEART_CHOICE_SUPPORT_POPURI || VarGet(VAR_POPURI_YELLOW_HEART_EVENT_CHOICE) == POPURI_YELLOW_HEART_CHOICE_SYMPATHIZE_WITH_LILLIA)
        {
            SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessage(gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupLillia_ArgumentResolved);
            TalkClose();
            SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
            MarkNpcSpokenTo(CHARACTER_LILLIA);
        }
        else
        {
            SetEntityFacing(ENTITY_LILLIA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_LILLIA_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_LILLIA);
            TalkMessage(gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupLillia_SupportRickConcern);
            TalkClose();
            SetEntityFacing(ENTITY_LILLIA, FACING_DOWN);
            MarkNpcSpokenTo(CHARACTER_LILLIA);
        }
    }
}
