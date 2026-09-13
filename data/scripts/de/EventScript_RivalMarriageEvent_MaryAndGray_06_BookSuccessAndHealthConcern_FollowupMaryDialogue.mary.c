#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupMaryDialogue_MaryReflectsOnGraysConcern[] =
        "Ich bin gerührt, dass er\r\n"
        "sich so sorgt. {Press}\p"
        "Ich verspreche, ihm keinen\r\n"
        "Kummer mehr zu machen. {Press}\p"
        "Ich bin so froh, dass ich\r\n"
        "ihn geheiratet habe!{Press}";
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
