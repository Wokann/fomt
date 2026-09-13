#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LoveEvent_Ann_02_PurpleHeart_LikeCleaningResponse_FollowupAnnCompletingChores[] =
        "さてと、もうちょっと、\r\n"
        "おそうじがんばろうかな。{Press}";

    const char gText_LoveEvent_Ann_02_PurpleHeart_HateCleaningResponse_FollowupAnnAsksAboutChores[] =
        "{Player}くんも、\r\n"
        "嫌いなんて言ってないで、\r\n"
        "おそうじした方がいいよ。{Press}";
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
