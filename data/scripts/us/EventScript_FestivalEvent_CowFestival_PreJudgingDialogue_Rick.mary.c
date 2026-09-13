#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Rick_AllTheCowsHereAreSuch[] =
        "All the Cows here are such \r\n"
        "high quality!{Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Rick_YoureEnteringACowFromPlace1[] =
        "You're entering a Cow from\r\n"
        "{Place1}, right? \r\n"
        "I hope you win! {Press}";
};

void EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Rick(void)
{
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Rick_AllTheCowsHereAreSuch);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Rick_YoureEnteringACowFromPlace1);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_RICK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_RICK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_DOWN);
}
