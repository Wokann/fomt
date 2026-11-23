#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0229_LocationInteraction_InspectClinicBedDuringCliffRecovery.mary.h"

void EventScript_0229_LocationInteraction_InspectClinicBedDuringCliffRecovery(void)
{
    if (VarGet(VAR_CLIFF_COLLAPSES_IN_SNOW_EVENT_STATE) == EVENT_LIFECYCLE_COMPLETED && VarGet(VAR_CLIFF_COLLAPSE_FOLLOWUP_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS && GetPlayerHeldArticleId() == ITEM_ARTICLE_PHOTO)
    {
        UsePlayerHeldItem();
        SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_HOSPITAL_BED_REACT);
        WaitFrames(60);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_CLIFF_COLLAPSED);
        SetTalkNameplateCharacter(CHARACTER_CLIFF);
        TalkMessage(gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffRecognizesFamilyPhoto);
        SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
        TalkMessage(gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffLearnsPlayerReturnedPhotoThroughAnn);
        SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
        TalkMessage(gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffExplainsLeavingFamilyAndRegret);
        SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
        TalkMessage(gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffApologizesAndThanksPlayerForPhoto);
        TalkClose();
        SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
        WaitFrames(60);
        SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_HOSPITAL_BED_IDLE);
        WaitFrames(60);
        AddNpcFriendship(CHARACTER_CLIFF, 20);
        MarkNpcSpokenTo(CHARACTER_CLIFF);
    }
    else
    {
        if (VarGet(VAR_CLIFF_COLLAPSE_FOLLOWUP_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffIsSleepingWell);
            TalkClose();
        }
        else
        {
            TalkOpen();
            TalkAppendMessage(gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_Bed);
            TalkClose();
        }
    }
}
