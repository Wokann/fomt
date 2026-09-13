#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FamilyEvent_Doug_BirthdayGiftFromAnn_Followup_DougPraisesAnnAndResolvesToWorkForHer[] =
        "I love my daughter so much! \r\n"
        "I don't mind working,\r\n"
        "'cause I know it's for her!{Press}";
};

void EventScript_FamilyEvent_Doug_BirthdayGiftFromAnn_FollowupDougDialogue(void)
{
    SetEntityFacing(ENTITY_DOUG, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_DOUG_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_DOUG);
    TalkMessage(gText_FamilyEvent_Doug_BirthdayGiftFromAnn_Followup_DougPraisesAnnAndResolvesToWorkForHer);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_DOUG);
    SetEntityFacing(ENTITY_DOUG, FACING_DOWN);
    return;
}
