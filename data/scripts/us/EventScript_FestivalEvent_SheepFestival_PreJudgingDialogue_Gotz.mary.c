#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Gotz_NoPlayerEntryComment[] =
        "This Sheep looks like it\r\n"
        "has a good personality. \r\n"
        "I like him. {Press}";

    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Gotz_CommentsOnPlayersEnteredSheep[] =
        "Your sheep all look\r\n"
        "very happy. {Press}";
};

void EventScript_FestivalEvent_SheepFestival_PreJudgingDialogue_Gotz(void)
{
    if (HasMetNpc(CHARACTER_GOTZ) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GOTZ);
    }
    SetEntityFacing(ENTITY_GOTZ, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_GOTZ);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Gotz_NoPlayerEntryComment);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GOTZ_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_GOTZ);
        TalkMessage(gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Gotz_CommentsOnPlayersEnteredSheep);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GOTZ) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GOTZ, 5);
    }
    MarkNpcSpokenTo(CHARACTER_GOTZ);
    SetEntityFacing(ENTITY_GOTZ, FACING_DOWN);
}
