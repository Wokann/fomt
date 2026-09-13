#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Thomas_WhichCowDoYouLikeBest[] =
        "Welche Kuh magst du\r\n"
        "am liebsten?{Press}";

    const char gText_FestivalEvent_CowFestival_PreJudgingDialogue_Thomas_ImGladYouEnteredWhoDo[] =
        "Gut, dass du mitmachst!\r\n"
        "Wer wird wohl gewinnen?{Press}";
};

void EventScript_FestivalEvent_CowFestival_PreJudgingDialogue_Thomas(void)
{
    if (HasMetNpc(CHARACTER_THOMAS) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_THOMAS);
    }
    SetEntityFacing(ENTITY_THOMAS, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_COW_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Thomas_WhichCowDoYouLikeBest);
    }
    else
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
        SetTalkNameplateCharacter(CHARACTER_THOMAS);
        TalkMessage(gText_FestivalEvent_CowFestival_PreJudgingDialogue_Thomas_ImGladYouEnteredWhoDo);
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_THOMAS) == FALSE)
    {
        AddNpcFriendship(CHARACTER_THOMAS, 5);
    }
    MarkNpcSpokenTo(CHARACTER_THOMAS);
    SetEntityFacing(ENTITY_THOMAS, FACING_RIGHT);
}
