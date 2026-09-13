#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_IWantedToEnterMySheep[] =
        "Ich wollte mein Schaf mit-\r\n"
        "machen lassen, aber es \r\n"
        "es war zu jung!{Press}\r\n"
        "Das ist nicht fair! \r\n"
        "Das Alter sollte egal sein!{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_ImSoGladYouWonPlayer[] =
        "Ich freue mich, dass du\r\n"
        "gewonnen hast\r\n"
        "{Player}!{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_DontFeelBadPlayer[] =
        "Ärgere dich nicht,\r\n"
        "{Player}.{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_May(void)
{
    if (HasMetNpc(CHARACTER_MAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MAY);
    }
    SetEntityFacing(ENTITY_MAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_ANGRY);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_IWantedToEnterMySheep);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_ImSoGladYouWonPlayer);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MAY_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_May_DontFeelBadPlayer);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MAY);
    SetEntityFacing(ENTITY_MAY, FACING_LEFT);
}
