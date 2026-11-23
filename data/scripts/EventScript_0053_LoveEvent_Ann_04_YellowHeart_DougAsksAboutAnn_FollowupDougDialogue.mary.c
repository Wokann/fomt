#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0053_LoveEvent_Ann_04_YellowHeart_DougAsksAboutAnn_FollowupDougDialogue.mary.h"

void EventScript_0053_LoveEvent_Ann_04_YellowHeart_DougAsksAboutAnn_FollowupDougDialogue(void)
{
    if (VarGet(VAR_ANN_YELLOW_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    if (VarGet(VAR_ANN_YELLOW_HEART_EVENT_CHOICE) == ANN_YELLOW_HEART_RESPONSE_LIKE_ANN)
    {
        SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_LikeAnnResponse_FollowupDougAsksPlayerToCareForAnn);
        TalkClose();
        SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
    else
    {
        SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_DOUG_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_DOUG);
        TalkMessage(gText_LoveEvent_Ann_04_YellowHeart_OnlyFriendsResponse_FollowupDougOffersMeal);
        TalkClose();
        SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
        MarkNpcSpokenTo(CHARACTER_DOUG);
    }
}
