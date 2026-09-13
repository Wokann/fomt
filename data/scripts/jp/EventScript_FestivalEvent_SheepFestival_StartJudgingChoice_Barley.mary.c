#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_ItsTimeForTheJudgingTo[] =
        "もうそろそろ優勝羊を\r\n"
        "決めようと思うんじゃが、\r\n"
        "審査を始めてもいいかの？{Press}";

    const char gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_ImReady[] =
        "審査を始める";

    const char gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_WaitAMinute[] =
        "ちょっとまって";

    const char gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_LetsStartThen[] =
        "じゃあ、始めるとしよう。{Press}";

    const char gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_JustLetMeKnowWhenYoure[] =
        "始めてもよくなったら、\r\n"
        "話しかけてくれんかの。{Press}";
};

void EventScript_FestivalEvent_SheepFestival_StartJudgingChoice_Barley(void)
{
    int unused_0, var_1, var_2;
    var_2 = GetContestAnimalIndex(ANIMAL_KIND_SHEEP);
    if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BARLEY);
    }
    SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_ItsTimeForTheJudgingTo);
    TalkClose();
    TalkOpen();
    var_1 = TalkChoice2(gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_ImReady, gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_WaitAMinute);
    switch (var_1)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_LetsStartThen);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
            {
                AddNpcFriendship(CHARACTER_BARLEY, 5);
            }
            MarkNpcSpokenTo(CHARACTER_BARLEY);
            SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
            if (GetAnimalAffection(ANIMAL_KIND_SHEEP, var_2) >= 200)
            {
                VarSet(VAR_SHEEP_FESTIVAL_RESULT, FESTIVAL_CONTEST_RESULT_WON);
            }
            if (VarGet(VAR_SHEEP_FESTIVAL_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
            {
                CallScript(EventScript_FestivalEvent_SheepFestival_PlayerVictory);
            }
            else
            {
                CallScript(EventScript_FestivalEvent_SheepFestival_ClosingAnnouncement);
            }
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_SheepFestival_StartJudgingChoice_Barley_JustLetMeKnowWhenYoure);
            TalkClose();
            if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
            {
                AddNpcFriendship(CHARACTER_BARLEY, 5);
            }
            MarkNpcSpokenTo(CHARACTER_BARLEY);
            SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
            break;
    }
}
