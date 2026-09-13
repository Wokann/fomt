#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_FollowupKaiDialogue_KaiComplainsAboutRicksInterference[] =
        "Did you hear that?!\r\n"
        "Rick is such a pain! {Press}\p"
        "He's always like that when \r\n"
        "I talk to Popuri!{Press}";
};

void EventScript_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_FollowupKaiDialogue(void)
{
    SetEntityFacing(ENTITY_KAI, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_KAI_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_KAI);
    TalkMessage(gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_FollowupKaiDialogue_KaiComplainsAboutRicksInterference);
    TalkClose();
    SetEntityFacing(ENTITY_KAI, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_KAI);
}
