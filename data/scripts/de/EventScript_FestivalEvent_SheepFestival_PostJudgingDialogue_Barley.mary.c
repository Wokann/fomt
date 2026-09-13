#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley_TheWinningSheepThisYearHad[] =
        "Das Gewinnerschaf hatte\r\n"
        "dieses Jahr ein wunder-\r\n"
        "schönes Fell und {Press}\r\n"
        "war so gesund...{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley_EvenIGotExcitedThisYear[] =
        "Sogar ich war ganz\r\n"
        "aufgeregt dieses Jahr. {Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Barley_ItsTooBadForYouDont[] =
        "Schade für dich.\r\n"
        "Reg dich aber nicht auf. \r\n"
        "Streng dich noch mehr{Press}\r\n"
        "an nächstes Jahr!{Press}";
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
