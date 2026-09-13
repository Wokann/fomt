#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_ItsAlwaysGoodToSeeAll[] =
        "Es ist immer gut, die \r\n"
        "verschiedenen Kühe \r\n"
        "zu sehen. {Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_PraisesPlayersWinningCow[] =
        "Herzlichen Glückwunsch! \r\n"
        "Wirklich eine tolle \r\n"
        "Leistung!{Press}";

    const char gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_IThoughtYouShouldHaveWon[] =
        "Ich finde, du hättest \r\n"
        "gewinnen sollen,\r\n"
        "{Player}.{Press}\r\n"
        "Versuch es nächstes \r\n"
        "Jahr wieder. {Press}";
};

void EventScript_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_ItsAlwaysGoodToSeeAll);
    }
    else
    {
        if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_PraisesPlayersWinningCow);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_THOMAS);
            TalkMessage(gText_FestivalEvent_CowFestival_PostJudgingDialogue_Thomas_IThoughtYouShouldHaveWon);
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
