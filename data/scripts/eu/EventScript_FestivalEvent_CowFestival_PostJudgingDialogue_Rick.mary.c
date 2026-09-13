#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Rick_IThoughtThatCowWouldWin[] =
        "I thought that Cow would \r\n"
        "win. It had the best teeth!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Rick_YourCowHadGoodTeethToo[] =
        "Your Cow had good teeth, \r\n"
        "too. I thought it could win.{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Rick_ItWasTooBadThisYear[] =
        "It was too bad this year,\r\n"
        "but you should try again \r\n"
        "next year. {Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Rick(void)
{
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Rick_IThoughtThatCowWouldWin);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Rick_YourCowHadGoodTeethToo);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Rick_ItWasTooBadThisYear);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_RICK) == FALSE)
    {
        AddNpcFriendship(CHARACTER_RICK, 5);
    }
    MarkNpcSpokenTo(CHARACTER_RICK);
    SetEntityFacing(ENTITY_RICK, FACING_DOWN);
}
