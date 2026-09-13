#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffAsksWherePlayerFoundPhoto[] =
        "!!...Wo hast du das hier \r\n"
        "gefunden...?{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffLearnsAnnAndDougSawPhoto[] =
        "Ahh... du hast es Ann \r\n"
        "und den anderen gesagt.{Press}\p"
        "Dieses Foto zeigt mich\r\n"
        "mit meiner Mutter und \r\n"
        "meiner Schwester.{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffExplainsLeavingHometownAfterFamilySeparated[] =
        "Ich mochte die Stadt nicht,\r\n"
        "in der wir lebten, also habe\r\n"
        "ich meine Mutter und meine{Press}\r\n"
        "Schwester verlassen, um \r\n"
        "alleine loszuziehen. {Press}\p"
        "Als ich zurückkam, war \r\n"
        "meine Mutter gestorben\r\n"
        "und meine Schwester{Press}\r\n"
        "verschwunden...\r\n"
        "Diese Stadt erinnert \r\n"
        "mich sehr daran...{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffApologizesForPersonalStory[] =
        "Sorry! Ich bin sicher, du \r\n"
        "interessierst dich nicht \r\n"
        "für meine Geschichte...{Press}.\r\n"
        "Danke für das Foto!{Press}";
};

void EventScript_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_FollowupCliffDialogue(void)
{
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_HOSPITAL_BED_REACT);
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_COLLAPSED);
    SetTalkNameplateCharacter(CHARACTER_CLIFF);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffAsksWherePlayerFoundPhoto);
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffLearnsAnnAndDougSawPhoto);
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_AFRAID);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffExplainsLeavingHometownAfterFamilySeparated);
    SetTalkPortrait(TALK_PORTRAIT_CLIFF_NORMAL);
    TalkMessage(gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffApologizesForPersonalStory);
    TalkClose();
    SetEntityAnim(ENTITY_PLAYER, ANIMATION_PLAYER_SHAKE_HEAD_NO);
    WaitFrames(60);
    SetEntityAnim(ENTITY_CLIFF, ANIMATION_CLIFF_HOSPITAL_BED_IDLE);
    VarSet(VAR_CLIFF_COLLAPSE_FOLLOWUP_EVENT_STATE, EVENT_LIFECYCLE_COMPLETED);
    AddNpcFriendship(CHARACTER_CLIFF, 20);
    MarkNpcSpokenTo(CHARACTER_CLIFF);
}
