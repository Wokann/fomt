#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsDayFestivalDialogue_Saibara[] =
        "I love making Rice Cakes\r\n"
        "every New Year. I never \r\n"
        "miss it. {Press}";
};

void EventScript_FestivalEvent_NewYearsDayFestivalDialogue_Saibara(void)
{
    if (HasMetNpc(CHARACTER_SAIBARA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_SAIBARA);
    }
    SetEntityFacing(ENTITY_SAIBARA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_SAIBARA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_SAIBARA);
    TalkMessage(gText_FestivalEvent_NewYearsDayFestivalDialogue_Saibara);
    ClearTalkPortrait();
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_SAIBARA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_SAIBARA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_SAIBARA);
    SetEntityFacing(ENTITY_SAIBARA, FACING_DOWN);
}
