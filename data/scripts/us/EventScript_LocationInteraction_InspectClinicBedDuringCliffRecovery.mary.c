#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffRecognizesFamilyPhoto[] =
        "Hey!! Where did you\r\n"
        "find this!?{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffLearnsPlayerReturnedPhotoThroughAnn[] =
        "Oh...I see...\r\n"
        "You told Ann and the\r\n"
        "others for me.{Press}\p"
        "This photo shows my \r\n"
        "mother any my sister...{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffExplainsLeavingFamilyAndRegret[] =
        "You see...I...{Press}\p"
        "I didn't like where I lived,\r\n"
        "so I left my mother and \r\n"
        "sister to strike {Press}\r\n"
        "on my own.{Press}\p"
        "When I came back, my mother\r\n"
        "had died and my sister had\r\n"
        "gone somewhere...{Press}\p"
        "Where, I just don't know...{Press}\p"
        "This town reminds me of that\r\n"
        "other one, long ago...{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffApologizesAndThanksPlayerForPhoto[] =
        "I'm sorry to bother you\r\n"
        "with my story. I'm sure you\r\n"
        "don't want to hear it...{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffIsSleepingWell[] =
        "Cliff is sleeping well...{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_Bed[] =
        "Bed{Press}";
};

void EventScript_LocationInteraction_InspectClinicBedDuringCliffRecovery(void)
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
