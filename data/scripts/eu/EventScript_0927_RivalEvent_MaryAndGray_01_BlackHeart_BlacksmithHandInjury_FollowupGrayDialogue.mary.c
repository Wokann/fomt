#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0927_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_FollowupGrayDialogue.mary.h"

void EventScript_0927_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_FollowupGrayDialogue(void)
{
    SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_FollowupGrayDialogue_GrayThinksFondlyOfMary);
    TalkClose();
    SetEntityFacing(ENTITY_GRAY, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_GRAY);
}
