#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffRecognizesFamilyPhoto[] =
        "Hey!! Wo hast du\r\n"
        "dies gefunden!?{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffLearnsPlayerReturnedPhotoThroughAnn[] =
        "Oh... Ich verstehe...\r\n"
        "Du hast es Ann und\r\n"
        "den anderen erzählt.{Press}\p"
        "Dies Foto zeigt meine \r\n"
        "Mutter und Schwester...{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffExplainsLeavingFamilyAndRegret[] =
        "Also... Ich...{Press}\p"
        "Ich habe mich nicht wohl\r\n"
        "gefühlt, wo ich gelebt habe,\r\n"
        "und so habe ich Mutter und{Press}\r\n"
        "Schwester verlassen, \r\n"
        "um allein loszuziehen.{Press}\p"
        "Als ich zurückkam, war \r\n"
        "meine Mutter gestorben und\r\n"
        "meine Schwester weg...{Press}\p"
        "Wo sie ist, keine Ahnung...{Press}\p"
        "Diese Stadt erinnert mich\r\n"
        "an die andere, \r\n"
        "vor langer Zeit...{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffApologizesAndThanksPlayerForPhoto[] =
        "Tut mir Leid, wenn ich dich\r\n"
        "mit meiner Geschichte nerve.{Press}\r\n"
        "Du willst sie sicher \r\n"
        "nicht hören...{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_CliffIsSleepingWell[] =
        "Cliff schläft ruhig...{Press}";

    const char gText_LocationInteraction_InspectClinicBedDuringCliffRecovery_Bed[] =
        "Bett{Press}";
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
