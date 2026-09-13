#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupMaryDialogue_MaryReflectsOnGraysConcern[] =
        "I'm touched he cares about\r\n"
        "me like that. {Press}\p"
        "I promise not to make \r\n"
        "him worry any more. {Press}\p"
        "I'm so glad I married him!{Press}";
};

void EventScript_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupMaryDialogue(void)
{
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupMaryDialogue_MaryReflectsOnGraysConcern);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_MARY);
    SetEntityFacing(ENTITY_MARY, FACING_RIGHT);
    return;
}
