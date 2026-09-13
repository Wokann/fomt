#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Basil_PublishingAward_MaryResolvesToImproveHerNovel[] =
        "Ich bin so stolz auf dich!\r\n"
        "Jetzt muss mein Roman \r\n"
        "noch besser werden!{Press}";
};

void EventScript_NPCEvent_Basil_PublishingAward_FollowupMaryDialogue(void)
{
    SetEntityFacing(ENTITY_MARY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MARY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MARY);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_MaryResolvesToImproveHerNovel);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_MARY);
    SetEntityFacing(ENTITY_MARY, FACING_UP);
    return;
}
