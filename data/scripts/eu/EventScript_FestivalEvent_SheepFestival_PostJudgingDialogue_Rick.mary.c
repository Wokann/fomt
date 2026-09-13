#define MARY_FOMT_EU
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick_ItsHarderToTellWhatSheep[] =
        "It's harder to tell what\r\n"
        "Sheep are thinking than \r\n"
        "Cows, don't you think? {Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick_YourSheepHadSuchFineWool[] =
        "Your Sheep had such fine\r\n"
        "Wool I was sure it would\r\n"
        "win! {Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick_DontWorryTheresAlwaysNextYear[] =
        "Don't worry. \r\n"
        "There's always next year.{Press}";
};

void EventScript_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick(void)
{
    if (HasMetNpc(CHARACTER_RICK) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_RICK);
    }
    SetEntityFacing(ENTITY_RICK, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    if (VarGet(VAR_SHEEP_FESTIVAL_PLAYER_ENTRY_SELECTED) == FESTIVAL_PLAYER_ENTRY_NOT_SELECTED)
    {
        TalkOpen();
        SetTalkPortrait(TALK_PORTRAIT_RICK_AFRAID);
        SetTalkNameplateCharacter(CHARACTER_RICK);
        TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick_ItsHarderToTellWhatSheep);
    }
    else
    {
        if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_HAPPY);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick_YourSheepHadSuchFineWool);
        }
        else
        {
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_RICK_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_RICK);
            TalkMessage(gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick_DontWorryTheresAlwaysNextYear);
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
