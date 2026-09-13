#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffAsksWherePlayerFoundPhoto[] =
        "!!...Where did you \r\n"
        "find this...?{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffLearnsAnnAndDougSawPhoto[] =
        "Ahh..So you told \r\n"
        "Ann and the others for me.{Press}\p"
        "This photo shows me with\r\n"
        "my mother and sister.{Press}\p";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffExplainsLeavingHometownAfterFamilySeparated[] =
        "I didn't like the town\r\n"
        "we lived in, so I left my\r\n"
        "mother and my sister to{Press}\r\n"
        "strike off on my own. {Press}\p"
        "When I came back, my \r\n"
        "mother had died and my\r\n"
        "sister was gone...{Press}\r\n"
        "This town reminds me of\r\n"
        "that one very much...{Press}";

    const char gText_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_Followup_CliffApologizesForPersonalStory[] =
        "Sorry! I'm sure you don't\r\n"
        "care about my story...\r\n"
        "Thanks for the photo!{Press}";
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
