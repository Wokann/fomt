#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_May_IHaveAWoolBlanketYou[] =
        "I have a Wool blanket, \r\n"
        "you know. My grampa made\r\n"
        "it for me!{Press}";

    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_May_IfYourSheepDoesntWinIll[] =
        "If your Sheep doesn't \r\n"
        "win, I'll cry!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PreJudgingDialogue_May(void)
{
    if (HasMetNpc(CHARACTER_MAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MAY);
    }
    SetEntityFacing(ENTITY_MAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_May_IHaveAWoolBlanketYou);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_May_IfYourSheepDoesntWinIll);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MAY);
    SetEntityFacing(ENTITY_MAY, FACING_LEFT);
}
