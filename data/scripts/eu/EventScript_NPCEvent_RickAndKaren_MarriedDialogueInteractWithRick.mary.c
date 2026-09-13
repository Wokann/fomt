#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick_RickEnjoysMarriedLife[] =
        "Ahh....This is the life!{Press}";

    const char gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick_KarenTellsRickToStop[] =
        "Stop it...!{Press}";

    const char gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick_RickExpressesHappinessMarryingKaren[] =
        "I'm so glad I married you, \r\n"
        "Karen. {Press}";

    const char gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick_KarenAsksRickNotToEmbarrassHerBeforePlayer[] =
        "Will you stop embarrasing me\r\n"
        "in front of {Player}?{Press}";
};

void EventScript_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick(void)
{
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    if (WasNpcSpokenToJustNow(CHARACTER_RICK) == FALSE)
    {
        SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick_RickEnjoysMarriedLife);
        TalkClose();
        SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick_KarenTellsRickToStop);
    }
    else
    {
        SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick_RickExpressesHappinessMarryingKaren);
        SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_KAREN_SURPRISED);
        SetTalkNameplateCharacter(CHARACTER_KAREN);
        TalkMessage(gText_NPCEvent_RickAndKaren_MarriedDialogueInteractWithRick_KarenAsksRickNotToEmbarrassHerBeforePlayer);
    }
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_RICK);
    MarkNpcSpokenTo(CHARACTER_KAREN);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    SetEntityFacing(ENTITY_KAREN, FACING_RIGHT);
    return;
}
