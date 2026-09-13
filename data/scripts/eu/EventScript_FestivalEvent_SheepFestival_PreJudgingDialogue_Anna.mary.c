#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Anna_ILoveSheepTheyreSuchGentle[] =
        "I love Sheep. They're\r\n"
        "such gentle creatures. {Press}";

    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Anna_YourSheepAreGoingToCompete[] =
        "Your sheep are going to \r\n"
        "compete, too? \r\n"
        "I hope you win!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PreJudgingDialogue_Anna(void)
{
    if (HasMetNpc(CHARACTER_ANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ANNA);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Anna_ILoveSheepTheyreSuchGentle);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_ANNA);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Anna_YourSheepAreGoingToCompete);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ANNA);
    SetEntityFacing(ENTITY_ANNA, FACING_UP);
}
