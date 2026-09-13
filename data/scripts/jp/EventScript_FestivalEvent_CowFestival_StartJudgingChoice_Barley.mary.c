#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_WereReadyToBeginTheJudging[] =
        "もうそろそろ優勝牛を\r\n"
        "決めようと思うんじゃが、\r\n"
        "審査を始めてもいいかの？{Press}";

    const char gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_ImReady[] =
        "審査を始める";

    const char gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_PleaseWait[] =
        "ちょっとまって";

    const char gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_LetsStartThen[] =
        "じゃあ、始めるとしよう。{Press}";

    const char gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_LetMeKnowWhenYoureReady[] =
        "始めてもよくなったら、\r\n"
        "話しかけてくれんかの。{Press}";
};

void EventScript_FestivalEvent_CowFestival_StartJudgingChoice_Barley(void)
{
    int unused_0, var_1, var_2;
    var_2 = GetContestAnimalIndex(ANIMAL_KIND_COW);
    if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
    {
        MarkNpcSpokenTo(CHARACTER_BARLEY);
    }
    SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
    TalkOpen();
    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
    SetTalkNameplateCharacter(CHARACTER_BARLEY);
    TalkMessage(gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_WereReadyToBeginTheJudging);
    TalkClose();
    TalkOpen();
    var_1 = TalkChoice2(gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_ImReady, gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_PleaseWait);
    switch (var_1)
    {
        case CHOICE_OPTION_1:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_LetsStartThen);
            TalkClose();
            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
            if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
            {
                AddNpcFriendship(CHARACTER_BARLEY, 5);
            }
            MarkNpcSpokenTo(CHARACTER_BARLEY);
            SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
            if (GetAnimalAffection(ANIMAL_KIND_COW, var_2) >= 200)
            {
                VarSet(VAR_COW_FESTIVAL_PLAYER_RESULT, FESTIVAL_CONTEST_RESULT_WON);
            }
            if (VarGet(VAR_COW_FESTIVAL_PLAYER_RESULT) == FESTIVAL_CONTEST_RESULT_WON)
            {
                CallScript(EventScript_FestivalEvent_CowFestival_PlayerVictory);
            }
            else
            {
                CallScript(EventScript_FestivalEvent_CowFestival_PostJudgingSceneSetup);
            }
            break;
        case CHOICE_OPTION_2:
            TalkClose();
            TalkOpen();
            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
            SetTalkNameplateCharacter(CHARACTER_BARLEY);
            TalkMessage(gText_FestivalEvent_CowFestival_StartJudgingChoice_Barley_LetMeKnowWhenYoureReady);
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
