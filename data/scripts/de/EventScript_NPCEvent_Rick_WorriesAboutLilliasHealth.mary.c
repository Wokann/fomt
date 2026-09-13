#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickExplainsResponsibilityDueToLilliasHealth[] =
        "Mamas Gesundheit war \r\n"
        "immer labil...Darum muss ich\r\n"
        "so sehr aufpassen!{Press}";

    const char gText_NPCEvent_Rick_WorriesAboutLilliasHealth_RickWishesForLilliasFullRecovery[] =
        "Wenn sie nur ein für \r\n"
        "alle Mal gesund würde...{Press}";
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
