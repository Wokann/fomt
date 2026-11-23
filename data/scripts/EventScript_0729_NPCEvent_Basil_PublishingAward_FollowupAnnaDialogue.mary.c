#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0729_NPCEvent_Basil_PublishingAward_FollowupAnnaDialogue.mary.h"

void EventScript_0729_NPCEvent_Basil_PublishingAward_FollowupAnnaDialogue(void)
{
    SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_AnnaExpressesPrideInBasil);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ANNA);
    SetEntityFacing(ENTITY_ANNA, FACING_UP);
    return;
}
