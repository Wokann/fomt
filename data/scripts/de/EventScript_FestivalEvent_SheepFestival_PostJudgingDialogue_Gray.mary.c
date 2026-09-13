#define MARY_FOMT_DE
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gray_YaaawnIllSureSleepWellTonight[] =
        "Gäääähn!... Ich schlafe\r\n"
        "heute sicher gut!{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gray_IHeardYouWonThatsGreat[] =
        "Du hast gewonnen.\r\n"
        "Das ist super!{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gray_DontSweatItPlayer[] =
        "Komm mal nicht ins \r\n"
        "Schwitzen, {Player}.{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Gray(void)
{
    if (HasMetNpc(CHARACTER_GRAY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_GRAY);
    }
    SetEntityFacing(ENTITY_GRAY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_GRAY_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_GRAY);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gray_YaaawnIllSureSleepWellTonight);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_GRAY_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_GRAY);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gray_IHeardYouWonThatsGreat);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_GRAY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_GRAY);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Gray_DontSweatItPlayer);
        }
    }
    TalkClose();
    if (WasNpcSpokenToToday(CHARACTER_GRAY) == FALSE)
    {
        AddNpcFriendship(CHARACTER_GRAY, 5);
    }
    MarkNpcSpokenTo(CHARACTER_GRAY);
    SetEntityFacing(ENTITY_GRAY, FACING_UP);
}
