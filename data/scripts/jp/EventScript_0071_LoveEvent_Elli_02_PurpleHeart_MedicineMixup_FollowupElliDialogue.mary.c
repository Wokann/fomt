#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0071_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupElliDialogue.mary.h"

void EventScript_0071_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupElliDialogue(void)
{
    if (VarGet(VAR_ELLI_PURPLE_HEART_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
    }
    SetEntityFacing(ENTITY_ELLI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ELLI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ELLI);
    ShowTalkHeartIndicator(CHARACTER_ELLI);
    TalkMessage(gText_LoveEvent_Elli_02_PurpleHeart_MedicineMixup_FollowupElliDialogue);
    TalkClose();
    SetEntityFacing(ENTITY_ELLI, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_ELLI);
}
