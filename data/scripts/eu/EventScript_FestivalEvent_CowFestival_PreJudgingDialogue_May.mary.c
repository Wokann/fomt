#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_May_ForSomeReasonMyGrandfatherDoesnt[] =
        "For some reason, my \r\n"
        "grandfather doesn't like \r\n"
        "entering competitions...{Press}\r\n"
        "I bet we could win, too!{Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_May_YoureGoingToCompeteRightI[] =
        "You're going to compete, \r\n"
        "right? I hope you win!{Press}";
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
