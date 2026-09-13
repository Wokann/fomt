#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_FollowupSaibaraDialogue_SaibaraNoticesGrayCannotStopSmiling[] =
        "What's wrong with Gray? \r\n"
        "He's been smiling non-stop! {Press}";
};

void EventScript_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_FollowupSaibaraDialogue(void)
{
    SetEntityFacing(ENTITY_SAIBARA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_RivalEvent_MaryAndGray_01_BlackHeart_BlacksmithHandInjury_FollowupSaibaraDialogue_SaibaraNoticesGrayCannotStopSmiling);
    TalkClose();
    SetEntityFacing(ENTITY_SAIBARA, FACING_DOWN);
    MarkNpcSpokenTo(CHARACTER_SAIBARA);
}
