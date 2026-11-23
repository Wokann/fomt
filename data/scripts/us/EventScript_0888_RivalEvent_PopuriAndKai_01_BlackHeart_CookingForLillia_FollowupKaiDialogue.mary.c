#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0888_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_FollowupKaiDialogue.mary.h"

void EventScript_0888_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_FollowupKaiDialogue(void)
{
    SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_01_BlackHeart_CookingForLillia_FollowupKaiDialogue_KaiConsidersWhatToCookForLillia);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_KAI);
}
