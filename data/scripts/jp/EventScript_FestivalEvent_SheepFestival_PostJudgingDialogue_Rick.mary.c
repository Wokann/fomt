#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick_ItsHarderToTellWhatSheep[] =
        "羊って、牛よりも\r\n"
        "何を考えているか分からない\r\n"
        "動物だったなぁ。{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick_YourSheepHadSuchFineWool[] =
        "キミの羊は毛なみが\r\n"
        "ちがったからね。\r\n"
        "優勝するとおもったよ。{Press}";

    const char gText_FestivalEvent_SheepFestival_PostJudgingDialogue_Rick_DontWorryTheresAlwaysNextYear[] =
        "気にするなって。\r\n"
        "来年、また出場したら\r\n"
        "いいじゃないか。{Press}";
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
