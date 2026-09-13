#define MARY_FOMT_US
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Thomas_AllTheSheepAreAlwaysSo[] =
        "All the Sheep are always\r\n"
        "so impressive. {Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Thomas_CongratulationsOnWinningYourEffortsPaid[] =
        "Congratulations on winning!\r\n"
        "Your efforts paid off. {Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Thomas_ItsTooBadAboutThisYear[] =
        "It's too bad about this \r\n"
        "year,but now you have a \r\n"
        "goal for next year!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Thomas_AllTheSheepAreAlwaysSo);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Thomas_CongratulationsOnWinningYourEffortsPaid);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Thomas_ItsTooBadAboutThisYear);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
}
