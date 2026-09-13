#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_May_ForSomeReasonMyGrandfatherDoesnt[] =
        "Aus irgendwelchen Gründen\r\n"
        "mag mein Großvater nicht \r\n"
        "an Wettkämpfen teilnehmen.{Press}\r\n"
        "Wir könnten sicher gewinnen!{Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_May_YoureGoingToCompeteRightI[] =
        "Du machst mit, oder?\r\n"
        "Ich hoffe, du gewinnst!{Press}";
};

void EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_May(void)
{
    if (HasMetNpc(CHARACTER_MAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_MAY);
    }
    SetEntityFacing(ENTITY_MAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_May_ForSomeReasonMyGrandfatherDoesnt);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_MAY_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_MAY);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_May_YoureGoingToCompeteRightI);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_MAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_MAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_MAY);
    SetEntityFacing(ENTITY_MAY, FACING_LEFT);
}
