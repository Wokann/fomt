#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupEllenDialogue_EllenSaysHidingLetterWasLikeHim[] =
        "あんなとこに\r\n"
        "かくしておくなんて\r\n"
        "あの人らしいわ。{Press}";

    const char gText_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupEllenDialogue_EllenRemembersHusbandsShyness[] =
        "すっごくはずかしがり屋\r\n"
        "だったのよ。あの人。{Press}";
};

void EventScript_NPCEvent_Ellen_GrandfathersHiddenLetterDiscovery_FollowupEllenDialogue(void)
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
