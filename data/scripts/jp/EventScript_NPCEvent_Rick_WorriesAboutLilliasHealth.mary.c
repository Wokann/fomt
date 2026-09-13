#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickExplainsResponsibilityDueToLilliasHealth[] =
        "母さんは昔から体が弱いんだ。\r\n"
        "僕たちがしっかりしないと。{Press}";

    const char gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickWishesForLilliasFullRecovery[] =
        "母さんの病気が治れば\r\n"
        "いいんだけど…{Press}";
};

void EventScript_NPCEvent_Rick_WorriesAboutLilliasHealth(void)
{
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkNameplateCharacter(CHARACTER_RICK);
    SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
    TalkMessage(gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickExplainsResponsibilityDueToLilliasHealth);
    SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
    TalkMessage(gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickWishesForLilliasFullRecovery);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_LEFT);
    return;
}
