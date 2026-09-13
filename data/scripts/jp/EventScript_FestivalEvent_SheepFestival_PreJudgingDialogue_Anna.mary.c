#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Anna_ILoveSheepTheyreSuchGentle[] =
        "羊っていいわね。\r\n"
        "やさしそうな顔してるもの。{Press}";

    const char gText_FestivalEvent_SheepFestival_PreJudgingDialogue_Anna_YourSheepAreGoingToCompete[] =
        "{Player}さんの羊も\r\n"
        "でるんでしょ？\r\n"
        "優勝出来るといいわね。{Press}";
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
