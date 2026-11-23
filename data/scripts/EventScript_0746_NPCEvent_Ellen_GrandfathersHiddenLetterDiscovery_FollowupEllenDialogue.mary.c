#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0746_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupEllenDialogue.mary.h"

void EventScript_0746_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupEllenDialogue(void)
{
    if (VarGet(VAR_ELLEN_GRANDFATHERS_HIDDEN_LETTER_EVENT_STATE) == EVENT_LIFECYCLE_IN_PROGRESS)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ELLEN);
        TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupEllenDialogue_EllenSaysHidingLetterWasLikeHim);
        SetTalkPortrait(TALK_PORTRAIT_ELLEN_NORMAL);
        TalkMessage(gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupEllenDialogue_EllenRemembersHusbandsShyness);
        TalkClose();
        MarkNpcSpokenTo(CHARACTER_ELLEN);
    }
}
