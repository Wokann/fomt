#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_02_PurpleHeart_LikeCleaningResponse_FollowupAnnCompletingChores[] =
        "Just a few more chores...{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_HateCleaningResponse_FollowupAnnAsksAboutChores[] =
        "Are you doing all your\r\n"
        "chores like you should, \r\n"
        "{Player}?{Press}";
};

void EventScript_LoveEvent_Ann_02_PurpleHeart_DiscussCleaning_FollowupAnnDialogue(void)
{
    if (VarGet(VAR_ANN_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    if (VarGet(VAR_ANN_PURPLE_HEART_EVENT_CHOICE) == ANN_PURPLE_HEART_RESPONSE_LIKE_CLEANING)
    {
        SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ANN);
        ShowTalkHeartIndicator(CHARACTER_ANN);
        TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_LikeCleaningResponse_FollowupAnnCompletingChores);
        TalkClose();
        SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
    else
    {
        SetEntityFacing(ENTITY_ANN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANN_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ANN);
        ShowTalkHeartIndicator(CHARACTER_ANN);
        TalkMessage(gText_LoveEvent_Ann_02_PurpleHeart_HateCleaningResponse_FollowupAnnAsksAboutChores);
        TalkClose();
        SetEntityFacing(ENTITY_ANN, FACING_RIGHT);
        MarkNpcSpokenTo(CHARACTER_ANN);
    }
}
