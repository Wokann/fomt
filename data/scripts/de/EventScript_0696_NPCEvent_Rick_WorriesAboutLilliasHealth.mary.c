#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0696_NPCEvent_Rick_WorriesAboutLilliasHealth.mary.h"

void EventScript_0696_NPCEvent_Rick_WorriesAboutLilliasHealth(void)
{
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_RICK);
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    TalkMessage(gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickExplainsResponsibilityDueToLilliasHealth);
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    TalkMessage(gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickWishesForLilliasFullRecovery);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    return;
}
