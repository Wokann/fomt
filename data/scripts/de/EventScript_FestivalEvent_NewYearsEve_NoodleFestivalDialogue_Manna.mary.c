#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Manna[] =
        "Du bist auch wegen der\r\n"
        "Nudeln gekommen? Ich\r\n"
        "liebe sie einfach! Ich \r\n"
        "finde, Buchweizennudeln \r\n"
        "sind die besten. \r\n"
        "Sie sind nahrhaft und\r\n"
        "schmecken... Ich kriege\r\n"
        "schon Hunger!\r\n"
        "Wo sind die Nudeln?{Press}";
};

void EventScript_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Manna(void)
{
    if (HasMetNpc(CHARACTER_MANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MANNA);
    }
    SetEntityFacing(ENTITY_MANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_MANNA_HAPPY);
    SetTalkNameplateCharacter(CHARACTER_MANNA);
    TalkMessageSlow(gText_FestivalEvent_NewYearsEve_NoodleFestivalDialogue_Manna);
    ClearTalkPortrait();
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MANNA);
    SetEntityFacing(ENTITY_MANNA, FACING_RIGHT);
}
