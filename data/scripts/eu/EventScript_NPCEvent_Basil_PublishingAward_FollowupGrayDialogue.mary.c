#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Basil_PublishingAward_FollowupGrayDialogue_GrayPraisesBasilsTalent[] =
        "Basil really is such \r\n"
        "a genius! {Press}";

    const char gText_NPCEvent_Basil_PublishingAward_FollowupGrayDialogue_GrayExpressesFamilyPride[] =
        "I'm glad to have someone \r\n"
        "like that in my own family!{Press}";
};

void EventScript_NPCEvent_Basil_PublishingAward_FollowupGrayDialogue(void)
{
    SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_GRAY);
    SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_FollowupGrayDialogue_GrayPraisesBasilsTalent);
    SetTalkPortrait(TALK_PORTRAIT_GRAY_BLUSHING);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_FollowupGrayDialogue_GrayExpressesFamilyPride);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_UP);
    return;
}
