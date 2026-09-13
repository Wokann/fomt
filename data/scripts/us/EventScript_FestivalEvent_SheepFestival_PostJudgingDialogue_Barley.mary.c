#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley_TheWinningSheepThisYearHad[] =
        "The winning Sheep this year\r\n"
        "had a wonderful coat, and\r\n"
        "was so healthy...{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley_EvenIGotExcitedThisYear[] =
        "Even I got excited \r\n"
        "this year. {Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley_ItsTooBadForYouDont[] =
        "It's too bad for you.\r\n"
        "Don't get upset, though. \r\n"
        "Just try harder next year!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley(void)
{
    if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BARLEY);
    }
    SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_BARLEY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley_TheWinningSheepThisYearHad);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley_EvenIGotExcitedThisYear);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley_ItsTooBadForYouDont);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_BARLEY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_BARLEY);
    SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
}
