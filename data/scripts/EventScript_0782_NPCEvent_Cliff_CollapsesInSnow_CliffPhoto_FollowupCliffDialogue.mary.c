#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0782_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_FollowupCliffDialogue.mary.h"

void EventScript_0782_NPCEvent_Cliff_CollapsesInSnow_CliffPhoto_FollowupCliffDialogue(void)
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
