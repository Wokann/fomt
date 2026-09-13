#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_RivalEvent_PopuriAndKai_02_BlueHeart_RicksConfrontation_FollowupKaiDialogue_KaiComplainsAboutRicksInterference[] =
        "Hast du das gehört?!\r\n"
        "Rick nervt so dermaßen! {Press}\p"
        "Er ist immer so, wenn \r\n"
        "ich mit Popuri rede!{Press}";
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
