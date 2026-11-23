#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

#include "EventScript_0706_NPCEvent_RickAndKaren_MarriedDialogueInteractWithKaren.mary.h"

void EventScript_0706_NPCEvent_RickAndKaren_MarriedDialogueInteractWithKaren(void)
{
    SetEntityFacing(ENTITY_KAREN, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (WasNpcSpokenToJustNow(CHARACTER_RICK) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithKaren_RickEnjoysMarriedLife);
        TalkClose();
        SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithKaren_KarenTellsRickToStop);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithKaren_RickExpressesHappinessMarryingKaren);
        SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithKaren_KarenAsksRickNotToEmbarrassHerBeforePlayer);
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_RICK);
    MarkNpcSpokenTo(CHARACTER_KAREN);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    return;
}
