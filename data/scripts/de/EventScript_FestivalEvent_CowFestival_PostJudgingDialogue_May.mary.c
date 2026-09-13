#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_May_ILikeCowsBecauseTheyreSo[] =
        "Ich mag Kühe, weil sie so\r\n"
        "sanft sind. {Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_May_ImSoHappyForYou[] =
        "Ich freue mich für dich!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_May_ImSorryIThoughtYourCow[] =
        "Tut mir Leid...\r\n"
        "Ich fand, deine Kuh \r\n"
        "war die Beste!{Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_May(void)
{
    if (HasMetNpc(CHARACTER_MAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MAY);
    }
    SetEntityFacing(ENTITY_MAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_May_ILikeCowsBecauseTheyreSo);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_May_ImSoHappyForYou);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_MAY_AFRAID);
            SetTalkNameplateCharacter(CHARACTER_MAY);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_May_ImSorryIThoughtYourCow);
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
