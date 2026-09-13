#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Zack[] =
        "Machst du dieses Jahr \r\n"
        "mit, {Player}?{Press}\p"
        "Du machst lieber etwas \r\n"
        "besonders Gutes, der\r\n"
        "Gourmet wird der Preis-{Press}\r\n"
        "richter sein.  Er ist \r\n"
        "schwer zu beeindrucken!{Press}";
};

void EventScript_FestivalEvent_CookingFestival_PreJudgingDialogue_Zack(void)
{
    if (HasMetNpc(CHARACTER_ZACK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ZACK);
    }
    SetEntityFacing(ENTITY_ZACK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_ZACK_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_ZACK);
    TalkMessage(gText_FestivalEvent_CookingFestival_PreJudgingDialogue_Zack);
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ZACK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ZACK, 5);
    }
    SetEntityFacing(ENTITY_ZACK, FACING_RIGHT);
    MarkNpcSpokenTo(CHARACTER_ZACK);
}
