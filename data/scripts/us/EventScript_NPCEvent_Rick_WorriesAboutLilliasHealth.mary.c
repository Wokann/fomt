#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickExplainsResponsibilityDueToLilliasHealth[] =
        "Mom's health has always been\r\n"
        "shakey...That's why I have \r\n"
        "so much responsibility!{Press}";

    const char gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickWishesForLilliasFullRecovery[] =
        "If only she would get \r\n"
        "better once and for all...{Press}";
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
