#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Anna_JustLookingAtSheepMakesMe[] =
        "Just looking at Sheep \r\n"
        "makes me feel calm...{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Anna_CongratulationsIBetThatSheepOf[] =
        "Congratulations! \r\n"
        "I bet that Sheep of yours\r\n"
        "will make a great Sweater!{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Anna_AndIThoughtYourSheepWas[] =
        "And I thought your Sheep\r\n"
        "was a sure winner, too!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Anna(void)
{
    if (HasMetNpc(CHARACTER_ANNA) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_ANNA);
    }
    SetEntityFacing(ENTITY_ANNA, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_ANNA_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_ANNA);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Anna_JustLookingAtSheepMakesMe);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Anna_CongratulationsIBetThatSheepOf);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_ANNA_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_ANNA);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Anna_AndIThoughtYourSheepWas);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_ANNA) == FALSE)
    {
        AddNpcFriendship(CHARACTER_ANNA, 5);
    }
    MarkNpcSpokenTo(CHARACTER_ANNA);
    SetEntityFacing(ENTITY_ANNA, FACING_UP);
}
