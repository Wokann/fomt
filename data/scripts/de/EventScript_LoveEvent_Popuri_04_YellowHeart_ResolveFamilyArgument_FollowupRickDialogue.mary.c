#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupRick_SupportPopuri[] =
        "Ja, hmm...\r\n"
        "Was denkst du darüber?!{Press}";

    const char gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupRick_SupportRick[] =
        "Ich bin froh, dass du mich\r\n"
        "verstanden hast. {Press}";

    const char gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupRick_SympathizeWithLillia[] =
        "Tut mir Leid, dass wir dich\r\n"
        "da reingezogen haben. {Press}";
};

void EventScript_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupRickDialogue(void)
{
    if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_CHOICE) == POPURI_YELLOW_HEART_CHOICE_SUPPORT_POPURI)
        {
            SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_ANGRY);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupRick_SupportPopuri);
            TalkClose();
            SetEntityFacing(ENTITY_RICK, FACING_LEFT);
            MarkNpcSpokenTo(CHARACTER_RICK);
        }
        else
        {
            if (VarGet(VAR_POPURI_YELLOW_HEART_EVENT_CHOICE) == POPURI_YELLOW_HEART_CHOICE_SUPPORT_RICK)
            {
                SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_RICK);
                TalkMessage(gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupRick_SupportRick);
                TalkClose();
                SetEntityFacing(ENTITY_RICK, FACING_LEFT);
                MarkNpcSpokenTo(CHARACTER_RICK);
            }
            else
            {
                SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_RICK);
                TalkMessage(gText_LoveEvent_Popuri_04_YellowHeart_ResolveFamilyArgument_FollowupRick_SympathizeWithLillia);
                TalkClose();
                SetEntityFacing(ENTITY_RICK, FACING_UP);
                MarkNpcSpokenTo(CHARACTER_RICK);
            }
        }
    }
}
