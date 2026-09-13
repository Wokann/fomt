#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalMarriageEvent_MaryAndGray_06_BookSuccessAndHealthConcern_FollowupMaryDialogue_MaryReflectsOnGraysConcern[] =
        "グレイがこんな風に考えてくれ\r\n"
        "ていたなんて…\r\n"
        "心配させないようにしなきゃ。{Press}\p"
        "グレイと結婚してよかった♡\r\n"
        "{Press}";
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
