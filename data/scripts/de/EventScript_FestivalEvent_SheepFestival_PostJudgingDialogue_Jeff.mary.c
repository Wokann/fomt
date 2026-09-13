#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Jeff_SheepAreSoGentleAndCalm[] =
        "Schafe sind so sanft\r\n"
        "und ruhig...{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Jeff_ICanTellThatYouPut[] =
        "Ich sehe, dass du dir\r\n"
        "viel Mühe mit der Schaf-\r\n"
        "zucht gibst. {Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Jeff_IHeardYouDidntWinI[] =
        "Du hast nicht gewonnen.\r\n"
        "Ich fasse es nicht!{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Jeff(void)
{
    if (HasMetNpc(CHARACTER_JEFF) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_JEFF);
    }
    SetEntityFacing(ENTITY_JEFF, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
        SetTalkNameplateCharacter(CHARACTER_JEFF);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Jeff_SheepAreSoGentleAndCalm);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_JEFF_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Jeff_ICanTellThatYouPut);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_JEFF_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_JEFF);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Jeff_IHeardYouDidntWinI);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_JEFF) == FALSE)
    {
        AddNpcFriendship(CHARACTER_JEFF, 5);
    }
    MarkNpcSpokenTo(CHARACTER_JEFF);
    SetEntityFacing(ENTITY_JEFF, FACING_LEFT);
}
