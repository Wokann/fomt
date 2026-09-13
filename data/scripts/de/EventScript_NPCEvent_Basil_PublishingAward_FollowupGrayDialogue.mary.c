#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Basil_PublishingAward_FollowupGrayDialogue_GrayPraisesBasilsTalent[] =
        "Basil ist wirklich \r\n"
        "ein Genie! {Press}";

    const char gText_NPCEvent_Basil_PublishingAward_FollowupGrayDialogue_GrayExpressesFamilyPride[] =
        "Ich bin stolz, so jemanden \r\n"
        "in meiner Familie zu haben!{Press}";
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
