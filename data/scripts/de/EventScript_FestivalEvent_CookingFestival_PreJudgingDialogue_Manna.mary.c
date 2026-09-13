#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Manna[] =
        "Nimmst du auch teil \r\n"
        "dieses Jahr, {Player}?\r\n"
        "Das ist toll! Ich sehe\r\n"
        "Männer gern kochen. \r\n"
        "Mein Man kann gar \r\n"
        "nicht kochen...\r\n"
        "Ich drücke dir die Daumen!{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Manna);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    SetEntityFacing(ENTITY_MANNA, FACING_LEFT);
    MarkNpcSpokenTo(CHARACTER_MANNA);
}
