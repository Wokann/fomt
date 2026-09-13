#define MARY_FOMT_JP
#include "fomt_constants.mary.h"
#include "fomt_callables.mary.h"
#include "fomt_scripts.mary.h"

mary_text_table
{
    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AreYouReadyToRaceOr[] =
        "やぁ、レースを始めるのかい？\r\n"
        "それともチケットを\r\n"
        "買うのかい？{Press}\r\n"
        "商品交換もやってるよ。{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BeginRace[] =
        "レース開始";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_PlaceABet[] =
        "チケット購入";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Exchange[] =
        "商品交換";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Nothing[] =
        "なんでもない";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureReadyToBegin[] =
        "始めてもいいんだね？{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Yes[] =
        "はい";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_No[] =
        "いいえ";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsStartThen[] =
        "そうか。\r\n"
        "じゃあ、始めるよ。{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureNotReadyAfterAll[] =
        "やめるのかい。{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BettingScreenSelectButtonInstructions[] =
        "チケットを買うんだね。{Press}\p"
        "購入画面でセレクトボタンを\r\n"
        "押すと、買い方の説明が\r\n"
        "出るから見ておくといいよ。{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureGoingToExchangeYour[] =
        "メダルを景品に替えるんだね。{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouCantDoItWhileHolding[] =
        "手に物を持ったまま\r\n"
        "景品交換はできないよ。{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouWantToExchangeYourMedal[] =
        "メダルを景品に替えるのかい？{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_MenuExchangeMedalsForPrizes[] =
        "メダルを景品に替える";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_CowContestJudgingStartPrompt[] =
        "もうそろそろ優勝牛を\r\n"
        "決めようと思うんじゃが、\r\n"
        "審査を始めてもいいかの？{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetsStart[] =
        "審査を始める";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_NotYet[] =
        "ちょっとまって";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsGetStartedThen[] =
        "じゃあ、始めるとしよう。{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetMeKnowWhenYoureReady[] =
        "始めてもよくなったら、\r\n"
        "話しかけてくれんかの。{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table[] =
        "テーブル{Press}";

    const char gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SheepContestJudgingStartPrompt[] =
        "もうそろそろ優勝羊を\r\n"
        "決めようと思うんじゃが、\r\n"
        "審査を始めてもいいかの？{Press}";
};

void EventScript_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice(void)
{
    int var_0, var_1, var_2, var_3, var_4, var_5;
    var_1 = VarGet(VAR_HOUR);
    var_2 = VarGet(VAR_MINUTE);
    if (GetEntityFacing(ENTITY_PLAYER) == FACING_UP)
    {
        if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL || VarGet(VAR_FALL_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
        {
            if (!(var_1 == 18 && var_2 == 1))
            {
                MarkNpcSpokenTo(CHARACTER_THOMAS);
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_AreYouReadyToRaceOr);
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice4(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BeginRace, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_PlaceABet, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Exchange, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Nothing);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureReadyToBegin);
                        TalkClose();
                        TalkOpen();
                        var_0 = TalkChoice2(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Yes, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_No);
                        switch (var_0)
                        {
                            case CHOICE_OPTION_1:
                                TalkClose();
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsStartThen);
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                var_3 = RunHorseRace(FESTIVAL_HORSE_RACE_MODE_COMPETE);
                                switch (var_3)
                                {
                                    case FESTIVAL_HORSE_RACE_INTERFACE_CANCELLED:
                                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        break;
                                    case FESTIVAL_HORSE_RACE_INTERFACE_CLOSED_WITHOUT_RESULT:
                                        FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                        PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
                                        break;
                                    case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_WON:
                                        if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                        {
                                            VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                            CallScript(EventScript_FestivalEvent_SpringHorseRace_PlayerVictory);
                                        }
                                        else
                                        {
                                            VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                            CallScript(EventScript_FestivalEvent_FallHorseRace_PlayerVictory);
                                        }
                                        break;
                                    case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_LOST:
                                        if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                        {
                                            VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                            CallScript(EventScript_FestivalEvent_SpringHorseRace_Competition);
                                        }
                                        else
                                        {
                                            VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                            CallScript(EventScript_FestivalEvent_FallHorseRace_Competition);
                                        }
                                        break;
                                }
                                break;
                            case CHOICE_OPTION_2:
                                TalkClose();
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureNotReadyAfterAll);
                                TalkClose();
                                break;
                        }
                        break;
                    case CHOICE_OPTION_2:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_HAPPY);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_BettingScreenSelectButtonInstructions);
                        TalkClose();
                        FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        var_3 = RunHorseRace(FESTIVAL_HORSE_RACE_MODE_BETTING);
                        switch (var_3)
                        {
                            case FESTIVAL_HORSE_RACE_INTERFACE_CANCELLED:
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                break;
                            case FESTIVAL_HORSE_RACE_INTERFACE_CLOSED_WITHOUT_RESULT:
                                FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                PlayBGM(AUDIO_START_WEAK, AUDIO_BGM_FESTIVAL);
                                break;
                            case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_WON:
                                if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                {
                                    VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                    CallScript(EventScript_FestivalEvent_SpringHorseRace_PlayerVictory);
                                }
                                else
                                {
                                    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_WON);
                                    CallScript(EventScript_FestivalEvent_FallHorseRace_PlayerVictory);
                                }
                                break;
                            case FESTIVAL_HORSE_RACE_INTERFACE_PLAYER_LOST:
                                if (VarGet(VAR_SPRING_FESTIVAL_HORSE_RACE_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                                {
                                    VarSet(VAR_SPRING_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                    CallScript(EventScript_FestivalEvent_SpringHorseRace_Competition);
                                }
                                else
                                {
                                    VarSet(VAR_FALL_FESTIVAL_HORSE_RACE_RESULT, FESTIVAL_HORSE_RACE_RESULT_NOT_WON);
                                    CallScript(EventScript_FestivalEvent_FallHorseRace_Competition);
                                }
                                break;
                        }
                        break;
                    case CHOICE_OPTION_3:
                        if (IsPlayerHoldingNothing() == TRUE)
                        {
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureGoingToExchangeYour);
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            OpenHorseRaceMedalExchange();
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        }
                        else
                        {
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouCantDoItWhileHolding);
                            TalkClose();
                        }
                        break;
                    case CHOICE_OPTION_4:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureNotReadyAfterAll);
                        TalkClose();
                        break;
                }
            }
            else
            {
                MarkNpcSpokenTo(CHARACTER_THOMAS);
                SetEntityFacing(ENTITY_THOMAS, FACING_DOWN);
                TalkOpen();
                SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                SetTalkNameplateCharacter(CHARACTER_THOMAS);
                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouWantToExchangeYourMedal);
                TalkClose();
                TalkOpen();
                var_0 = TalkChoice2(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_MenuExchangeMedalsForPrizes, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Nothing);
                switch (var_0)
                {
                    case CHOICE_OPTION_1:
                        if (IsPlayerHoldingNothing() == TRUE)
                        {
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureGoingToExchangeYour);
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            OpenHorseRaceMedalExchange();
                            FadeInScreen(SCREEN_FADE_STYLE_WHITE_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                        }
                        else
                        {
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_THOMAS);
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_YouCantDoItWhileHolding);
                            TalkClose();
                        }
                        break;
                    case CHOICE_OPTION_2:
                        TalkClose();
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_THOMAS_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_THOMAS);
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SoYoureNotReadyAfterAll);
                        TalkClose();
                        break;
                }
            }
        }
        else
        {
            if (VarGet(VAR_COW_FESTIVAL_SESSION_STATE) == FESTIVAL_PHASE_INITIAL)
            {
                if (!(var_1 == 18 && var_2 == 1))
                {
                    var_4 = GetContestAnimalIndex(ANIMAL_KIND_COW);
                    if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
                    {
                        MarkNpcSpokenTo(CHARACTER_BARLEY);
                    }
                    SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
                    TalkOpen();
                    SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                    SetTalkNameplateCharacter(CHARACTER_BARLEY);
                    TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_CowContestJudgingStartPrompt);
                    TalkClose();
                    TalkOpen();
                    var_0 = TalkChoice2(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetsStart, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_NotYet);
                    switch (var_0)
                    {
                        case CHOICE_OPTION_1:
                            TalkClose();
                            TalkOpen();
                            SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                            SetTalkNameplateCharacter(CHARACTER_BARLEY);
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsGetStartedThen);
                            TalkClose();
                            FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                            if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
                            {
                                AddNpcFriendship(CHARACTER_BARLEY, 5);
                            }
                            MarkNpcSpokenTo(CHARACTER_BARLEY);
                            SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
                            if (GetAnimalAffection(ANIMAL_KIND_COW, var_4) >= 200)
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
                            TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetMeKnowWhenYoureReady);
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
                else
                {
                    TalkOpen();
                    TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table);
                    TalkClose();
                }
            }
            else
            {
                if (VarGet(VAR_SHEEP_FESTIVAL_ACTIVE) == FESTIVAL_PHASE_INITIAL)
                {
                    if (!(var_1 == 18 && var_2 == 1))
                    {
                        var_5 = GetContestAnimalIndex(ANIMAL_KIND_SHEEP);
                        if (HasMetNpc(CHARACTER_BARLEY) == FALSE)
                        {
                            MarkNpcSpokenTo(CHARACTER_BARLEY);
                        }
                        SetEntityFacing(ENTITY_BARLEY, GetOppositeFacing(GetEntityFacing(ENTITY_PLAYER)));
                        TalkOpen();
                        SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                        SetTalkNameplateCharacter(CHARACTER_BARLEY);
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_SheepContestJudgingStartPrompt);
                        TalkClose();
                        TalkOpen();
                        var_0 = TalkChoice2(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetsStart, gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_NotYet);
                        switch (var_0)
                        {
                            case CHOICE_OPTION_1:
                                TalkClose();
                                TalkOpen();
                                SetTalkPortrait(TALK_PORTRAIT_BARLEY_NORMAL);
                                SetTalkNameplateCharacter(CHARACTER_BARLEY);
                                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_GreatLetsGetStartedThen);
                                TalkClose();
                                FadeOutScreen(SCREEN_FADE_STYLE_BLACK_MOSAIC, SCREEN_FADE_SPEED_NORMAL);
                                if (WasNpcSpokenToToday(CHARACTER_BARLEY) == FALSE)
                                {
                                    AddNpcFriendship(CHARACTER_BARLEY, 5);
                                }
                                MarkNpcSpokenTo(CHARACTER_BARLEY);
                                SetEntityFacing(ENTITY_BARLEY, FACING_DOWN);
                                if (GetAnimalAffection(ANIMAL_KIND_SHEEP, var_5) >= 200)
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
                                TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_LetMeKnowWhenYoureReady);
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
                    else
                    {
                        TalkOpen();
                        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table);
                        TalkClose();
                    }
                }
                else
                {
                    TalkOpen();
                    TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table);
                    TalkClose();
                }
            }
        }
    }
    else
    {
        TalkOpen();
        TalkMessage(gText_FestivalEvent_HorseRaceAndAnimalContestReceptionChoice_Table);
        TalkClose();
    }
}
