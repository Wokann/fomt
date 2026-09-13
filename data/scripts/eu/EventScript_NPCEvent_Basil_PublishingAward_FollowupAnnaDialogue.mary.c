#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_NPCEvent_Basil_PublishingAward_AnnaExpressesPrideInBasil[] =
        "I'm so proud to have \r\n"
        "such a smart husband!{Press}";
};

void EventScript_NPCEvent_Basil_PublishingAward_FollowupAnnaDialogue(void)
{
    SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ANNA);
    TalkMessage(gText_NPCEvent_Basil_PublishingAward_AnnaExpressesPrideInBasil);
    TalkClose();
    MarkNpcSpokenTo(CHARACTER_ANNA);
    SetEntityFacing(ENTITY_ANNA, FACING_UP);
    return;
}
